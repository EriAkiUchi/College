import random
#simulador de batalha naval
def geraMatriz():
    M = []
    for i in range(10):
        linha = []
        for j in range(10):
            linha.append(' . ')
        M.append(linha)

    tabuleiro = []
    for i in range(len(M)):
        linha = []
        if i == 0:
            linha.append('')
            for l in range(1,len(M)):
                linha.append('  '+str(l))
        else:
            linha.append(str(i))
            for l in range(len(M)):
                linha.append(M[i][l])
        tabuleiro.append(linha)
    return tabuleiro

def imprimeMatriz(M):
    for i in range(len(M)):
        for k in range(len(M[0])):
            print(M[i][k], end=' ')
        print()


def embarcacao(M,e,linha,coluna,vertical,l):
    verifica = 0
    if vertical == 0:
        if coluna <= (len(M[0])-e):
            c = coluna
            for j in range(e):
                if M[linha][c] == ' . ':
                    verifica += 1
                c += 1
            c = coluna
            if verifica == e:
                for i in range(e):
                    M[linha][c] = l
                    c += 1
                return M, True
    else:
        if linha <= (len(M)-e):    
            c = linha
            for k in range(e):
                if M[c][coluna] == ' . ':
                    verifica += 1
                c += 1
            c = linha
            if verifica == e:
                for i in range(e):
                    M[c][coluna] = l
                    c += 1
                return M, True
    return M, False

def atirar(M,T,x,y,a):
    if M[x][y] == ' . ':
        print('Acertou na água.')
        M[x][y] = ' o '
        T[x][y] = ' o '
    elif M[x][y] == ' o ' or M[x][y] == ' X ':
        print('Você já tentou atirar nesta coordenada. Tente outra coordenada.')
        return M, T, a
    elif M[x][y] == ' P ':
        print('Acertou o porta-aviões!')
        M[x][y] = ' X '
        T[x][y] = ' X '
    elif M[x][y] == ' E ':
        print('Acertou o encouraçado!')
        M[x][y] = ' X '
        T[x][y] = ' X '
    elif M[x][y] == ' C ':
        print('Acertou o cruzeiro!')
        M[x][y] = ' X '
        T[x][y] = ' X '
    elif M[x][y] == ' S ':
        print('Acertou o submarino!')
        M[x][y] = ' X '
        T[x][y] = ' X '
    return M, T, a-1

def main():
    M = geraMatriz()
    T = geraMatriz()
    c = 2
    print('''
     ______   _______ _________ _______  _                 _______    _        _______           _______  _       
    (  ___ \ (  ___  )\__   __/(  ___  )( \      |\     /|(  ___  )  ( (    /|(  ___  )|\     /|(  ___  )( \      
    | (   ) )| (   ) |   ) (   | (   ) || (      | )   ( || (   ) |  |  \  ( || (   ) || )   ( || (   ) || (      
    | (__/ / | (___) |   | |   | (___) || |      | (___) || (___) |  |   \ | || (___) || |   | || (___) || |      
    |  __ (  |  ___  |   | |   |  ___  || |      |  ___  ||  ___  |  | (\ \) ||  ___  |( (   ) )|  ___  || |      
    | (  \ \ | (   ) |   | |   | (   ) || |      | (   ) || (   ) |  | | \   || (   ) | \ \_/ / | (   ) || |      
    | )___) )| )   ( |   | |   | )   ( || (____/\| )   ( || )   ( |  | )  \  || )   ( |  \   /  | )   ( || (____/|
    |/ \___/ |/     \|   )_(   |/     \|(_______/|/     \||/     \|  |/    )_)|/     \|   \_/   |/     \|(_______/
                                                                                                              
    ''')
    while c <= 5:
        
        if c == 2:
            l = ' S '
        elif c == 3:
            l = ' C '
        elif c == 4:
            l = ' E '
        else:
            l = ' P '

        linha = random.randint(1,9)
        coluna = random.randint(1,9)
        vertical = random.randint(0,1)

        BN, flag = embarcacao(M,c,linha,coluna,vertical,l)

        if flag == True:
            c += 1
        else:
            print('reposicionando............')
    #imprimeMatriz(BN)
    tentativas = 30
    while tentativas > 0:
        p,e,c,s = 0,0,0,0
        print(f'Você tem {tentativas} tentativas restantes.')
        x = int(input('Digite uma coordenada x de 1 até 9 para atirar:\n'))
        y = int(input('Digite uma coordenada y de 1 até 9 para atirar:\n'))
        BN,T,tentativas = atirar(BN,T,x,y,tentativas)
        for i in range(len(M)):
            for j in range(len(M[0])):
                if BN[i][j] == ' P ':
                    p += 1
                elif BN[i][j] == ' E ':
                    e += 1
                elif BN[i][j] == ' C ':
                    c += 1
                elif BN[i][j] == ' S ':
                    s += 1
        if p == 0 and e == 0 and c == 0 and s == 0:
            print('Você acertou todas as embarcações!')
            break
        imprimeMatriz(T)
    print('Resultado final:')
    imprimeMatriz(BN)
main()
