//-----------------------------------------------------------------------------------------------------------------
//NOME: PEDRO LOUREIRO MORONE BRANCO VOLPE   TIA: 42131936
//
//NOME: ERIC AKIO UCHIYAMADA                 TIA: 42107865
//
//NOME: Oliver Kieran Galvão McCormack       TIA: 42122058
//-----------------------------------------------------------------------------------------------------------------
//Produto.h
#ifndef __PRODUTO_H__
#define __PRODUTO_H__

#include <string>

class Produto
{
  private:
    int p_codigo;
    std::string p_nome;
    int p_qtde;
    float p_valorUnitario;
  
  public:

    Produto(int codigo, std::string nome,int qtde, float valorUnitario);

    ~Produto();

    int GetCodigo() const;
    void SetCodigo(int codigo);

	  std::string GetName() const;
	  void SetName(std::string nome);

    int GetQtde() const;
    void SetQtde(int qtde);

    float GetValorUnitario() const;
    void SetValorUnitario(float valorUnitario);
};

#endif