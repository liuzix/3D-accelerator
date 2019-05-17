# -*- coding: utf-8 -*-
"""
Created on Sun Apr  7 11:37:48 2019

@author: Administrator
"""

import json
indices=[1,2,3,1,3,4,2,3,6,3,7,6,5,6,7,5,7,8,3,4,8,3,7,8,1,2,6,1,5,6,1,4,5,4,5,8,2,3,4,2,3,7,6,7,8,3,4,7]
new_indices=[]
for indice in indices:
    new_indices.append(indice-1)
print(new_indices)
filename="data_file.json"
data={
      "meshes": # meshes is a list
         [{"vertices":[0,0,0,1,0,0,1,1,0,0,1,0,0,0,-1,1,0,-1,1,1,-1,0,1,-1],
         "indices":new_indices,
         "uvCount":100,
         "position":[0.5,0.5,-0.5],
         "name":"cube1"}
         ]
       
      }
with open("data_file.json","w") as write_file:
    json.dump(data,write_file)
json_data = open(filename) # open json file to read
data1 = json.load(json_data) # load the data for parsing
vertice_array=data["meshes"][0]["vertices"]
print(vertice_array)
'''
,
          {"vertices":[0,0,0,1,0,0,1,1,0,0,1,0],
         "indices":[1-1,2-1,3-1,2-1,3-1,4-1],
         "uvCount":200,
         "position":[1,1,1],
         "name":"cube2"}
'''