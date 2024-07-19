#include "./entities.hpp"
#include "primitiveDraw.hpp"
#include "./util.hpp"

b2Body* createQuadBody(b2Vec2 *dimensions, bool dinamic)
{

    b2BodyDef bodydef;
    bodydef.position = *dimensions;
    if (dinamic)
    {
        bodydef.type = b2BodyType::b2_dynamicBody;
    }
    b2Body *body = game::physic::world->CreateBody(&bodydef);

    b2FixtureDef fixturedef;
    fixturedef.density = 1;
    fixturedef.restitution = 0;
    fixturedef.friction = 0.3;
    b2PolygonShape shape;
    shape.SetAsBox(dimensions[1].x, dimensions[1].y);
    fixturedef.shape = &shape;
    body->CreateFixture(&fixturedef);
    body->SetAwake(true);
    return body;
}
void drawQuadBody(b2Body *body)
{
    b2Fixture *fixture = body->GetFixtureList();
    b2PolygonShape *shape = (b2PolygonShape *)fixture->GetShape();
    b2Vec2 point = body->GetPosition();
    float angle = body->GetAngle();
    glPushMatrix();
    translate(point);
    rotate(angle);
    quad(shape->m_vertices);
    glPopMatrix();
}

b2Body *createCircleBody(b2Vec2 position, float ray, bool dinamic)
{
    b2BodyDef bodydef;
    bodydef.position = position;
    if (dinamic)
    {
        bodydef.type = b2BodyType::b2_dynamicBody;
    }
    b2Body *body = game::physic::world->CreateBody(&bodydef);

    b2FixtureDef fixturedef;
    fixturedef.density = 1;
    fixturedef.restitution = 1;
    fixturedef.friction = 1;
    b2CircleShape shape;
    shape.m_p = b2Vec2(0, 0);
    shape.m_radius = ray;
    fixturedef.shape = &shape;
    body->CreateFixture(&fixturedef);
    body->SetAwake(true);
    return body;
}
void drawCircleBody(b2Body *body)
{
    b2Fixture *fixture = body->GetFixtureList();
    b2CircleShape *shape = (b2CircleShape *)fixture->GetShape();
    b2Vec2 point = body->GetPosition();
    float angle = body->GetAngle();
    glPushMatrix();
    translate(point);
    rotate(angle);
    circle(shape->m_radius);
    glPopMatrix();
}
b2Body* createTriangleBody(b2Vec2 position, b2Vec2* vertex, bool dinamic){
    b2BodyDef bodydef;
    bodydef.position =  position;
    if (dinamic)
    {
        bodydef.type = b2BodyType::b2_dynamicBody;
    }
    b2Body *body = game::physic::world->CreateBody(&bodydef);

    b2FixtureDef fixturedef;
    fixturedef.density = 1;
    fixturedef.restitution = 1;
    fixturedef.friction = 1;
    b2PolygonShape shape;
    shape.Set(vertex, 3);
    fixturedef.shape = &shape;
    body->CreateFixture(&fixturedef);
    body->SetAwake(true);
    return body;
}
void drawTriangleBody(b2Body* body){
    b2Fixture *fixture = body->GetFixtureList();
    b2PolygonShape *shape = (b2PolygonShape *)fixture->GetShape();
    b2Vec2 point = body->GetPosition();
    float angle = body->GetAngle();
    glPushMatrix();
    translate(point);
    rotate(angle);
    triangle(shape->m_vertices);
    glPopMatrix();
}
void drawBody(b2Body *body)
{
    b2Fixture *fixture = body->GetFixtureList();
    switch (fixture->GetType())
    {
    case b2Shape::Type::e_circle :
        drawCircleBody(body);
        break;
    case b2Shape::Type::e_polygon:
        b2PolygonShape* shape = (b2PolygonShape*) fixture->GetShape();
        if(shape->GetVertexCount() >= 4)
            drawQuadBody(body);
        else
            drawTriangleBody(body);
        break;
    }
}
