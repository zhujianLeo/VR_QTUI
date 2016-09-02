#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"gswidget.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static  MainWindow* getMainWindow();

public slots:
    void  removeSubTab(int index);
     bool eventFilter(QObject *,QEvent *);
     void singleClicked();
     void doubleClicked();

     void  start_stop_record();
     void  close_allcomputer();
     void  save_img();
     void  save_video();
private:
    Ui::MainWindow *ui;
    GSWidget* cameras[30];
    QTimer *timer;
    int currentCamera;
};

#endif // MAINWINDOW_H
