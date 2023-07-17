# Eric Akio Uchiyamada  TIA: 42107865
import random
def populaVetor(vet,n):
    for i in range(len(vet)):
        vet[i] = random.randint(1,n*10)
    vet.sort()
    return vet

def buscaBinária(vet,x):
    cont = 0
    i = 0
    f = len(vet)-1
    while i<=f:
        
        m = (i+f)//2
        if x == vet[m]:
            print(f'quantidade de comparações: {cont}')
            return m
        elif x < vet[m]:
            f = m - 1
        else:
            i = m + 1
        cont += 1
    print(f'quantidade de comparações: {cont}')
    print(f'{x} não foi encontrado no vetor')
    return -1
    
def main():
    n = int(input('Digite um número para ser o tamanho do vetor:\n'))
    vet = [0]*n
    print(populaVetor(vet,n))
    x = int(input('Digite um número inteiro para fazer busca no vetor: \n'))
    print(buscaBinária(vet,x))

main()
