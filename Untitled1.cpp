#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class Noh
{
	private:
		
    public:
    char dado;
    Noh *next;
    Noh()
    {
        next=0;
    }
    Noh(char nDado, Noh* nNext=0){

        dado=nDado;
        next=nNext;
    }

};

class Pilha
{
    private:
        Noh *Head;

    public:
        Pilha()
        {
            Head=0;
        }

        bool PiVazia();
        
        void Push(char);
        void Pop();
        int tamPilha();
        char nElementos();

};

bool Pilha::PiVazia()
{
    return (Head==0);
}

void Pilha::Pop()
{
    if(PiVazia()!=true)
    {
        char dado = Head->dado;
        Noh *tmp = Head;
        Head = Head->next;
        delete tmp;
    }
}
char Pilha::nElementos()
{
    if(!PiVazia())
	{
    	return Head->dado;
    }
}

void Pilha::Push(char v)
{
      if(PiVazia())
	  {
        Noh *novo = new Noh(v);
        novo->next=Head;
        Head=novo;
      }else
	  {
        Noh *tmp = new Noh(v);
        tmp->next=Head;
        Head=tmp;
      }
}


int main ()
{
    Pilha sub;
    int wok;
    
	cin >> wok;
    
	while(wok--)
    {
    char carac;
    char arr[400];
    
	cin >> arr;
    
	int len=strlen(arr);
    
	for(int i=0;i<len;i++)
    {
        if(arr[i]=='(')
             sub.Push(arr[i]);
        else if(arr[i]==')')
             {
                 while(sub.nElementos()!='(')
                 {
                     cout << sub.nElementos();
                     sub.Pop();
                 }
                 sub.Pop();
            }
        else if(arr[i]=='+' || arr[i]=='-' ||arr[i]=='*' ||arr[i]=='/' ||arr[i]=='^' )
              sub.Push(arr[i]);
        else
            cout << arr[i];

    }
    cout << endl;
    }

return 0;
}
