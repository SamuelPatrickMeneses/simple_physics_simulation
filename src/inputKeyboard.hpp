#ifndef GAME_KEYBOARD
#define GAME_KEYBOARD
#include <map>
using namespace std;
class keyBuffer
{
private:
 map<unsigned char, int> back;
    map<unsigned char, int> front;
public:
    void put(unsigned char key);
    int check(unsigned char key);
    void swap();
};
#endif
