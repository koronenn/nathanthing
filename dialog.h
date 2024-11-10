#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <counterthing.h>
#include <QLabel>
#include <QTimer>  // Include QTimer
#include <QCloseEvent>  // Include QCloseEvent header

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void updateDisplayNum(int newDisplayNum); // Slot to update display number
    void closeEvent(QCloseEvent *event);
private:
    Ui::Dialog *ui;
    counterThing counter; // Instance of counterThing
    QLabel *numberLabel;  // Label to display the number
    QTimer* timer;
};

#endif // DIALOG_H
