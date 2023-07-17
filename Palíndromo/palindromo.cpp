#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int TAMANHO_MAXIMO = 100;
struct Pilha
{
    int topo;
    char frase[];
};


bool Push(Pilha& stack,char e);
char Pop(Pilha& stack);
char Top(Pilha& stack);
void Print(Pilha& stack);
Pilha Create();
bool Empty(Pilha& stack);
int Count(Pilha& stack);


int main()
{       
    Pilha stack = Create();
    string entrada;
    cout << "Digite uma palavra ou frase para verificar se é um palíndromo ou não:" << endl;
    cin >> entrada;
    entrada.erase(remove(entrada.begin(),entrada.end(),' '));
    

    for(int i = 0;i < entrada.length();i++)
        Push(stack,entrada[i]);

    cout << "palavra/frase digitada: " << entrada << endl;
    cout << "pilha: " << endl;
    Print(stack);



    return 0;
}

Pilha Create()
{
    Pilha pilha;
    pilha.topo = 0;
    for(int i = 0; i < TAMANHO_MAXIMO;i++)
    {
        pilha.frase[i] = '\0';
    }

    return pilha;
}

bool Push(Pilha& stack,char e)
{
    if (stack.topo == TAMANHO_MAXIMO)
        return false;
    stack.frase[stack.topo] = e;
    stack.topo++;
    return true;
}
char Pop(Pilha& stack)
{
    if(stack.topo == 0)
        return '\0';
    stack.topo--;
    char aux = stack.frase[stack.topo];
    stack.frase[stack.topo] = '\0';
    return aux;
}

char Top(Pilha& stack)
{
    if(stack.topo == 0)
        return '\0';

    return stack.frase[stack.topo-1];
}

void Print(Pilha& stack)
{
    for(int i = stack.topo;i >= 0;i--)
    {
        cout << i << " : " << stack.frase[i] << endl;
    }
}

bool Empty(Pilha& stack)
{
    if(stack.topo == '\0')
        return true;
    return false;
}
int Count(Pilha& stack)
{   
    int count;
    if(Empty(stack) == true)
        return count = 0;
    for(int i = stack.topo-1;i >= 0;i--)
        count++;
    return count;
}