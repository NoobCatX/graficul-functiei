#include "structures.hpp"
void updateLanguage()
{
    FILE *p;
    p = fopen("language.txt","r");
    int k = 0;
    while(!feof(p))
    {
        fgets(L.lang[k],100,p);
        k++;
    }
    fclose(p);
}
