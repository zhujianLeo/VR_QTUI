#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QTabWidget;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);

signals:

public slots:

};

#endif // WIDGET_H
