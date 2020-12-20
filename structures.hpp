#ifndef STRUCTURES_H
#define STRUCTURES_H
struct buttons
{
    int x1,x2,y1,y2;
    const int height = 70;
    const int width = 100;
    char content[10];

} btns1[50],btns2[50],btn;

struct inputField {
    const int left = 30;
    const int top = 70;
    const int right = 770;
    const int bottom = 250;
    const int width = right - left;
    const int height = bottom - top;

}rect;

struct graphic
{
    float left;
    float right;

    struct
    {
        int x, y;
    } mid;

    int zoomx;
    int zoomy;

}G;
#endif
