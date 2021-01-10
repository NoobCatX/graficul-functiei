void drawExitBtn(struct buttons *btn){
    setcolor(COLOR(255,0,0));
    setlinestyle(0,0,2);
    circle(getmaxx()-32,33,20);
    line(getmaxx()-40,40,getmaxx()-25,25);
    line(getmaxx()-40,25,getmaxx()-25,40);
    btn[49].x1 = getmaxx()-32-10;
    btn[49].y1 = 33-10;
    btn[49].x2 = getmaxx()-32+10;
    btn[49].y2 = 33+10;
}
void drawGoBackBtn(struct buttons *btn)
{
    setcolor(DARKGRAY);
    circle(53,35,20);
    line(55,30,50,35);
    line(55,40,50,35);
    btn[50].x1 = 35;
    btn[50].y1 = 15;
    btn[50].x2 = 75;
    btn[50].y2 = 55;
}
void drawInputField(char s[])
{
    setcolor(0);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(400,50,s); //title
    setlinestyle(SOLID_LINE,0,2);
    rectangle(30,70,770,250);
    settextjustify(0,0);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
}
void getButtonsContent(char fileName[], struct buttons *btn)
{
    FILE * btns = fopen(fileName,"r");
    char s[256], *p;
    int i = 0;
    fgets(s,256,btns);

    p=strtok(s,",");
    while(p)
    {
        i++;
        if(strcmp(p,"v")==0)
            strcpy(btn[i].content,",");
        else strcpy(btn[i].content,p);
        p=strtok(NULL,",");
    }
}
void drawButtonsField(int n, struct buttons *btn, int left_margin, int cols )
{
    int k=-1, newLine=0;

    for(int i=0; i<n; i++)
    {
        if(i%cols==0 && i!=0)
        {
            k=0;
            newLine+=70;
        }
        else k++;

        rectangle(left_margin+(btn->width)*k,rect.height+rect.top+30+newLine,left_margin+100+(btn->width)*k,rect.height+rect.top+100+newLine);
        btn[i+1].x1=left_margin+(btn->width)*k;
        btn[i+1].y1=rect.height+rect.top+30+newLine;
        btn[i+1].x2=left_margin+100+(btn->width)*k;
        btn[i+1].y2=rect.height+rect.top+100+newLine;
    }
}
void drawDeleteButton(int x1, int y1, int x2, int y2, struct buttons *btn)
{
    setcolor(COLOR(255,0,0));
    rectangle(x1,y1,x2,y2);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
    outtextxy(x1+8,y1+33,"DEL");
    btn[40].x1=x1;
    btn[40].y1=y1;
    btn[40].x2=x2;
    btn[40].y2=y2;

}
void drawResetButton(int x1, int y1, int x2, int y2, struct buttons *btn)
{

    setcolor(GREEN);
    rectangle(x1,y1,x2,y2);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
    outtextxy(x1+8,y1+33,"RES");
    btn[41].x1=x1;
    btn[41].y1=y1;
    btn[41].x2=x2;
    btn[41].y2=y2;

}
void drawNextStepButton(int x1, int y1, int x2, int y2, struct buttons *btn)
{

    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
    setcolor(MAGENTA);
    outtextxy(W.width/2,W.height-W.height/4+100,L.lang[12+L.l]);
    settextjustify(0,0);
    rectangle(x1,y1,x2,y2);
    btn[42].x1=x1;
    btn[42].y1=y1;
    btn[42].x2=x2;
    btn[42].y2=y2;
}
void resetInput()
{
    setfillstyle(SOLID_FILL,WHITE);
    setcolor(BLACK);
    rectangle(30,70,W.width-30,250);
    floodfill(35,75,BLACK);
    setcolor(GREEN);
}
