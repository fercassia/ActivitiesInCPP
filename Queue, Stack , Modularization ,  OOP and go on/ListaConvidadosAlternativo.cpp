#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>

using namespace std;

const int MaxTamanhoLista = 3;

struct InformacoesConvidados
{
	char nomeConvidado[80];
	char telConvidado[14];
	char empresaConvidado[15];
	char cargoConvidado[10];

	bool ePreenchido = false;
};
class ListaConvidados
{
private:
	InformacoesConvidados convidadosInfos[MaxTamanhoLista];
	int Primeiro, Ultimo, Quantos;
public:
	ListaConvidados();

	int Tamanho();
	bool ListaVazia();
	bool ListaCheia();
	int RetornaUltimo();

	void InserirConvidadosNaListaPosicao(int posicao);

	void PesquisarConvidadosPelaPosicao(int posicao);
	void PesquisarConvidadosPeloNome(int cont, char pesquisarNome[80]);

	void ImprimirConvidadosDaLista();

	void PreencheDadosUsuario(int posicao);

	int UltimaPosicaoVazia();
	int UltimaPosicaoPreenchida();

	int NumeroPosicoesVazias();
	int NumeroPosicoesPreenchidas();

	void RemoverConvidadoPorPosicao(int posicao);
	void RemoverConvidadoPorNome(char nomeQueDesejaRetirar[80]);
};

ListaConvidados :: ListaConvidados()
{
	Primeiro = Ultimo = Quantos = 0;
}

int ListaConvidados :: NumeroPosicoesPreenchidas()
{
    int numeroPreenchidas = 0;

    for(int inicio = 0; inicio <= MaxTamanhoLista - 1; inicio++)
    {
        if(convidadosInfos[inicio].ePreenchido)
        {
            numeroPreenchidas++;
        }
    }

    return numeroPreenchidas;
}

int ListaConvidados :: NumeroPosicoesVazias()
{
    int numeroVazias = 0;

    for(int inicio = 0; inicio <= MaxTamanhoLista - 1; inicio++)
    {
        if(!convidadosInfos[inicio].ePreenchido)
        {
            numeroVazias++;
        }
    }

    return numeroVazias;
}

int ListaConvidados :: UltimaPosicaoPreenchida()
{
    int ultimaPreenchida = 0;

    for(int contador = 0; contador <= MaxTamanhoLista - 1; contador++)
    {
        if(convidadosInfos[contador].ePreenchido)
        {
            ultimaPreenchida = contador;
        }
    }

    return ultimaPreenchida;
}

int ListaConvidados :: UltimaPosicaoVazia()
{
    int ultimaVazia = 0;

    for(int contador = 0; contador <= MaxTamanhoLista - 1; contador++)
    {
        if(!convidadosInfos[contador].ePreenchido)
        {
            ultimaVazia = contador;
        }
    }

    return ultimaVazia;
}

bool ListaConvidados :: ListaVazia()
{
	return Primeiro == NumeroPosicoesPreenchidas();
}

bool ListaConvidados :: ListaCheia()
{
	return MaxTamanhoLista == NumeroPosicoesPreenchidas();
}

int ListaConvidados :: Tamanho()
{
	return NumeroPosicoesPreenchidas();
}

int ListaConvidados :: RetornaUltimo()
{
	return UltimaPosicaoPreenchida();
}

void ListaConvidados :: PreencheDadosUsuario(int posicao)
{
    cout<<"\n\nDigite o nome do convidado: ";
        fflush(stdin);
    gets(convidadosInfos[posicao].nomeConvidado);

    cout<<"\n\nDigite o telefone do convidado(Codigo do paihs+ddd+telefone) (ddd e telefone soh numeros): ";
        fflush(stdin);
    gets(convidadosInfos[posicao].telConvidado);

    cout<<"\n\nDigite o nome da empresa do convidado: ";
        fflush(stdin);
    gets(convidadosInfos[posicao].empresaConvidado);

    cout<<"\n\nDigite o cargo do convidado: ";
        fflush(stdin);
    gets(convidadosInfos[posicao].cargoConvidado);

    convidadosInfos[posicao].ePreenchido = true;

    cout<<"\n\nConvidado inserido com sucesso na posicao: "<<posicao;
}

void ListaConvidados :: InserirConvidadosNaListaPosicao(int posicao)
{
    if (NumeroPosicoesPreenchidas() == MaxTamanhoLista)
    {
        cout<<"A lista ja esta cheia. Elemento nao inserido.";
        return;
    }

    if(!convidadosInfos[posicao].ePreenchido)
    {
        cout<<"\n\nSimplesmente inserindo usuario na posicao pois a mesma esta vazia.";
        PreencheDadosUsuario(posicao);
    }
    else if (posicao < UltimaPosicaoVazia())
    {
        cout<<"\n\nEmpurrando elementos para a direita.";
        for (int aux = MaxTamanhoLista - 1; aux >= posicao; aux--)
        {
            convidadosInfos[aux] = convidadosInfos[aux-1];

            if (aux == posicao)
            {
                PreencheDadosUsuario(posicao);
            }
        }
    }
    else if (posicao > UltimaPosicaoVazia())
    {
        cout<<"\n\nEmpurrando elementos para a esquerda.";
        for (int aux = UltimaPosicaoVazia(); aux <= posicao; aux++)
        {
            convidadosInfos[aux] = convidadosInfos[aux+1];

            if (aux == posicao)
            {
                PreencheDadosUsuario(posicao);
            }
        }
    }
    else
    {
        PreencheDadosUsuario(posicao);
    }
}
//_________________________________________________________________________________________________________________________
void ListaConvidados :: PesquisarConvidadosPeloNome(int cont, char pesquisarNome[80])
{
	if(cont >= Primeiro)
	{
		if(strcmp(convidadosInfos[cont].nomeConvidado, pesquisarNome) == 0)
		{
			cout<<"\n\nNome do convidado: "<<convidadosInfos[cont].nomeConvidado;
			cout<<"\n\nTelefone do convidado: "<<convidadosInfos[cont].telConvidado;
			cout<<"\n\nNome da empresa do convidado: "<<convidadosInfos[cont].empresaConvidado;
			cout<<"\n\nCargo do convidado: "<<convidadosInfos[cont].cargoConvidado;
			cout<<"\n\nPosicao da Lista: "<<cont;
		}
		PesquisarConvidadosPeloNome(cont-1, pesquisarNome);
		return;
	}
}
//__________________________________________________________________________________________________________________________
void ListaConvidados :: PesquisarConvidadosPelaPosicao(int posicao)
{
	if(posicao >= Primeiro && convidadosInfos[posicao].ePreenchido)
	{
		cout<<"\n\nNome do convidado: "<<convidadosInfos[posicao].nomeConvidado;
		cout<<"\n\nTelefone do convidado: "<<convidadosInfos[posicao].telConvidado;
		cout<<"\n\nNome da empresa do convidado: "<<convidadosInfos[posicao].empresaConvidado;
		cout<<"\n\nCargo do convidado: "<<convidadosInfos[posicao].cargoConvidado;
	}
	else
    {
        cout<<"Posicao: "<<posicao<<" nao esta preenchia. Impossivel consultar convidado.";
    }
	return;
}

//____________________________________________________________________________________________________________________
void ListaConvidados :: ImprimirConvidadosDaLista()
{
    if(ListaVazia())
	{
		cout<<"Lista Vazia!!";
	}

	for(int aux = Primeiro; aux <= MaxTamanhoLista - 1; aux++)
	{
	    if (convidadosInfos[aux].ePreenchido)
        {
            cout<<"\n\nConvidado da posicao: "<<aux;
            cout<<"\n\nNome do convidado: "<<convidadosInfos[aux].nomeConvidado;
            cout<<"\n\nCargo do convidado: "<<convidadosInfos[aux].cargoConvidado;
            cout<<"\n\nTelefone do convidado: "<<convidadosInfos[aux].telConvidado;
            cout<<"\n\nNome da empresa do convidado: "<<convidadosInfos[aux].empresaConvidado;
        }
	}
}

//____________________________________________________________________________________________________________________

void ListaConvidados :: RemoverConvidadoPorNome(char nomeQueDesejaRetirar[80])
{
    if(ListaVazia())
	{
		cout<<"Lista Vazia!!\nNenhum convidado removido.";
		return;
	}

	else
	{
	    int aux = 0;
	    for(aux; aux < MaxTamanhoLista; aux++)
        {
            if(aux == MaxTamanhoLista - 1 && strcmp(convidadosInfos[aux].nomeConvidado, nomeQueDesejaRetirar) == 0)
            {
                convidadosInfos[aux].ePreenchido = false;
                cout<<"Usuario removido com sucesso.\n\n";
                return;
            }
            else if (aux == MaxTamanhoLista - 1 && strcmp(convidadosInfos[aux].nomeConvidado, nomeQueDesejaRetirar) != 0)
            {
                convidadosInfos[aux].ePreenchido = false;
                cout<<"Usuario nao foi removido por nao ter sido encontrado na lista de convidados.\n\n";
                return;
            }

            if(strcmp(convidadosInfos[aux].nomeConvidado, nomeQueDesejaRetirar) == 0)
            {
                cout<<"Usuario para remocao encontrado na posicao: "<<aux<<endl;
                return;
            }
        }

	    if (aux == UltimaPosicaoPreenchida())
        {
            convidadosInfos[aux].ePreenchido = false;
            cout<<"Usuario removido com sucesso.\n\n";
            return;
        }
        else if (UltimaPosicaoPreenchida() - 1 > aux)
        {
            int pos = aux;
            for(pos; pos <= UltimaPosicaoPreenchida() - 1; pos++)
            {
                if (pos == UltimaPosicaoPreenchida() - 1)
                {
                    convidadosInfos[pos].ePreenchido = false;
                    break;
                }

                convidadosInfos[pos] = convidadosInfos[pos+1];
            }
        }

        return;
	}
}
//____________________________________________________________________________________________________________________
void ListaConvidados :: RemoverConvidadoPorPosicao(int posicao)
{
    if(ListaVazia())
	{
		cout<<"Lista Vazia!!\nNenhum convidado removido.";
		return;
	}

    if(convidadosInfos[posicao].ePreenchido == false)
    {
        cout<<"Nao existe nenhum conviado preenchido na posicao: "<<posicao<<". Convidado nao removido.";
		return;
    }

	else if (posicao == MaxTamanhoLista - 1 || posicao == UltimaPosicaoPreenchida() - 1)
    {
        convidadosInfos[posicao].ePreenchido = false;
    }
    else if (UltimaPosicaoPreenchida() - 1 > posicao)
    {
        int pos = posicao;
        for(pos; pos <= UltimaPosicaoPreenchida() - 1; pos++)
        {
            if (pos == UltimaPosicaoPreenchida() - 1)
            {
                convidadosInfos[pos].ePreenchido = false;
                break;
            }

            convidadosInfos[pos] = convidadosInfos[pos+1];
        }
    }
    return;
}

//____________________________________________________________________________________________________________________

void OpcoesParaLista()
{
	ListaConvidados gerenciadorDaLista;
	InformacoesConvidados infoConvidado;
	int posicao;
	int opcaoDeEscolha;
	char nomeDoConvidado[80];

	do{
		system("cls");
		cout<<"\t\t\t\nGERENCIADOR LISTA DE CONVIDADOS"<<endl;
		cout<<"\n\n1- Inserir nome de convidado por posicao"
            <<"\n\n2- Pesquisar convidado por nome"
			<<"\n\n3- Pesquisar convidado por posicao"
			<<"\n\n4- Imprimir lista de convidados"
			<<"\n\n5- Remover convidado por nome"
			<<"\n\n6- Remover convidado por posicao"
			<<"\n\n7- Imprimir quantas pessoas ha na lista"
			<<"\n\n8- Sair"
			<<"\n\nDigite a opcao que deseja: ";
            cin>>opcaoDeEscolha;
		switch(opcaoDeEscolha)
		{
			case 1: system("cls");
                cout<<"\n\n Insira a posicao que deseja inserir o convidado(se a lista estiver vazia, ele sera o primeiro da lista): ";
                cin>>posicao;

                if(posicao >= MaxTamanhoLista)
                {
                    cout<<"\nComando Invalido\nA maior posicao aceitavel na lista e: "<<MaxTamanhoLista-1;
                }
                else
                {
                    gerenciadorDaLista.InserirConvidadosNaListaPosicao(posicao);
                    cout<<"\n\nOperacao executada com sucesso!"<<endl;
                }
            getch();
            break;

			case 2: system("cls");
                cout<<"\n\n Insira o nome do convidado que deseja pesquisar: ";
                    fflush(stdin);
                gets(nomeDoConvidado);

                gerenciadorDaLista.PesquisarConvidadosPeloNome(gerenciadorDaLista.RetornaUltimo()-1, nomeDoConvidado);

                getch();
                break;

			case 3: system("cls");
                if(gerenciadorDaLista.ListaVazia())
                {
                    cout<<"Lista Vazia";
                }
                else
                {
                    if(posicao > MaxTamanhoLista-1)
                    {
                        cout<<"Comando invalido!";
                    }
                    else
                    {
                        cout<<"\n\n1- Insira a posicao que deseja pesquisar: ";
                        cin>>posicao;
                        gerenciadorDaLista.PesquisarConvidadosPelaPosicao(posicao);
                    }
                }
                getch();
                break;

			case 4:system("cls");
                gerenciadorDaLista.ImprimirConvidadosDaLista();

                getch();
                break;

			case 5: system("cls");
                cout<<"\n\n1- Insira o nome do convidado que deseja retirar da lista: ";
                    fflush(stdin);
                gets(nomeDoConvidado);

                gerenciadorDaLista.RemoverConvidadoPorNome(nomeDoConvidado);

                getch();
                break;

			case 6: system("cls");
                cout<<"\n\nInsira a posicao do conviado que deseja remover: ";
                cin>>posicao;

                if(posicao >= MaxTamanhoLista)
                {
                    cout<<"\nComando Invalido\nA maior posicao aceitavel para remocao da lista e: "<<MaxTamanhoLista-1;
                }else
                {
                    gerenciadorDaLista.RemoverConvidadoPorPosicao(posicao);
                    cout<<"\n\nOperacao executada com sucesso!"<<endl;
                }

                getch();
                break;

			case 7: system("cls");
                cout<<"Na lista ha "<<gerenciadorDaLista.NumeroPosicoesPreenchidas()<<" convidados.";

                getch();
                break;

            case 8: system("cls");
                cout<<"\nAté mais";

                getch();
                break;
            default:
                cout<<"\nComando Invalido";
                getch();
		}
	}while(opcaoDeEscolha >= 1 && opcaoDeEscolha <= 8);
}

int main()
{
	OpcoesParaLista();

	return 0;
}
