# -*- coding: utf-8 -*-
"""
Created on Sat Apr  6 17:57:43 2019

@author: Administrator
"""

import numpy as np
import pygame
from math import *
from constants import *
# Class to describe a Camera object
class Camera(object):
  def __init__(self, position, target):
      self.position = position # camera position in the 3d world
      self.target = target # where the camera is looking (location)
# Class to describe a Mesh object
class Mesh(object):
  def __init__(self, vertices, faces, name, position, rotation):
      self.name = name # mesh name
      self.vertices = vertices # collection of (x,y,z) vertices to define mesh
      self.faces = faces # collections of faces to define the mesh
      self.position = position # its position in the 3d world
      self.rotation = rotation # rotation state of the mesh
# Class to define the face of a mesh
# Face objects simply index the vertices index to get the
# three vertices of a face
class Face(object):
  def __init__(self, a, b, c):
      self.a = a # faces are triangles so have a set of 3 indexes
      self.b = b
      self.c = c
# Class to define the rendering device
class Device(object):
# constructor initializes frame buffer
  def __init__(self, pixel_width, pixel_height):
      self.pixel_width = pixel_width
      self.pixel_height = pixel_height
      pygame.init() # init pygame
      self.main_clock = pygame.time.Clock()
      self.display = pygame.display.set_mode((self.pixel_width, self.pixel_height), 0, 32) # create display
      self.depth_buffer = np.full( (self.pixel_width, self.pixel_height), MAX_VAL)
      pygame.display.set_caption("alien invasion")
# clear screen to one solid color
  def clear(self, color):
      self.display.fill(color)
      self.depth_buffer[:] = MAX_VAL # clear depth buffer
# set pixel

  def put_pixel(self, x, y, z, color):
#print "z buffer shows: " + str(self.depth_buffer[x][y])
#print "current z is: " + str(z)
      if (x>=self.pixel_width or y>=self.pixel_height):
          return
      if self.depth_buffer[x][y] < z:
#print "not drawing this"
          return # ignore put pixel if depth buffer is less than z
      self.depth_buffer[x][y] = z
      #print(x,y)
      self.display.set_at((x,y), color)
# update output
  def update_display(self):
      pygame.display.update()
# transform 3d coords to window coords using the transformaton matrix
  def project_to_window(self, vertex, transform_matrix):
# get clipped coordinates (to window)
      clip_coords = np.dot(transform_matrix, vertex)
# get normalized device coordinates
      n_coords = clip_coords / float(clip_coords[3])
# now translate into window coordinates
      viewport_x = 0 # specify x coordinate of bottom left-most point
      viewport_y = 0 # specify y coordinate of bottom left-most point
      viewport_w = self.pixel_width
      viewport_h = self.pixel_height
      xw = ((viewport_w / 2.0) * n_coords[0]) + (viewport_x + (viewport_w / 2.0))
      yw = ((viewport_h / 2.0) * n_coords[1]) + (viewport_y + (viewport_h / 2.0))
      zw = ((FAR - NEAR) / 2.0) * n_coords[2] + ((FAR + NEAR) / 2.0)
      return (xw, yw, zw)
# does clipping to make sure only pixels on screen will be drawn
  def draw_point(self, point, color):
      x = point[X]
      y = point[Y]
      z = point[Z]
      self.put_pixel(int(x), int(y), z, color)

# clamp value between 0 and 1
  def clamp(self, value, min_val = 0, max_val = 1):
      return max( float(min_val), min(float(value), float(max_val)) )
# interpolate the value between 2 vertices
# min is the starting point, max is the ending
  def interpolate(self, min_val, max_val, gradient):
      val = float(min_val) + ( float(max_val) - float(min_val) ) * self.clamp(float(gradient))
      return val
# draw line between two points left to right
# papb -> pcpd
  def process_scan_line(self, y, pa, pb, pc, pd, color):
# gradient between vertex a and vertex b
      if pa[Y] != pb[Y]:
          gradient1 = (y - pa[Y]) / (pb[Y] - pa[Y])
      else:
          gradient1 = 1
# gradient between vertex c and vertex d
      if pc[Y] != pd[Y]:
          gradient2 = (y - pc[Y]) / (pd[Y] - pc[Y])
      else:
          gradient2 = 1
# compute sx and ex
      sx = int(self.interpolate(pa[X], pb[X], gradient1))
      ex = int(self.interpolate(pc[X], pd[X], gradient2))

# starting z and ending z
      z1 = self.interpolate(pa[Z], pb[Z], gradient1)
      z2 = self.interpolate(pc[Z], pd[Z], gradient2)
      for x in range(sx, ex): # draw a point from startx to finish x
          gradient = (float(x) - float(sx)) / (float(ex) - float(sx))
          z = self.interpolate(z1, z2, gradient)
          self.draw_point((x, y, z), color)
# function to draw the triangle given 2 points and the color
  def draw_triangle(self, p1, p2, p3, color):
# first sort p1, p2 and p3 so that p1 is at the top
# followed by p2 and then p3
      if p1[Y] > p2[Y]:
          temp = p2
          p2 = p1
          p1 = temp
      if p2[Y] > p3[Y]:
          temp = p2
          p2 = p3
          p3 = temp
      if p1[Y] > p2[Y]:
          temp = p2
          p2 = p1
          p1 = temp
# now calculate inverse slopes
      if p2[Y] - p1[Y] > 0:
          dp1p2 = ( float(p2[X]) - float(p1[X]) ) / ( float(p2[Y]) - float(p1[Y]) )
      else:
          dp1p2 = 0.0
      if p3[Y] - p1[Y] > 0:
          dp1p3 = ( float(p3[X]) - float(p1[X]) ) / ( float(p3[Y]) - float(p1[Y]) )
      else:
          dp1p3 = 0.0
# now draw scan line for the triangles
      start_y = int(p1[Y])
      end_y = int(p3[Y]) + 1
      if dp1p2 > dp1p3:
          for y in range(start_y, end_y):
              if y < p2[Y]:
                  self.process_scan_line(y, p1, p3, p1, p2, color)
              else:
                  self.process_scan_line(y, p1, p3, p2, p3, color)
      else:
          for y in range(start_y, end_y):
              if y < p2[Y]:
                  self.process_scan_line(y, p1, p2, p1, p3, color)
              else:
                  self.process_scan_line(y, p2, p3, p1, p3, color)

# main rendor function that re-computes each vertex projection each frame
  def render(self, camera, meshes):
    view = view_matrix(camera, UP_VECTOR)
# generate projection matrix
    aspect_ratio = float(self.pixel_height) / float(self.pixel_width)
    projection = perspective_projection(NEAR, FAR, ANGLE_OF_VIEW, aspect_ratio)
    for mesh in meshes:
# generate world matrix for the mesh
        rotation_angles = (mesh.rotation[0], mesh.rotation[1], mesh.rotation[2])
        translations = (mesh.position[0], mesh.position[1], mesh.position[2])
        world = world_matrix(SCALING, rotation_angles, translations)
# generate final transform matrix
        transform_matrix = np.dot(view, world)
        transform_matrix = np.dot(projection, transform_matrix)
        faceindex = 0
        for face in mesh.faces: # now render each face on the screen
# first define the three vertices of the face to be drawn
            try:
              vertex_a = mesh.vertices[face.a]
              vertex_b = mesh.vertices[face.b]
              vertex_c = mesh.vertices[face.c]
# convert teh 3-d vertices to 2-d pixels that can be drawn on the screen
              pixel_a = self.project_to_window(vertex_a, transform_matrix)
              pixel_b = self.project_to_window(vertex_b, transform_matrix)
              pixel_c = self.project_to_window(vertex_c, transform_matrix)
# color triangles
              color = 2 + (faceindex % len(mesh.faces)) * 100 / len(mesh.faces)
              if faceindex == 0 or faceindex ==1:
                color_vec = (255, 255, 255, 255)
              else:
                color_vec = (color, color, color, 255)
              #color_vec=(255,255,0,255)
              self.draw_triangle(pixel_a, pixel_b, pixel_c, color_vec)
              faceindex += 1
            except:
                #print("face index out of range")
                #print(face.a,face.b,face.c)
                pass

#
# Matrix transform functions
#
##################################

# create scale matrix
def scale_matrix(cx, cy, cz):
      scale = np.identity(4) # start with 4x4 identity matrix
      scale[0, 0] = cx
      scale[1, 1] = cy
      scale[2, 2] = cz
      return scale
def translate_matrix(dx, dy, dz):
      trans = np.identity(4)
      trans[0, 3] = dx
      trans[1, 3] = dy
      trans[2, 3] = dz
      return trans
def rotate_matrix_x(angle):
      rad = angle * 0.01743 # pi/180 = 0.01743
      rotate = np.identity(4)
      rotate[1, 1] = cos(rad)
      rotate[1, 2] = sin(rad)
      rotate[2, 1] = -sin(rad)
      rotate[2, 2] = cos(rad)
      return rotate
def rotate_matrix_y(angle):
      rad = angle * 0.01743 # pi/180 = 0.01743
      rotate = np.identity(4)
      rotate[0, 0] = cos(rad)
      rotate[0, 2] = -sin(rad)
      rotate[2, 0] = sin(rad)
      rotate[2, 2] = cos(rad)
      return rotate
def rotate_matrix_z(angle):
      rad = angle * 0.01743 # pi/180 = 0.01743
      rotate = np.identity(4)
      rotate[0, 0] = cos(rad)
      rotate[0, 1] = -sin(rad)
      rotate[1, 0] = sin(rad)
      rotate[1, 1] = cos(rad)
      return rotate
def orthographic_projection(near, far, left, right, bottom, top):
    ortho = np.zeros((4, 4))
# first column changes
    ortho[0, 0] = 2.0 / (right - left)
# second column changes
    ortho[1, 1] = 2.0 / (top - bottom)

# third column changes
    ortho[2, 2] = -2.0 / (far - near)
# fourth column changes
    ortho[0, 3] = -(right + left) / (right - left)
    ortho[1, 3] = -(top + bottom) / (top - bottom)
    ortho[2, 3] = -(far + near) / (far - near)
    ortho[3, 3] = 1
    return ortho
def perspective_projection(near, far, angle_of_view, aspect_ratio):
# start with some maths needed to get the matrix
    rad_view = angle_of_view * 0.01743 # change angle of view to rads
    size = near * tan(rad_view / 2.0)
    left = -size
    right = size
    bottom = -size / aspect_ratio
    top = size / aspect_ratio
    persp = np.zeros((4, 4))
# first column changes
    persp[0, 0] = 2.0 * near / (right - left)
# second column changes
    persp[1, 1] = 2 * near / (top - bottom)
# third column changes
    persp[0, 2] = (right + left) / (right - left)
    persp[1, 2] = (top + bottom) / (top - bottom)
    persp[2, 2] = -(far + near) / (far - near)
    persp[3, 2] = -1.0
# fourth column changes
    persp[2, 3] = -(2 * far * near) / (far - near)
    return persp
# create the vew matrix where you pass the camera object
def view_matrix(camera, up):
# first specify the translation matrix based on camera position
      translate = translate_matrix(camera.position[0], camera.position[1], camera.position[2])
      translate = np.linalg.inv(translate) # invert translate matrix
# create target and up vectors
      target_vector = np.array([camera.target[0], camera.target[1], camera.target[2]])
      up_vector = np.array([up[0], up[1], up[2]])
# now get camera rotation matrix based on tutorial http://ogldev.atspace.co.uk/www/tutorial13/tutorial13.html
      N = target_vector
      N = N / np.linalg.norm(N) # need to normalize N array
      U = up_vector
      U = U / np.linalg.norm(U) # need to normalize U array
      U = np.cross(U, target_vector)
      V = np.cross(N, U)

# generate matrix based on U,V,N vectors
      rotate = np.identity(4) # start with identity matrix
      rotate[0, 0] = U[0]
      rotate[0, 1] = U[1]
      rotate[0, 2] = U[2]
      rotate[1, 0] = V[0]
      rotate[1, 1] = V[1]
      rotate[1, 2] = V[2]
      rotate[2, 0] = N[0]
      rotate[2, 1] = N[1]
      rotate[2, 2] = N[2]
      view = np.dot(rotate, translate)
      return view
def world_matrix(scale_factors, rotation_angles, translations):
# scale the object
    scale = scale_matrix(scale_factors[0], scale_factors[1], scale_factors[2])
# rotate the object
    rotate_x = rotate_matrix_x(rotation_angles[0])
    rotate_y = rotate_matrix_y(rotation_angles[1])
    rotate_z = rotate_matrix_z(rotation_angles[2])
# translate the object
    translate = translate_matrix(translations[0], translations[1], translations[2])
    world = np.dot(rotate_x, scale)
    world = np.dot(rotate_y, world)
    world = np.dot(rotate_z, world)
    world = np.dot(translate, world)
    return world