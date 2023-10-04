#ifndef RGB_H
#define RGB_H

class Rgba
{
private:
    int r;
    int g;
    int b;
    int a;/* data */
public:
    Rgba(int r = 0, int g = 0, int b = 0, int a = 0);
    int getR();
    int getG();
    int getB();
    int getA();
    void setRgba(int r, int g, int b, int a);
};

#endif