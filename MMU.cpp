#include "MMU.h"

MMU::MMU()
{
    //ctor
}

MMU::~MMU()
{
    //dtor
}

AsignacionContinua::AsignacionContinua(unsigned int base, unsigned int limite)
{
    this->base = base;
    this->limit = limite;
}

AsignacionContinua::~AsignacionContinua()
{
    //dtor
}

unsigned int AsignacionContinua::getRealAddress(unsigned int logicalAddres)
{
    if(logicalAddres>=this->base && logicalAddres < (this->base + this->limit))
        return this->base + logicalAddres;
    return 0;
}

Segmentacion::Segmentacion(segment_table *st)
{
    this->ST = st;
}

unsigned int Segmentacion::getRealAddress(unsigned int logicalAddres)
{
    if(logicalAddres >= this->ST->data_base && logicalAddres < (this->ST->data_base + this->ST->data_limit))
    {
        return this->ST->data_base + logicalAddres;
    }
    else if(logicalAddres >= this->ST->code_base && logicalAddres < (this->ST->code_base + this->ST->code_limit))
    {
        return this->ST->code_base + logicalAddres;
    }
    else if(logicalAddres >= this->ST->heap_base && logicalAddres < (this->ST->heap_base + this->ST->heap_limit))
    {
        return this->ST->heap_base + logicalAddres;
    }
    return 0;
}

Segmentacion::~Segmentacion()
{

}

Paginacion::Paginacion(unsigned int **pages)
{
    this->pages_index = pages;
}

Paginacion::~Paginacion()
{

}

unsigned int Paginacion::getRealAddress(unsigned int logicalAddres)
{
    unsigned int first_level = 22 >> logicalAddres;
    unsigned int second_level =(logicalAddres << 10) >> 20;
    unsigned int offset_level = (logicalAddres << 20) >> 20;

    return ((this->pages_index)[first_level])[second_level] + offset_level;
}
