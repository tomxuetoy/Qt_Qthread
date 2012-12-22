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
    while(1){
        qDebug("thread one----------");
        emit threadSignal1();
        usleep(100000);
    }
    //exec();
}

myThread2::myThread2(QObject *parent)
    : QThread(parent)
{
}

void myThread2::run()
{
    while(1){
        qDebug("thread two");
        emit threadSignal2();
        usleep(100000);
    }
    //exec();
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    onethread = new myThread(this);
    twothread = new myThread2(this);

    connect(onethread, SIGNAL(threadSignal1()),
            this, SLOT(mySlot1()));
    connect(twothread, SIGNAL(threadSignal2()),
            this, SLOT(mySlot2()),Qt::QueuedConnection);

    onethread->start(QThread::NormalPriority);
    twothread->start(QThread::NormalPriority);
}

void MainWindow::mySlot1()
{
    ui->textEdit1->append("This is thread1");
}

void MainWindow::mySlot2()
{
    ui->textEdit2->append("This is thread2");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit1->append("textEdit1");
    ui->textEdit2->append("textEdit2");
}
