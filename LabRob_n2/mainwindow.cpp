#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    alarm_diag = new Alarm_diag(this);
    tmr_diag = new Timer_diag(this);

//підключення сигналів до слотів
    connect(ui->add_alarm_btn, SIGNAL(clicked()), this, SLOT(Open_alarm()));
    connect(ui->add_timer_btn, SIGNAL(clicked()), this, SLOT(Open_timer()));
    connect(alarm_diag, SIGNAL(accepted()), this, SLOT(Add_Alarm()));
    connect(tmr_diag, SIGNAL(accepted()), this, SLOT(Add_Timer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//відкриває діалогове вікно для добавлення будильника
void MainWindow::Open_alarm()
{

    alarm_diag->open();
}

//створює та додає новий віджет будильника
void MainWindow::Add_Alarm()
{
    qDebug() << "Addind new alarm";
    alarm = new Alarm(this);
    alarm->setTime(alarm_diag->alrm().toString());
    ui->alarm_Layout->addWidget(alarm);
}

//відкриває діалогове вікно для добавлення таймера
void MainWindow::Open_timer()
{

    tmr_diag->open();
}

//створює та додає новий віджет таймера
void MainWindow::Add_Timer()
{
    qDebug() << "Addind new timer";
    tmr = new Timer(this);
    tmr->setHours(tmr_diag->getHours());
    tmr->setMin(tmr_diag->getMin());
    tmr->setSec(tmr_diag->getSec());
    ui->timer_Layout->addWidget(tmr);
}

