#include "first.h"
#include "ui_first.h"
#include "mainwindow.h"

first::first(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::first)
{
    ui->setupUi(this);
    // Load the image
    QPixmap image("image folder");

    // Set the pixmap on the QLabel
    ui->label->setPixmap(image.scaled(this->size(), Qt::IgnoreAspectRatio));
}

first::~first()
{
    delete ui;
}

void first::on_pushButton_clicked()
{
    // Create an instance of MainWindow
    MainWindow *secondWindow = new MainWindow();

    // Show the second window
    secondWindow->show();
}

