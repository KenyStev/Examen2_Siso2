#ifndef BANKIMPLEMENT_H
#define BANKIMPLEMENT_H

#define N_CAJEROS 5
#define M_PERSONAS 10
#define X_tiempo_de_atencion 10
#define Y_spawn 3
#define Z_spawn 6

#include <thread>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "Semaphore.h"

using namespace std;

class BankImplement
{
    public:
        int cajeros_activos = 0;
        int clientes_activos = 0;
        Semaphore *clients_en_fila_sem = new Sem(M_PERSONAS);
        Semaphore *clients_atender_sem = new Sem(N_CAJEROS);
        Semaphore *cajeros_sem = new Sem(0);

        thread *cajeros[N_CAJEROS];
        thread *clients[M_PERSONAS];

        BankImplement();
        void spawn_client();
        void cajero(int index);
        void cliente(int num_cliente);
        void run();

        virtual ~BankImplement();
    protected:
};

#endif // BANKIMPLEMENT_H
