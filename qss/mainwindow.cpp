#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file(":/qt_doc/Qt_Style_Sheets.html");
    if (file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QByteArray html = file.readAll();
        ui->widget->setHtml(html);
    }
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_OK_clicked()
{
    this->setStyleSheet(ui->textEdit_qss->toPlainText());
}

void MainWindow::on_pushButton_clicked()
{
    QFile file(":/qss/button.qss");
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return;
    }
    QByteArray qss = file.readAll();
    ui->textEdit_qss->setText(qss);
    file.close();
}
