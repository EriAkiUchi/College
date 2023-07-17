#include <stdio.h>
#include <stdlib.h>
//exercício de multiplicação de matrizes
int **alocar_matriz(int linhas,int colunas)
{
	int **a,i,j,k;
	
	a = (int **) calloc(linhas,sizeof(int*));
	for(i = 0;i < linhas;i++)
	{
		a[i] = (int *) calloc(colunas, sizeof(int));
	}
	
	for(j = 0;j < linhas;j++)
	{
		for(k = 0;k < colunas;k++)
		{
			printf("Digite um numero para colocar na matriz: ");
			scanf("%d",&a[j][k]);
		}
	}
	return a;
}

void multiplica_matriz(int **A,int **B,int**C,int linhasA,int colunasA,int linhasB,int colunasB)
{
    int acumulador;
    for(int i = 0;i < linhasA;i++)
    {   
        for(int j = 0;j < colunasB;j++)
        {
            C[i][j] = 0;
            for(int k = 0;k < linhasB;k++)
            {
                acumulador += A[i][k] * B[k][j];
            }
            C[i][j] = acumulador;
            acumulador = 0;
        }
    
    }   
}

int main()
{
	int linhasA = 2,colunasA = 3,linhasB = 3,colunasB = 1,**A,**B,**C;

	A = alocar_matriz(linhasA,colunasA);
	printf("\n");
	B = alocar_matriz(linhasB,colunasB);
	printf("\n");
	C = alocar_matriz(linhasA,colunasB);
	printf("\n");

	multiplica_matriz(A,B,C,linhasA,colunasA,linhasB,colunasB);

	for(int i = 0;i < linhasA;i++)
	{
		for(int j = 0;j < colunasB;j++)
		{
			printf("matriz[%d][%d] = %d\n",i,j,C[i][j]);
		}
  	}


  	for(int k = 0;k < linhasA;k++)
		free(A[k]);
	
	free(A);
	for(int l = 0;l < linhasB;l++)
		free(B[l]);
	
	free(B);
	for(int m = 0;m < linhasA;m++)
		free(C[m]);
	
	free(C);
}
