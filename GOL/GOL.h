#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
/*
 * @author NaiveWang
 * @email wanhzhiwen@gmail.com
 * Creative Commons
 **/
#define T_HEIGHT    100
#define T_WIDTH     100
#define W_HEIGHT    1000
#define W_WIDTH     1000
/*debug function section*/
void DEBUG_W(int x,int y,int status)
{
    static FILE *fp;
    fp = fopen("debug.log","a");
    fprintf(fp,"%d|%d  %d\n",y,x,status);
}

/*Type section*/
typedef struct Status_of_dot
{
    char s;
}SOD;
typedef struct Matrix
/*
 * This is the structure of the Matrix status,
 * status:span status
 * A&B : the two status of dot matrix.
 **/
{
    char status;
    int height;
    int width;
    SOD *A;
    SOD *B;
}matrix;
/*global arguments section*/
matrix M;
int init_lock;
/*Initializing section*/
void M_init(matrix *M,int h,int w)
{
    M->A = malloc(h*w*sizeof(SOD));
    M->B = malloc(h*w*sizeof(SOD));
    M->height = h;
    M->width = w;
    M->status = 0;
    ZeroMemory(M->A,h*w*sizeof(SOD));
    ZeroMemory(M->B,h*w*sizeof(SOD));
}
void M_free(matrix *M)
{
    free(M->A);
    free(M->B);
}
/*Dot Processing section*/
int Edge(n,m)
{
    if(n==m)   return 0;
    if(n+1) return n;
    else    return m-1;
}
int Index(x,y,w)
{
    return x+y*w;
}
int Counter(SOD *base,int x,int y,int w,int h,int n)
{
    int ax,ay;
    int counter;

    counter = 0;
    for(ax=x-n,ay=y-n;ax<x+n;ax++)
    {
        counter+=(base+Index(Edge(ax,w),Edge(ay,h),w))->s;
    }
    for(;ay<y+n;ay++)
    {
        counter+=(base+Index(Edge(ax,w),Edge(ay,h),w))->s;
    }

    for(ax=x-n,ay=y-n;ay<y+n;ay++)
    {
        counter+=(base+Index(Edge(ax,w),Edge(ay,h),w))->s;
    }
    for(;ax<x+n;ax++)
    {
        counter+=(base+Index(Edge(ax,w),Edge(ay,h),w))->s;
    }
    counter-=(base+Index(Edge(x-n,w),Edge(y-n,h),w))->s;
    counter+=(base+Index(Edge(x+n,w),Edge(y+n,h),w))->s;
    //counter-=(base+Index(Edge(x-n,w),Edge(y+n,h),w))->s;
    //counter-=(base+Index(Edge(x+n,w),Edge(y-n,h),w))->s;
    return counter;
}
void Process(matrix *M)
{
    static SOD *current;
    static SOD *next;
    static int counter_h;
    static int counter_w;
    static int border;

    if(M->status)
    {
        M->status=0;
        current = M->B;
        next = M->A;
    }
    else{
        M->status=1;
        next = M->B;
        current = M->A;
    }
    for(counter_h=0;counter_h<M->height;counter_h++)
        for(counter_w=0;counter_w<M->width;counter_w++)
    {
        border = Counter(current,counter_w,counter_h,M->width,M->height,1);
        //DEBUG_W(counter_w,counter_h,border);
        //Rules here

        if(border<2*127) (next+Index(counter_w,counter_h,M->width))->s=(char)0;
        else if(border==2*127) (next+Index(counter_w,counter_h,M->width))->s=(char)(current+Index(counter_w,counter_h,M->width))->s;
        else if(border==3*127) (next+Index(counter_w,counter_h,M->width))->s=(char)127;
        else (next+Index(counter_w,counter_h,M->width))->s=(char)0;
    }

}
/*Graphic section (Display)*/
void Display()
{
    if(init_lock)
    {
        static SOD *d;
        static int x,y,counter;
        static char color;


        d=M.status?M.B:M.A;
        counter = 0;
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);

        for(y=0;y<M.height;y++)
        {
            for(x=0;x<M.width;x++)
            {
                color = ((d+counter)->s)<<1;
                glColor3ub(color,color,color);
                //printf("%d|%d %d\n",x,y,(d+counter)->s);
                glBegin(GL_QUADS);
                glVertex2i(x,y);
                glVertex2i(x+1,y);
                glVertex2i(x+1,y+1);
                glVertex2i(x,y+1);
                glEnd();
                counter++;
            }
        }

        //glEnd();
        glFlush();
        Process(&M);
        Sleep(100);
    }
    else
    {
        static int x,y,counter;
        static char color;


        counter = 0;
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);

        for(y=0;y<M.height;y++)
        {
            for(x=0;x<M.width;x++)
            {
                color = ((M.A+counter)->s)<<1;
                glColor3ub(color,0,0);
                //printf("%d|%d %d\n",x,y,(d+counter)->s);
                glBegin(GL_QUADS);
                glVertex2i(x,y);
                glVertex2i(x+1,y);
                glVertex2i(x+1,y+1);
                glVertex2i(x,y+1);
                glEnd();
                counter++;
            }
        }

        //glEnd();
        glFlush();
    }
}

void myReshape(GLsizei w,GLsizei h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);//指明当前矩阵为GL_PROJECTION
    glLoadIdentity();//将当前矩阵置换为单位阵

    gluOrtho2D(0.0,T_WIDTH,0.0,T_HEIGHT);//定义二维正视投影矩阵
    glMatrixMode(GL_MODELVIEW);//指明当前矩阵为GL_MODELVIEW
}
/*Controlling section*/
void Start(unsigned char key,int x,int y)
{
    if(key == 's') init_lock=1;
}
void SetDot(int button,int state,int x,int y)
{
    if(!init_lock)
    {
        if(button==GLUT_LEFT_BUTTON&&state==GLUT_UP)
        {
            x/=(W_WIDTH/T_WIDTH);
            y/=(W_HEIGHT/T_HEIGHT);
            if(M.A[Index(x,T_HEIGHT-1-y,M.width)].s)
                M.A[Index(x,T_HEIGHT-1-y,M.width)].s = 0;
            else M.A[Index(x,T_HEIGHT-1-y,M.width)].s = 127;
        }
        else if(button==GLUT_RIGHT_BUTTON) init_lock=1;
    }
    else
    {
        if(button==GLUT_RIGHT_BUTTON) init_lock=0;
    }
}

