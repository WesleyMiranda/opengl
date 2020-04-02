import cv2 as cv
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

fig = plt.figure(figsize=(4,4))

placa = cv.imread("./img/pare - 2.png")
placa_array = np.asarray(placa);
placa_flat_array = []
print(placa_array.)

#for i in range(0, placa_array.):
 #   for j in range(0, placa_array.size[1]):
  #      placa_flat_array[i*placa_array.size[1] + j] = placa_array[0][0]

placa_HSV = cv.cvtColor(placa, cv.COLOR_RGB2HSV)


H = cv.calcHist([placa_HSV], [0], None, [256], [0, 256])
S = cv.calcHist([placa_HSV], [1], None, [256], [0, 256])
V = cv.calcHist([placa_HSV], [2], None, [256], [0, 256])

H[0] = 0
S[0] = 0
V[0] = 0

print(sum(H))
print(sum(S))
print(sum(V))



ax = fig.add_subplot(111, projection='3d')

ax.scatter(H, S, V)

plt.show()
