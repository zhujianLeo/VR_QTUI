#include "gswidget.h"
#include "ui_gswidget.h"
#include <QMouseEvent>
#include "mainwindow.h"

#include <QGridLayout>


#define MINI_W 300
#define MINI_H 156

#define MIDDLE_W 300
#define MIDDLE_H 276


GSWidget::GSWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GSWidget)
{
    ui->setupUi(this);

    setStyleSheet("QTabWidget:pane {background:  #061927; }");

    img = new QImage();
    signal_statu1 = new QImage() ;
    signal_statu2 = new QImage();
    window_s = MINI;

    if(! ( img->load(":/image/fake1.jpg") ) ) //加载图像
    {
                delete img;
                return;
    }
    if(! ( signal_statu1->load(":/image/normal_statu.png") ) ) //加载图像
    {
                delete signal_statu1;
                return;
    }
    if(! ( signal_statu2->load(":/image/innormal_statu") ) ) //加载图像
    {
                delete signal_statu2;
                return;
    }
    ui->label_2->setFixedWidth(80);
    ui->signal_statu1->setFixedWidth(20);
    ui->signal_statu2->setFixedWidth(20);
    ui->label->setPixmap(QPixmap::fromImage(*img));
    ui->label->setScaledContents(true);
    ui->signal_statu1->setPixmap(QPixmap::fromImage(*signal_statu1));
    ui->signal_statu2->setPixmap(QPixmap::fromImage(*signal_statu2));


    ui->label_ios->hide();
    ui->label_iris->hide();
    ui->label_color->hide();
    ui->label_exposure->hide();
    ui->horizontalSlider_ios->hide();
    ui->horizontalSlider_iris->hide();
    ui->horizontalSlider_color->hide();
    ui->horizontalSlider_exposure->hide();

    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    ui->label_ios->setPalette(pa);
    ui->label_ios->setAttribute(Qt::WA_TranslucentBackground);

    ui->label_iris->setPalette(pa);
    ui->label_iris->setAttribute(Qt::WA_TranslucentBackground);

    ui->label_color->setPalette(pa);
    ui->label_color->setAttribute(Qt::WA_TranslucentBackground);

    ui->label_exposure->setPalette(pa);
    ui->label_exposure->setAttribute(Qt::WA_TranslucentBackground);


    ui->label_2->setPalette(pa);
    ui->label_2->setAttribute(Qt::WA_TranslucentBackground);

    ui->label_3->setPalette(pa);
    ui->label_3->setAttribute(Qt::WA_TranslucentBackground);



    ui->cam->setPalette(pa);
    ui->cam->setAttribute(Qt::WA_TranslucentBackground);

    ui->label->setAttribute(Qt::WA_TranslucentBackground);

    ui->fps->setPalette(pa);
    ui->fps->setAttribute(Qt::WA_TranslucentBackground);

    ui->signal_statu1->setAttribute(Qt::WA_TranslucentBackground);
    ui->signal_statu2->setAttribute(Qt::WA_TranslucentBackground);

    ui->horizontalSlider_color->setAttribute(Qt::WA_TranslucentBackground);
    ui->horizontalSlider_ios->setAttribute(Qt::WA_TranslucentBackground);
    ui->horizontalSlider_iris->setAttribute(Qt::WA_TranslucentBackground);
    ui->horizontalSlider_exposure->setAttribute(Qt::WA_TranslucentBackground);


    ui->horizontalSlider_ios->setStyleSheet("QSlider{ background-color:rgb(10,42,63)}");
    ui->horizontalSlider_color->setStyleSheet("QSlider{ background-color:rgb(10,42,63)}");
    ui->horizontalSlider_iris->setStyleSheet("QSlider{ background-color:rgb(10,42,63)}");
    ui->horizontalSlider_exposure->setStyleSheet("QSlider{ background-color:rgb(10,42,63)}");



    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Background,QColor(10,42,63));
    this->setPalette(palette); // 至此, 已给widget加上了背景图.

    position.setX(geometry().x());
    position.setY(geometry().y());
    ui->gridLayout1->setSpacing(2);

}

GSWidget::~GSWidget()
{
    delete img;
    delete ui;
}

void GSWidget::showMiniWindow(){

    this->setAutoFillBackground(true);

    QPalette palette = this->palette();

    palette.setColor(QPalette::Background,QColor(6,25,39));
     this->setPalette(palette);

    ui->label_ios->hide();
    ui->label_iris->hide();
    ui->label_color->hide();
    ui->label_exposure->hide();
    ui->horizontalSlider_ios->hide();
    ui->horizontalSlider_iris->hide();
    ui->horizontalSlider_color->hide();
    ui->horizontalSlider_exposure->hide();
   // setGeometry(geometry().x(), geometry().y()+40, MINI_W, MINI_H);
    resize(MINI_W,MINI_H);
  //  move(geometry().x()+5,geometry().y());
    lower();
}

void GSWidget::showMiddleWindow(){


    this->setAutoFillBackground(true);

    QPalette palette = this->palette();
//        palette.setBrush(QPalette::Window,
//                         QBrush(QPixmap(":/image/bg_mid.png").scaled( // 缩放背景图.
//                                 QSize(210,256),
//                                 Qt::IgnoreAspectRatio,
//                                 Qt::SmoothTransformation))); // 使用平滑的缩放方式
    palette.setColor(QPalette::Background,QColor(10,42,63));
     this->setPalette(palette); // 至此, 已给widget加上了背景图

    ui->label_ios->show();
    ui->label_iris->show();
    ui->label_color->show();
    ui->label_exposure->show();
    ui->horizontalSlider_ios->show();
    ui->horizontalSlider_iris->show();
    ui->horizontalSlider_color->show();
    ui->horizontalSlider_exposure->show();
    resize(MIDDLE_W,MIDDLE_H);
  //  move(geometry().x()-5,geometry().y());
    raise();
}


void GSWidget::showMaxWindow(){

    int w = this->height();
    int h = this->width();
    move(QPoint(0,0));
    resize(1830,800);
    //showFullScreen();
}

void GSWidget::setWindowModel(WINDOW_MODEL model){

    window_s = model;
}
WINDOW_MODEL GSWidget::getWindowModel(){
    return window_s;
}

void GSWidget::mouseMoveEvent(QMouseEvent *event){


}


void GSWidget::enterEvent(QEvent * event){
    if(window_s == MINI){
        showMiddleWindow();
    }
}
void GSWidget::leaveEvent(QEvent *event){
    if(window_s == MINI){
        showMiniWindow();
    }
}



