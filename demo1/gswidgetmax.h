#ifndef GSWIDGETMAX_H
#define GSWIDGETMAX_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class GSWidgetMax;
}

class GSWidgetMax : public QWidget
{
    Q_OBJECT

public:
    explicit GSWidgetMax(QWidget *parent = 0);
    ~GSWidgetMax();

private:
    Ui::GSWidgetMax *ui;
    QButtonGroup *btnGroup;
public slots:
    void onRadioClick();

};

#endif // GSWIDGETMAX_H
