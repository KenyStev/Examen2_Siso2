#ifndef MMU_H
#define MMU_H
#include <iostream>

using namespace std;

class MMU
{
    public:
        MMU();
        virtual unsigned int getRealAddress(unsigned int logicalAddres) = 0;
        virtual ~MMU();
    protected:
    private:
};

class AsignacionContinua : public MMU
{
    public:
        unsigned int base, limit;
       AsignacionContinua(unsigned int base, unsigned int limite);
       unsigned int getRealAddress(unsigned int logicalAddres);
       virtual ~AsignacionContinua();
};

struct segment_table{
    unsigned int data_base, data_limit;
    unsigned int code_base, code_limit;
    unsigned int heap_base, heap_limit;
};

class Segmentacion : public MMU
{
    public:
       segment_table *ST;
       Segmentacion(segment_table *);
       unsigned int getRealAddress(unsigned int logicalAddres);
       virtual ~Segmentacion();
};

class Paginacion : public MMU
{
    public:
       unsigned int **pages_index;
       Paginacion(unsigned int **);
       unsigned int getRealAddress(unsigned int logicalAddres);
       virtual ~Paginacion();
};

#endif // MMU_H
