import random

tag = input('Digite a tag dos arquivos (exemplo: "2" para cidades2.txt)')
qtd_cidades = int(input('Quantidade de cidades '))

arquivo_cidades = 'dataset/cidades' + str(tag) + '.txt'

with open(arquivo_cidades, 'w') as fhandle:
    fhandle.write(str(qtd_cidades)+'\n')

    for i in range(0, qtd_cidades):
        fhandle.write('{0:.5f} {1:.5f}\n'.format(
            random.uniform(-90,90),
            random.uniform(-180,180)
        ))
