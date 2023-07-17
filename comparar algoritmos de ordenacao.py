import random
import time

def geraVetor(v):
    for i in range(len(v)):
        v[i] = random.randint(1,100)
    return v

def bubbleSort(v):
    comp = 0
    trocas = 0
    for k in range(len(v)):
        for i in range(len(v)-1-k):
            comp += 1
            if v[i] > v[i+1]:
                aux = v[i]
                v[i] = v[i+1]
                v[i+1] = aux
                trocas += 1
    return v, comp, trocas

def insertSort(v):
    comp = 0
    trocas = 0
    for i in range(1,len(v)):
        x = v[i]
        j = i-1
        trocas += 1
        while j >= 0 and x < v[j]:
            v[j+1] = v[j]
            j -= 1
            comp += 1
        v[j+1] = x
    return v, comp, trocas

def selectionSort(v):
    comp = 0
    trocas = 0
    for i in range(len(v)):
        min = i
        for j in range(i+1,len(v)):
            comp += 1
            if v[min] > v[j]:
                min = j
        aux = v[i]
        v[i] = [min]
        v[min] = aux
        trocas += 1
    return v,comp,trocas

def main():
    n = int(input('Digite o tamanho do vetor:\n'))
    vet = [0]*n
    vet = geraVetor(vet)
    v1 = list(vet)
    v2 = list(vet)
    v3 = list(vet)

    ini = time.time()
    v1, comp1, trocas1 = bubbleSort(v1)
    fim = time.time()
    t_bubble = fim - ini

    ini = time.time()
    v2, comp2, trocas2 = insertSort(v2)
    fim = time.time()
    t_insert = fim - ini

    ini = time.time()
    v3, comp3, trocas3 = selectionSort(v3)
    fim = time.time()
    t_selection = fim - ini

    #print(f'vetor ordenado bubbleSort: {v1}')
    print(f'tempo para bubbleSort: {t_bubble} ms')
    print(f'comparações em bubbleSort: {comp1}')
    print(f'movimentações em bubbleSort: {trocas1} ')
    print()
    #print(f'vetor ordenado insertSort: {v2}')
    print(f'tempo para insertionSort: {t_insert} ms')
    print(f'comparações em insertionSort: {comp2}')
    print(f'movimentações em insertionSort: {trocas2}')
    print()
    #print(f'vetor ordenado selectionSort: {v3}')
    print(f'tempo para selectionSort: {t_selection} ms')
    print(f'comparações em selectionSort: {comp3}')
    print(f'movimentações em selectionSort: {trocas3}')

    print(f'Algoritmo       |       Tempo(ms)           |      Comparações      |       Movimentações      ')
    print(f'BubbleSort      |       {t_bubble:.8f}          |       {comp1}           |            {trocas1}       ')
    print(f'InsertionSort   |       {t_insert:.8f}          |       {comp2}             |          {trocas2}       ')
    print(f'SelectionSort   |       {t_selection:.8f}           |       {comp3}             |       {trocas3}       ')
    print('\nInsertSort é o mais eficiente por ter menos comparações comparado com os outros dois métodos de ordenação e menor número de comparações comparado a BubbleSort.\nSelectionSort pode ter um tempo menor, mas a diferença é imperceptível para o sentido humano.')
main()
