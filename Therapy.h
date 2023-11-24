#ifndef THERAPY_H
#define THERAPY_H

#include <QMainWindow>

namespace Ui {
class Therapy;
}

class QTimer;

class Therapy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Therapy(int initialMinutes, QWidget *parent = nullptr);
    ~Therapy();

private slots:
    void updateTimer();
    void on_close_clicked();

private:
    Ui::Therapy *ui;
    QTimer *timer;

    int remainingTime;
    int initialMinutes;
    void updateTimerDisplay();
};

#endif // THERAPY_H
