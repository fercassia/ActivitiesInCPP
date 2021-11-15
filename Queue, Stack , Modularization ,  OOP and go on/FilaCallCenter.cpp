#include<iostream>
#include<conio.h>

using namespace std;

const int MAXQUEUE = 3;

struct ClientsInformations//Informações dos clientes
{
    char clientName[100];
    char cpf[11];
    int birthDay;
    int monthOfBirth;
    int yearOfBirth;
    char reasonForTheCall[120];
};

class CallCenterQueue
{
private:
    ClientsInformations Client[MAXQUEUE];
    int FinalQueue, BeginningQueue, HowMany;
public:
    CallCenterQueue();
    int EmptyQueue();
    int FullQueue();
    int QueueSize();
    void Queuing(ClientsInformations &AClient);//No inicio
    void SearchingClientInformation(ClientsInformations &AClient);//No meio
    void Dequeuing(ClientsInformations &AClient);//Do Fim
    void PritingQueue(ClientsInformations &AClient);
};

CallCenterQueue :: CallCenterQueue() //Construtor padrão
{   FinalQueue = BeginningQueue = HowMany = 0;   }

int CallCenterQueue :: EmptyQueue()
{   return (HowMany == 0);   }

int CallCenterQueue :: FullQueue()
{   return (HowMany == MAXQUEUE);   }

int CallCenterQueue :: QueueSize()
{   return (HowMany);   }

void CallCenterQueue  ::  Queuing(ClientsInformations &AClient)
{
    if(FullQueue())
    {
        cout<<"Hello attendant, I'm Cassia! The Queue IS FULL\n";
        getch();
    }
    else
    {
        Client[FinalQueue] = AClient;
        cout<<"Client "<<Client[FinalQueue].clientName<<" Added in the queue!\n";
        HowMany++;
        FinalQueue = (FinalQueue+1) % MAXQUEUE;
        cout<<"\nQueue updated!!\n Now have a number of "<<HowMany<<" client(s) waiting be attended to";
        getch();
    }
    return;
}

void CallCenterQueue  ::  SearchingClientInformation(ClientsInformations &AClient)
{
    if(EmptyQueue())
    {
        cout<<"Hello attendant, I'm Cassia! There is no client information, because the queue is empty\n";
        getch();
    }
    else
    {
        cout<<"\n\t\t\t CLIENT INFORMATION";

        cout<<"\nName: "<< Client[BeginningQueue].clientName;

        cout<<"\nCPF: "<< Client[BeginningQueue].cpf;

        cout<<"\nBirthday: "<<Client[BeginningQueue].birthDay<<"/"<< Client[BeginningQueue].monthOfBirth<<"/"<<Client[BeginningQueue].yearOfBirth;

        cout<<"\nReason for The call: "<< Client[BeginningQueue].reasonForTheCall;

        cout<<"\n\t\t\t ATENTION!!\nAfter the service, you MUST leave and REMOVE the client from the QUEUE!!"<<endl;
        cout<<"\n\t\t\t ATENTION!!\nIf you not do that, you will be searching for the information from the same client!!"<<endl;
        getch();
    }
    return;
}

void CallCenterQueue  ::  Dequeuing(ClientsInformations &AClient)
{
    if(EmptyQueue())
    {
        cout<<"Hello attendant, I'm Cassia! The Queue IS EMPTY";
        getch();
    }
    else
    {
        AClient = Client[BeginningQueue];
        cout<<"Client "<<Client[BeginningQueue].clientName<<" removed from the queue!\n";
        HowMany--;
        BeginningQueue = (BeginningQueue+1) % MAXQUEUE;
        cout<<"Queue updated!\nNow have a number of "<<(HowMany)<<" client(s) waiting be attended to";
        getch();
    }
    return;
}

void CallCenterQueue  ::  PritingQueue(ClientsInformations &AClient)
{
    cout<<"Queue: ";
    for(int aux = BeginningQueue; aux < FinalQueue; aux++)
    {
        cout<<Client[aux].clientName<<" | ";
    }
    getch();
    return;
}
//***********************************************************************************************************************************************
int main()
{
    CallCenterQueue activitiesList;
    ClientsInformations feedingClientInformations[MAXQUEUE];
    int userOption, contador = 0;

    if(contador > MAXQUEUE)
    {
        contador = 0;
    }

    do{
        system("cls");
        cout<<"\n\t\t\tCALLCENTER"
            <<"\n\nDigite opcao: "
            <<"\n\n1-Queue: "
            <<"\n\n2-Search for client information: "
            <<"\n\n3-Unqueue: "
            <<"\n\n4-Priting: "<<endl;
            cin>> userOption;
            if(userOption == 1)
            {

                cout<<"\nType name's client: ";
                cin>>feedingClientInformations[contador].clientName;

                cout<<"\nType cpf's client: ";
                cin>>feedingClientInformations[contador].cpf;

                cout<<"\nType Birth Day's client: ";
                cin>>feedingClientInformations[contador].birthDay;

                cout<<"\nType Month day's client: ";
                cin>>feedingClientInformations[contador].monthOfBirth;

                cout<<"\nType year day's client: ";
                cin>>feedingClientInformations[contador].yearOfBirth;

                cout<<"\nType Reason to call of client: ";
                cin>>feedingClientInformations[contador].reasonForTheCall;

                cout<<"\n_____________________________________________________";
                activitiesList.Queuing(feedingClientInformations[contador]);
            }
            if(userOption == 2)
            {
                activitiesList.SearchingClientInformation(feedingClientInformations[contador]);
            }
            if(userOption == 3)
            {
                activitiesList.Dequeuing(feedingClientInformations[contador]);
            }
            if(userOption == 4)
            {
                activitiesList.PritingQueue(feedingClientInformations[contador]);
            }
            contador++;
    }while(userOption >= 1 && userOption <= 4);
    return 0;
}
