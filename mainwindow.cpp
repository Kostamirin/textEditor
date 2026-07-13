#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(const QString &title, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_title(title)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{
    return;
}



void MainWindow::on_actionSave_as_triggered()
{
    return;
}

