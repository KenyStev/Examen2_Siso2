#include "LRU.h"

LRU::LRU()
{
    //ctor
}

LRU::~LRU()
{
    //dtor
}

int LRU::getFaultPage(int *cadena, int size, int marcos_cant)
{
    int faultPage = 0;

    int next = 0;

    int frames[marcos_cant];

    for(int i=0; i<size; i++)
    {
        if(!(this->isThere(frames,marcos_cant,cadena[i])))
        {
            faultPage++;
        }
        frames[next%marcos_cant] = cadena[i];
        next = next%marcos_cant + 1;
    }

    return faultPage;
}


bool LRU::isThere(int *frames,int marcos_cant,int val)
{
    bool state = false;
    for(int i = 0; i<marcos_cant;i++)
    {
        if(frames[i]==val)
        {
            state = true;
            break;
        }
    }
    return state;
}
