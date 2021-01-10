#ifndef STRUCTURES_H
#define STRUCTURES_H
struct window {
    const int width = 800;
    const int height = 800;
}W;
struct buttons
{
    int x1,x2,y1,y2;
    const int height = 70;
    const int width = 100;
    char content[10];

} btns0[51],btns1[51],btns2[51],btns3[51],btn;
struct inputField
{
    const int left = 30;
    const int top = 70;
    const int right = 770;
    const int bottom = 250;
    const int width = right - left;
    const int height = bottom - top;

    struct
    {
        int x=55;
        int y=130;
    } text;

} rect;
struct graphic
{
    double left;
    double right;
    int left_screen;
    int right_screen;

    struct
    {
        double x, y;
    } MIN,MAX;

    int min_screen;
    int max_screen;

    int cadran;
    int Ox;
    int Oy;

    struct
    {
        int x, y;
    } mid;

    int zoomx;
    int zoomy;

    int nr_points;
    int asim=0;
} G;
struct points
{
    double x;
    double y;
    int color = 2;
    char e[6];
} P[10000];
struct LANG
{
    char lang[50][256];
    int l = 0;
}L;
struct FUNCT
{
    char funct[256];
    char e[5];
}F;
struct stiva
{
    char info;
    stiva *urm;
};

struct stiva2
{
    double info;
    stiva2 *urm;
};

#endif
