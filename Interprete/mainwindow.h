#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <iostream>
#include <fstream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbrir_triggered();

    void on_actionGuardar_triggered();

    void on_actionAcerca_de_SrCode_triggered();
    void contarParentesis();
    void on_actionAcerde_triggered();

    void on_actionCerrar_triggered();

private:
    Ui::MainWindow *ui; //Ventana en la que estamos trabajando
    QString nombreArchivo;
};

#endif // MAINWINDOW_H
