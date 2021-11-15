#include <iostream>

using namespace std;

void carregaVetor(int vetor[], int max)
{
    for(int aux1 = 0; aux1 < max; aux1++)
    {
        cout<<"Informe o " <<aux1+1<<"o. numero: ";
        cin>> vetor[aux1];
    }
}

void mostraListaOriginal(int vetor[], int max)
{
    cout<< "Lista original: \n";

    for(int aux1 = 0; aux1 < max; aux1++)
    {
        cout<<"\t" <<vetor[aux1];
    }
}

void mostraListaSemRepetidos(int vetor[], int max)
{
    int contador = 0;

    cout<< "\n Lista sem repetidos: \n";

    for(int aux1 = 0; aux1 < max; aux1++)
    {
        for(int aux2 = aux1+1; aux2 < max; aux2++)
        {
            if(vetor[aux1] == vetor[aux2])
            {
                contador++;
            }
        }
        if(contador == 0)
        {
            cout<<"\t"<<vetor[aux1];
        }

        contador = 0;
    }
}
int main()
{
    const int max = 5;

    int original[max];

    carregaVetor(original, max);

    mostraListaOriginal(original, max);

    mostraListaSemRepetidos(original, max);

    cout << "\n\n\n" << endl;
    return 0;
}
