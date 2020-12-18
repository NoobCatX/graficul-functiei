#include<math.h>

struct stiva
{
    char info;
    stiva *urm;
};

struct stiva2
{
    float info;
    stiva2 *urm;
};

int prioritate(char p)
{
    if( p == ')' || p == '(')
        return 0;
    if( p == '+')
        return 1;
    if( p == '-')
        return 2;
    if( p == '*')
        return 3;
    if( p == '/')
        return 4;
    if( p == '^')
        return 5;
    if( p == 'c' || p == 's' || p == 'l' || p == 'a' || p == 'r' || p == 'e')
        return 6;
    return -1;
}

bool opr(char c[], int &t)
{
    if(!strncmp(c,"sin",3) || !strncmp(c,"cos",3) || !strncmp(c,"abs",3) || !strncmp(c,"rad",3) || !strncmp(c,"exp",3))
    {
        t = 2;
        return true;
    }
    if(!strncmp(c,"ln",2))
    {
        t = 1;
        return true;
    }
    return false;
}

float operatie(float x, float y, char c)
{
    if(c == '+')
        return x + y;
    if(c == '-')
        return y - x;
    if(c == '*')
        return x * y;
    if(c == '/')
        return y / x;
    if(c == '^')
        return pow(y,x);
    if(c == 's')
        return sin(x);
    if(c == 'c')
        return cos(x);
    if(c == 'a')
        return abs(x);
    if(c == 'l')
        return log(x);
    if(c == 'r')
    {
        if(x >= 0)
            return sqrt(x);
        else
            return -1;
    }
    if(c == 'e')
        return exp(x);
    return -1;
}


void push(stiva2* &f, float x)
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

void evaluator(char c[], int x)
{
    char op[] = "()+-*/^";
    int t;
    stiva *s;
    stiva2 *f;
    pushC(s,'(');
    strcat(c,")");
    for(int i = 0; i < strlen(c); i++)
    {
        int y = prioritate(c[i]);
        if(y != -1 && (y > prioritate(s->info) || c[i] == '('))
        {
            if(opr(c+i,t))
            {
                pushC(s,c[i]);
                i+=t;
            }
            else
                pushC(s,c[i]);
        }
        else if(c[i] == 'x')
            push(f,x);
        else if(c[i] >= 48 && c[i] <= 57)
        {
            int d = c[i]-48;
            while(c[i+1] >= 48 && c[i+1] <= 57)
            {
                d = d * 10 + (c[i+1]-48);
                i++;
            }
            push(f,d);
        }
        else
        {
            while(y < prioritate(s->info) && s != NULL)
            {
                float d = f->info,g;
                pop(f);
                if(strchr(op,s->info))
                {
                    g = f->info;
                    pop(f);
                    push(f,operatie(d,g,s->info));
                    popC(s);
                }
                else
                {
                    if(s->info == 'r' && d < 0)
                    {

                        break;
                    }
                    push(f,operatie(d,1,s->info));
                    popC(s);
                }

            }
            if(s->info == '(' && c[i] == ')')
                popC(s);
            if(c[i] != ')')
                pushC(s,c[i]);
        }

    }
    printf("%f",f->info);
    pop(f);
}
