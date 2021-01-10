#define infinit INT_MAX
#define epsi 0.0001
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <graphics.h>
#include <limits.h>
#include <shellapi.h>
#include "lang.hpp"
#include "startPage.hpp"

int main()
{
    initwindow(W.width, W.height, "", (GetSystemMetrics(SM_CXSCREEN) - W.width)/2, (GetSystemMetrics(SM_CYSCREEN) - W.height)/2);
    setbkcolor(15);
    cleardevice();
    registermousehandler(WM_LBUTTONDOWN, click_handler_menu);
    updateLanguage();
    start();
    getch();
    return 0;
}
