#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "objimageloader.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    objImageLoader objFileList_;
    //std::vector<std::string> openDir();



private slots:
    void on_play_clicked();

    void on_reverse_clicked();

    void on_pause_clicked();

    void on_forward_clicked();

    void on_stop_clicked();


    void on_OpenFile_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
