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

int priority(char p)
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
    if( p == 'c' || p == 's' || p == 'l' || p == 'a' || p == 'r' || p == 'e' || p == 'q' || p == 'o')
        return 6;
    return -1;
}

bool opr(char c[], int &t)
{
    if(!strncmp(c,"sin",3) || !strncmp(c,"cos",3) || !strncmp(c,"abs",3) || !strncmp(c,"exp",3) || !strncmp(c,"qrt",2))
    {
        t = 2;
        return true;
    }
    else if(!strncmp(c,"ln",2))
    {
        t = 1;
        return true;
    }
    else if(!strncmp(c,"og10",4))
    {
        t = 3;
        return true;
    }
    return false;
}

float operatie(float x, float y, char c, char e[])
{
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
        return log(x);
    if(c == 'o')
        return log10(x);
    if(c == 'q')
    {
        if(x >= 0)
            return sqrt(x);
        else
            strcpy(e,"error");
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


float evaluator(char c[], float x, char e[])
{
    char op[] = "+-*/^",aux[256];
    int t,z=0;
    stiva *s;
    stiva2 *f;
    strcpy(e,"*");
    strcpy(aux,c);
    strcpy(c+1,aux);
    c[0] = '(';
    pushC(s,'(');
    strcat(c,")");
    for(int i = 1; i < strlen(c); i++)
    {
        if((strchr(op,c[i]) && strchr(op,c[i+1])) || (c[i] == ')' && c[i+1] == '('))
        {
            strcpy(e,"error");
            return 0;
        }
        int y = priority(c[i]);
        if((c[i] == 's' && c[i+1] == 'q') || (c[i] == 'l' && c[i+1] == 'o'))
            i++;
        if(y != -1 && (y > priority(s->info) || c[i] == '('))
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
            float d = c[i]-48;
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
                    d = d + (float)(c[i+1]-48) / 10;
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
            while(y < priority(s->info) && s != NULL)
            {
                float d = f->info,g;
                pop(f);
                if(strchr(op,s->info))
                {
                    g = f->info;
                    pop(f);
                    push(f,operatie(d,g,s->info,e));
                    popC(s);
                }
                else
                {
                    push(f,operatie(d,1,s->info,e));
                    popC(s);
                }
                if(!strcmp(e,"error"))
                    return 0;
            }
            if(s->info == '(' && c[i] == ')')
                popC(s);
            if(c[i] != ')')
                pushC(s,c[i]);
        }

    }
    if(s == NULL)
    {
        printf("%lf",f->info);
        return f->info;
    }
    else
    {
        strcpy(e,"error");
        return 0;
    }
}


