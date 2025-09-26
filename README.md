# Detective Quest — Mapa da Mansão (Árvore Binária em C)

Simulação do mapa da mansão utilizando **árvore binária**. O jogador inicia no **Hall de entrada** e pode escolher seguir **esquerda (e)** ou **direita (d)** em cada cômodo até alcançar um **nó-folha** (sem caminhos).

## Requisitos
- Compilador C (GCC/Clang) com suporte a C99

## Compilação
```bash
gcc -std=c99 -O2 -Wall -Wextra -o detective_quest main.c
```

## Execução
```bash
./detective_quest
```

## Controles
- `e` — seguir para a esquerda
- `d` — seguir para a direita
- `s` — sair

## Estrutura do mapa (fixa no código)
```
               Hall de entrada
                 /           \
          Sala de estar      Cozinha
           /         \       /     \
   Biblioteca    Escritório  Despensa Jardim
```

## Arquivos
- `main.c` — código-fonte (sem blocos de comentários em cinza; apenas o código)
- `README.md` — instruções de uso

Curadoria de TI — Enigma Studios
