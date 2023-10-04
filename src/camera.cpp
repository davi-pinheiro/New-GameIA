#include "camera.h"

Camera::Camera(int xCamera, int yCamera, int wCamera, int hCamera)
{
    this->camera = new SDL_Rect();
    this->camera->x = (xCamera / 2) - wCamera / 2;
    this->camera->y = (yCamera / 2) - hCamera / 2;
    this->camera->w = wCamera;
    this->camera->h = hCamera;

    this->filme = new SDL_Rect();
    this->filme->x = 0;
    this->filme->y = 0;
    this->filme->w = wCamera - 2;
    this->filme->h = hCamera - 2;
}


SDL_Rect* Camera::getCamera(void)
{
    return camera;
}
SDL_Rect* Camera::getFilme(void)
{
    return filme;
}

int Camera::getXCamera(void)
{
    return camera->x;
}
int Camera::getYCamera(void)
{
    return camera->y;
}
int Camera::getWidthCamera(void)
{
    return camera->w;
}
int Camera::getHeightCamera(void)
{
    return camera->h;
}

int Camera::getXFilme(void)
{
    return filme->x;
}
int Camera::getYFilme(void)
{
    return filme->y;
}
int Camera::getWidthFilme(void)
{
    return filme->w;
}
int Camera::getHeightFilme(void)
{
    return filme->h;
}

void Camera::setXCamera(int x)
{
    this->camera->x = x;
}
void Camera::setYCamera(int y)
{
    this->camera->y = y;
}
void Camera::setWidthCamera(int w)
{
    this->camera->w = w;
}
void Camera::setHeightCamera(int h)
{
    this->camera->h = h;
}

void Camera::setXFilme(int x)
{
    this->filme->x = x;
}
void Camera::setYFilme(int y)
{
    this->filme->y = y;
}
void Camera::setWidthFilme(int w)
{
    this->filme->w = w;
}
void Camera::setHeightFilme(int h)
{
    this->filme->h = h;
}
