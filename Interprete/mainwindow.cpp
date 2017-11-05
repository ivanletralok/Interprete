#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> //Libreria de mensajes emergentes
#include <QFileDialog> //Buscar un archivo para arbrirlo
#include <QFile> //Enlazar el archivo
#include <QTextStream> //Leer el archivo
#include <fstream>

using std::ifstream;
using std::string;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->nombreArchivo.clear();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrir_triggered()
{
    nombreArchivo = QFileDialog::getOpenFileName(this,"Abrir"); //Buscamos el archivo en el directorio
    QFile archivo;
    QTextStream lectura;
    archivo.setFileName(nombreArchivo); //Establecemos la ruta del archivo (Enlazamos)
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(archivo.isOpen()){
        lectura.setDevice(&archivo);
        ui->textoPlano->setPlainText(lectura.readAll()); //Agregarle texto
    }
    archivo.close(); //Para poder trabajar con el archivo mas adelante
}

void MainWindow::on_actionGuardar_triggered()
{
    if(nombreArchivo.isEmpty()){ //Para guardar un archivo nuevo
        nombreArchivo = QFileDialog::getSaveFileName(this,"Guardar archivo");
        QFile archivo;
        QTextStream escritura;
        archivo.setFileName(nombreArchivo); //enlazamiento con el archivo que se creara

        archivo.open(QIODevice::WriteOnly | QIODevice::Text);

        escritura.setDevice(&archivo);
        if(archivo.isOpen()){
            escritura<<ui->textoPlano->toPlainText();
        }else{
             QMessageBox::information(this,"SrCode","Error al guardar el archivo");
        }
        archivo.close();
    }else{
        QFile archivo;
        QTextStream escritura;
        archivo.setFileName(nombreArchivo); //enlazamiento con el archivo que se creara

        archivo.open(QIODevice::WriteOnly | QIODevice::Text);

        escritura.setDevice(&archivo);
        if(archivo.isOpen()){
            escritura<<ui->textoPlano->toPlainText();
        }else{
             QMessageBox::information(this,"SrCode","Error al guardar el archivo");
        }
        archivo.close();
    }
}

void MainWindow::on_actionAcerca_de_SrCode_triggered()
{
    //QMessageBox::about(this,"SrCode","Creado por AleX");
    contarParentesis();
}

void MainWindow::contarParentesis()
{
    int parAbre=0, parCierra=0;
    int a,c;
    ifstream f; // escribir y leer
    string aux;
    f.open(nombreArchivo.toStdString());
    while(getline(f,aux)){
        for(int i = 0;i < (int)aux.length();i++){
            if(aux[i] == '(') parAbre++;
            else if (aux[i] == ')') parCierra++;
        }
    }
    if(parAbre == parCierra){
        QMessageBox::information(this,"Resultado","No hay error de parentesis");
    }else{
        if(parAbre > parCierra){
            c = parAbre-parCierra;
            QMessageBox::information(this,"Resultado","Faltan "+QString::number(c)+" parentesis que cierran");
        }else{
            a = parCierra-parAbre;
            QMessageBox::information(this,"Resultado","Faltan "+QString::number(a)+" parentesis que abren");
        }
    }
}

void MainWindow::on_actionAcerde_triggered()
{
    QMessageBox::information(this,"Autor","Alex Ivan");
}

void MainWindow::on_actionCerrar_triggered()
{
    close();
}
