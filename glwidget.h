#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <GL/gl.h>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void print(int k);

private:
    int k = 0;
    void dragon(int x1, int y1, int x2, int y2, int k);
};

#endif // GLWIDGET_H
