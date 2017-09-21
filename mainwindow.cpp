#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printJson(const QJsonObject &obj)
{
    QJsonArray jsonArray = obj["response"].toArray();
    foreach (const QJsonValue & value, jsonArray)
    {
        QJsonObject obj = value.toObject();
        qDebug()<<obj["first_name"].toString();
        qDebug()<<obj["last_name"].toString();
        qDebug()<<obj["uid"].toInt();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QVariantMap args;
    args.insert("user_ids","5796477");
    VKRequest req;
            req = VkQt::instance()->users()->get(args);
    auto reply = VkQt::instance()->execute(&req);
    connect(reply, SIGNAL(resultReady(QJsonObject)), this, SLOT(printJson(QJsonObject)));
}
