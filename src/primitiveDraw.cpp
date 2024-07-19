#include "./game.hpp"

void line(b2Vec2* vertex){
    glBegin(GL_LINE);
    VERTEX_F2(2, vertex)
    glEnd();
}

void triangle(b2Vec2* vertex){
    glBegin(GL_TRIANGLES);
    VERTEX_F2(3, vertex)
    glEnd();
}
void quad(b2Vec2* vertex){
    glBegin(GL_QUADS);
    VERTEX_F2(4, vertex)
    glEnd();
}
void circle(float ray){
    const int vertc = 360;
    b2Vec2 vertv(0.f, ray);
    const float angleStep = 1.f;
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < vertc; i++, vertv = rotatePoint(vertv, angleStep)) {
        glVertex2f(vertv.x, vertv.y);    
    }
    glEnd();
}