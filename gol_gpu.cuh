#ifndef GOL_GPU_H
#define GOL_GPU_H

#include <stdlib.h>
#include <stdio.h>
//#include <GL/glut.h>

__global__ void processing(unsigned char*,int);

unsigned char* data;
int h,w;
void _initGPU(int,int);
void _exitGPU();

void stepGPU();



#endif
