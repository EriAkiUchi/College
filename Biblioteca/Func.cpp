// ERIC AKIO UCHIYAMADA ------ TIA: 42107865 ----- TURMA: 03D
// PEDRO L M B VOLPE --------- TIA: 42131936 ----- TURMA: 03D
// LAURA F ABI DAUD ---------- TIA: 42118816 ----- TURMA: 03D
// OLIVER K G MCCORMACK ------ TIA: 42122058 ----- TURMA: 03D
//--------------------------------------------------------------------------------------------------    

#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
//--------------------------------------------------------------------------------------------------    
#include "DoublyCircularLinkedList.h"
#include "Utils.h"
#include "Func.h"
//--------------------------------------------------------------------------------------------------   

#define SAFE_DELETE(ptr) { if(ptr) { delete ptr; ptr = nullptr; }}

//--------------------------------------------------------------------------------------------------    

// FUNÇÃO AUXILIAR PARA SALVAR OS DADOS INFORMADOS PELO USUARIO EM UMA STRUCT {DATA} 
Data SaveData(Data database, std::string data, int count){//inserir dados na lista
  switch (count) {
    case 1:
      database.Disciplina = data;
      break;
    case 2:
      database.Isbn = data;
      break;
    case 3:
      database.Titulo = data;
      break;
    case 4:
      database.Autor = data;
      break;
    case 5:
      database.Edicao = GetIntFromString(data);  // converte o daddo para inteiro
      break;
    case 6:
      database.Cidade = data;
      break;
    case 7:
      database.Editora = data;
      break;
    case 8:
      database.Ano = GetIntFromString(data); // converte o daddo para inteiro
      break;
    case 9:
      database.Bibliografia = GetBoolFromString(data); // converte o daddo para booleano
      break;
  }
  return database;
}
//--------------------------------------------------------------------------------------------------    

// FUNÇÃO PARA LER O ARQUIVO E SALVAR SEU CONTEUDO NA LISTA ENCADEADA
void ReadArchive(LinkedList* list){// ler o arquivo caso 1
  std::ifstream ifs;
	std::string str;
  try{
		  // Tenta abrir o arquivo "bibliografia.csv".
		    ifs.open("bibliografia.csv");
    
		    if (ifs.is_open()){ // Lê a primeira linha do arquivo e salva o conteúdo na string str.
		    
			    std::getline(ifs, str);
          
          while(std::getline(ifs,str)){ //ler o resto do arquivo
            Data database;
      
            std::istringstream iss(str);
	          std::string data;
            int count = 1;
          
            while (std::getline(iss, data, ';')){ //ler a linha
              database = SaveData(database,data,count);
              count++;                      
            } 
            //Adiciona linha do CSV na linkedlist
            Append(list, database); 
          } // end while
			    ifs.close();// Fecha o arquivo.
		    } // end if 
	    } // end try
	    catch (...) {
        
	    }
}
//--------------------------------------------------------------------------------------------------    

// FUNÇÃO PARA INPRIMIR O CONTEUDO DA LISTA ENCADEADA CARREGADA (ITEM 1) 
void Print(const LinkedList* list)//caso 2
{
 // Percorrer todos os nós da lista (do início ao fim)
 // e imprimir as informações de cada nó.
   if (IsEmpty(list))
   {
      std::cout << "Lista vazia!\n\n";
   }
   else
   {
    Node *node = list->head;
    std::cout << "Lista com " << Count(list) <<  " elementos: \n"; 
    for(int i = 0;i < list->count;i++) {
      std::string bibliografia = (node->dados.Bibliografia == true) ? "S" : "N";
      //imprimir cada dado do livro:
      std::cout << "\n\nDados do livro [" << i+1 << "]:" <<       
                   "\nDiciplina: " << node->dados.Disciplina <<
                   "\nISBN: " << node->dados.Isbn << 
                   "\nTitulo: " << node->dados.Titulo <<
                   "\nAutor: " << node->dados.Autor <<
                   "\nEdicao: " << node->dados.Edicao <<
                   "\nCidade: " << node->dados.Cidade <<
                   "\nEditora: " << node->dados.Editora <<
                   "\nAno: " << node->dados.Ano <<
                   "\nBibliografia: " << bibliografia << std::endl;
      node = node->next;
    }//end for
     std::cout << "\n\n";
  }
}
//--------------------------------------------------------------------------------------------------    

// FUNÇÃO PARA ESCREVER O CONTEUDO DA LISTA ENCADEADA NO ARQUIVO CSV (SOBREESCREVENDO-O)
bool WriteStringToFile(LinkedList* list, const std::string& filename)//sobrescrever o arquivo
{
	std::ofstream ofs;
  
	try
	{
    ofs.open(filename, std::ios::out);
    
		if (ofs.is_open())
		{
      std::string line = "Disciplina;ISBN;T�tulo;Autor;Edi�o;Cidade;Editora;Ano;Bibliografia b�sica";
      Node* node = list->head;
      ofs << line << std::endl;//inserir a primeira linha
      
      for(int i = 0; i < list->count; i++){ //Sobreescreve o arquivo ate toda a lista encadeada ser armazenada
        std::string bibliografia = (node->dados.Bibliografia == true) ? "S" : "N";
        std::string edicao = std::to_string(node->dados.Edicao);
        std::string ano = std::to_string(node->dados.Ano);
        line = node->dados.Disciplina + ";" 
          + node->dados.Isbn + ";" 
          + node->dados.Titulo + ";" 
          + node->dados.Autor + ";" 
          + edicao + ";" 
          + node->dados.Cidade + ";" 
          + node->dados.Editora + ";" 
          + ano + ";" 
          + bibliografia;
        ofs << line << std::endl;//inserir cada linha
        node = node->next; //proximo nó
      }// end for
      
			ofs.close();

			return true;
		}
	}
	catch (...)	{
	}
  
	return false;
}
//--------------------------------------------------------------------------------------------------    

// INSERE UM NOVO LIVRO NA LISTA ENCADEADA (DADOS INFORMADOS PELO USUARIO)
void InsertBook(LinkedList* list){//Inserir livro
  
  Data database; int i = 0; std::string data;
  std::string coluns[] = {"Disciplina","ISBN","Titulo","Autor","Edicao","Cidade", "Editora","Ano","Bibliografia"};  
  
  for(int i = 0; i < 9; i++){
    if(i != 8) 
    std::cout << "Digite o dado da coluna [" << coluns[i] << "] a ser inserido: \n"; 
    else
      std::cout << "Digite o dado da coluna [" << coluns[i] << "] a ser inserido(bibliografia deve ser 'S' ou 'N'): \n";
    
    std::getline(std::cin, data);
    database = SaveData(database, data, i+1);//salvar dado no nó
  }
  Append(list, database); //Insere o dado na lista encadeada
}
//--------------------------------------------------------------------------------------------------    

// REMOVE UM LIVRO DA LISTA ENCADEADA COM BASE NO ISBN OU NO TITULO DO LIVRO
bool RemoveBook(LinkedList* list){//Remover livro
  if(IsEmpty(list)) {
    std::cout << "Lista vazia!\n";
    return false; 
  }
  
  std::string data;
  std::cout << "Digite o ISBN ou Titulo do livro a ser removido:" << std::endl;
  std::getline(std::cin,data);
  
  Node* node = RemoveNode(list, data); // Encontra o nó a ser removido
  if (node == nullptr) {
    std::cout << "Livro não está presente no arquivo\n";
    return false;
  }
  std::cout << "Livro removido: \n" << node->dados.Titulo << "\n\n";
  SAFE_DELETE(node); //Deleta o espaço alocado pelo nó removido
  return true;
  
}
//--------------------------------------------------------------------------------------------------    

// CONTA QUANTOS LIVROS BRASILEIROS E ESTRANGEIROS TEM NA LISTA ENCADEADA E SUA MEDIA
bool CountBook(LinkedList* list){//Ver quais livros são brasileiros e estrangeiros
  if(IsEmpty(list)) {
    std::cout << "Lista vazia!\n";
    return false; 
  }
  
  float brasileiro = 0;//contador de livros brasileiros
  float estrangeiro = 0;//contador de livros estrangeiros
  Node* node = list->head;  
  for (int i = 0; i < list->count; i++){    
    if((node->dados.Isbn[4] == '8') && (node->dados.Isbn[5] == '5')) { brasileiro++; }
    else { estrangeiro++; }
    node = node->next;
  }
  float count = list->count;
  float br = (brasileiro/count)*100;//porcentagem de livros brasileiros
  float est = (estrangeiro/count)*100;//porcentagem de livros estrangeiros
  std::cout << "Quantidade de livros: \n" << list->count
            << "\nQuantidade de livros brasileiros: " << brasileiro
            << "\nPorcentagem: " << br << "%" 
            << "\nQuantidade de livros estrangeiros: " << estrangeiro
            << "\nPorcentagem: " << est << "%\n";
  
  return true;
}
//--------------------------------------------------------------------------------------------------    

// Obter a quantidade de livros com bibliografia publicados entre os anos de 2002 e 2010, e a respectiva porcentagem
bool BooksBetween2002_2010(LinkedList* list)
{
  if(IsEmpty(list)) {
    std::cout << "Lista vazia!\n";
    return false; 
  }
  
  int count = 0;//contador de livros dentro do intervalo
  float total = list->count;
  Node *node = list->head;
  for(int i = 0;i < list->count;i++)
  {
    if((node->dados.Ano > 2002) && (node->dados.Ano < 2010))
      count++;
    node = node->next;  
  }
  float c = count;
  float porcentagem = (c/total)*100;//porcentagem de livros dentro do intervalo
  std::cout << "Quantidade de livros publicados entre 2002 e 2010:\n" << count
            << "\nPorcentagem:\n" << porcentagem << "%\n";
  
  return true;
}
//--------------------------------------------------------------------------------------------------    

// Obter o nome, data de publicação e a idade de um dos livros mais antigo e um dos livros mais recentes, e obter a media da idade destes livros
bool BooksAges(LinkedList* list)
{
  if(IsEmpty(list)) {
    std::cout << "Lista vazia!\n";
    return false; 
  }
  Node* node = list->head;
  Data maisVelho; maisVelho.Ano = node->dados.Ano;//determinar o livro mais velho
  Data maisNovo; maisNovo.Ano = node->dados.Ano;//determinar o livro mais novo
  
  for (int i = 0; i < list->count; i++){
    if (node->dados.Ano < maisVelho.Ano)
      maisVelho = node->dados;
    if (node->dados.Ano > maisNovo.Ano)
      maisNovo = node->dados;      
    node = node->next;
  }  

  // Pega o ano atual
  std::time_t t = std::time(nullptr);
  std::tm *const ano = std::localtime(&t);
  int ano_f = ano->tm_year + 1900;
  
  float idadeVelho = ano_f - maisVelho.Ano;
  float idadeNovo = ano_f - maisNovo.Ano;
  float media = (idadeVelho+idadeNovo)/2;//media das idades
  std::cout << "Livro mais antigo: " << maisVelho.Titulo << 
               "\nPublicado em: " << maisVelho.Ano << 
               "\nCuja idade considerando a data atual é: " << idadeVelho << 
               "\n\nLivro mais recente: " << maisNovo.Titulo << 
               "\nPublicado em: " << maisNovo.Ano << 
               "\nCuja idade considerando a data atual é: " << idadeNovo << 
               "\n\nCujas médias de idade entre ambos os livros é de: " << media << " anos\n" << std::endl;
  
  return true;
}
//--------------------------------------------------------------------------------------------------    
