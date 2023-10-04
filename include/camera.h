#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>

class Camera
{
    private:
    SDL_Rect* camera;
    SDL_Rect* filme;
    public:
    Camera(int x, int y, int w, int h);

    SDL_Rect* getCamera(void);
    SDL_Rect* getFilme(void);

    int getXCamera(void);
    int getYCamera(void);
    int getWidthCamera(void);
    int getHeightCamera(void);

    int getXFilme(void);
    int getYFilme(void);
    int getWidthFilme(void);
    int getHeightFilme(void);

    void setXCamera(int x);
    void setYCamera(int y);
    void setWidthCamera(int w);
    void setHeightCamera(int h);

    void setXFilme(int x);
    void setYFilme(int y);
    void setWidthFilme(int w);
    void setHeightFilme(int h);
};

#endif