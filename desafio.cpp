#include <iostream>
#include <cstring>
//Eric Akio Uchiyamada  TIA:42107865

int *AumentarArray(int *array,int *array_aux,int n,int novo_tam) //funcao para aumentar o tamanho do vetor
{
    size_t tam = novo_tam;//definir novo tamanho do vetor
    array_aux = new int[tam];//alocar vetor com o novo tamanho
 
    memcpy(array_aux,array,n*sizeof(int));//copiar os elementos de um vetor para o novo vetor

    delete[] array;
    array = array_aux;//array aponta para o novo vetor

    return array;
}

int main()
{
    int n = 0,j = 0,novo_tam = 0;
    char aumentar = 's';    
    bool flag = true;
    std::cout << "Informe o tamanho do array: ";
    std::cin >> n;//tamanho do vetor inicial
    int *array = new int[n];//vetor inicial
    int *array_aux = 0;//vetor auxiliar


    for(int i = 0;i < n;i++)//iniciar o vetor com valores -1
        array[i] = -1;
    
    while(flag)
    {   
        std::cout << "Informe um numero positivo para o elemento " << j << ": ";
        std::cin >> array[j];
        if(array[j] < 0)//verificar se o valor inserido é negativo
        {
            array[j] = -1;
            flag = false;//encerrar programa
        }
        if(array[j] >= 0 && j == n-1)//se limite do vetor for atingido
        {
            std::cout << "O limite do array foi atingido. Deseja aumentar o tamanho do array? (S/N) ";
            std::cin >> aumentar;
            if(toupper(aumentar) == 'S')//caso de aumentar o vetor
            {   
                std::cout << "Informe o novo tamanho do vetor: ";
                std::cin >> novo_tam;
                if(novo_tam > n)//se o novo tamanho eh menor que o tamanho original
                {
                    array = AumentarArray(array,array_aux,n,novo_tam);
                    n = novo_tam;
                    for(int k = j+1;k < n;k++)//inserir -1 nos novos espaços
                        array[k] = -1;
                }
                else//se o novo tamanho eh menor ou igual ao tamanho original
                {
                    std::cout << "O tamanho do novo array não pode ser menor ou igual ao atual.\n";
                    flag = false;
                }
            }
            else//caso de nao aumentar o vetor
                flag = false;   
        }    
        j++;
    }
    std::cout << "Encerrando..." << std::endl;
    for(int l = 0;l < n;l++)//imprimir os elementos do vetor
        std::cout << "array[" << l << "]: " << array[l] << std::endl;

    delete[] array_aux;
    array = nullptr;
}

/*
REFERENCIAS:

  - aula de ponteiros e alocação dinâmica

  - https://cplusplus.com/forum/general/11111/

  - https://cplusplus.com/reference/cstring/memcpy/

  - https://cplusplus.com/reference/cstring/size_t/

  
*/