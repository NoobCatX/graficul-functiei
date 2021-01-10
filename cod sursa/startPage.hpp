#include "firstPage.hpp"
#include <Windows.h>
//#pragma comment(lib, "winmm.lib")
void start();
void drawSettingsPage();
int decorations_left(int d)
{
    line(d,500-d,d,d+350);
    d-=50;
    if(d==50) return 0;
    return decorations_left(d);
}
int decorations_right(int d)
{
    line(d,d-300,d,-d+1150);
    d-=50;
    if(d==500) return 0;
    return decorations_right(d);
}
void menuBtn(char s[],int x1, int y1, int x2, int y2, int k)
{

    setcolor(MAGENTA);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    //outtextxy(400,285,s);
    outtextxy(x1+110,y1+35,s);
    //rectangle(300,250,500,300);
    rectangle(x1,y1,x2,y2);
    settextjustify(0,0);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,4);


    btns0[k].x1 = x1;
    btns0[k].y1 = y1;
    btns0[k].x2 = x2;
    btns0[k].y2 = y2;

}
void backBtn()
{
    menuBtn(L.lang[7+L.l],285,700,500,750,50);
}
void click_handler_exit(int x, int y)
{
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        if(x > 320 && x < 375 && y > 420 && y < 460) ///yes
            exit(1);
        if(x > 420 && x < 475 && y > 420 && y < 460) ///no
            start();
    }
}
void drawExitPopUp()
{
    registermousehandler(WM_LBUTTONDOWN, click_handler_exit);
    setcolor(3);
    rectangle(getmaxx()/2-225,getmaxy()/2-125,getmaxx()/2+225, getmaxy()/2+175);
    setfillstyle(1,BLACK);
    floodfill(getmaxx()/2-224,getmaxy()/2-124,3);
    setcolor(BLACK);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    outtextxy(getmaxx()/2,getmaxy()/2-50,L.lang[8+L.l]);
    outtextxy(getmaxx()/2-50,getmaxy()/2+50,L.lang[9+L.l]);
    outtextxy(getmaxx()/2+50,getmaxy()/2+50,L.lang[10+L.l]);

}
void click_handler_settings(int x,int y)
{
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        if(x>200 && x<350 && y>200 && y<350)
        {
            L.l = 22;
            drawSettingsPage();
            //printf("engl");
        }
        if(x>450 && x <600 && y>200 && y<350){
            //printf("ro");
            L.l = 0;
            drawSettingsPage();
            }
        if(x>200 && x<350 && y>500 && y<600)
        {

            //printf("playMusic"); // filename: jazz.mp3 || jazz.wav
            mciSendString("play jazz.mp3 repeat", NULL, 0, NULL);

        }
        if(x>450 && x<600 && y>500 && y<600){
            //printf("stopMusic");
            mciSendString("close jazz.mp3", NULL, 0, NULL);
        }


        if(x > btns0[50].x1 && y > btns0[50].y1 && x < btns0[50].x2 && y < btns0[50].y2)
            start();
    }
}
void drawSettingsPage()
{
    cleardevice();

    setcolor(0);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(GREEN);
    outtextxy(400,60,L.lang[2+L.l]);
    setcolor(BLUE);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    outtextxy(400,175,L.lang[5+L.l]);
    readimagefile("ENG3.jpg",getmaxx()/4,getmaxy()/4,getmaxx()/4+150,getmaxy()/4+150);

    readimagefile("RO3.jpg",getmaxx()-getmaxx()/4-150,getmaxy()/4,getmaxx()-getmaxx()/4,getmaxy()/4+150);

    outtextxy(400,460,L.lang[6+L.l]);
    readimagefile("soundON.jpg",getmaxx()/4,getmaxy()/4+100+270-25-25-50,getmaxx()/4+150,getmaxy()/4+150+100+270-25-25-50);
    readimagefile("soundOFF.jpg",getmaxx()-getmaxx()/4-150,getmaxy()/4+100+270-25-25-50-5,getmaxx()-getmaxx()/4,getmaxy()/4+150+100+270-25-25-50-5);
    backBtn();
    registermousehandler(WM_LBUTTONDOWN, click_handler_settings);
}
void drawAboutPage()
{
    int colors[16],k=0,x=30,y=190;
    colors[0] = colors[1] = colors [2] = 1;
    colors[3] = colors[4] = 2;
    colors[5] = colors [6] = colors[7] = colors[8] = colors [9] = 0;
    colors[10] = colors[11] = colors [12] = colors [13] = 0;
    colors [13] = colors [14] = 0;
    cleardevice();
    setcolor(0);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(GREEN);
    outtextxy(400,60,L.lang[3+L.l]);

    setcolor(MAGENTA);
    settextjustify(0,0);

    settextjustify(CENTER_TEXT,CENTER_TEXT);
    FILE *p;
    if(L.l == 22)
        p = fopen("AboutE.txt","r");
    else
        p = fopen("AboutR.txt","r");
    char c[100];
    fgets(c,100,p);
    outtextxy(getmaxx()/2,125,c);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
    settextjustify(0,0);
    while(!feof(p))
    {
        fgets(c,100,p);
        setcolor(colors[k]);
        k++;
        outtextxy(x,y,c);
        y+=30;
    }
    fclose(p);
    backBtn();
}
void click_handler_menu(int x, int y)
{
    //printf("menu");
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        if(x > btns0[0].x1 && x < btns0[0].x2 && y > btns0[0].y1 && y < btns0[0].y2)
            drawPageOne();
        if(x > btns0[1].x1 && x < btns0[1].x2 && y > btns0[1].y1 && y < btns0[1].y2)
            drawSettingsPage();
        if(x > btns0[2].x1 && x < btns0[2].x2 && y > btns0[2].y1 && y < btns0[2].y2)
            drawAboutPage();
        if(x > btns0[3].x1 && x < btns0[3].x2 && y > btns0[3].y1 && y < btns0[3].y2)
            drawExitPopUp();
        if(x > btns0[50].x1 && x < btns0[50].x2 && y > btns0[50].y1 && y < btns0[50].y2)
            start();
    }
}
void start()
{
    cleardevice();
    setcolor(0);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(400,125,L.lang[0+L.l]);
    //printf("lang: %s",L.lang[0+L.l]);
    settextjustify(0,0);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
    menuBtn(L.lang[1+L.l],290,250,510,300,0);
    menuBtn(L.lang[2+L.l],290,350,510,400,1);
    menuBtn(L.lang[3+L.l],290,450,510,500,2);
    menuBtn(L.lang[4+L.l],290,550,510,600,3);
    setcolor(2);
    decorations_left(250);
    decorations_right(700);
    registermousehandler(WM_LBUTTONDOWN, click_handler_menu);
}

