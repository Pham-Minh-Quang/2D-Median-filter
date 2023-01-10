# 2D-Median-filter
This project that I do for my old university friend from Australia. The algorithm that I watch on youtube. Reference: https://www.youtube.com/watch?v=eJx3g-ZEfm4 
.After watching the algorithm on yotube, the first thing was found out how to add the noisy.csv file into the code, after that I had border the matrix by 0, and then using matrix 3x3 into the new matrix, then I added 9 elements into one aray and then choose the middle element. That element is the value we will change to each position and after all, I export the testClean-using-pointer.csv file. Then I compare with the clean csv file, it is same. The way to test is very simple, I added a clean.csv file into the 2d-array and then using the for loop to check each value of the element in two arrays and used a variable test to increase 1 when it is the same , because I have already known the total number of csv file is matrix 242x308, means 74536 numbers, the result of test is also 74536.

The file main.c will run the code, in this file, will have include the the medianfilter.h, which link to the function in the file medianfilter.c. Therefore, 3 files have to be in the same folder.

In this project, I have learned how to use pointer, dynamic allocation and multiple files in C.
