#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
MainWindow::MainWindow(const QString &title, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_title(title)
{
    ui->setupUi(this);
    this->setWindowTitle("Enter the text");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{

    QString input_text_user = ui->textEdit->toPlainText();
    if(File_path.isEmpty())// проверка есть ли уже файл
    {
        File_path = QFileDialog::getSaveFileName(this,"file save","text.txt","txt (*.txt);;Any file (*)",nullptr);
        if(File_path.isEmpty())
        {
            QMessageBox::critical(this,"ERROR","Not find file path");//ошибка если путь к файлу не найден
            qDebug()<<"ERROR patch not find";
            return;
        }


        QFile file(File_path);
        QTextStream file_strim(&file);
        file.open(QIODeviceBase::WriteOnly);
        file_strim <<input_text_user;
        file.close();
        qDebug()<<"Path:" + File_path;
        this->setWindowTitle("File: "+File_path);
        return;
    }
    else//если файл есть но нужно изменить текст внутри
    {
        QFile file(File_path);
        QTextStream file_strim(&file);
        file.open(QIODeviceBase::WriteOnly);
        file_strim <<input_text_user;
        file.close();
        qDebug()<<"Path:" + File_path;
        this->setWindowTitle("File: "+File_path);
        return;
    }

}



void MainWindow::on_actionSave_as_triggered()
{
    QString input_text_user = ui->textEdit->toPlainText();
    File_path = QFileDialog::getSaveFileName(this,"file save","text.txt","txt (*.txt);;Any file (*)",nullptr);
    if(File_path.isEmpty())
    {
        QMessageBox::critical(this,"ERROR","Not find file path");//ошибка если путь к файлу не найден
        qDebug()<<"ERROR patch not find";
        return;
    }


    QFile file(File_path);
    QTextStream file_strim(&file);
    file.open(QIODeviceBase::WriteOnly);
    file_strim << input_text_user;
    file.close();
    qDebug()<<"Path:" + File_path;
    this->setWindowTitle("File: "+File_path);
    return;

}

