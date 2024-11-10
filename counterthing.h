#ifndef COUNTERTHING_H
#define COUNTERTHING_H
#include <QObject>
#include<cstdlib>
#include <ctime>
class counterThing : public QObject
{
    Q_OBJECT
    int displayNum;
public:
    counterThing();
    void randomDataDisplay();

signals:
    void displayNumChanged(int displayNum);
};

#endif // COUNTERTHING_H
