#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

namespace Ui {
class MainWindow;
}

class myThread : public QThread
{
  Q_OBJECT

public:
    myThread(QObject *parent = 0);
    void run();

signals:
    void threadSignal1();
};

class myThread2 : public QThread
{
  Q_OBJECT

public:
    myThread2(QObject *parent = 0);
    void run();

signals:
    void threadSignal2();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void mySlot1();
    void mySlot2();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    myThread *onethread;
    myThread2 *twothread;
};

#endif // MAINWINDOW_H
