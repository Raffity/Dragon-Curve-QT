#include "glwidget.h"


GLWidget::GLWidget(QWidget *parent):
    QGLWidget(parent)
{

}

void GLWidget::initializeGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,800,600,0,0,1);
    glClearColor(0,0,0,1);
}

void GLWidget::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    makeCurrent();
    swapBuffers();
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0, w,h);
}


void GLWidget::paintDragon(int k)
{
    this->k = k;
    update();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    glBegin(GL_LINES);
        dragon(200,200,500,500,k);
    glEnd();

}


void GLWidget::dragon(int x1, int  y1, int  x2, int  y2, int k)
{
    if(k>0)
    {
        int xn = (x1+x2)/2 + (y2-y1)/2;
        int yn = (y1+y2)/2 - (x2-x1)/2;

        dragon(x1, y1, xn, yn, k-1);
        dragon(x2, y2, xn, yn, k-1);
    }
    else
    {
        glVertex2i(x1,y1);
    }
}
