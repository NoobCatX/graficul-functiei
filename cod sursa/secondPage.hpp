#include "structures.hpp"
#include "eval.hpp"
#include "drawGraph.hpp"

char left[10];
char right[10];
int isLeft = -1;
void drawPageOne();
void DEL2(int k)
{
    setfillstyle(SOLID_FILL,WHITE);
    setcolor(COLOR(248,248,255));
    if(k==1)
    {
        if(L.l!=0)
        {
            rectangle(200,100,763,143);
            floodfill(201,101,COLOR(248,248,255));
        }
        else
        {
            rectangle(250,100,763,143);
            floodfill(251,101,COLOR(248,248,255));
        }
    }
    else if(k==2)
    {
        if(L.l!=0)
        {
            rectangle(225,163,758,206);
            floodfill(226,164,COLOR(248,248,255));
        }
        else
        {
            rectangle(280,163,758,206);
            floodfill(281,164,COLOR(248,248,255));
        }
    }
    setcolor(GREEN);
}
void EVAL()
{
    FILE* in_file = fopen("input.txt","r");
    double left_int, right_int;
    int values[1000], k=0;
    fgets(F.funct,256,in_file);
    F.funct[strlen(F.funct)-1]=NULL;
    fscanf(in_file, "%lf %lf", &left_int, &right_int);
    fclose(in_file);

    G.left = left_int;
    G.right = right_int;
    //printf("left: %d\nright: %d\n", G.left, G.right);
    strcpy(left,"");
    strcpy(right,"");
    closegraph();
    drawGraphPage();
}
void click_handler_two(int x, int y)
{

    if(ismouseclick(WM_LBUTTONDOWN))
    {
        for(int q=1; q<=12; q++)
        {
            if(x > btns2[q].x1 && x < btns2[q].x2 && y > btns2[q].y1 && y < btns2[q].y2)
            {
                if(isLeft == 1)
                {
                    strcat(left,btns2[q].content);
                    outtextxy(rect.text.x+textwidth(L.lang[14+L.l])+23, rect.text.y+20, left);
                }
                else if(isLeft==0)
                {
                    strcat(right,btns2[q].content);
                    outtextxy(rect.text.x+textwidth(L.lang[15+L.l])+20, rect.text.y+80, right);
                }
            }
        }
        if(x > btns2[13].x1 && x < btns2[13].x2 && y > btns2[13].y1 && y < btns2[13].y2) /// left btn
        {
            setcolor(COLOR(200,0,0));
            settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
            outtextxy(rect.text.x,rect.text.y+20,L.lang[14+L.l]);
            isLeft = 1;
            setcolor(GREEN);
        }
        if(x > btns2[14].x1 && x < btns2[14].x2 && y > btns2[14].y1 && y < btns2[14].y2) /// right btn
        {

            setcolor(COLOR(200,0,0));
            settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
            isLeft = 0;
            outtextxy(rect.text.x,rect.text.y+80,L.lang[15+L.l]);
            setcolor(GREEN);
        }
        if(x > btns2[40].x1 && x < btns2[40].x2 && y > btns2[40].y1 && y < btns2[40].y2) /// delete btn
        {
            if(isLeft == 1)
            {
                DEL2(1);
                left[strlen(left)-1] = NULL;
                outtextxy(rect.text.x+textwidth(L.lang[14+L.l])+23, rect.text.y+20, left);
            }
            else if(isLeft==0)
            {
                DEL2(2);
                right[strlen(right)-1] = NULL;
                outtextxy(rect.text.x+textwidth(L.lang[15+L.l])+20, rect.text.y+80, right);
            }
        }
        if(x > btns2[41].x1 && x < btns2[41].x2 && y > btns2[41].y1 && y < btns2[41].y2) /// reset btn
        {
            resetInput();
            strcpy(left,"");
            strcpy(right,"");
        }
        if(x > btns2[42].x1 && x < btns2[42].x2 && y > btns2[42].y1 && y < btns2[42].y2) /// next step
        {
            fprintf(input_file,"\n%s %s",left,right);
            fclose(input_file);
            closegraph();
            EVAL();
        }
        if(x > btns2[49].x1 && x < btns2[49].x2 && y > btns2[49].y1 && y < btns2[49].y2) /// exit
            exit(1);
}}
void drawPageTwo()
{
    int left_margin = 250;
    int y_text = rect.height+rect.top+85;
    int x_text = 200;
    registermousehandler(WM_LBUTTONDOWN, click_handler_two);
    drawInputField(L.lang[13+L.l]);
    getButtonsContent("pageTwoBtns.txt", btns2);
    drawButtonsField(12, btns2, left_margin, 3);
    drawDeleteButton(rect.right-190, rect.bottom+45, rect.right-130,rect.bottom+90, btns2);
    drawResetButton(rect.right-190, rect.bottom+110, rect.right-130,rect.bottom+155, btns2);
    drawNextStepButton(left_margin,W.height-W.height/4+60,left_margin+300,W.height-W.height/4+120,btns2);
    drawExitBtn(btns2);

    // text
    char temp[10];
    setcolor(BLUE);
    for(int i=0; i<9; i++)
    {
        x_text+=95;
        if(i%3==0 && i!=0)
        {
            y_text+=70;
            x_text = 295;
        }
        itoa(i+1,temp,10);
        outtextxy(x_text,y_text,temp);
    }
    y_text += 65;
    x_text = 295;
    outtextxy(x_text,y_text,"0");
    x_text += 95;
    outtextxy(x_text,y_text,".");
    x_text += 95;
    outtextxy(x_text,y_text,"-");

    setcolor(COLOR(200,0,0));
    if(L.l==0)
    {
        settextstyle(COMPLEX_FONT,HORIZ_DIR,4);

        /// left btn
        rectangle(left_margin-200, rect.bottom+40, left_margin-30,rect.bottom+100);
        outtextxy(left_margin-180, rect.bottom+90,L.lang[14+L.l]);
        btns2[13].x1 = left_margin-200;
        btns2[13].y1 = rect.bottom+40;
        btns2[13].x2 = left_margin-30;
        btns2[13].y2 = rect.bottom+100;

        /// right btn
        rectangle(left_margin-200, rect.bottom+130, left_margin-30,rect.bottom+190);
        outtextxy(left_margin-195, rect.bottom+180,L.lang[15+L.l]);
        btns2[14].x1 = left_margin-200;
        btns2[14].y1 = rect.bottom+130;
        btns2[14].x2 = left_margin-30;
        btns2[14].y2 = rect.bottom+190;
    }
    else if(L.l != 0)
    {
        settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
        /// left btn
        rectangle(left_margin-200, rect.bottom+40, left_margin-30,rect.bottom+100);
        outtextxy(left_margin-180, rect.bottom+90,L.lang[14+L.l]);
        btns2[13].x1 = left_margin-200;
        btns2[13].y1 = rect.bottom+40;
        btns2[13].x2 = left_margin-30;
        btns2[13].y2 = rect.bottom+100;

        /// right btn
        rectangle(left_margin-200, rect.bottom+130, left_margin-30,rect.bottom+190);
        outtextxy(left_margin-195, rect.bottom+180,L.lang[15+L.l]);
        btns2[14].x1 = left_margin-200;
        btns2[14].y1 = rect.bottom+130;
        btns2[14].x2 = left_margin-30;
        btns2[14].y2 = rect.bottom+190;

    }
}

