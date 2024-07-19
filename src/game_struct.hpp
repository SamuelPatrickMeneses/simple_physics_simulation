#include <Box2D/Box2D.h>
#ifndef GAME_STRUCT_H
#define GAME_STRUCT_H
#ifndef GAME_KEYBOARD
    #include "./inputKeyboard.hpp"
#endif
typedef void procedure(void);
typedef void keyListener(unsigned char key, int x, int y);
typedef void resizeListener(int width, int height);

procedure internalStep;
keyListener internalKeyDown;
keyListener internalKeyUp;
resizeListener internalResize;
        

namespace game
{
    namespace physic{
        extern b2World *world;
        const b2Vec2 initialGravity(0, -10);
    }
    namespace properts
    {
        extern const int width;
        extern const int height;
        extern const float stepDuration;
        const int velocityIteration = 8;
        const int positionIteration = 4;
    }
    namespace runtimeVariables
    {
        extern float lestStep;
        extern int width;
        extern int height;
    }
    namespace lifeCicle
    {
        procedure step;
        procedure start;
        procedure load;
        procedure unload;
        keyListener keyDown;
        // keyListener keyUp;
        void config(int argc, char **argv);
    }
    namespace input{
        extern keyBuffer* keyboard;
    }
}

#endif
