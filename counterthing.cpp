#include "counterthing.h"
#include <iostream>
counterThing::counterThing() : displayNum(0) {}

void counterThing::randomDataDisplay()
{
    displayNum = rand();
    std::cout << displayNum << std::endl;
    emit displayNumChanged(displayNum);
}
