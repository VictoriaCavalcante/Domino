# Domino
Estrutura utilizada: 

Foi utilizada uma lista duplamente encadeada com com os campos info "esquerdo" e "direito" para definir o valor de ambos os lados da peça do dominó, e um info especial denominado "testado" para definir as peças que já foram modificadas na lista para que não sejam novamente modificadas durante as 3 funções que utilizamos para ordenar o jogo. 

Principais funções utilizadas: 

A primeira função de ordenar consiste em verificar se o campo esquerdo do atual primeiro elemento da lista é igual ao campo direito dos próximos elementos, se encontrar um igual ele o transporta para o começo da lista e torna-se o primeiro e continua a verificação fazendo isso em todos os dominós. 

A segunda função compara o campo esquerdo do elemento que no momento é o primeiro da lista com o campo esquerdo dos próximos elementos e se for igual realiza e inversão da peça de dominó e a transporta para o início da lista, bem semelhante a primeira só que dessa vez fazendo outra comparação e invertendo o dominó antes de transportá-lo. 

A terceira função verifica o último caso que é o de apenas precisar inverter a peça. Para isso a variável "testado" foi essencial pois ela nos diz quem ainda não foi utilizada. Nesta função o dominó que não foi "testado" ainda, é selecionado para que aja a comparação entre o elemento anterior (lembrando que a lista é duplamente encadeada para facilitar) de info da direita com o seu da direita e se forem iguais o elemento selecionado (o que está com testado = 0) tem seus campos de esquerda e direita invertidos. 

Como utilizar o código: 

Ao compilar o código o usuário deve entrar com a quantidade de peças que serão utilizadas, e uma estrutura de repetição se encarregará de proporcionar ao usuário que faça a entrada dos números que compõem os dois lados de cada peça, sendo estes de 0 a 6 e não pode haver peças iguais, como por exemplo: (3, 2) e (3, 2) ou (3,2) e (2,3), nesta segunda elas são iguais, visto que as peças de dominó podem ser invertidas. 

O programa dirá se o conjunto dado de peças forma um jogo válido ou não e se o jogo for válido, mostrará a configuração (ordem) das peças. 

Pode-se entrar com no máximo 28 peças e quando não houver mais interesse em realizar outro caso de teste o usuário deverá finalizar o programa fornecendo o valor 0 (zero) na quantidade de peças. 
