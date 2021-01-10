#include "structures.hpp"
#include <string.h>

int priority(char p)
{
    if( p == '(')
        return 0;
    if( p == ')')
        return 1;
    if( p == '+')
        return 2;
    if( p == '-')
        return 3;
    if( p == '*')
        return 4;
    if( p == '/')
        return 5;
    if( p == '^')
        return 6;
    if(p == '<' || p == '>')
        return 7;
    if(p == '=')
        return 8;
    if( p == 'c' || p == 's' || p == 'l' || p == 'a' || p == 'r' || p == 'e' || p == 'q' || p == 'o')
        return 9;
    return -1;
}

bool opr(char c[], int &t)
{
    if(!strncmp(c,"sin",3) || !strncmp(c,"cos",3) || !strncmp(c,"abs",3) || !strncmp(c,"exp",3) || !strncmp(c,"qrt",2))
    {
        t = 2;
        return true;
    }
    else if(!strncmp(c,"ln",2) || !strncmp(c,"og",2))
    {
        t = 1;
        return true;
    }
    return false;
}

double operatie(double x, double y, char c, char e[],int &color,int &k)
{
    if(c == '=')
        return x == y;
    if(c == '>')
    {
        if(x < y)
        {
            k=1;
            color = 3;
        }
        return x < y;
    }
    if(c == '<')
    {
        if(x > y)
        {
            k=1;
            color = 1;
        }
        return x > y;
    }
    if(c == '+')
        return x + y;
    if(c == '-')
        return y - x;
    if(c == '*')
        return x * y;
    if(c == '/')
    {
        if(x == 0)
            strcpy(e,"error");
        else
            return y / x;
    }
    if(c == '^')
        return pow(y,x);
    if(c == 's')
        return sin(x);
    if(c == 'c')
        return cos(x);
    if(c == 'a')
        return abs(x);
    if(c == 'l')
    {
        if(x < 0)
            strcpy(e,"error");
        else
            return log(x);
    }
    if(c == 'o')
    {
        if(x < 0)
            strcpy(e,"error");
        else
            return log10(x);
    }
    if(c == 'q')
    {
        if(x >= 0)
            return sqrt(x);
        else
            strcpy(e,"error");
    }
    if(c == 'e')
        return exp(x);
    return getmaxx()+1;
}

void push(stiva2* &f, double x)
{
    stiva2 *p = new stiva2;
    p->info = x;
    p->urm = f;
    f = p;
}

void pushC(stiva* &f, char x)
{
    stiva *p = new stiva;
    p->info = x;
    p->urm = f;
    f = p;
}

void popC(stiva* &f)
{
    stiva *deSters = f;
    f = f->urm;
    delete deSters;
}

void pop(stiva2* &f)
{
    stiva2 *deSters = f;
    f = f->urm;
    delete deSters;
}

double evaluator(char c[], double x, char e[],int &color)
{
    char op[] = "+-*/^<>",aux[256];
    int k=0,m=1;
    int t,z=0;
    color = 2;
    stiva *s = NULL;
    stiva2 *f = NULL;
    strcpy(e,"*");
    pushC(s,'(');
    for(int i = 1; i < strlen(c); i++)
    {
        if(c[i] == '(')
            m++;
        if(c[i] == ')')
            m--;
        if((strchr(op,c[i]) && strchr(op,c[i+1])) || (c[i] == ')' && c[i+1] == '(') || m < 0)
        {
            strcpy(e,"error");
            return getmaxx()+1;
        }
        int y = priority(c[i]);
        if((c[i] == 's' && c[i+1] == 'q') || (c[i] == 'l' && c[i+1] == 'o'))
            i++;
        if(y != -1 && (y > priority(s->info) || c[i] == '(') && c[i] != ')')
        {
            if(opr(c+i,t))
            {
                pushC(s,c[i]);
                i+=t;
            }
            else if(c[i] == '-' && c[i-1] == '(')
                z = 1;
            else
                pushC(s,c[i]);
        }
        else if(c[i] == 'x')
        {
            if(z == 1)
            {
                push(f,-x);
                z = 0;
            }
            else
                push(f,x);
        }
        else if(c[i] == 'p')
        {
            if(z == 1)
            {
                push(f,-3.14);
                z = 0;
            }
            else
                push(f,3.14);
            i++;
        }
        else if(c[i] >= 48 && c[i] <= 57)
        {
            double d = c[i]-48;
            while((c[i+1] >= 48 && c[i+1] <= 57))
            {
                d = d * 10 + (c[i+1]-48);
                i++;
            }
            if(c[i+1] == '.')
            {
                i++;
                while((c[i+1] >= 48 && c[i+1] <= 57))
                {
                    d = d + (double)(c[i+1]-48) / 10;
                    i++;
                }
            }
            if(z == 1)
            {
                d = -d;
                z = 0;
            }
            push(f,d);
        }
        else
        {
            while(y <= priority(s->info) && s != NULL)
            {
                if(f == NULL)
                {
                    strcpy(e,"error");
                    return getmaxx()+1;
                }
                double d = f->info,g;
                pop(f);
                if(strchr(op,s->info) || s->info == '=')
                {
                    if(f == NULL)
                    {
                        strcpy(e,"error");
                        return getmaxx()+1;
                    }
                    g = f->info;
                    pop(f);
                    char h = s->info;
                    popC(s);
                    if(h == '=' && (s->info == '>' || s->info == '<'))
                    {
                        double u;
                        if(s->info == '>')
                        {
                            u = g >= d;
                            if(u)
                            {
                                k=1;
                                color = 3;
                            }
                        }
                        else
                        {
                            u = g <= d;
                            if(u)
                            {
                                k=1;
                                color = 1;
                            }
                        }
                        push(f,u);
                        popC(s);
                    }
                    else
                        push(f,operatie(d,g,h,e,color,k));
                }
                else
                {
                    push(f,operatie(d,1,s->info,e,color,k));
                    popC(s);
                }
                if(strcmp(e,"error") == 0)
                    return getmaxx()+1;
            }
            if(s->info == '(' && c[i] == ')')
                popC(s);
            if(c[i] != ')')
                pushC(s,c[i]);
        }

    }
    if(k == 0 && (strchr(c,'<') || strchr(c,'<')))
    {

        return getmaxx()+1;
    }

    if(s != NULL || m > 0 || f->urm != NULL)
    {
        strcpy(e,"error");
        return getmaxx()+1;
    }
    return f->info;
}

double asimp_oriz(char c[],char e[])
{
    double l;
    int y;
    l = evaluator(c,infinit,e,y);
    if(abs(infinit-abs(l)) > infinit / 2)
        return l;
    else
        return infinit;
}

bool asimp_obl(char c[],char e[],double &m, double &n)
{
    int y;
    double x;
    m = evaluator(c,infinit,e,y) / infinit;
    if(abs(infinit-abs(m)) <= infinit / 2 && m!=0)
        return false;
    x = infinit * int(m);
    n = evaluator(c,infinit,e,y) - x;
    if(abs(infinit-abs(n)) <= infinit / 2)
        return false;
    return true;
}

void asimp_vert()
{
    int h;
    if(G.cadran == 0 || G.cadran == 6 || G.cadran == 8)
        h = -1;
    else
        h = 0;
    for(int i=0; i < G.nr_points-2; i++)
        if(abs(P[i+1].y-P[i].y) > 20 && abs(P[i-1].y-P[i].y) > 20 && h < 1 && G.asim != 0)
        {
            G.asim--;
            setcolor(3);
            h++;
            setlinestyle(1,0,2);
            line(P[i].x*G.zoomx+G.mid.x,0,P[i].x*G.zoomx+G.mid.x,getmaxy());
        }
        else
            h = 0;
}
