float eval(float x)
{
    return cos(x)*x;
}

int left_screen, right_screen;

void initGraph()
{
    G.left = -20;
    G.right = 20;
    G.mid.x = getmaxx()/2;
    G.mid.y = getmaxy()/2;
    G.zoomx = 20;
    G.zoomy = 20;
    left_screen = ceil(G.left)*G.zoomx;
    right_screen = floor(G.right)*G.zoomy;
}

void drawGraphic()
{
    initwindow(1800, 900, "ok", (GetSystemMetrics(SM_CXSCREEN) - 1800)/2, (GetSystemMetrics(SM_CYSCREEN) - 900)/2);
    initGraph();
    setbkcolor(15);
    cleardevice();
    setcolor(2);
    setlinestyle(1,1,5);

    float value;

    for(int i=left_screen; i<=right_screen; i++)
    {
        if(i==left_screen)
        {
            moveto(floor((left_screen+1)/20.0*G.zoomx)+G.mid.x,floor(eval(left_screen/20.0)*G.zoomy)+G.mid.y);
            delay(100);
        }
        value=i/20.0;
        lineto(floor(value*G.zoomx)+G.mid.x,floor(eval(value)*G.zoomy)+G.mid.y);
        delay(1);
    }
}
