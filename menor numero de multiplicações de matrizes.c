//Eric Akio Uchiyamada    42107865
//versão para encontrar a menor quantidade de operações
#include <limits.h>
#include <stdio.h>
//dada as dimensões de certas matrizes, encontrar a ordem que faça menos multiplicações de matrizes
int MatrixChainOrder(int p[], int n)
{
	int m[n][n];
	int i, j, k, L, q;

	// custo é 0 quando multiplica 1 matriz
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L é o tamanho atual da cadeia de matrizes
	for (L = 2; L < n; L++) {
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
        
				if (q < m[i][j])//armazenando o menor valor
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];//menor custo
}

int main()
{
	int arr[] = { 30, 35, 15, 5, 10, 20 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Minimum number of multiplications is %d\n",
		MatrixChainOrder(arr, size));

	return 0;
}
