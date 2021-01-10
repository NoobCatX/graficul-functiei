void drawPageOne();
bool showMinMax = false, showAsimp = false, showPoints = false;
void eval(points &C)
{
    C.y = -evaluator(F.funct,C.x,C.e,C.color);
}
void MIN()
{
    double my = 9999999,mx=  0;
    for(int i=0; i<G.nr_points; i++)
        if(P[i].y < my)
        {
            my = P[i].y;
            mx = P[i].x;
        }

    G.MIN.y = my*G.zoomy+G.mid.y;
    G.MIN.x = mx*G.zoomx+G.mid.x;
    setlinestyle(0,0,2);
    setcolor(9);
    circle(G.MIN.x, G.MIN.y, 6);
    //printf("MIN: x: %lf y: %lf\n",G.MIN.x, G.MIN.y);
}
void MAX()
{
    double my = -9999999,mx = 0;
    for(int i=0; i<G.nr_points; i++)
        if(P[i].y > my)
        {
            my = P[i].y;
            mx = P[i].x;
        }
    G.MAX.y = my*G.zoomy+G.mid.y;
    G.MAX.x = mx*G.zoomx+G.mid.x;
     setlinestyle(0,0,2);
    setcolor(9);
    circle(G.MAX.x, G.MAX.y, 6);
    //printf("MAX: x: %lf y: %lf\n",G.MAX.x, G.MAX.y);
}
void calcPoints()
{
    int k=0;
    int c1=0,c2=0,c3=0,c4=0;
    for(int i=G.left_screen; i<=G.right_screen; i++)
    {
        P[k].x = i/10.0;
        eval(P[k]);
        k++;
    }
    G.nr_points = k;
}
void drawAxis()
{
    setcolor(0);
    setlinestyle(0,0,2);
    int offset = 70;
    int spacing = 25;
    if(G.cadran==0) // middle
    {
        // +
        line(0,getmaxy()/2,getmaxx(),getmaxy()/2); //Ox
        line(getmaxx()/2,0,getmaxx()/2,getmaxy()); //Oy
        G.Ox = getmaxy()/2;
        G.Oy = getmaxx()/2;
        // >
        line(getmaxx()-15-offset,getmaxy()/2-15,getmaxx()-offset,getmaxy()/2);
        line(getmaxx()-15-offset,getmaxy()/2+15,getmaxx()-offset,getmaxy()/2);
        // ^
        line(getmaxx()/2-15,15+offset,getmaxx()/2,0+offset);
        line(getmaxx()/2+15,15+offset,getmaxx()/2,0+offset);
    }
    else if(G.cadran==1) //cadran 1
    {
        //+
        line(0,getmaxy()-100-spacing,getmaxx(),getmaxy()-100-spacing); //Ox
        line(100+spacing,0,100+spacing,getmaxy());  //Oy
        G.Ox = getmaxy()-100-spacing;
        G.Oy = 100+spacing;
        // >
        line(getmaxx()-15-offset,getmaxy()-115-spacing,getmaxx()-offset,getmaxy()-100-spacing);
        line(getmaxx()-15-offset,getmaxy()-85-spacing,getmaxx()-offset,getmaxy()-100-spacing);
        // ^
        line(70+15+spacing,15+offset,100+spacing,0+offset);
        line(130-15+spacing,15+offset,100+spacing,0+offset);
    }
    else if(G.cadran==2) //cadran 2
    {
        //+
        line(0,100+spacing,getmaxx(),100+spacing); //Ox
        line(100+spacing,0,100+spacing,getmaxy());  //Oy
        G.Ox = 100+spacing;
        G.Oy = 100+spacing;
        // >
        line(getmaxx()-15-offset,85+spacing,getmaxx()-offset,100+spacing);
        line(getmaxx()-15-offset,115+spacing,getmaxx()-offset,100+spacing);
        // ^
        line(70+15+spacing,15+offset,100+spacing,0+offset);
        line(130-15+spacing,15+offset,100+spacing,0+offset);
    }
    else if(G.cadran==3) //cadran 3
    {
        //+
        line(getmaxx()-100-spacing,0,getmaxx()-100-spacing,getmaxy()); //Oy
        line(0,100+spacing,getmaxx(),100+spacing); //Ox
        G.Ox = 100+spacing;
        G.Oy = getmaxx()-100-spacing;
        // >
        line(getmaxx()-15-offset,85+spacing,getmaxx()-offset,100+spacing);
        line(getmaxx()-15-offset,115+spacing,getmaxx()-offset,100+spacing);
        // ^
        line(getmaxx()-115-spacing,15+offset,getmaxx()-100-spacing,0+offset);
        line(getmaxx()-85-spacing,15+offset,getmaxx()-100-spacing,0+offset);
    }
    else if(G.cadran==4) //cadran 4
    {
        //+
        line(0,getmaxy()-100-spacing,getmaxx(),getmaxy()-100-spacing); //Ox
        line(getmaxx()-100-spacing,0,getmaxx()-100-spacing,getmaxy()); //Oy
        G.Ox = getmaxy()-100-spacing;
        G.Oy = getmaxx()-100-spacing;
        // >
        line(getmaxx()-15-offset,getmaxy()-115-spacing,getmaxx()-offset,getmaxy()-100-spacing);
        line(getmaxx()-15-offset,getmaxy()-85-spacing,getmaxx()-offset,getmaxy()-100-spacing);
        // ^
        line(getmaxx()-115-spacing,15+offset,getmaxx()-100-spacing,0+offset);
        line(getmaxx()-85-spacing,15+offset,getmaxx()-100-spacing,0+offset);
    }
    ///combinated (c1c2=5 c2c3=6 c3c4=7 c4c1=8)
    else if(G.cadran==5) //c1 & c2
    {
        //+
        line(100+spacing,0,100+spacing,getmaxy());  //Oy
        line(0,getmaxy()/2,getmaxx(),getmaxy()/2); //Ox
        G.Ox = getmaxy()/2;
        G.Oy = 100+spacing;
        // >
        line(getmaxx()-15-offset,getmaxy()/2-15,getmaxx()-offset,getmaxy()/2);
        line(getmaxx()-15-offset,getmaxy()/2+15,getmaxx()-offset,getmaxy()/2);
        // ^
        line(70+15+spacing,15+offset,100+spacing,0+offset);
        line(130-15+spacing,15+offset,100+spacing,0+offset);
    }
    else if(G.cadran==6) //c2 & c3
    {
        //+
        line(0,100+spacing,getmaxx(),100+spacing); //Ox
        line(getmaxx()/2,0,getmaxx()/2,getmaxy()); //Oy
        G.Ox = 100+spacing;
        G.Oy = getmaxx()/2;
        // ^
        line(getmaxx()/2-15,15+offset,getmaxx()/2,0+offset);
        line(getmaxx()/2+15,15+offset,getmaxx()/2,0+offset);
        // >
        line(getmaxx()-15-offset,85+spacing,getmaxx()-offset,100+spacing);
        line(getmaxx()-15-offset,115+spacing,getmaxx()-offset,100+spacing);
    }
    else if(G.cadran==7) //c3 & c4
    {
        //+
        line(0,getmaxy()/2,getmaxx(),getmaxy()/2); //Ox
        line(getmaxx()-100-spacing,0,getmaxx()-100-spacing,getmaxy()); //Oy
        G.Ox = getmaxy()/2;
        G.Oy = getmaxx()-100-spacing;
        // >
        line(getmaxx()-15-offset,getmaxy()/2-15,getmaxx()-offset,getmaxy()/2);
        line(getmaxx()-15-offset,getmaxy()/2+15,getmaxx()-offset,getmaxy()/2);
        // ^
        line(getmaxx()-115-spacing,15+offset,getmaxx()-100-spacing,0+offset);
        line(getmaxx()-85-spacing,15+offset,getmaxx()-100-spacing,0+offset);
    }
    else if(G.cadran==8) // c4 & c1
    {
        //+
        line(getmaxx()/2,0,getmaxx()/2,getmaxy()); //Oy
        line(0,getmaxy()-100-spacing,getmaxx(),getmaxy()-100-spacing); //Ox
        G.Ox = getmaxy()-100-spacing;
        G.Oy = getmaxx()/2;
        // >
        line(getmaxx()-15-offset,getmaxy()-115-spacing,getmaxx()-offset,getmaxy()-100-spacing);
        line(getmaxx()-15-offset,getmaxy()-85-spacing,getmaxx()-offset,getmaxy()-100-spacing);
        // ^
        line(getmaxx()/2-15,15+offset,getmaxx()/2,0+offset);
        line(getmaxx()/2+15,15+offset,getmaxx()/2,0+offset);
    }

}
void int_to_char(int y,char st[],int &k)
{
    if(y)
    {
        int_to_char(y/10, st, k);
    }
    else
        return;
    st[k] = y % 10 + 48;
    k++;
}
void drawAxisPoints()
{
    settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    char st[10],st2[10];
    int k;
    for( int i = -160; i <= 160; i++)
    {
        circle(i*G.zoomx+G.mid.x,G.Ox,2);
        circle(G.Oy,(-i)*G.zoomy+G.mid.y,2);

        if(i == 0)
            outtextxy(i*G.zoomx+G.mid.x-10,G.Ox+20,"0");
        else if(i % 5 == 0 && i != 0)
        {
            if(i < 0)
            {
                strcpy(st,"-");
                k=1;
            }
            else
            {
                strcpy(st,"");
                k=0;
            }
            int_to_char(abs(i),st,k);
            st[k] = '\0';
            outtextxy(i*G.zoomx+G.mid.x,G.Ox+20,st);
            outtextxy(G.Oy-20,(-i)*G.zoomy+G.mid.y,st);
        }
    }
    setcolor(4);
    if(G.left == 0)
    {
        circle(G.left*G.zoomx+G.mid.x,G.Ox,3);
        outtextxy(G.left*G.zoomx+G.mid.x-15,G.Ox+40,"0");
    }
    else
    {
        circle(G.left*G.zoomx+G.mid.x,G.Ox,3);
        if(G.left < 0)
        {
            strcpy(st,"-");
            k=1;
        }
        else
        {
            strcpy(st,"");
            k=0;
        }
        int_to_char(abs(G.left),st,k);
        st[k] = '\0';
        outtextxy(G.left*G.zoomx+G.mid.x,G.Ox+40,st);
    }
    if(G.right == 0)
    {
        circle(G.right*G.zoomx+G.mid.x,G.Ox,3);
        outtextxy(G.right*G.zoomx+G.mid.x-15,G.Ox+40,"0");
    }
    else
    {
        circle(G.right*G.zoomx+G.mid.x,G.Ox,3);
        if(G.right < 0)
        {
            strcpy(st,"-");
            k=1;
        }
        else
        {
            strcpy(st,"");
            k=0;
        }
        int_to_char(abs(G.right),st,k);
        st[k] = '\0';
        outtextxy(G.right*G.zoomx+G.mid.x,G.Ox+40,st);
    }
    setcolor(0);
    settextjustify(LEFT_TEXT,TOP_TEXT);

}
void initGraph()
{
    G.zoomx = 30;
    G.zoomy = 30;
    G.left_screen = G.left*10;
    G.right_screen = G.right*10;
    //G.mid.x = getmaxx()/2;
    //G.mid.y = getmaxy()/2;

}
void drawBtns()
{
    setlinestyle(0,0,2);
    setcolor(MAGENTA);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);

    rectangle(getmaxx()-60,getmaxy()-60,getmaxx()-10,getmaxy()-10);
    btns3[0].x1 = getmaxx()-60;
    btns3[0].y1 = getmaxy()-60;
    btns3[0].x2 = getmaxx()-10;
    btns3[0].y2 = getmaxy()-10;
    outtextxy(getmaxx()-47,getmaxy()-55,"-");

    rectangle(getmaxx()-60,getmaxy()-120,getmaxx()-10,getmaxy()-70);
    btns3[1].x1 = getmaxx()-60;
    btns3[1].y1 = getmaxy()-120;
    btns3[1].x2 = getmaxx()-10;
    btns3[1].y2 = getmaxy()-70;
    outtextxy(getmaxx()-47,getmaxy()-115,"+");

    rectangle(getmaxx()-60,getmaxy()-180,getmaxx()-10,getmaxy()-130);
    btns3[2].x1 = getmaxx()-60;
    btns3[2].y1 = getmaxy()-180;
    btns3[2].x2 = getmaxx()-10;
    btns3[2].y2 = getmaxy()-130;
    outtextxy(getmaxx()-47,getmaxy()-175,"R");

    settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
    setcolor(COLOR(255,0,125));
    rectangle(10,getmaxy()-60,100,getmaxy()-10);
    btns3[3].x1 = 10;
    btns3[3].y1 = getmaxy()-60;
    btns3[3].x2 = 100;
    btns3[3].y2 = getmaxy()-10;
    outtextxy(25,getmaxy()-50,"IMG");
    setcolor(MAGENTA);
    rectangle(110,getmaxy()-60,200,getmaxy()-10);
    btns3[4].x1 = 110;
    btns3[4].y1 = getmaxy()-60;
    btns3[4].x2 = 200;
    btns3[4].y2 = getmaxy()-10;
    outtextxy(125,getmaxy()-50,L.lang[16+L.l]);

    setcolor(BLACK);
    rectangle(320,getmaxy()-60,480,getmaxy()-10); // MIN/MAX
    btns3[5].x1 = 320;
    btns3[5].y1 = getmaxy()-60;
    btns3[5].x2 = 480;
    btns3[5].y2 = getmaxy()-10;
    outtextxy(330,getmaxy()-50,"MIN/MAX");

    rectangle(490,getmaxy()-60,690,getmaxy()-10); // ASIMPTOTE
    btns3[6].x1 = 490;
    btns3[6].y1 = getmaxy()-60;
    btns3[6].x2 = 690;
    btns3[6].y2 = getmaxy()-10;
    outtextxy(500,getmaxy()-50,L.lang[L.l+17]);

    rectangle(700,getmaxy()-60,900,getmaxy()-10); // puncte
    btns3[7].x1 = 700;
    btns3[7].y1 = getmaxy()-60;
    btns3[7].x2 = 900;
    btns3[7].y2 = getmaxy()-10;
    outtextxy(710,getmaxy()-50,L.lang[18+L.l]);

    setcolor(7);
    rectangle(910,getmaxy()-60,1050,getmaxy()-10); // clear
    btns3[8].x1 = 910;
    btns3[8].y1 = getmaxy()-60;
    btns3[8].x2 = 1050;
    btns3[8].y2 = getmaxy()-10;
    outtextxy(925,getmaxy()-50,L.lang[L.l+19]);

}
void outText()
{
    char out_s[256],aux[256],aux2[256];
    strcpy(aux,F.funct);
    strcpy(aux2,aux+1);
    strcpy(aux,aux2);
    aux[strlen(aux)-1]=NULL;
    strcpy(out_s,"f(x)=");
    strcat(out_s,aux);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    setcolor(BLACK);
    outtextxy(15, 15,out_s);
}
void drawIntersectPoints()
{
    for(int i=0; i<G.nr_points; i++)
    {
        if(P[i].x*G.zoomx+G.mid.x == G.Oy)
        {
            setcolor(COLOR(255,0,50));
            circle(P[i].x*G.zoomx+G.mid.x,P[i].y*G.zoomy+G.mid.y,3);
        }
        else if(((P[i].y*G.zoomy+G.mid.y >= G.Ox && P[i-1].y*G.zoomy+G.mid.y < G.Ox) ||
                 (P[i].y*G.zoomy+G.mid.y <= G.Ox && P[i-1].y*G.zoomy+G.mid.y > G.Ox)) &&
                P[i].color == P[i-1].color &&
                !(abs(P[i-1].y-P[i].y) > 20 && abs(P[i-1].y-P[i].y) > 20) &&
                !(abs(P[i+1].y-P[i].y) > 20 && abs(P[i+1].y-P[i].y) > 20) &&
                !((strchr(F.funct,'<') || strchr(F.funct,'<')) && P[i].color == 2) &&
                strcmp(P[i].e,"error") && strcmp(P[i+1].e,"error") &&
                P[i].y != (getmaxx()+1) && (P[i-1].y != (getmaxx()+1) || P[i+1].y != (getmaxx()+1)))
        {
            setcolor(COLOR(255,0,50));
            circle((P[i].x*G.zoomx+G.mid.x+P[i-1].x*G.zoomx+G.mid.x)/2,getmaxy()/2,3);
        }
    }
}
void drawGraph()
{
    setcolor(2);
    setlinestyle(0,0,3);
    G.asim = 0;
    int h;
    if(G.cadran == 0 || G.cadran == 6 || G.cadran == 8)
        h = -1;
    else
        h = 0;
    if(G.nr_points == 1)
    {
        circle(P[0].x*G.zoomx+G.mid.x,P[0].y*G.zoomy+G.mid.y,2);
        floodfill(P[0].x*G.zoomx+G.mid.x,P[0].y*G.zoomy+G.mid.y,2);
    }
    else
    {
        for(int i=1; i < G.nr_points-1; i++)
        {
            setcolor(P[i].color);
            setlinestyle(0,0,3);
            if(strcmp(P[i].e,"error") && strcmp(P[i+1].e,"error") && P[i].color == P[i+1].color &&
                    (P[i].y != (getmaxx()+1) && P[i+1].y != (getmaxx()+1)) && !(abs(P[i+1].x-P[i].x) > 20 || abs(P[i+1].y-P[i].y) > 20))
            {
                line(P[i].x*G.zoomx+G.mid.x,P[i].y*G.zoomy+G.mid.y,P[i+1].x*G.zoomx+G.mid.x,P[i+1].y*G.zoomy+G.mid.y);
                h = 0;
            }
            else if(abs(P[i+1].y-P[i].y) > 20 && abs(P[i-1].y-P[i].y) > 20 && h < 1)
            {
                h++;
                G.asim++;
            }
        }
    }
}
void setPosition()
{
    int c1=0,c2=0,c3=0,c4=0;
    for(int k=0; k<G.nr_points; k++)
    {
        if(P[k].x>0 && -P[k].y>0)
        {
            c1=1;
        }
        else if(P[k].x>0 && -P[k].y<0)
        {
            c2=1;
        }
        else if(P[k].x<0 && -P[k].y<0)
        {
            c3=1;
        }
        else if(P[k].x<0 && -P[k].y>0)
        {
            c4=1;
        }
    }
//    printf("c1: %d c2: %d c3: %d c4: %d",c1,c2,c3,c4);

    if((c1!=0 && c3!=0) || (c4!=0 && c2!=0))
    {
        G.cadran = 0;
        G.mid.x = getmaxx()/2;
        G.mid.y = getmaxy()/2;
    }
    else if(c1!=0 && c2!=0)
    {
        G.cadran = 5;
        G.mid.x = 100+25;
        G.mid.y = getmaxy()/2;
    }
    else if(c2!=0 && c3!=0)
    {
        G.cadran = 6;
        G.mid.x = getmaxx()/2;
        G.mid.y = 100+25;
    }
    else if(c3!=0 && c4!=0)
    {
        G.cadran = 7;
        G.mid.x = getmaxx()-100-25;
        G.mid.y = getmaxy()/2;
    }

    else if(c4!=0 && c1!=0)
    {
        G.cadran = 8;
        G.mid.x = getmaxx()/2;
        G.mid.y = getmaxy()-100-25;
    }
    else if(c1!=0)
    {
        G.cadran = 1;
        G.mid.x=100+25;
        G.mid.y=getmaxy()-100-25;
    }
    else if(c2!=0)
    {
        G.cadran = 2;
        G.mid.x=100+25;
        G.mid.y=100+25;
    }
    else if(c3!=0)
    {
        G.cadran = 3;
        G.mid.x=getmaxx()-100-25;
        G.mid.y=100+25;
    }

    else if(c4!=0)
    {
        G.cadran = 4;
        G.mid.x=getmaxx()-100-25;
        G.mid.y=getmaxy()-100-25;
    }
}
void drawOutline()
{
    int offset = 70;
    bar(0,0,getmaxx(),offset);
    bar(0,0,offset,getmaxy());
    bar(0,getmaxy()-offset,getmaxx(),getmaxy());
    bar(getmaxx()-offset,0,getmaxx(),getmaxy());
    setcolor(1);
    setlinestyle(0,0,1);
    line(offset,offset,getmaxx()-offset,offset);
    line(offset,offset,offset,getmaxy()-offset);
    line(offset,getmaxy()-offset,getmaxx()-offset,getmaxy()-offset);
    line(getmaxx()-offset,offset,getmaxx()-offset,getmaxy()-offset);
}
void drawAsimp()
{
    double l;
    char e[6];
    int k=0,y;
    char s[256];
    strcpy(s,F.funct);
    asimp_vert();
    if(strstr(s,"cos") || strstr(s,"sin") || strstr(s,"log") || strstr(s,"ln"))
        return;
    l = -asimp_oriz(s,e);
    setlinestyle(1,0,2);
    setcolor(4);
    if(abs(l) != infinit)
    {
        line(0,l*G.zoomy+G.mid.y,getmaxx(),l*G.zoomy+G.mid.y);
        k = 1;
    }
    if(k == 0)
    {
        double m,n;
        int y;
        char e[6];
        bool asimp = asimp_obl(s,e,m,n);
        if((m*G.left+n == evaluator(F.funct,G.left,e,y)) && (m*G.right+n == evaluator(F.funct,G.right,e,y)))
            return;
        if(asimp)
        {
            double x = 0 - (m * G.left + n),
                   y = 0 - (m * G.right + n);
            line(G.left*G.zoomx+G.mid.x,x*G.zoomy+G.mid.y,G.right*G.zoomx+G.mid.x,y*G.zoomy+G.mid.y);
        }
    }
}
void zoom()
{
    setbkcolor(15);
    cleardevice();
    drawAxis();
    drawAxisPoints();
    drawGraph();
    if(showPoints)
    {
        drawIntersectPoints();
    }
    if(showAsimp)
    {
        drawAsimp();
    }
    if(showMinMax)
    {
        MIN();
        MAX();
    //printf("\nmax: %lf %lf\n",G.MIN.x, G.MIN.y);
    //printf("\nmin: %lf %lf\n",G.MAX.x, G.MAX.y);
    }
    drawOutline();
    drawExitBtn(btns3);
    outText();
    drawBtns();

}
void click_handler_three(int x, int y)
{
    //printf("x: %d\n", x);
    //printf("y: %d", y);
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        if(x > btns3[0].x1 && x < btns3[0].x2 && y > btns3[0].y1 && y < btns3[0].y2) // zoom out
        {
            if(G.zoomx > 10 && G.zoomy > 10)
            {
                G.zoomx-=5;
                G.zoomy-=5;
            }
            zoom();
        }
        if(x > btns3[1].x1 && x < btns3[1].x2 && y > btns3[1].y1 && y < btns3[1].y2) // zoom in
        {
            G.zoomx+=5;
            G.zoomy+=5;
            zoom();
        }
        if(x > btns3[2].x1 && x < btns3[2].x2 && y > btns3[2].y1 && y < btns3[2].y2) // reset
        {
            G.zoomx = 30;
            G.zoomy = 30;
            zoom();
        }
        if(x > btns3[3].x1 && x < btns3[3].x2 && y > btns3[3].y1 && y < btns3[3].y2) // bmp
        {
            writeimagefile("graphic.bmp",0,0,getmaxx()-62,getmaxy()-62);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            outtextxy(getmaxx()/2,45,L.lang[21+L.l]);
            ShellExecute(NULL, "open", "graphic.bmp", NULL, NULL, 0);
        }
        if(x > btns3[4].x1 && x < btns3[4].x2 && y > btns3[4].y1 && y < btns3[4].y2) // new
        {
         //   printf("new");
            closegraph();
            initwindow(W.width, W.height, "", (GetSystemMetrics(SM_CXSCREEN) - W.width)/2, (GetSystemMetrics(SM_CYSCREEN) - W.height)/2);
            setbkcolor(15);
            cleardevice();
            remove("input.txt");
            FILE *input_file = fopen("input.txt","w");
            drawPageOne();
        }
        if(x > btns3[5].x1 && x < btns3[5].x2 && y > btns3[5].y1 && y < btns3[5].y2) // min/max
        {
            showMinMax = true;
            zoom();
        }

        if(x > btns3[6].x1 && x < btns3[6].x2 && y > btns3[6].y1 && y < btns3[6].y2) // asimptote
        {

            showAsimp = true;
            zoom();
        }
        if(x > btns3[7].x1 && x < btns3[7].x2 && y > btns3[7].y1 && y < btns3[7].y2) // puncte intersectie
        {

            showPoints = true;
            zoom();
        }
        if(x > btns3[8].x1 && x < btns3[8].x2 && y > btns3[8].y1 && y < btns3[8].y2) // clear
        {
            showAsimp = false;
            showMinMax = false;
            showPoints = false;
            zoom();
        }
        if(x > btns3[49].x1 && x < btns3[49].x2 && y > btns3[49].y1 && y < btns3[49].y2) // clear
            exit(1);

    }
}
void drawGraphPage()
{
    initwindow(1800, 900, "", (GetSystemMetrics(SM_CXSCREEN) - 1800)/2, (GetSystemMetrics(SM_CYSCREEN) - 900)/2);
    setbkcolor(15);
    cleardevice();
    registermousehandler(WM_LBUTTONDOWN,click_handler_three);
    initGraph();
    calcPoints();
    setPosition();
    drawAxis();
    drawAxisPoints();
    drawGraph();
    drawOutline();
    drawExitBtn(btns3);
    outText();
    drawBtns();
    getch();
    closegraph();
}
