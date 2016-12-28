#include <iostream>
#include "BankImplement.h"
#include "LRU.h"
#include "MMU.h"

using namespace std;

int main()
{
//    BankImplement bank;
//    bank.run();
//    bank.spawn_client();

    LRU lru;
    int cadena[20] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    cout<<"LRU: "<<lru.getFaultPage(cadena, 20, 3)<<endl;

    MMU *mmu;

    //asignacion continua
    mmu = new AsignacionContinua(100,500);
    cout<<"asignacion continua: "<<mmu->getRealAddress(150)<<endl;
    delete mmu;

    //Segmentacion
    segment_table table;
    table.data_base = 100;
    table.data_limit = 250;
    table.code_base = 400;
    table.code_limit = 100;
    table.heap_base = 500;
    table.heap_limit = 700;
    mmu = new Segmentacion(&table);
    cout<<"segmentacion: "<<mmu->getRealAddress(600)<<endl;
    delete mmu;

    //paginacion
    unsigned int *pages[5];
    pages[0] = new unsigned int[15];
    pages[0][0] = 250;
    mmu = new Paginacion(pages);
    cout<<"Paginacion: "<<mmu->getRealAddress(15)<<endl;
    delete mmu;

    return 0;
}
