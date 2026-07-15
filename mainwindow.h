#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QString &title, QWidget *parent = nullptr);
    ~MainWindow() override;
    QString m_title;

private slots:

    // Первое меню
    void on_actionSave_triggered();
    void on_actionSave_as_triggered();
    void on_actionOpen_file_triggered();
    void on_textEdit_textChanged();

    // Второе меню
    void on_actionCreate_New_triggered();
    void on_actionClose_triggered();

private:
    bool saveToFile(const QString &filePath);

    Ui::MainWindow *ui;

    int num_of_opened_windows = 1;

    QString File_path = "";
};
#endif // MAINWINDOW_H