#include "./game.hpp"

    void keyBuffer::put(unsigned char key)
    {
        this->back[key] = 1;
    }

    int keyBuffer::check(unsigned char key)
    {
        return this->front[key];
    }

    void keyBuffer::swap()
    {
        for (pair<unsigned char, int> p : this->back)
            this->back[p.first] += this->front[p.first] + 1;
        this->front.clear();
        this->back.swap(this->front);
    }