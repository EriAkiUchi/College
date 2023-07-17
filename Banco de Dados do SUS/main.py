#Aluno: Eric Akio Uchiyamada       TIA: 42107865

dados = []
Vazio = ''
sintomas = []
idade = []

meu_arquivo = open('SUS-Covid.txt', 'r')

while True:
    linha = meu_arquivo.readline().rstrip()
    if linha == Vazio:
        break
    else:
        dados.append(linha)

pessoas = len(dados) - 1 


for i in range(len(dados)):
    info = dados[i].split(";")

    sintomas.append(info[0])


def homens():
    global homem
    homem = 0
    for i in range(len(dados)):
        info = dados[i].split(";")
    
        if info[5] == "Masculino":
            homem += 1
    return homem


def mulheres():
    global mulher
    mulher = 0
    for i in range(len(dados)):
        info = dados[i].split(";")
    
        if info[5] == "Feminino":
            mulher += 1
    return mulher

def positivo():
    global covidado
    covidado = 0

    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[4] == "Positivo":
            covidado += 1

    return covidado    


def homemPositivo():
    hcovidado = 0
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[4] == "Positivo" and info[5] == "Masculino":
            hcovidado += 1
    return hcovidado

def mulherPositivo():
    mcovidado = 0
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[4] == "Positivo" and info[5] == "Feminino":
            mcovidado += 1
    return mcovidado

def rt_pcr():
    rt = 0
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[3] == "RT-PCR":
            rt += 1
    return rt

def anticorpo():
    anti = 0
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[3] == "TESTE RÁPIDO - ANTICORPO":
            anti += 1
    return anti

def assintomatico():
    global assinto
    assinto = 0
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[0] == "Assintomático":
            assinto += 1
    return assinto

def febre():
    febre = 0
    for i in range(len(sintomas)):
       
        if sintomas[i] == 'Febre':
            febre += 1
    return febre

def dor_cabeca():
    cabeca = 0
    for i in range(len(sintomas)):

        if sintomas[i] == 'Dor de Cabeça':
            cabeca += 1
    return cabeca

def dor_garganta():
    garganta = 0
    for i in range(len(sintomas)):

        if sintomas[i] == 'Dor de Garganta':
            garganta += 1
    return garganta

def velhas():
    pimba = 0
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[0] == 'Assintomático' and info[5] == 'Feminino' and int(info[8]) > 50:
            pimba += 1
    return pimba

def velhos():
    pimba = 0
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[0] == 'Assintomático' and info[5] == 'Masculino' and int(info[8]) > 50:
            pimba += 1
    return pimba

def jovens():
    pimba = 0
    for j in range(1,20):
        idade.append(str(j))
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[0] != 'Assintomático' and info[8] in idade:
            pimba += 1
    return pimba

def sao_paulo():
    sp = 0
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[7] == 'São Paulo' and info[0] != 'Assintomático':
            sp += 1
    return sp

def dracena():
    drac = 0
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[7] == 'Dracena' and info[5] == 'Feminino' and info[0] != 'Assintomático':
            drac += 1
    return drac

def Bauru():
    bau = 0
    for i in range(len(dados)):
        info = dados[i].split(";")

        if info[7] == 'Bauru' and info[5] == 'Masculino' and info[0] != 'Assintomático' and int(info[8]) > 50:
            bau += 1
    return bau
def main():
    print(pessoas,"pessoas fizeram teste")

    porc_homem = (homens()/pessoas)*100
    print(f'{homens()} homens\n{porc_homem:.2f}%')

    porc_mulher = (mulheres()/pessoas)*100
    print(f'{mulheres()} mulheres\n{porc_mulher:.2f}%')

    print(positivo(),"pessoas testaram positivo para Covid19")

    porc_homemCovidado = (homemPositivo()/pessoas)*100
    print(f'{homemPositivo()} homens positivos\n{porc_homemCovidado:.2f}%')

    porc_mulherCovidado = (mulherPositivo()/pessoas)*100
    print(f'{mulherPositivo()} mulheres positivos\n{porc_mulherCovidado:.2f}%')

    porc_rt = (rt_pcr()/pessoas)*100
    print(f'{rt_pcr()} testes RT-PCR foram feitos\n{porc_rt:.2f}%')

    porc_anti = (anticorpo()/pessoas)*100
    print(f'{anticorpo()} testes anticorpo foram feitos\n{porc_anti:.2f}%')

    porc_assintomatico = (assintomatico()/pessoas)*100
    print(f'{assintomatico()} pessoas estão assintomáticas \n{porc_assintomatico:.2f}%')

    porc_febre = (febre()/pessoas)*100
    print(f'{febre()} pessoas apresentaram febre \n{porc_febre:.2f}%')

    porc_cabeca = (dor_cabeca()/pessoas)*100
    print(f'{dor_cabeca()} pessoas apresentaram dor de cabeça\n{porc_cabeca:.2f}%')

    porc_garganta = (dor_garganta()/pessoas)*100
    print(f'{dor_garganta()} pessoas apresentam dor de garganta\n{porc_garganta:.2f}%')

    porc_velhas = (velhas()/pessoas)*100
    print(f'{velhas()} mulheres acima de 50 anos estão assintomáticas\n{porc_velhas:.2f}%')

    porc_velhos = (velhos()/pessoas)*100
    print(f'{velhos()} homens acima de 50 anos estão assintomáticos\n{porc_velhos:.2f}%')

    porc_jovens = (jovens()/pessoas)*100
    print(f'{jovens()} pessoas abaixo de 20 anos estão sintomáticas\n{porc_jovens:.2f}%')

    porc_sp = (sao_paulo()/pessoas)*100
    print(f'{sao_paulo()} pessoas estão sintomáticas no município de São Paulo\n{porc_sp:.2f}%')

    porc_dracena = (dracena()/pessoas)*100
    print(f'{dracena()} mulheres estão sintomáticas no município de Dracena\n{porc_dracena:.2f}%')

    porc_bauru = (Bauru()/pessoas)*100
    print(f'{Bauru()} homens acima de 50 anos estão sintomáticos no município de bauru\n{porc_bauru:.2f}%')

main()

meu_arquivo.close()
    






