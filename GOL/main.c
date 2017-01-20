#include <stdio.h>
#include <stdlib.h>
#include "GOL.h"

int main(int argc,char **argv)
{
    init_lock=0;
    M_init(&M,T_HEIGHT,T_WIDTH);
    //printf("Hello world!\n");
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(W_WIDTH,W_HEIGHT);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Cellular Motor");
    glutReshapeFunc(myReshape);



    glutDisplayFunc(Display);
    glutMouseFunc(&SetDot);
    glutIdleFunc(Display);
    glutMainLoop();
    M_free(&M);
    return 0;
}
