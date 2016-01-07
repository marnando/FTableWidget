#include "ui_ftablewidget.h"
#include "ftablewidget.h"
#include <QMessageBox>

FTableWidget::FTableWidget(QTableWidget *parent)
    : QTableWidget(parent),
    ui(new Ui::FTableWidget)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(10);

    QStringList tableHeader;
    tableHeader << "#" << "Value" << "Value" << "Value" << "Value" << "Value" << "Value" << "Value" << "Value" << "Value";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setStyleSheet("QTableView {selection-background-color: red;}");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg( (row+1)*(column+1)) );
            ui->tableWidget->setItem(row, column, newItem);
        }
    }

    connect( ui->tableWidget, SIGNAL( cellDoubleClicked (int, int) ), this, SLOT( cellSelected( int, int ) ) );
}

FTableWidget::~FTableWidget()
{
    delete ui;
}

void FTableWidget::cellSelected(int nRow, int nCol)
{
    QMessageBox::information(this, "", "Cell at row " + QString::number(nRow) + " column " + QString::number(nCol) + " was double clicked.", QMessageBox::Ok);
}
