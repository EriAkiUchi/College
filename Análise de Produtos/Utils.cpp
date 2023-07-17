//-----------------------------------------------------------------------------------------------------------------
//NOME: PEDRO LOUREIRO MORONE BRANCO VOLPE   TIA: 42131936
//
//NOME: ERIC AKIO UCHIYAMADA                 TIA: 42107865
//
//NOME: Oliver Kieran Galvão McCormack       TIA: 42122058
// 
//-----------------------------------------------------------------------------------------------------------------
#include "Utils.h"
#include <iostream>
#include <sstream>
#include <string>

void ShowAllProducts(AVL *tree) 
{
  NodeAVL *root = tree->GetRoot();
  
  std::cout << ShowAllProductsInternal(root) << '\n';
}

std::string ShowAllProductsInternal(const NodeAVL* node) 
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << ShowAllProductsInternal(node->GetLeft());
    oss << "------------------------------"
        << "\nCode: "     << node->GetID()
		    << "\nName: "     << node->GetData().GetName()
        << "\nQuantity: " << node->GetData().GetQtde()
        << "\nValue: "    << node->GetData().GetValorUnitario()
        << "\n";
		oss << ShowAllProductsInternal(node->GetRight());
		return oss.str();
	}

	//return "null ";
	return "";
}

void ShowProductsBelow(AVL *tree)
{
  NodeAVL *root = tree->GetRoot();
  int num;
  std::cout << "Digite um nº para mostrar os produtos cuja\nquantidade em estoque seja menor que o nº: ";
  std::cin >> num;
  std::cout << "\n" <<ShowProductsBelowInternal(root, num) << "\n";
}

std::string ShowProductsBelowInternal(const NodeAVL *node,int num)
{
  if(node != nullptr)
  {
    std::ostringstream oss;
    if(node->GetData().GetQtde() < num)
    {
      oss << "------------------------------"
        << "\nCode: "     << node->GetID()
		    << "\nName: "     << node->GetData().GetName()
        << "\nQuantity: " << node->GetData().GetQtde()
        << "\nValue: "    << node->GetData().GetValorUnitario()
        << "\n";
    }
    oss << ShowProductsBelowInternal(node->GetLeft(), num);
    oss << ShowProductsBelowInternal(node->GetRight(), num);
    return oss.str();
  }
  return "";
}

void ShowProductValueInStock(AVL* tree)
{
  NodeAVL *root = tree->GetRoot();
  std::string nome; float total;
  std::cout << "Digite um produto para calcular o valor total em estoque: ";
  std::cin.ignore();
  std::getline(std::cin,nome);
  ShowProductValueInStockInternal(root,nome);
}

void ShowProductValueInStockInternal(const NodeAVL *node, std::string nome)
{
  if(node != nullptr)
  {
    ShowProductValueInStockInternal(node->GetLeft(), nome);
    if(node->GetData().GetName() == nome)
    {
      std::ostringstream oss;
      oss << "\nCode: "     << node->GetID()
		    << "\nName: "     << node->GetData().GetName()
        << "\nQuantity: " << node->GetData().GetQtde()
        << "\nValue: "    << node->GetData().GetValorUnitario()
        << "\n";
      std::string produto = oss.str();
      float total = (node->GetData().GetQtde()) * (node->GetData().GetValorUnitario());
      std::cout << produto;
      std::cout << "\nO valor total em estoque é R$" << total << std::endl;
    }
    ShowProductValueInStockInternal(node->GetRight(), nome);
  }  
  return;
}

void GetTotalStockValue(AVL *tree)
{
  NodeAVL *root = tree->GetRoot();
  float total = 0.0;
  GetTotalStockValueInternal(root,total);
  std::cout << "Valor total de estoque: R$" << total << "\n";
}

void GetTotalStockValueInternal(const NodeAVL *node, float &total)
{
  if(node != nullptr)
  {
    GetTotalStockValueInternal(node->GetLeft(), total);
    total += (node->GetData().GetQtde()) * (node->GetData().GetValorUnitario());
    GetTotalStockValueInternal(node->GetRight(), total);
  }  
}