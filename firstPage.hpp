#include "structures.hpp"
#include "components.hpp"
#include "secondPage.hpp"

char temp[256];
char input[256];

int k = 0;
int lineLenght[3];
int i = 1;

void drawPageOne()
{
    int left_margin = 100;
    int right_margin = 700;

    int x_text = 0;
    int y_text = rect.height+rect.top+10;

    drawInputField("INTRODUCETI FUNCTIA");
    getButtonsContent("pageOneBtns.txt",btns1);
    drawButtonsField(30, btns1, left_margin, 6);
    drawDeleteButton(left_margin+btn.width*6+15,rect.height+rect.top+45,left_margin+btn.width*7-25,rect.height+rect.top+85,btns1);
    drawResetButton(left_margin+btn.width*6+15,rect.height+rect.top+100,left_margin+btn.width*7-25,rect.height+rect.top+140, btns1);
    drawNextStepButton(left_margin+150,windowHeight-windowHeight/4+60,left_margin+450,windowHeight-windowHeight/4+120,btns1);

    // text
    setcolor(BLUE);

    for(int i=1; i<=30; i++)
    {
        if(i==3 || i==9 || i==14 || i==15 || i==20 )
        {
            x_text+=textwidth("abcdef");
            outtextxy(x_text,y_text,btns1[i].content);
        }
        else if(i==26)
        {
            x_text+=textwidth("abcde");
            outtextxy(x_text,y_text,btns1[i].content);
        }
        else if(i==1 || i==7 || i==13 || i==19 || i==25)
        {
            if(i==7 || i==19)
            {
                outtextxy(left_margin+30,y_text+70,btns1[i].content);
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
                if(i==25) x_text=left_margin+40;
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
    fprintf(input_file,"%s",input);
    cleardevice();
    x__text=55;
    y__text=130;
    delay(100);
    registermousehandler(WM_LBUTTONDOWN, click_handler_two);
    drawPageTwo();
}

void click_handler_one(int x,int y)
{
    setcolor(GREEN);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    outtextxy(x__text,y__text,temp);

    if(ismouseclick(WM_LBUTTONDOWN))
    {
        if(textwidth(temp)>=600)
        {
            lineLenght[i++]=strlen(temp);
            strcpy(temp,"");
            y__text+=50;
            k++;
        }
        for(int q=1; q<=30; q++)
            if(x > btns1[q].x1 && x < btns1[q].x2 && y > btns1[q].y1 && y < btns1[q].y2)
            {
                strcat(temp, btns1[q].content);
                outtextxy(x__text,y__text,temp);
                strcat(input, btns1[q].content);
            }

        if(x > btns1[40].x1 && x < btns1[40].x2 && y > btns1[40].y1 && y < btns1[40].y2) /// delete
        {
            temp[strlen(temp)-1]=NULL;
            input[strlen(input)-1]=NULL;
            if(strlen(temp)==0)
            {
                if(k!=0) y__text-=50;
                if(k==2)strcpy(temp,input+lineLenght[1]);
                else if(k==1) strcpy(temp,input);
                DEL1(k);
                k--;
            }
            DEL1(k);
            outtextxy(x__text,y__text,temp);
        }
        if(x > btns1[41].x1 && x < btns1[41].x2 && y > btns1[41].y1 && y < btns1[41].y2) /// reset
        {
            strcpy(temp,"");
            strcpy(input,"");
            k = 0;
            i = 1;
            y__text = 130;
            resetInput();
        }
        if(x > btns1[42].x1 && x < btns1[42].x2 && y > btns1[42].y1 && y < btns1[42].y2) /// next step
            nextStep();
    }

}


