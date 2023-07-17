def quicksort(lista, inicio, fim):
    if inicio < fim:
        p = partition(lista, inicio, fim)
        quicksort(lista, inicio, p-1)
        quicksort(lista, p+1, fim)

def partition(lista, inicio, fim):
    i = inicio
    j = fim - 1
    pivot = lista[fim]

    while i < j:
        while i < fim and lista[i] < pivot:
            i += 1
        while j > inicio and lista[j] >= pivot:
            j -= 1
        if i < j:
            lista[i], lista[j] = lista[j], lista[i]
    if lista[i] > pivot:
        lista[i], lista[fim] = lista[fim], lista[i]
    return i

a = [22,11,88,66,55,77,33,44]
quicksort(a,0,len(a)-1)
print(a)
