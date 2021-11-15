#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>

using namespace std;

const int MAXPilha = 3;

struct Motorista
{
    char nomeMotorista [100];
    char matriculaMotorista [6];
};
struct InformacoesCaminhao//Informações dos clientes
{
    Motorista motoristaCaminhao;
    char modelo[15];
    char cor[10];
    char chassi[15];
    char anoDeFabricacao[4];
};

class CegonhaDeCaminhao
{
private:
    InformacoesCaminhao CaminhaoInfo[MAXPilha];
    int Inicio, Topo, Quantos;
public:
    CegonhaDeCaminhao();
    int PilhaVazia();
    int PilhaCheia();
    int PilhaTamanho();
    int RetornaTopo();
    void CadastrarECarregarCaminhao();//No inicio
    void PesquisarCaminhao(int cont, char nome[100]);//No meio
    void DescarregarCaminhao(InformacoesCaminhao &Caminhao);//Do Fim
    void ImprimirFilaCaminhao(InformacoesCaminhao &Caminhao);
};

CegonhaDeCaminhao :: CegonhaDeCaminhao() //Construtor padrão
{
    Inicio = Topo = Quantos = 0;
}

int CegonhaDeCaminhao :: PilhaVazia()
{
    return (Quantos == 0);
}

int CegonhaDeCaminhao :: PilhaCheia()
{
    return (Quantos == MAXPilha);
}

int CegonhaDeCaminhao :: PilhaTamanho()
{
    return Quantos;
}
int CegonhaDeCaminhao :: RetornaTopo()
{
    return Topo;
}
void CegonhaDeCaminhao  ::  CadastrarECarregarCaminhao()
{
    if(!PilhaCheia())
    {
        cout<<"\nDigite nome do motorista: ";
            fflush(stdin);
        gets(CaminhaoInfo[Topo].motoristaCaminhao.nomeMotorista);

        cout<<"\nDigite matricula do motorista: ";
            fflush(stdin);
        gets(CaminhaoInfo[Topo].motoristaCaminhao.matriculaMotorista);

        cout<<"\nDigite o modelo do caminhao: ";
            fflush(stdin);
        gets(CaminhaoInfo[Topo].modelo);

        cout<<"\nDigite a cor do caminhao: ";
            fflush(stdin);
        gets(CaminhaoInfo[Topo].cor);

        cout<<"\nDigite o chassi do caminhao: ";
            fflush(stdin);
        gets(CaminhaoInfo[Topo].chassi);

        cout<<"\nDigite o ano de fabricacao do caminhao: ";
            fflush(stdin);
        gets(CaminhaoInfo[Topo].anoDeFabricacao);

        cout<<"\nCaminhao cadastrado e vinculado ao motorista com sucesso!\nCaminnhao na Cegonha!";
        Topo++;
        Quantos++;
    }
    return;
}

void CegonhaDeCaminhao  ::  DescarregarCaminhao(InformacoesCaminhao &Caminhao)
{
    if(!PilhaVazia())
    {
        Topo--;
        Caminhao = CaminhaoInfo[Topo];
        Quantos--;
    }
    return;
}

void CegonhaDeCaminhao  ::  PesquisarCaminhao(int cont, char pesquisarNomeMotorista[100])
{
    if(cont >= Inicio)
    {
        if(strcmp(CaminhaoInfo[cont].motoristaCaminhao.nomeMotorista,pesquisarNomeMotorista)== 0)
        {
            cout<<"\n\t\t\t INFORMACAO CAMINHAO";
            cout<<"\nNome Caminhoneiro: "<< CaminhaoInfo[cont].motoristaCaminhao.nomeMotorista;
            cout<<"\nMatricula Caminhoneiro: "<< CaminhaoInfo[cont].motoristaCaminhao.matriculaMotorista;
            cout<<"\nModelo caminhao: "<<CaminhaoInfo[cont].modelo;
            cout<<"\nCor caminhao: "<< CaminhaoInfo[cont].cor;
            cout<<"\nChassi caminhao: "<< CaminhaoInfo[cont].chassi;
            cout<<"\nAno Fabricacao caminhao: "<< CaminhaoInfo[cont].anoDeFabricacao;
        }
        else
        {
            cout<<"\n\t\t\t INFORMACAO CAMINHAO";
            cout<<"\n\t\t\t Informacao nao encontrada!!";
        }

        PesquisarCaminhao(cont-1, pesquisarNomeMotorista);
        return;
    }
}

void CegonhaDeCaminhao  ::  ImprimirFilaCaminhao(InformacoesCaminhao &Caminhao)
{
    cout<<"Pilha de caminhoes: ";
    for(int aux = Topo-1; aux >= Inicio; aux--)
    {
        cout<<CaminhaoInfo[aux].motoristaCaminhao.nomeMotorista<<" - Modelo Caminhao: "<<CaminhaoInfo[aux].modelo<<" || ";
    }
    return;
}
//***********************************************************************************************************************************************
void OpcaoUsuarioCegonha()
{
    CegonhaDeCaminhao gerenciadorDePilhasCegonhaDeCaminhao;
    InformacoesCaminhao iformacoes;
    char pesquisarNome[100];
    int userOption;

    do{
        system("cls");
        cout<<"\n\t\t\tCEGONHA CAMINHOES"
            <<"\n\nEscolha uma das opcoes abaixo: "
            <<"\n\n1-Cadastrar caminhao e empilha-lo"
            <<"\n\n2-Descarregar o caminhao e tira-lo da pilha"
            <<"\n\n3-Pesquisar pelo caminhao e motorista"
            <<"\n\n4-Imprimir a pilha de caminhoes"
            <<"\n\n5-Imprimir a quantos caminhoes estao na fila"
            <<"\n\n6-Sair"
            <<"\n\nDigita a opcao: ";
            cin>> userOption;

            switch(userOption)
            {
                case 1: system("cls");
                    if(gerenciadorDePilhasCegonhaDeCaminhao.PilhaCheia())
                        cout<<"\nOpcao invalida...Pilha CHEIA!";
                    else
                        gerenciadorDePilhasCegonhaDeCaminhao.CadastrarECarregarCaminhao();
                    getch();
                    break;

                case 2: system("cls");
                    if(gerenciadorDePilhasCegonhaDeCaminhao.PilhaVazia())
                        cout<<"\nOpcao invalida...Pilha VAZIA!";
                    else
                        {
                            gerenciadorDePilhasCegonhaDeCaminhao.DescarregarCaminhao(iformacoes);
                            cout<<"\nCaminhao do motorista "<<iformacoes.motoristaCaminhao.nomeMotorista<<" Modelo "<<iformacoes.modelo<<" foi descarregado";
                        }
                    getch();
                    break;

                case 3: system("cls");
                    if(gerenciadorDePilhasCegonhaDeCaminhao.PilhaVazia())
                        cout<<"\nOpcao invalida...Pilha VAZIA!";
                    else
                    {
                        cout<<"\nDigite o nome do motorista que esta vinculado ao caminhao de desejo: ";
                            fflush(stdin);
                        gets(pesquisarNome);
                        gerenciadorDePilhasCegonhaDeCaminhao.PesquisarCaminhao(gerenciadorDePilhasCegonhaDeCaminhao.RetornaTopo()-1,pesquisarNome);
                                                                            //Perguntar ao professor pq - 1 duas vezes;
                    }
                    getch();
                    break;

                case 4: system("cls");
                    if(gerenciadorDePilhasCegonhaDeCaminhao.PilhaVazia())
                        cout<<"\nPilha VAZIA!";
                    else
                        gerenciadorDePilhasCegonhaDeCaminhao.ImprimirFilaCaminhao(iformacoes);
                    getch();
                    break;

                case 5: system("cls");
                    cout<<"Tem "<<gerenciadorDePilhasCegonhaDeCaminhao.PilhaTamanho()<<" Caminhoes na pilha";
                    getch();
                    break;
                case 6: system("cls");
                    cout<<"Ateh mais!";
                    getch();
                    break;

                default:cout<<"\nOpcao invalida, press. qq tecla para continuar ";

                getch();
                break;
            }
    }while(userOption >= 1 && userOption <= 6);
}
//***********************************************************************************************************************************************
int main()
{
    OpcaoUsuarioCegonha();
    return 0;
}
