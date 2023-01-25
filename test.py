# def solution(m):
#     size = len(m)
#     for i,elem in enumerate(m):
#         elem[i] = 0
#     row_sum = [sum(i) for i in m]
    
#     transi = []
#     stable = []
#     for i in range(len(row_sum)):
#         if row_sum[i] == 0:
#             stable.append(i)
#         else:
#             transi.append(i)

#     n_tran = len(transi)
    
#     for i in range(0, n_tran - 1):
#         prt2 = transi[n_tran - i - 1]
#         for j in range(0, n_tran - 1):
#             prt1 = transi[j]   
#             m[prt1] = fuse(m[prt1] , prt1, m[prt2], prt2)

#     output=[]
#     for i in stable:
#         output.append(m[0][i])

#     all_num = sum(output)
#     output.append(all_num)
#     if all_num == 0:
#         output=[1 for i in stable]
#         output.append(len(stable))

#     return output

# def fuse(arr1, idx1, arr2, idx2):
#     indices = [i for i in range(len(arr1)) if i != idx1 and i != idx2]
#     arr2_sum = sum(arr2)
#     result = [0 for i in arr1]
#     for i in indices:
#         result[i] = arr2_sum * arr1[i] + arr1[idx2] * arr2[i]

#     div = 0
#     for i in range(len(result)):
#         div = com_div(div, result[i])

#     simp_result = [int(i / div) for i in result]
#     return simp_result
    

# def com_div(a,b):
#     if (b == 0):
#         return a
#     else:
#         return com_div (b, a % b)

# a = [[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
# print(solution(a))






import matplotlib.pyplot as plt
import numpy as np


# prepare some coordinates
x, y, z = np.indices((8, 8, 8))

# draw cuboids in the top left and bottom right corners, and a link between
# them
cube1 = (x < 3) & (y < 3) & (z < 3)
cube2 = (x >= 5) & (y >= 5) & (z >= 5)
link = abs(x - y) + abs(y - z) + abs(z - x) <= 2

# combine the objects into a single boolean array
voxelarray = cube1 | cube2 | link

# set the colors of each object
colors = np.empty(voxelarray.shape, dtype=object)
colors[link] = 'red'
colors[cube1] = 'blue'
colors[cube2] = 'green'

# and plot everything
ax = plt.figure().add_subplot(projection='3d')
ax.voxels(voxelarray, facecolors=colors, edgecolor='k')

plt.show()