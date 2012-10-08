#include "BarGraphWidget.h"
#include <QPainter>
#include <QDebug>

BarGraphWidget::BarGraphWidget(QWidget *parent) :
    QWidget(parent)
{
    initialize();
}

void BarGraphWidget::initialize()
{
    height = 500;
    column_width = 50;
    width = 500;
    resize(width, height);
}

void BarGraphWidget::setColumns(int columns)
{
    this->columns = columns;
    for(int i=0; i < columns; i++) {
        column_values.insert(i, 0);
    }
}

void BarGraphWidget::setValue(int column, int value)
{
    column_values.insert(column, value);
}

void BarGraphWidget::paintEvent(QPaintEvent *)
{
    for(int i=0; i < columns; i++ ) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(0, height-20);
        painter.setBrush(Qt::blue);
        qreal bar_height = column_values.value(i, 0);
        int h = static_cast<int>(bar_height);
        painter.drawRect( (10 * i) + (50 * i), 0, 50, -h);
    }

}
