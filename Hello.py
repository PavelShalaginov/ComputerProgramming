import numpy as np
import cv2
from matplotlib import pyplot as plt

for test in range(1,40):
    s=str(test)+'.jpg'
    img = cv2.imread(s,0)
    print (s)
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            if img[i][j]>196:
                img[i][j]=255
                
    cv2.imwrite('_'+s,img)
