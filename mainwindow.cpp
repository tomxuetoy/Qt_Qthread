#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>

/* ****** Thread part ****** */
myThread::myThread(QObject *parent)
    : QThread(parent)
{
}

void myThread::run()
{
    //QTimer timer;
    //connect(&timer, SIGNAL(timeout()), this, SLOT(TimerUpdate()));
    //timer.start(200); //update of each 200ms
    while(1){
        qDebug("thread one----------");
        //usleep(100);
    }
    exec();
}

myThread2::myThread2(QObject *parent)
    : QThread(parent)
{
}

void myThread2::run()
{
    //QTimer timer;
    //connect(&timer, SIGNAL(timeout()), this, SLOT(TimerUpdate()));
    //timer.start(200); //update of each 200ms
    while(1){
        qDebug("thread two");
        //usleep(100);
    }
    exec();
}
/*
void myThread::TimerUpdate()
{
    emit deviceAmbient();
}
*/
/* ****** Thread part ****** */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    onethread = new myThread(this);
    onethread->start(QThread::NormalPriority);

    twothread = new myThread2(this);
    twothread->start(QThread::NormalPriority);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(CloseApp()));
}

void MainWindow::CloseApp()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
