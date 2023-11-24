#include "therapy.h"
#include "ui_therapy.h"
#include <QTimer>
#include <QTime>
#include <QPixmap>

Therapy::Therapy(int initialMinutes, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Therapy),
    initialMinutes(initialMinutes)
{
    ui->setupUi(this);

    QString styleSheet =  "background-color: #D8BFD8;"; // Replace lightBlue with your desired color
    this->setStyleSheet(styleSheet);

    // Convert initial time from minutes to seconds
    remainingTime = initialMinutes * 60;

    // Create a QTimer instance
    timer = new QTimer(this);

    // Connect the timeout signal of the timer to a custom slot
    connect(timer, &QTimer::timeout, this, &Therapy::updateTimer);

    // Start the timer with a 1-second interval
    timer->start(1000);

    // Set the remaining time in the UI
    updateTimerDisplay();

    // Set the range of the progress bar to be between 0 and 100
    ui->progressBar->setRange(0, initialMinutes * 60);

    // Set the initial value of the progress bar to 2%
    ui->progressBar->setValue((2.0 / 100) * (initialMinutes * 60));

    ui->label_date_time->setGeometry(650, 120, 200, 50); // Adjust the values as needed
    ui->progressBar->setGeometry(550, 50, 400, 20);
    this->resize(1000, 500);

    // Set the font size of the timer label
    QFont font = ui->label_date_time->font();
    font.setPointSize(20); // Adjust the font size as needed
    ui->label_date_time->setFont(font);

    // Set the geometry of the close button
    ui->close->setGeometry(600, 200, 300, 100);
    ui->close->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 16pt;");

    // Add a QLabel for the image
    QLabel* imageLabel = new QLabel(this);
    QPixmap imagePixmap("image-folder");  // Replace with the path to your image file
    imageLabel->setPixmap(imagePixmap.scaled(500,500,Qt::KeepAspectRatio));
    imageLabel->setGeometry(10,10, 500, 500);
}

Therapy::~Therapy()
{
    delete ui;
}
void Therapy::updateTimer()
{
    if (remainingTime > 0) {
        --remainingTime;
        updateTimerDisplay();
    } else {
        timer->stop();
        ui->label_date_time->setText("Countdown finished!");
        ui->progressBar->setValue(ui->progressBar->maximum());
        // Perform additional actions when the countdown reaches 0
    }

}


void Therapy::updateTimerDisplay()
{
    QTime time(0, remainingTime / 60, remainingTime % 60);
    QString time_text = time.toString("hh:mm:ss");
    ui->label_date_time->setText(time_text);

    // Calculate progress based on the remaining time and initial minutes
    int progressValue = static_cast<int>(((initialMinutes * 60 - remainingTime) / (initialMinutes * 60.0)) * 100);
    ui->progressBar->setValue(progressValue);
}




void Therapy::on_close_clicked()
{
    this->close();
}

