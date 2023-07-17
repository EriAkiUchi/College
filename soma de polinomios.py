def grauFuncao():
    z = int(input("Insira o grau do polinômio: "))
    z += 1
    return z

def coeficientes(poli1):
    print("Insira os coeficientes dos termos: ")
    for i in range(len(poli1)-1, -1, -1):
        poli1[i] = int(input())
    return poli1

def geraPoli(poli1):
    polinomio = ''
    for i in range(len(poli1)-1, 0, -1):
        if poli1[i] < 0:
            polinomio += str(poli1[i]) + "x" + "^" + str(i) + " "
        elif poli1[i] > 0:
            polinomio += "+" + str(poli1[i]) + "x" + "^" + str(i) + " "
        else:
            polinomio = polinomio
    if poli1[0] < 0:
        polinomio += str(poli1[0])
    elif poli1[0] > 0:
        polinomio += "+" + str(poli1[0])
    return polinomio

def calculoPoli(poli1,x):
    calculo = 0
    for i in range(len(poli1)-1, -1, -1):
        calculo += (poli1[i] *(x**i))
    calculo_p = '' + str(calculo)
    return calculo_p

def somaPoli(poli1,poli2):

    poli3 = [0]*10
    
    if len(poli1) > len(poli2):
        for i in range(len(poli2)-1,-1,-1):
            poli3[i] = poli1[i] + poli2[i]
        for i in range(len(poli1)-1,len(poli2)-1,-1):
            poli3[i] = poli1[i] 

    if len(poli2) > len(poli1):
        for i in range(len(poli1)-1,-1,-1):
            poli3[i] = poli1[i] + poli2[i]
        for i in range(len(poli2)-1,len(poli1)-1,-1):
            poli3[i] = poli2[i]
    
    if len(poli1) == len(poli2):
        for i in range(len(poli2)-1,-1,-1):
            poli3[i] = poli1[i] + poli2[i]

    soma = ''
    for i in range(len(poli3)-1, 0, -1):
        if poli3[i] < 0:
            soma += str(poli3[i]) + "x" + "^" + str(i) + " "
        elif poli3[i] > 0:
            soma += "+" + str(poli3[i]) + "x" + "^" + str(i) + " "
        else:
            soma = soma
    if poli3[0] < 0:
        soma += str(poli3[0])
    elif poli3[0] > 0:
        soma += "+" + str(poli3[0])

    return soma 

def main():
    grau1 = grauFuncao()
    grau2 = grauFuncao()
    poli1 = [0]*grau1
    poli2 = [0]*grau2
    coeficientes(poli1)
    print(f' O primeiro polinômio é: P(x) = {geraPoli(poli1)}')
    x = int(input("Insira o valor de x: "))
    print(f'O resultado é de: {calculoPoli(poli1, x)}')

    coeficientes(poli2)
    print(f'O segundo polinômio é: Q(x) = {geraPoli(poli2)}')
    print(f'A soma dos polinômios é de: S(x) = {somaPoli(poli1,poli2)}')

main()

