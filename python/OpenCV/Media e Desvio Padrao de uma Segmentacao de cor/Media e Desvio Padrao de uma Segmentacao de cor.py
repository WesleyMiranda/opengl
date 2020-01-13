import cv2 as cv
import numpy as np
import os


path_images = "./img/"
placas = ("placas pare")
files_list = os.listdir(path_images)

H = []; S = []; V = []

for image in files_list:
    placa = cv.imread(path_images + placas + "/" + image)
    placa_HSV = cv.cvtColor(placa, cv.COLOR_BGR2HSV)

    for line in placa_HSV:
        for pixel in line:
            if pixel[2] > 20 and pixel[1] > 20:
                if pixel[0] < 155:
                    H.append(pixel[0] + 255)
                else:
                    H.append(pixel[0])
                S.append(pixel[1])
                V.append(pixel[2])


arquivo = open('resultados/' + placa + '.txt','w')
arquivo.write("MEDIA H:" + str(np.average(H)) + "\nDESVIO H: "+ str(np.std(H)) + "\n")
arquivo.write("MEDIA S:" + str(np.average(S)) + "\nDESVIO S: "+ str(np.std(S)) + "\n")
arquivo.write("MEDIA V:" + str(np.average(V)) + "\nDESVIO V: "+ str(np.std(V)) + "\n")
arquivo.close()

cv.waitKey(0)
