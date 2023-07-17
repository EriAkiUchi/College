//-----------------------------------------------------------------------------------------------------------------
//NOME: PEDRO LOUREIRO MORONE BRANCO VOLPE   TIA: 42131936
//
//NOME: ERIC AKIO UCHIYAMADA                 TIA: 42107865
//
//NOME: Oliver Kieran Galvão McCormack       TIA: 42122058
// 
//-----------------------------------------------------------------------------------------------------------------
//main
#include <iostream>
#include <string>
#include "AVL.h"
#include "Utils.h"

void Insert(AVL* avl)
{
	int num = 0,qtde = 0; float valorUnitario = 0.0;
  std::string nome = "";
	std::cout << "Insert Product Code: ";
	std::cin >> num;
  std::cout << "Insert Product Name: ";
  // std::cin >> nome;
  std::cin.ignore();
  std::getline(std::cin,nome);
   std::cout << "Insert quantity: ";
  std::cin >> qtde;
  std::cout << "Insert value: ";
  std::cin >> valorUnitario;

  Produto data = {num,nome,qtde,valorUnitario};
	NodeAVL* node = avl->Insert(num, data);
	if (node)
		std::cout << "Node inserted!\n";
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";
}

void Remove(AVL* avl)
{
	int num;
	std::cout << "Remove id: ";
	std::cin >> num;
	avl->Remove(num);
}

void Search(AVL* avl)
{
	int num;
	std::cout << "Search id: ";
	std::cin >> num;
	NodeAVL* node = avl->Search(num);
	if (node)
		std::cout << "Node found:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}

void Predecessor(AVL* avl)
{
	int num;
	std::cout << "Find predecessor of: ";
	std::cin >> num;
	NodeAVL* node = avl->Predecessor(num);
	if (node)
		std::cout << "Predecessor of " << num << ":\n" << node->ToString();
	else
		std::cout << "*** ERROR! There is no predecessor of " << num << "!\n";
}

void Successor(AVL* avl)
{
	int num;
	std::cout << "Find successor of: ";
	std::cin >> num;
	NodeAVL* node = avl->Successor(num);
	if (node)
		std::cout << "Successor of " << num << ":\n" << node->ToString();
	else
		std::cout << "*** ERROR! There is no successor of " << num << "!\n";
}

void FindMin(AVL* avl)
{
	NodeAVL* node = avl->FindMin();
	if (node)
		std::cout << "Minimum:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find minimum (tree is probably empty...)\n";
}

void FindMax(AVL* avl)
{
	NodeAVL* node = avl->FindMax();
	if (node)
		std::cout << "Maximum:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find maximum (tree is probably empty...)\n";
}

void TraverseInOrder(AVL* avl)
{
	std::cout << avl->TraverseInOrder() << '\n';
}

void TraversePreOrder(AVL* avl)
{
	std::cout << avl->TraversePreOrder() << '\n';
}

void TraversePostOrder(AVL* avl)
{
	std::cout << avl->TraversePostOrder() << '\n';
}

void Clear(AVL* avl)
{
	avl->Clear();
}

int main()
{

	AVL* avl = new AVL();

	// const int SIZE = 9;
	// int ids[SIZE] = { 5, 4, 3, 1, 2, 6, 7, 9, 8 };
	// for (int i = 0; i < SIZE; ++i)
	// 	avl->Insert(ids[i], std::to_string(ids[i]));

  //DADOS TESTE (SUPERMERCADO)
  //------------------------------------------------
  Produto data = Produto(1,"Suco de Uva",10,6.99);
  avl->Insert(1,data);
  
  data = Produto(2,"Chiclete de Melancia",100,1.99);
  avl->Insert(2,data);
  
  data = Produto(3,"Al Mossar?",1,36.98);
  avl->Insert(3,data);
  
  data = Produto(4,"Coca-Cola Litrão",12,8.99);
  avl->Insert(4,data);
  
  data = Produto(5,"Salgadinho Torcida",50,6.99);
  avl->Insert(5,data);
  
  data = Produto(6,"Pizza Congelada",5,12.99);
  avl->Insert(6,data);
  
  data = Produto(7,"Agua",10000,5.99);
  avl->Insert(7,data);
  
  data = Produto(8,"Pistache",2,100.99);
  avl->Insert(8,data);
  
  data = Produto(9,"Geladinho(chup-chup)",10,4.99);
  avl->Insert(9,data);
  
  data = Produto(10,"Shampoo Men 125 em 1",20,14.99);
  avl->Insert(10,data);
  
  data = Produto(11,"Bombom Garoto",25,9.99);
  avl->Insert(11,data);
  
  data = Produto(12,"Leite Berço",70,18.99);
  avl->Insert(12,data);

  data = Produto(13,"Manteiga na Manteiga",4,14.99);
  avl->Insert(13,data);
  
  data = Produto(14,"Pipoca Doce",21,7.99);
  avl->Insert(14,data);

  data = Produto(15,"Mr. Musculo",15,17.98);
  avl->Insert(15,data);
  //------------------------------------------------
  
	int option = 0;
	do
	{
		std::cout << "*** Menu ***\n"
			<< "[1] Inserir Produto\n"
			<< "[2] Remover Produto\n"
			<< "[3] Search Produto\n"
			<< "[4] Apresenta todos os Produtos\n"
      << "[5] Calcula valor em R$ do produto em Estoque\n"
      << "[6] Calcula valor do Estoque\n"
      << "[7] Mostra Produtos Inferiores\n"
			<< "[8] Clear\n"
			<< "[0] Exit\n"
			<< "Option: ";
    
		std::cin >> option;
		std::cout << '\n';

		switch (option)
		{
		case 1: Insert(avl); break;
		case 2: Remove(avl); break;
		case 3: Search(avl); break;
		case 4: ShowAllProducts(avl); break;
    case 5: ShowProductValueInStock(avl); break;
    case 6: GetTotalStockValue(avl); break;  
		case 7: ShowProductsBelow(avl); break;
		case 8: Clear(avl); break;
		}

		std::cout << '\n';
	} while (option != 0);

	delete avl;
  avl = nullptr;
}
//#endif
