#include "customglwidget.h"
#include <GLUT/glut.h>
#include <OpenGL/GLu.h>
//#include <QFileDialog>
//#include <QDir>

//customGLWidget::customGLWidget()
//{

//}


// global counter used to keep track of which mesh should be drawn
int counter = 0;
bool stopFlag = false;
// used to initially draw when play is pressed
//bool paint = false;

customGLWidget::customGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{

}

void customGLWidget::initializeGL()
{
  initializeOpenGLFunctions();
  glClearColor(0,1,0,0);
}

void customGLWidget::resizeGL(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(150, (GLfloat)w / (GLfloat)h, 0.5, 300);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslated(0,0,-3);


}

//void customGLWidget::openDir()
//{
//    // in mac you use users? what do you use in windows? homepath and it returns the home path
//    // arugments: the parent class, title you want to show and then the directory
//    //QString fileType = "obj files (*.obj)";
//    QString directoryName = QFileDialog::getExistingDirectory(this, "open directory", QDir::homePath(),  QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
//    QDir dir = directoryName;
//    QStringList objImage = dir.entryList(QStringList() << "*.obj", QDir::Files);
//    foreach(QString fileName, objImage) {
//       objFileList_.objFileVec.push_back(fileName.toStdString());
//    }
//}

void customGLWidget::draw()
{

   //std::vector<std::string> tempVec;
   //std::string test = "/Users/nancy/Documents/spring2021/CSCI_5565_introComputerGraphics/project/surfaceAnimationViewer__/Sphere_Animation/sphere_000.obj";
   //tempVec.push_back(test);
   //tempVec = openFile.openDir();
   //tempOBJFileVec = OBJContainer_.objFileVec;
   OBJContainer_.loadMesh(OBJContainer_.objFileVec,stopFlag, counter);
   glBegin(GL_TRIANGLES);

   // Go through each vertex and print its number,
   //  position, normal, and texture coordinate
   for (int j = 0; j < OBJContainer_.OBJContainer.size(); j++)
   {
       //glVertex3f(OBJContainer_[j].X,OBJContainer_[j].Y, OBJContainer_[j].Z);
       glVertex3f(OBJContainer_.OBJContainer[j].X, OBJContainer_.OBJContainer[j].Y, OBJContainer_.OBJContainer[j].Z);
   }

   glEnd();
   glFlush();
//  if (!break_)
//  {
//    paintGL();
//  }

}

void customGLWidget::paintGL()
{

       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glClearColor(0,1,0,0);
       glColor3f(1,1,1);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
       draw ();



//       glBegin(GL_TRIANGLES);

//       // Go through each vertex and print its number,
//       //  position, normal, and texture coordinate
//       for (int j = 0; j < OBJContainer_.OBJContainer.size(); j++)
//       {
//           //glVertex3f(OBJContainer_[j].X,OBJContainer_[j].Y, OBJContainer_[j].Z);
//           glVertex3f(OBJContainer_.OBJContainer[j].X, OBJContainer_.OBJContainer[j].Y, OBJContainer_.OBJContainer[j].Z);
//       }

//       glEnd();
//       glFlush();
}




