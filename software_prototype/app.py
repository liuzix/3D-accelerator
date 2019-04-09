
#SOFTWARE PROTOTYPE FILES IN PYTHON
######pygpu – RENDER MODULE in python

#### app.y
#### application that uses the above pygpu render module
from render import *
import numpy as np
import sys
import pygame
import time
import json
def load_mesh_from_json(filename):
  meshes = [] # list of meshes we will return
  json_data = open(filename) # open json file to read
  data = json.load(json_data) # load the data for parsing
  num_meshes = len(data["meshes"]) # holds number of meshes in model
  for mesh_index in range(num_meshes):
# first get vertices and indices array
      vertices_array = data["meshes"][mesh_index]["vertices"]
      indices_array = data["meshes"][mesh_index]["indices"]
# get uvCount (i have no idea what this is???)
      uv_count = int(data["meshes"][mesh_index]["uvCount"])
      vertices_step = 3
# determines how many of the vertices we
# want to use from the json file. we don't
# need all of them
      '''
      if uv_count == 0:
          vertices_step = 6
      elif uv_count == 1:
          vertices_step = 8
      elif uv_count == 2:
          vertices_step = 10
          '''
# get number of vertices we care about
      vertices_count = int(len(vertices_array) / vertices_step)
      print(vertices_count,vertices_step)
# get number of faces we care about which is size of arr / 3 (a,b,c)
      faces_count = int(len(indices_array) / 3)
      print(faces_count)
# get the vertices array
      vertices = [] # init empty vertices list
      for index in range(vertices_count):
          x = float(vertices_array[index * vertices_step])
          y = float(vertices_array[index * vertices_step + 1])
          z = float(vertices_array[index * vertices_step + 2])
          w = 1
          vertices.append(np.matrix([[x], [y], [z], [w]]))
      #print(vertices)
# get the faces array
      faces = [] # init empty faces list
      for index in range(faces_count):
          a = int(indices_array[index * 3])
          b = int(indices_array[index * 3 + 1])
          c = int(indices_array[index * 3 + 2])
          faces.append(Face(a, b, c))
      print(len(faces))
# get the position specified in blender
      px = float(data["meshes"][mesh_index]["position"][0])
      py = float(data["meshes"][mesh_index]["position"][1])
      pz = float(data["meshes"][mesh_index]["position"][2])
      position = (px, py, pz)
# get mesh name
      name = data["meshes"][mesh_index]["name"]
# set default rotation values
      rotation = (0, 0, 0)
# now we have all of the mesh data so we can create he mesh object
      new_mesh = Mesh(vertices, faces, name, position, rotation)
      meshes.append(new_mesh) # add new mesh to our meshes array
  return meshes

#############################################
# #
# main program #
# #
#############################################
####### code to create a new rendering device #######
filename="bird.json"
meshes = load_mesh_from_json(filename)
print(type(meshes))
for mesh in meshes:
    for vertice in mesh.vertices:
        print(vertice)
    for face in mesh.faces:
        print(face.a,face.b,face.c)


my_device = Device(500, 500) # screen 100 x 100
####### code to create a new camera ######
camera_position = (0, 0, 5) # move 5 units along the z axis
camera_target = (0.0, 0.0, 1.0) # pointed straight at z axis
my_camera = Camera(camera_position, camera_target)
####### code to load in mesh from json file #######



while True:
  for event in pygame.event.get():
      if event.type == pygame.QUIT: # wait for user to close window
          sys.exit()

  my_device.clear((0, 0, 0, 255)) # clear screen
  #pygame.display.flip()
# rotate cube slightly during each frame rendered
  mesh.rotation = (mesh.rotation[0] , mesh.rotation[1] + 1, mesh.rotation[2]) # move mesh position slightly
  my_device.render(my_camera, meshes) # render meshes
  my_device.update_display() # update display
       