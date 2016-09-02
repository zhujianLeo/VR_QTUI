#include "gswidgetmax.h"
#include "ui_gswidgetmax.h"
#include "QDebug"
#include <QStyleFactory>

GSWidgetMax::GSWidgetMax(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GSWidgetMax)
{
    ui->setupUi(this);
    // 设置头像
    QPixmap pixmap(":/image/fake3.jpg");
    ui->label_img->setScaledContents(true);
    ui->label_img->setPixmap(pixmap);

    QPixmap pixmap_fakedata(":/image/fake_data.jpg");
    ui->label_data->setScaledContents(true);
    ui->label_data->setPixmap(pixmap_fakedata);






    ui->normal->setStyleSheet(
    "QPushButton {width: 86px; height: 32px;border:none;background:url(:/image/unchosed.png);font-size: 14px;color: rgb(108,191,221);}"
    "QPushButton:checked{width: 86px; height: 32px;border:none;background:url(:/image/chosed.png);font-size: 14px;color: black;}"
    );
    ui->mask->setStyleSheet(
    "QPushButton {width: 86px; height: 32px;border:none;background:url(:/image/unchosed.png);font-size: 14px;color: rgb(108,191,221);}"
    "QPushButton:checked{width: 86px; height: 32px;border:none;background:url(:/image/chosed.png);font-size: 14px;color: black;}"
    );
    ui->cutoff->setStyleSheet(
    "QPushButton {width: 86px; height: 32px;border:none;background:url(:/image/unchosed.png);font-size: 14px;color: rgb(108,191,221);}"
    "QPushButton:checked{width: 86px; height: 32px;border:none;background:url(:/image/chosed.png);font-size: 14px;color: black;}"
    );


    ui->normal->setCheckable(true);
    ui->normal->isChecked();
    ui->mask->setCheckable(true);
    ui->cutoff->setCheckable(true);
    //ui->radioButton_1->setStyle(QStyleFactory::create("Fusion"));

//    "QPushButton {spacing: 5px;font-size: 14px;  color: rgb(97, 108, 114);}"
//    "QPushButton::indicator{ width: 100px; height: 100px;}"
//    "QPushButton::indicator::unchecked {image: url(:/image/unchosed.png);}"
//    "QPushButton::indicator::checked {image: url(:/image/chosed.png);}"

    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->normal, 0);
    btnGroup->addButton(ui->mask, 1);
    btnGroup->addButton(ui->cutoff, 2);
    connect(ui->normal, SIGNAL(clicked()), this, SLOT(onRadioClick()));
    connect(ui->mask, SIGNAL(clicked()), this, SLOT(onRadioClick()));
    connect(ui->cutoff, SIGNAL(clicked()), this, SLOT(onRadioClick()));
}

GSWidgetMax::~GSWidgetMax()
{
    delete ui;
}

void GSWidgetMax::onRadioClick(){

    switch(btnGroup->checkedId())
       {
       case 0:
           qDebug() << QString::fromLocal8Bit("第一个radio 被点击了");
           break;
       case 1:
           qDebug() << QString::fromLocal8Bit("第二个radio 被点击了");
           break;
       case 2:
           qDebug() << QString::fromLocal8Bit("第三个radio 被点击了");
           break;
       }
}
