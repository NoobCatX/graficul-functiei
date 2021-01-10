#include "structures.hpp"
#include "components.hpp"
FILE *input_file = fopen("input.txt","w");
#include "secondPage.hpp"
char temp[256];
char input[256];
int k = 0;
int lineLenght[3];
int i = 1;
void start();
void invalidInputError()
{
    settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(COLOR(255,0,0));
    outtextxy(getmaxx()/2,W.height-W.height/4+170,L.lang[20+L.l]);
    settextjustify(0,0);
}
void DEL1(int k)
{
    setfillstyle(SOLID_FILL,WHITE);
    setcolor(COLOR(248,248,255));
    if(k==0)
    {
        rectangle(54,88,760,130);
        floodfill(56,89,COLOR(248,248,255));
    }
    else if(k==1)
    {
        rectangle(54,140,760,182);
        floodfill(56,141,COLOR(248,248,255));
    }
    else if(k==2)
    {
        rectangle(54,192,760,234);
        floodfill(56,193,COLOR(248,248,255));
    }
    setcolor(GREEN);
}
void nextStep()
{
    char e[6],aux[256],_temp[256];
    strcpy(aux,input);
    strcpy(_temp,input);
    strcpy(_temp+1,aux);
    _temp[0] = '(';
    strcat(_temp,")");
    int p,y,z;
    y = evaluator(_temp,1, e, p);
    strcpy(aux,"*");
    z = evaluator(_temp,0,aux,z);
    if(!strcmp(e,"error") && !strcmp(aux,"error"))
    {
        invalidInputError();
        strcpy(e,"");
    }
    else
    {
        strcpy(aux,input);
        strcpy(input+1,aux);
        input[0] = '(';
        strcat(input,")");
        fprintf(input_file,"%s",input);
        strcpy(input,"");
        strcpy(temp,"");
        cleardevice();
        rect.text.x=55;
        rect.text.y=130;
        drawPageTwo();
    }
}
void click_handler_one(int x,int y)
{
    setcolor(GREEN);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    outtextxy(rect.text.x,rect.text.y,temp);

    if(ismouseclick(WM_LBUTTONDOWN))
    {
        if(strlen(temp)>=24)
        {
            lineLenght[i++]=strlen(temp);
            strcpy(temp,"");
            rect.text.y+=50;
            k++;
        }
        for(int q=1; q<=30; q++)
            if(x > btns1[q].x1 && x < btns1[q].x2 && y > btns1[q].y1 && y < btns1[q].y2)
            {
                strcat(temp, btns1[q].content);
                outtextxy(rect.text.x,rect.text.y,temp);
                strcat(input, btns1[q].content);
            }

        if(x > btns1[40].x1 && x < btns1[40].x2 && y > btns1[40].y1 && y < btns1[40].y2) /// delete
        {
            temp[strlen(temp)-1]=NULL;
            input[strlen(input)-1]=NULL;

            if(strlen(temp)==0)
            {
                if(k==1)
                {
                    rect.text.y-=50;
                    k--;
                    DEL1(k);
                    strcpy(temp,input);
                }
                else if(k==2)
                {
                    strcpy(temp,input+lineLenght[1]);
                    rect.text.y-=50;
                    k--;
                    DEL1(k);
                }
            }
            DEL1(k);
            outtextxy(rect.text.x,rect.text.y,temp);
        }
        if(x > btns1[41].x1 && x < btns1[41].x2 && y > btns1[41].y1 && y < btns1[41].y2) /// reset
        {
            strcpy(temp,"");
            strcpy(input,"");
            k = 0;
            i = 1;
            rect.text.y = 130;
            rect.text.x = 55;
            resetInput();
        }
        if(x > btns1[42].x1 && x < btns1[42].x2 && y > btns1[42].y1 && y < btns1[42].y2) /// next step
            nextStep();


        if(x > btns1[50].x1 && x < btns1[50].x2 && y > btns1[50].y1 && y < btns1[50].y2) /// prev step
            start();
        if(x > btns1[49].x1 && x < btns1[49].x2 && y > btns1[49].y1 && y < btns1[49].y2) /// prev step
            exit(1);


    }

}
void drawPageOne()
{
    drawBtns();
    int left_margin = 100;
    int right_margin = 700;

    int x_text = 0;
    int y_text = rect.height+rect.top+10;
    cleardevice();

    registermousehandler(WM_LBUTTONDOWN, click_handler_one);
    drawInputField(L.lang[0+L.l]);

    getButtonsContent("pageOneBtns.txt",btns1);
    drawButtonsField(30, btns1, left_margin, 6);
    drawDeleteButton(left_margin+btn.width*6+15,rect.height+rect.top+45,left_margin+btn.width*7-25,rect.height+rect.top+85,btns1);
    drawResetButton(left_margin+btn.width*6+15,rect.height+rect.top+100,left_margin+btn.width*7-25,rect.height+rect.top+140, btns1);
    drawNextStepButton(left_margin+150,W.height-W.height/4+60,left_margin+450,W.height-W.height/4+120,btns1);
    drawExitBtn(btns1);
    drawGoBackBtn(btns1);

    setcolor(BLUE);
    for(int i=1; i<=30; i++)
    {
        if(i==8)
        {
            x_text+=111;
            outtextxy(x_text,y_text,btns1[i].content);
            x_text-=10;

        }
        else if(i==14)
        {
            x_text+=130;
            outtextxy(x_text,y_text,btns1[i].content);
            x_text-=10;
        }

        else if(i==3 || i==9 || i==14 || i==15 || i==20 )
        {
            x_text+=textwidth("abcdef");
            outtextxy(x_text,y_text,btns1[i].content);
        }
        else if(i==26)
        {
            x_text+=textwidth("abcdef");
            outtextxy(x_text,y_text,btns1[i].content);
        }

        else if(i==1 || i==7 || i==13 || i==19 || i==25)
        {
            if(i==7 || i==19)
            {
                outtextxy(left_margin+20,y_text+70,btns1[i].content);
                y_text+=70;
                x_text=textwidth(btns1[1].content)+40+20;
            }

            else if(i==13)
            {
                outtextxy(left_margin+10,y_text+70,btns1[i].content);
                y_text+=70;
                x_text=textwidth(btns1[1].content)+40;
            }
            else
            {
                y_text+=70;
                if(i==25) x_text=left_margin+20;
                else x_text=left_margin+20;
                outtextxy(x_text,y_text,btns1[i].content);
            }
        }
        else
        {
            x_text+=textwidth("abc")+40;
            outtextxy(x_text,y_text,btns1[i].content);
        }
    }

    if(temp)
    {
        setcolor(GREEN);
        settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
        outtextxy(rect.text.x,rect.text.y,temp);
    }

}

