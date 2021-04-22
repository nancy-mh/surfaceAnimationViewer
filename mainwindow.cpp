#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
//#include <QApplication>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_play_clicked()
{
    //counter ++;
    // this is the play button so breaking out of the outer for loop is always false
    bool stop = false;

     //  this doesnt do anything
     ui->openGLWidget->paint = true;

    std::cout << "this is play" << std::endl;
    //update();
}

//std::vector<std::string> MainWindow::openDir()
//{
//    std::vector<std::string> temp;
//    // in mac you use users? what do you use in windows? homepath and it returns the home path
//    // arugments: the parent class, title you want to show and then the directory
//    //QString fileType = "obj files (*.obj)";
//    QString directoryName = QFileDialog::getExistingDirectory(this, "open directory", QDir::homePath(),  QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
//    QDir dir = directoryName;
//    QStringList objImage = dir.entryList(QStringList() << "*.obj", QDir::Files);
//    foreach(QString fileName, objImage) {
//       temp.push_back(fileName.toStdString());
//    }
//    return temp;
//}

void MainWindow::on_reverse_clicked()
{

}

void MainWindow::on_pause_clicked()
{

}

void MainWindow::on_forward_clicked()
{

}

void MainWindow::on_stop_clicked()
{

}


void MainWindow::on_OpenFile_clicked()
{
//    //std::vector<std::string> temp;
//    // in mac you use users? what do you use in windows? homepath and it returns the home path
//    // arugments: the parent class, title you want to show and then the directory
//    //QString fileType = "obj files (*.obj)";
    QString directoryName = QFileDialog::getExistingDirectory(this, "open directory", QDir::homePath(),  QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QDir dir = directoryName;
    //QFileInfoList objImagelist = dir.entryInfoList()
    QStringList objImage = dir.entryList(QStringList() << "*.obj", QDir::Files);
    foreach(QString fileName, objImage) {
       objFileList_.objFileVec.push_back(fileName.toStdString());
    }
//    std::vector<std::string> temp_;
//    temp_ = openDir();

}
