#include <Box2D/Box2D.h>
#include "./game_struct.hpp"

#ifndef GAME_ENTITIES
#define GAME_ENTITIES

b2Body* createQuadBody(b2Vec2* dimensions, bool dinamic = false);
void drawQuadBody(b2Body* body);

b2Body* createCircleBody(b2Vec2 position, float ray, bool dinamic = false);
void drawCircleBody(b2Body* body);

b2Body* createTriangleBody(b2Vec2 position, b2Vec2* vertex, bool dinamic = false);
void drawTriangleBody(b2Body* body);

void drawBody(b2Body* body);

#endif