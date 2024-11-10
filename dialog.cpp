#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>  // Include QTimer

Dialog::~Dialog()
{
    delete ui;
}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    counter()  // Initialize counterThing
{
    ui->setupUi(this);

    // Connect the signal from counterThing to the updateDisplayNum slot
    bool connected = connect(&counter, &counterThing::displayNumChanged, this, &Dialog::updateDisplayNum);
    Q_ASSERT(connected);
    srand(time(NULL));

    // Create a QTimer to call randomDataDisplay every 1 second
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, &counter, &counterThing::randomDataDisplay);
    timer->start(1000);
}

void Dialog::closeEvent(QCloseEvent *event)
{
    // Ensure the timer is stopped before closing the dialog
    if (timer) {
        timer->stop();  // Stop the timer
        delete timer;   // Delete the timer
        timer = nullptr;
    }

    // Call the base class closeEvent to actually close the dialog
    event->accept();
}

void Dialog::updateDisplayNum(int newDisplayNum)
{
    // Update the label text with the new number
    ui->numberLabel->setText(QString::number(newDisplayNum));
}
