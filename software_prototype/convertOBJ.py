# -*- coding: utf-8 -*-
"""
Created on Sun Apr  7 14:33:31 2019

@author: Administrator
"""
import json

outputfilename="bird.json"
filename='Bird_Leg.obj'
with open(filename) as file_object:
    lines=file_object.readlines()
vertices=[]
faces=[]
for line in lines[0:1448]:
    if (line[0]=='v')&(line[1]==' '):
        vx=float(line.split()[1])
        vy=float(line.split()[2])
        vz=float(line.split()[3])
        vertices.append(vx)
        vertices.append(vy)
        vertices.append(vz)
        #print(vx,vy,vz)
    if line[0]=='f':
        index1=int(line.split()[1].split('/')[0])-1
        index2=int(line.split()[2].split('/')[0])-1
        index3=int(line.split()[3].split('/')[0])-1
        faces.append(index1)
        faces.append(index2)
        faces.append(index3)
        #print([index1,index2,index3])
print("number of faces:",len(faces)/3)
print("number of vertices:",len(vertices)/3)

data={
      "meshes": # meshes is a list
         [{"vertices":vertices,
         "indices":faces,
         "uvCount":100,
         "position":[0,0,0],
         "name":"cube1"}
         ]
       
      }
with open(outputfilename,"w") as write_file:
    json.dump(data,write_file)
json_data = open(outputfilename) # open json file to read
data1 = json.load(json_data) # load the data for parsing
vertice_array=data["meshes"][0]["vertices"]
print(vertice_array)