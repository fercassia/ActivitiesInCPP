#include <iostream>
#include <stdlib.h>

using namespace std;

void Swap(int *aux1, int *aux2 ) //Troca de posi��o do maior numero e menor n�mero
{
    int reservaNumero = *aux1;
    *aux1= *aux2;
    *aux2 = reservaNumero;
}
//--------------------------------------------------------------------------
int Particao(int arrayNumeros[], int inicio, int fim) //Parti��o e ordena��o primeiramente
{
    int contadorNumero = inicio;

    int pivot = arrayNumeros[fim];

    for(int aux = inicio; aux < fim; aux++)
    {
        if(arrayNumeros[aux] <= pivot)
        {
            Swap(&arrayNumeros[contadorNumero],&arrayNumeros[aux]);
            contadorNumero++;
        }
    }
    Swap(&arrayNumeros[contadorNumero],&arrayNumeros[fim]); //Trocando de posi��o do pivo para a posi��o central da lista
    return contadorNumero; //Retornando a posi��o do pivot
}
//---------------------------------------------------------------------------
void QuickSort(int arrayNumeros[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int posicao = Particao(arrayNumeros, inicio, fim);//Pegando a posi��o do pivot

        QuickSort(arrayNumeros, inicio, posicao-1);//Subdividindo a lista para esquerda -> menores que o pivot
        QuickSort(arrayNumeros, posicao+1, fim);//Subdividindo a lista para direita -> maiores que o pivot
    }
}

//----------------------------------------------------------------------------------
void PrintArray(int arrayNumeros[], int tamanho)
{
    for(int aux = 0; aux < tamanho; aux++)
    {
        cout<<arrayNumeros[aux]<<" | ";
    }
}

//----------------------------------------------------------------------------
int main()
{
    int arrayTrabalhoNumeros[] = {24,7,19,80,8,4,92,21,1,49};

    int tamanhoArray = sizeof(arrayTrabalhoNumeros)/sizeof(arrayTrabalhoNumeros[0]);

    cout<<"\n\nArray antes de ordenacao: \n";
    PrintArray(arrayTrabalhoNumeros,tamanhoArray);

    QuickSort(arrayTrabalhoNumeros,0,tamanhoArray-1);

    cout<<"\n\nArray ordenada: \n";
    PrintArray(arrayTrabalhoNumeros,tamanhoArray);

    system("pause");
    return 0;
}
