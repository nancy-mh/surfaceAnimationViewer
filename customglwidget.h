#ifndef CUSTOMGLWIDGET_H
#define CUSTOMGLWIDGET_H
#include "objimageloader.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "mainwindow.h"

class customGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    customGLWidget(QWidget *parent = nullptr);
    objImageLoader OBJContainer_;
    MainWindow openFile;
    //void openDir();
    void draw();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // CUSTOMGLWIDGET_H
