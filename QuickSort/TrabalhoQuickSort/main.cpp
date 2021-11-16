#include <iostream>
#include <stdlib.h>

using namespace std;

void Swap(int *esquerda, int *direita ) //Troca de posição do maior numero e menor número
{
    int reservaNumero = *esquerda;
    *esquerda= *direita;
    *direita = reservaNumero;
}
//--------------------------------------------------------------------------
int Particao(int arrayNumeros[], int inicio, int fim) //Partição e ordenação primeiramente
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
    Swap(&arrayNumeros[contadorNumero],&arrayNumeros[fim]); //Trocando de posição do pivo para a posição central da lista
    return contadorNumero; //Retornando a posição do pivot
}
//---------------------------------------------------------------------------
void QuickSort(int arrayNumeros[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int posicaoPivot = Particao(arrayNumeros, inicio, fim);//Pegando a posição do pivot

        QuickSort(arrayNumeros, inicio, posicaoPivot-1);//Subdividindo a lista para esquerda -> menores que o pivot
        QuickSort(arrayNumeros, posicaoPivot+1, fim);//Subdividindo a lista para direita -> maiores que o pivot
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

    int tamanhoArray = sizeof(arrayTrabalhoNumeros)/sizeof(arrayTrabalhoNumeros[0]);//Tamanho da array

    cout<<"\n\nArray antes de ordenacao: \n";
    PrintArray(arrayTrabalhoNumeros,tamanhoArray);

    QuickSort(arrayTrabalhoNumeros,0,tamanhoArray-1);

    cout<<"\n\nArray ordenada: \n";
    PrintArray(arrayTrabalhoNumeros,tamanhoArray);

    system("pause");
    return 0;
}
