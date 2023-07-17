#Eric Akio Uchiyamada 42107865
import pygame
import sys
import os
pygame.init()

screen = pygame.display.set_mode((800,600))

pygame.display.set_caption("Jogo da Velha")

bright_cyan = (224,255,255)
black = (0,0,0)
screen.fill(bright_cyan)

fonte = pygame.font.SysFont("comicsansms", 25)
fraseTexto = fonte.render("Jogo da Velha", True, black)

folder = "velha"
tabuleiro = pygame.image.load(os.path.join(folder,"tabuleiro.jpg"))

letra_x = pygame.image.load(os.path.join(folder,"letra_x.jpg"))
circulo = pygame.image.load(os.path.join(folder, "circulo.png"))

altura_x, largura_x = letra_x.get_rect().size
letra_x = pygame.transform.scale(letra_x,(int(altura_x//6),int(largura_x//8)))

altura_cir, largura_cir = circulo.get_rect().size
circulo = pygame.transform.scale(circulo,(int(altura_cir//3),int(largura_cir//3)))


x,y = 100, 100
screen.blit(fraseTexto, [350,10])
screen.blit(tabuleiro, (x,y))

pygame.display.flip()
player = True
matriz = [[2,2,2],[2,2,2],[2,2,2]]
def verifica(matriz):
    for i in range(len(matriz)):
        player1_l, player1_c, player2_l, player2_c = 0,0,0,0
        for j in range(len(matriz)):
            if matriz[i][j] == 1:
                player1_l += 1
            if matriz[j][i] == 1:
                player1_c += 1
            if matriz[i][j] == 0:
                player2_l += 1
            if matriz[j][i] == 0:
                player2_c += 1
        if player1_l == 3 or player1_c == 3:
            return 1
        if player2_l == 3 or player2_c == 3:
            return 2
    player1_dp, player1_ds, player2_dp, player2_ds = 0,0,0,0
    for i in range(len(matriz)):
        for j in range(len(matriz)):
            if i == j:
                if matriz[i][i] == 1:
                    player1_dp += 1
                if matriz[i][i] == 0:
                    player2_dp += 1
            if i+j == 2:
                if matriz[i][j] == 1:
                    player1_ds += 1
                if matriz[i][j] == 0:
                    player2_ds += 1
    if player1_dp == 3 or player1_ds == 3:
        return 1
    if player2_dp == 3 or player2_ds == 3:
        return 2
    return -1
cont = 0
while True:
    vencedor = verifica(matriz)
    if vencedor == 1:
        print("Player 1 venceu!")
    elif vencedor == 2:
        print("Player 2 venceu!")
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.MOUSEMOTION:
            x = pygame.mouse.get_pos()[0]
            y = pygame.mouse.get_pos()[1]
            print("Mouse movendo X:",x)
            print("Mouse movendo Y:",y)
        if event.type == pygame.MOUSEBUTTONDOWN:
            #linha e coluna 1
            if x >= 115 and x <= 200 and y >= 115 and y <= 200:
                if player == True and vencedor == -1:    
                    screen.blit(circulo, (115,115))
                    player = False
                    matriz[0][0] = 1
                    cont += 1
                elif player == False and vencedor == -1:
                    screen.blit(letra_x, (115,115))
                    player = True
                    matriz[0][0] = 0
                    cont += 1
            #linha 1 e coluna 2
            if x >= 200 and x <= 287 and y >= 115 and y <= 200:
                if player == True and vencedor == -1:    
                    screen.blit(circulo, (200,115))
                    player = False
                    matriz[0][1] = 1
                    cont += 1
                elif player == False and vencedor == -1:
                    screen.blit(letra_x, (200,115))
                    player = True
                    matriz[0][1] = 0
                    cont += 1
            #linha 1 e coluna 3
            if x >= 289 and x <= 374 and y >= 115 and y <= 200:
                if player == True and vencedor == -1:    
                    screen.blit(circulo, (289,115))
                    player = False
                    matriz[0][2] = 1
                    cont += 1
                elif player == False and vencedor == -1:
                    screen.blit(letra_x, (289,115))
                    player = True
                    matriz[0][2] = 0
                    cont += 1
            #linha 2 e coluna 1
            if x >= 115 and x <= 200 and y >= 203 and y <= 283:
                if player == True and vencedor == -1:    
                    screen.blit(circulo, (115,203))
                    player = False
                    matriz[1][0] = 1
                    cont += 1
                elif player == False and vencedor == -1:
                    screen.blit(letra_x, (115,203))
                    player = True
                    matriz[1][0] = 0
                    cont += 1
            #linha 2 e coluna 2
            if x >= 200 and x <= 287 and y >= 203 and y <= 283:
                if player == True and vencedor == -1:    
                    screen.blit(circulo, (200,203))
                    player = False
                    matriz[1][1] = 1
                    cont += 1
                elif player == False and vencedor == -1:
                    screen.blit(letra_x, (200,203))
                    player = True
                    matriz[1][1] = 0
                    cont += 1
            #linha 2 e coluna 3
            if x >= 289 and x <= 374 and y >= 203 and y <= 283:
                if player == True and vencedor == -1:    
                    screen.blit(circulo, (289,203))
                    player = False
                    matriz[1][2] = 1
                    cont += 1
                elif player == False and vencedor == -1:
                    screen.blit(letra_x, (289,203))
                    player = True
                    matriz[1][2] = 0
                    cont += 1 
            #linha 3 e coluna 1
            if x >= 115 and x <= 200 and y >= 290 and y <= 374:
                if player == True and vencedor == -1:    
                    screen.blit(circulo, (115,290))
                    player = False
                    matriz[2][0] = 1
                    cont += 1
                elif player == False and vencedor == -1:
                    screen.blit(letra_x, (115,290))
                    player = True
                    matriz[2][0] = 0
                    cont += 1
            #linha 3 e coluna 2
            if x >= 200 and x <= 287 and y >= 290 and y <= 374:
                if player == True and vencedor == -1:    
                    screen.blit(circulo, (200,290))
                    player = False
                    matriz[2][1] = 1
                    cont += 1
                elif player == False and vencedor == -1:
                    screen.blit(letra_x, (200,290))
                    player = True
                    matriz[2][1] = 0
                    cont += 1
            #linha 3 e coluna 3
            if x >= 289 and x <= 374 and y >= 290 and y <= 374:
                if player == True and vencedor == -1:    
                    screen.blit(circulo, (289,290))
                    player = False
                    matriz[2][2] = 1
                    cont += 1
                elif player == False and vencedor == -1:
                    screen.blit(letra_x, (289,290))
                    player = True
                    matriz[2][2] = 0
                    cont += 1
    if cont == 9:
        print("Empatou!")
    pygame.display.update()

#pygame.quit()

