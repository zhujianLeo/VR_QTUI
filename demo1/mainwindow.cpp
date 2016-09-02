#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpushbutton.h"
#include "gswidget.h"
#include "gswidgetmax.h"
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentCamera = -1;
//    ui->tableWidget->setColumnCount(2);

//    QStringList m_Header;
//    m_Header<<QString("所有镜头预览")<<QString("单个镜头预览");
//    ui->tableWidget->setHorizontalHeaderLabels(m_Header);

    //ui->tabWidget->
    //ui->tabWidget->setTabPosition(QTabWidget::TabPosition());
   // ui->tabWidget->setStyleSheet();

    //ui->tabWidget->setStyleSheet("QSplitter::handle { background:darkGray; } QSplitter::handle:horizontal { width:1px; } QSplitter::handle:vertical { height:1px; }");
    // ui->tabWidget->setStyleSheet("background:yellow;");


//     QString tabBarStyle = "QTabBar::tab {min-width:50px;min-height:3px;color: white;background-color:#2F4F4F;background-image:url(:/image/tab1_1.png);border: 1px solid black;border-top-left-radius: 10px;border-top-right-radius: 10px;padding:5px;}\
//     QTabBar::tab:!selected {margin-top: 2px;} \
//     QTabBar::tab:selected {background-color: #2F4F5F;} \
//     QTabWidget::tab-bar{alignment:left;}";

//     QString tabBarStyle = " QTabBar::tab:hover {border-image: url(:/image/tab1_1.png);width: 38px;height: 129px;background: transparent;position: absolute;}\
//     QTabBar::tab:selected {border-image: url(:/image/tab1_2.png);width: 38px;height: 129px;background: transparent;position: absolute;}\
//     QTabWidget::tab-bar{alignment:left;}";


    QString tabBarStyle = "QTabBar::tab:hover {border-image: url(:/image/tab1_2.png);color:white;width: 120px;height: 30px;border: 1px solid black;position: absolute;}\
    QTabWidget:pane {background:  #102f44; }\
    QTabBar::tab:first:!selected {border-image: url(:/image/tab1_2.png);color:white;width: 120px;height: 30px;background: transparent;position: absolute;}\
    QTabBar::tab:first:selected {border-image: url(:/image/tab1_1.png);color:white;width: 120px;height: 30px;background: transparent;position: absolute;}\
    QTabBar::tab:last:hover {border-image: url(:/image/tab2_2.png);margin-left:-15px;color:white;width: 120px;height: 30px;background: transparent;position: absolute;}\
    QTabBar::tab:last:!selected {border-image: url(:/image/tab2_2.png);margin-left:-15px;color:white;width: 120px;height: 30px;background: transparent;position: absolute;}\
    QTabBar::tab:last:selected {border-image: url(:/image/tab2_1.png);margin-left:-15px;color:white;width: 120px;height: 30px;background: transparent;position: absolute;}\
    QTabWidget::tab-bar{alignment:left; }";


     ui->tabWidget->setStyleSheet(tabBarStyle);
     ui->tabWidget->setWindowState(Qt::WindowFullScreen);
     ui->centralWidget->setStyleSheet("background:#061927;");
       // color="#102f44"

    //对于子tabwidget的风格编辑设置
     QString tabBarStyle2 = " QTabBar::tab:hover {border-image: url(:/image/selected_icon.jpg);color:white;width: 120px;height: 30px;border: 1px solid black;position: absolute;}\
     QTabWidget:pane {background:  #061927; }\
     QTabBar::tab:!selected {border-image: url(:/image/selected_icon.jpg);color:white;width: 120px;height: 20px;background: transparent;position: absolute;}\
     QTabBar::tab:selected {border-image: url(:/image/selected_icon.jpg);color:white;width: 120px;height: 20px;background: transparent;position: absolute;}\
     QTabWidget:pane {background:  #061927; }\
     QTabWidget::tab-bar{alignment:left; }";
     ui->tabWidget_2->removeTab(1);
     ui->tabWidget_2->setStyleSheet(tabBarStyle2);
     ui->tabWidget_2->setWindowState(Qt::WindowFullScreen);


     int count = 0;
     for(int k = 0;k<5;k++){
         for(int i = 0;i<6;i++){
            cameras[count] = new GSWidget();
            //ui->gridLayout->addItem((QLayoutItem*)cameras[count]);
            ui->gridLayout->addWidget(cameras[count],k,i);
            cameras[count]->installEventFilter(this);
            count++;
         }
     }


    ui->gridLayout->setHorizontalSpacing(30);
    ui->gridLayout->setMargin(15);
   // ui->gridLayout->setVerticalSpacing(1);

     //添加开始录制和停止录制按钮
     QPushButton* start_stop_record_btn = new QPushButton("StartRecord");
     start_stop_record_btn->setObjectName("start_stop_record_btn");
     start_stop_record_btn->setFixedHeight(35);
     start_stop_record_btn->setFixedWidth(86);
     start_stop_record_btn->setCheckable(true);
     start_stop_record_btn->setStyleSheet(
     "QPushButton {width: 86px; height: 32px;border:none;background:url(:/image/unchosed.png);font-size: 14px;color: rgb(108,191,221);}"
     "QPushButton:pressed{width: 86px; height: 32px;border:none;background:url(:/image/chosed.png);font-size: 14px;color: black;}"
     );
     ui->gridLayout->addWidget(start_stop_record_btn,5,0);



     //添加 保存一帧图片的控制开关
     QPushButton* save_img_btn = new QPushButton("SaveFrame");
     save_img_btn->setObjectName("save_img_btn");
     save_img_btn->setFixedHeight(35);
     save_img_btn->setFixedWidth(86);
     save_img_btn->setCheckable(true);
     save_img_btn->setStyleSheet(
     "QPushButton {width: 86px; height: 32px;border:none;background:url(:/image/unchosed.png);font-size: 14px;color: rgb(108,191,221);}"
     "QPushButton:pressed{width: 86px; height: 32px;border:none;background:url(:/image/chosed.png);font-size: 14px;color: black;}"
     );
     ui->gridLayout->addWidget(save_img_btn,6,0);


     //添加保存当前录制的视频
     QPushButton* save_video_btn = new QPushButton("SaveVideo");
     save_video_btn->setObjectName("save_video_btn");
     save_video_btn->setFixedHeight(35);
     save_video_btn->setFixedWidth(86);
     save_video_btn->setCheckable(true);
     save_video_btn->setStyleSheet(
     "QPushButton {width: 86px; height: 32px;border:none;background:url(:/image/unchosed.png);font-size: 14px;color: rgb(108,191,221);}"
     "QPushButton:pressed{width: 86px; height: 32px;border:none;background:url(:/image/chosed.png);font-size: 14px;color: black;}"
     );
     ui->gridLayout->addWidget(save_video_btn,5,1);

     //添加关闭所有电脑的控制开关
     QPushButton* close_allcomputer_btn = new QPushButton("ShutDown");
     close_allcomputer_btn->setObjectName("close_allcomputer_btn");
     close_allcomputer_btn->setFixedHeight(35);
     close_allcomputer_btn->setFixedWidth(86);
     close_allcomputer_btn->setCheckable(true);
     close_allcomputer_btn->setStyleSheet(
     "QPushButton {width: 86px; height: 32px;border:none;background:url(:/image/unchosed.png);font-size: 14px;color: rgb(108,191,221);}"
     "QPushButton:pressed{width: 86px; height: 32px;border:none;background:url(:/image/chosed.png);font-size: 14px;color: black;}"
     );
     ui->gridLayout->addWidget(close_allcomputer_btn,7,0);

    timer =  new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(singleClicked()));
    connect(ui->tabWidget_2,SIGNAL(tabCloseRequested(int)),this,SLOT(removeSubTab(int)));


    connect(start_stop_record_btn,SIGNAL(clicked()),this,SLOT(start_stop_record()));
    connect(close_allcomputer_btn,SIGNAL(clicked()),this,SLOT(close_allcomputer()));
    connect(save_img_btn,SIGNAL(clicked()),this,SLOT(save_img()));
    connect(save_video_btn,SIGNAL(clicked()),this,SLOT(save_video()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event){

    for(int i =0;i<30;i++){
        if(watched == cameras[i]){
            if(event->type() == QEvent::MouseButtonDblClick){
                 qDebug("MouseButtonDblClick");
                 qDebug("MouseButtonDblClick i = %d",i);
                 currentCamera = i;
                 doubleClicked();

            }else if(event->type() == QEvent::MouseButtonPress){
                 qDebug("MouseButtonPress");
                 qDebug("MouseButtonDblClick i = %d",i);
//                 if(currentCamera>=0){
//                     cameras[currentCamera]->showMiniWindow();
//                     cameras[currentCamera]->setWindowModel(MINI);
//                 }

                 currentCamera = i;
                 //timer->start(250);
            }
        }
    }
}

void MainWindow::singleClicked(){
 timer->stop();
 //cameras[currentCamera]->showMiddleWindow();
 if(cameras[currentCamera]->getWindowModel() != MIDDLE){

    cameras[currentCamera]->setWindowModel(MIDDLE);
 }else if (cameras[currentCamera]->getWindowModel() == MIDDLE) {
    cameras[currentCamera]->setWindowModel(MINI);
 }

}

void MainWindow::doubleClicked(){

    GSWidgetMax* widget = new GSWidgetMax();
    ui->tabWidget_2->addTab(widget,QIcon("/image/selected_icon.jpg"),"Camera1");
    ui->tabWidget_2->setTabsClosable(true);
    ui->tabWidget_2->setCurrentIndex(ui->tabWidget_2->tabBar()->count()-1);

    timer->stop();
}


void MainWindow::removeSubTab(int index)
{
      if(index == 0 ){

           return;
      }
      ui->tabWidget_2->removeTab(index);
}



void  MainWindow::start_stop_record(){
    QPushButton* btn= qobject_cast<QPushButton*>(sender());
     QString buttonName = btn->text();

    if(buttonName == "StartRecord"){
        btn->setText("StopRecord");

    }else if(buttonName == "StopRecord"){

        btn->setText("StartRecord");
    }
    qDebug("start_stop_record");
}



void  MainWindow::close_allcomputer(){
     qDebug("close_allcomputer");

}

void  MainWindow::save_img(){
     qDebug("save_img");
}


void  MainWindow::save_video(){
     qDebug("save_video");

}


