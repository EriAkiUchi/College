#transformar numero decimal em binario
def binarioInterativo(n):
    lista = []
    bin = ''
    while n != 0:
        lista.append(n % 2)
        n = n // 2 
        
    for i in range(len(lista)-1,-1,-1):
        bin += str(lista[i])
    return bin
def binarioRecursivo(n):
    if n == 0:
        return ''
    else:
        return str(binarioRecursivo(n//2)) + str(n%2)

def main():
    n = int(input("Digite um número decimal inteiro:\n"))
    #print(binarioInterativo(n))
    print(binarioRecursivo(n))
main()
