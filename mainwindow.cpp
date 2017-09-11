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

void MainWindow::on_pushButton_clicked()
{
    QVariantMap args;
    args.insert("user_ids","210700286");
    VKRequest req;
            req = VkQt::instance()->users()->get(args);
    VkQt::instance()->execute(&req);
}
