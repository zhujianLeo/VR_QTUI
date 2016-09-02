#ifndef GSWIDGET_H
#define GSWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
enum WINDOW_MODEL{
    MINI,
    MIDDLE,
    MAX
};

namespace Ui {
class GSWidget;
}

class GSWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GSWidget(QWidget *parent = 0);
    ~GSWidget();

private:
    Ui::GSWidget *ui;

private:
    QImage* img;
    QImage* signal_statu1;
    QImage* signal_statu2;
    WINDOW_MODEL window_s;
    QPoint position;



    QLabel* label_cam;
    QLabel* label_statu1 ;
    QLabel* label_statu2;
    QLabel* label_fps;
    QLabel* label_img;
    QLabel* label_ios;
    QLabel* label_iris ;
    QLabel* label_color;
    QLabel* label_exposure;
   // QTimer *timer;

public:
    void showMiniWindow();
    void showMiddleWindow();
    void showMaxWindow();
    void setWindowModel(WINDOW_MODEL model);
    WINDOW_MODEL getWindowModel();


protected:
    void mouseMoveEvent(QMouseEvent *event);
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent *event);

};

#endif // GSWIDGET_H
