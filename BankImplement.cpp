#include "BankImplement.h"

BankImplement::BankImplement()
{
    srand(time(NULL));
}

BankImplement::~BankImplement()
{
    //dtor
}

void BankImplement::spawn_client()
{
    int next_client = 0;
    thread *new_client;
    while(true)
    {
        int time_sleep = rand()%(Z_spawn) + Y_spawn;
        usleep(time_sleep);
        new_client = new thread(&BankImplement::cliente,this,next_client);
        printf("Nuevo Cliente quiere entrar: %d\n",next_client++);
        fflush(stdout);

        if(this->clientes_activos < M_PERSONAS)
        {
            this->clients[this->clientes_activos] = new_client;
            this->clientes_activos++;
        }
        else{
            printf("Banck lleno cliente %d se fue\n",next_client);
            fflush(stdout);

//            break;
        }
    }
}

void BankImplement::cajero(int index)
{
    while(true)
    {
        this->clients_en_fila_sem->wait();
    }
}

void BankImplement::cliente(int num_cliente)
{
    if(this->clientes_activos<M_PERSONAS)
    {
        printf("Cliente %d esperando en fila\n",num_cliente);
        fflush(stdout);
//        this->cajeros_sem->signal();
        this->clients_en_fila_sem->signal();
        this->clients_atender_sem->wait();
        printf("Cliente %d fue atendido\n",num_cliente);
        fflush(stdout);
    }
    printf("Cliente %d se fue\n",num_cliente);
}

void BankImplement::run()
{

}
