//-----------------------------------------------------------------------------------------------------------------
//NOME: PEDRO LOUREIRO MORONE BRANCO VOLPE   TIA: 42131936
//
//NOME: ERIC AKIO UCHIYAMADA                 TIA: 42107865
//
//NOME: Oliver Kieran Galvão McCormack       TIA: 42122058
// 
//-----------------------------------------------------------------------------------------------------------------
// Utils.h
#ifndef __UTILS_H__
#define __UTILS_H__

#include "AVL.h"
#include "Produto.h"

namespace Utils
{
	template <typename T>
	static T Max(T l, T r)
	{
		return (l > r) ? l : r;
	}
}

void ShowAllProducts(AVL *tree);
std::string ShowAllProductsInternal(const NodeAVL* node);

void ShowProductsBelow(AVL *tree);
std::string ShowProductsBelowInternal(const NodeAVL *node,int num);

void ShowProductValueInStock(AVL* tree);
void ShowProductValueInStockInternal(const NodeAVL *node, std::string nome);

void GetTotalStockValue(AVL *tree);
void GetTotalStockValueInternal(const NodeAVL *node, float &total);

#endif