import cv2 as cv
import numpy as np

src = cv.imread("example.jpg")

# convert to gray scale
src = cv.cvtColor(src, cv.COLOR_BGR2GRAY)


dst = cv.equalizeHist(src)

cv.imshow('Source',src)
cv.imshow('Dest', dst)

cv.waitKey()


clahe =  cv.createCLAHE()
cl_dest = clahe.apply(src)

res = np.hstack((dst, cl_dest))
cv.imshow('simple histeq VS CLAHE', res)
cv.waitKey()