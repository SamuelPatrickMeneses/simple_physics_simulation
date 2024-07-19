#include <GL/gl.h>
#include <GL/glut.h>
#include <Box2D/Box2D.h>

#ifndef GAME_PRIMITIVE_DRAW
#define GAME_PRIMITIVE_DRAW

#define VERTEX_F2(vertc, vertv)             \
    for(int i = 0; i < vertc; i++)          \
        glVertex2f(vertv[i].x, vertv[i].y);                      
void line(b2Vec2* vertex);
void triangle(b2Vec2* vertex);
void quad(b2Vec2* vertex);

void circle(float ray);

#endif