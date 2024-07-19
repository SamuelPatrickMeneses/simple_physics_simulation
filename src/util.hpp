#include <chrono>
#include <thread>
#include <time.h>
#include <math.h>
#include <iostream>
#include <Box2D/Box2D.h>

#ifndef GAME_UTIL
#define GAME_UTIL
#define RAD_VAL (180 / M_PI)
#define print(x) std::cout << x << std::endl
unsigned long now(void);
long int sleep(long int sleepTime);
b2Vec2 rotatePoint(b2Vec2 &point, float angle);
void rotate(float rad);
void translate(b2Vec2 position);


float inline angleToRad(float angle)
{
    return angle / RAD_VAL;
}
float inline radToAngle(float rad){
    return rad * RAD_VAL;
}
#endif