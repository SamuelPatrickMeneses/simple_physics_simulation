#include "./game.hpp"

unsigned long now()
{
    return (clock() / CLOCKS_PER_SEC) * 1000;
}

long int sleep(long int sleepTime)
{
    if (sleepTime < 0)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        return sleepTime;
    }
    return 0;
}
b2Vec2 rotatePoint(b2Vec2 &point, float angle)
{
    angle = angleToRad(angle);
    float seno = sin(angle);
    float coseno = cos(angle);
    float tempx = coseno * point.x - point.y * seno;
    float tempy = coseno * point.y + point.x * seno;
    point.x = tempx;
    point.y = tempy;
    return point;
};
void rotate(float rad){
    glRotatef(radToAngle(rad), 0.f, 0.f, 1.f);
}
void translate(b2Vec2 point){
    glTranslated(point.x, point.y, 0.f);
}
