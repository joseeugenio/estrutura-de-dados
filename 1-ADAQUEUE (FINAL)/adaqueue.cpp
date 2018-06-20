#include <stdio.h>
#include <iostream>
//#include <stdlib.h>


using namespace std;
class  Noh
{
    public:
        int dado;
        Noh *prox;
        Node()
        {
            prox=NULL;
        }
        Noh(int info, Noh *nProx=NULL )
        {
            dado=info;
            prox=nProx;
        }
};

class Fila{
        int tam;
        Noh *comeco, *fim;
        int tamMax;

    public:
        Fila()
        {
            comeco=fim=NULL;
            tam=0;
            //tamMax = 1000000; //10^6
        }

        //bool negativo();
        int Frente();
        int Back();
        void Reverte();
        void toFrontN(int);
        void Push_BackN(int);
        bool Vazia();
};
/*
bool Noh::Negativo(){
    for(int i=0; i<tam ; i++){
     dado=comeco->dado;
     if(dado<0)
     return false
     else
     return true
    }
}
*/
bool Fila::Vazia()
{
    if(tam == 0)/*cout<<"No job for Ada?\n";*/return true;
    else return false;
}

Fila::Frente()
{
    if(Vazia())
        printf("\n\nNo job for Ada?\n\n");

	int dado;
	dado=comeco->dado;
        cout<<comeco->dado;
        cout<<endl;
        Noh *tmp = comeco;
        comeco = comeco->prox;
        delete tmp;
        tam--;

    //return dados[inicio];
    //inicio= (inicio+1)%tamMax;
    //tam--;
}

Fila::Back()
{
    if(Vazia())
        printf("\n\nNo job for Ada?\n\n");

	int dado;
	dado=fim->dado;
        return fim->dado;// cout<<fim->info;cout<<endl;
        Noh *tmp = fim;
        fim = fim->prox;
        delete tmp;
        tam--;

    //return dados[inicio];
    //inicio= (inicio+1)%tamMax;
    //tam--;
}

void Fila::Push_BackN(int valor)
{
    if(Vazia()){
        //comeco=new Noh(valor);
        //fim= new Noh(valor);
        comeco= fim = new Noh(valor);
    }else
    {
        fim->prox = new Noh(valor);
        fim= fim->prox;
        tam++;
        //return true;
    }

}
void Fila::toFrontN(int valor)
{
    if(Vazia())
    {
        comeco= fim = new Noh(valor);
    }else
    {
        Noh *temp = new Noh(valor);
        temp->prox=comeco;
        comeco=temp;
    }
    tam++;
}

void Fila::Reverte()
{
	int v=tam;
    for(int i=1;i<v;i++)
    {
        int dado;
        dado = comeco->dado;
        Noh *p = comeco;
        comeco = comeco->prox;
        delete p;
        Push_BackN(dado);

    }
}
int main(){

    Fila fila;
    int nElementos, indi;
    string digito;

    cin>>nElementos;
    for(int contador=0;contador<nElementos;contador++)
    {       cin>>digito;

            if(digito=="back")
            {
                fila.Back();
            }
            else if(digito=="front")
            {
                fila.Frente();
            }
            else if (digito=="reverse")
            {
                fila.Reverte();
            }
            else if(digito=="push_back")
            {
                cin>>indi;
                if(indi>=0 && indi <=100)
                {
                    fila.Push_BackN(indi);
                }
            }
            else if(digito=="toFront")
            {   cin>>indi;
                if(indi>=0 && indi <=100)
                {
                    fila.toFrontN(indi);
                }
            }

    }
    return 0;
}
