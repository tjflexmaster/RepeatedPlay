#ifndef BARGRAPHWIDGET_H
#define BARGRAPHWIDGET_H

#include <QWidget>
#include <QMap>

class BarGraphWidget : public QWidget
{
    Q_OBJECT
public:
    BarGraphWidget(QWidget *parent = 0);
    void setColumns(int columns);
    void setValue(int column, int value);
    void initialize();

protected:
    void paintEvent(QPaintEvent *);
signals:

private:
    int height;
    int width;
    int columns;
    int column_width;
    QMap<int, int> column_values;

    
};

#endif // BARGRAPHWIDGET_H
