#include <stdio.h>

//Ramificação da arvore para acessar todos as 'folhas'
int TamMax(int esq ,int dir)
{
    return esq > dir ? esq : dir;
}

// str que tem limite 1000 posicoes
char str[10001];
int indice;

//recursividade: aqui onde a ramificação vai ser chamada
int tamanho()
{
        if (str[indice++] =='l')
        {
            return 1;
        }else
        {

            return TamMax(tamanho(),tamanho())+1;

        }
}

int main()
{
        int folha;
        scanf("%d",&folha);
        while (folha--)
        {
                scanf("%s", str);
                indice=0;
                printf("%d\n",tamanho() - 1);
        }
        return 0;
}
