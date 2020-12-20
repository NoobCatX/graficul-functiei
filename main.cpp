#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <graphics.h>
#include "firstPage.hpp"


int main()
{
    initwindow(windowWidth, windowHeight, "", (GetSystemMetrics(SM_CXSCREEN) - windowWidth)/2, (GetSystemMetrics(SM_CYSCREEN) - windowHeight)/2);
    setbkcolor(15);
    cleardevice();
    drawPageOne();
    registermousehandler(WM_LBUTTONDOWN, click_handler_one);

    getch();
    return 0;
}
