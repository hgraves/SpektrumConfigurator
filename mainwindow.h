#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadFile();
    QString readLine(QFile *);

private slots:

    void on_saveAs_pushButton_clicked();

    void on_loadFile_pushButton_clicked();

    void on_Acro_radioButton_clicked();

    void on_Heli_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    QString saveFilename;
    QString loadFilename;
};
#endif // MAINWINDOW_H
