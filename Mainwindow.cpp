#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "therapy.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString styleSheet =  "background-color: #D8BFD8;"; // Replace lightBlue with your desired color
    this->setStyleSheet(styleSheet);
    // Set a different background color for the line edit
    QString lineEditStyleSheet = "background-color: white;"; // Replace white with your desired color
    ui->lineEdit->setStyleSheet(lineEditStyleSheet);

    // Add a border to the buttons
    QString buttonStyleSheet = "border: 2px solid #800080;"; // Hex color code for purple
    ui->btn1->setStyleSheet(buttonStyleSheet + "font-size: 20pt;");
    ui->btn2->setStyleSheet(buttonStyleSheet + "font-size: 20pt;");
    ui->btn3->setStyleSheet(buttonStyleSheet + "font-size: 20pt;");
    ui->btn4->setStyleSheet(buttonStyleSheet + "font-size: 20pt;");
    ui->btn5->setStyleSheet(buttonStyleSheet + "font-size: 20pt;");
    ui->btn6->setStyleSheet(buttonStyleSheet + "font-size: 20pt;");
    ui->btn7->setStyleSheet(buttonStyleSheet + "font-size: 20pt;");
    ui->btn8->setStyleSheet(buttonStyleSheet + "font-size: 20pt;");
    ui->btn9->setStyleSheet(buttonStyleSheet + "font-size: 20pt;");
    ui->btn0->setStyleSheet(buttonStyleSheet + "font-size: 20pt;");
    ui->pushButton_11->setStyleSheet(buttonStyleSheet);
    ui->pushButton_12->setStyleSheet(buttonStyleSheet);
    ui->close->setStyleSheet(buttonStyleSheet);

    this->resize(1000, 500);

    ui->lineEdit->setGeometry(40, 40, 400, 40);

    ui->btn1->setGeometry(550, 40, 100, 100);
    ui->btn2->setGeometry(660, 40, 100, 100);
    ui->btn3->setGeometry(770, 40, 100, 100);
    ui->btn4->setGeometry(550, 150, 100, 100);
    ui->btn5->setGeometry(660, 150, 100, 100);
    ui->btn6->setGeometry(770, 150, 100, 100);
    ui->btn7->setGeometry(550, 260, 100, 100);
    ui->btn8->setGeometry(660, 260, 100, 100);
    ui->btn9->setGeometry(770, 260, 100, 100);
    ui->btn0->setGeometry(660, 370, 100, 100);
    ui->pushButton_11->setGeometry(175, 150, 150, 50);
    ui->pushButton_12->setGeometry(175, 250, 150, 50);
    ui->close->setGeometry(175, 350, 150, 50);




    // Connect all digit buttons to the on_digitButton_clicked slot
    connect(ui->btn0, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->btn2, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->btn3, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->btn4, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->btn5, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->btn6, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->btn7, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->btn8, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));
    connect(ui->btn9, SIGNAL(clicked()), this, SLOT(on_digitButton_clicked()));

    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(on_pushButton_11_clicked()));
    // Connect the "Close" button to the on_btnClose_clicked slot
    connect(ui->close, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    // Connect the "Open New Window" button to the on_btnOpenNewWindow_clicked slot
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(on_pushButton_12_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_digitButton_clicked()
{
    // Get the sender() to determine which button was clicked
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    // Append the digit from the clicked button to the line edit
    if (clickedButton != nullptr) {
        QString digit = clickedButton->text();
        appendNumber(digit);
    }
}

void MainWindow::appendNumber(const QString& number)
{
    // Get the current text in the line edit
    QString currentText = ui->lineEdit->text();

    // Check if the current text is not empty
    if (!currentText.isEmpty()) {
        // Append the specified number beside the existing text
        QString newText = currentText + number;
        ui->lineEdit->setText(newText);
    } else {
        // If the line edit is empty, set the text to the specified number
        ui->lineEdit->setText(number);
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_clicked()
{
    // Close the main window
    this->close();
}


void MainWindow::on_pushButton_12_clicked()
{
    // Get the initial time from the line edit
    int initialTime = ui->lineEdit->text().toInt();

    // Create a new instance of TherapyWindow with the initial time
    Therapy *therapyWindow = new Therapy(initialTime);

    // Show the new window
    therapyWindow->show();
}

