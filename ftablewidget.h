#ifndef FTABLEWIDGET_H
#define FTABLEWIDGET_H

#include <QTableWidget>

namespace Ui {
    class FTableWidget;
}

class FTableWidget : public QTableWidget
{
    Q_OBJECT

private:
    Ui::FTableWidget * ui;

public:
    FTableWidget(QTableWidget *parent = 0);
    ~FTableWidget();

public slots:
    void cellSelected(int nRow, int nCol);
};

#endif // FTABLEWIDGET_H
