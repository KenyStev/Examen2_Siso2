#ifndef LRU_H
#define LRU_H


class LRU
{
    public:
        LRU();

        int getFaultPage(int *cadena, int size, int marcos_cant);
        bool isThere(int *frames,int marcos_cant,int val);
        virtual ~LRU();
    protected:
    private:
};

#endif // LRU_H
