//-----------------------------------------------------------------------------------------------------------------
//NOME: PEDRO LOUREIRO MORONE BRANCO VOLPE   TIA: 42131936
//
//NOME: ERIC AKIO UCHIYAMADA                 TIA: 42107865
//
//NOME: Oliver Kieran Galvão McCormack       TIA: 42122058
//-----------------------------------------------------------------------------------------------------------------
#include "Produto.h"
#include <string>

Produto::Produto(int codigo,std::string nome, int qtde, float valorUnitario)
	: p_codigo(codigo)
  , p_nome(nome)
  , p_qtde(qtde)
  , p_valorUnitario(valorUnitario)
{
}

Produto::~Produto() { }

int Produto::GetCodigo() const
{
  return p_codigo;
}

void Produto::SetCodigo(int codigo)
{
  p_codigo = codigo;
}
std::string Produto::GetName() const
{
  return p_nome;  
}

void Produto::SetName(std::string nome)
{
  p_nome = nome;
}

int Produto::GetQtde() const
{
  return p_qtde;
}

void Produto::SetQtde(int qtde)
{
  p_qtde = qtde;
}

float Produto::GetValorUnitario() const
{
    return p_valorUnitario;  
}

void Produto::SetValorUnitario(float valorUnitario)
{
  p_valorUnitario = valorUnitario;
}
