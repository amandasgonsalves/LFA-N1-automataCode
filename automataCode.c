#include <stdio.h>
#include <string.h>

// estados do autÃ´mato
typedef enum {
    retornaBase,
    recarregaBateria,
    desligado,
    ocioso,
    recebeMissao,
    andar,
    N,
    S,
    L,
    O,
    analisaSolo,
    capturaFotoVideo,
    afereTemperatura,
    enviaCentral,
    confirmado
} Estado;

// sÃ­mbolos do alfabeto
typedef enum {
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h,
    i,
    j,
    k,
    l,
    m,
    n,
    o
} Simbolo;

// funÃ§Ã£o que recebe o estado atual e o sÃ­mbolo atual, e retorna o prÃ³ximo estado
Estado proximoEstado(Estado estadoAtual, Simbolo simboloAtual) {
    switch (estadoAtual) {
        case desligado:
            if (simboloAtual == a) {
                return ocioso;
            }
            break;
        case ocioso:
            if (simboloAtual == h) {
                return recebeMissao;
            }
            break;
        case recebeMissao:
            if (simboloAtual == g) {
                return afereTemperatura;
            } else if (simboloAtual == l) {
                return capturaFotoVideo;
            } else if (simboloAtual == m) {
                return analisaSolo;
            } else if (simboloAtual == j) {
                return recarregaBateria;
            } else if (simboloAtual == b) {
                return andar;
            }
            break;
        case andar:
            if (simboloAtual == c) {
                return N;
            } else if (simboloAtual == d) {
                return S;
            } else if (simboloAtual == e) {
                return L;
            } else if (simboloAtual == f) {
                return O;
            } else if (simboloAtual == l) {
                return capturaFotoVideo;
            } else if (simboloAtual == m) {
                return analisaSolo;
            } else if (simboloAtual == g) {
                return afereTemperatura;
            }
            break;
        case N:
            if (simboloAtual == c) {
                return N;
            } else if (simboloAtual == k) {
                return retornaBase;
            }
            break;
        case S:
            if (simboloAtual == d) {
                return S;
            } else if (simboloAtual == k) {
                return retornaBase;
            }
            break;
        case L:
            if (simboloAtual == e) {
                return L;
            } else if (simboloAtual == k) {
                return retornaBase;
            }
            break;
        case O:
            if (simboloAtual == f) {
                return O;
            } else if (simboloAtual == k) {
                return retornaBase;
            }
            break;
        case afereTemperatura:
            if (simboloAtual == i) {
                return enviaCentral;
            }
            break;
        case capturaFotoVideo:
            if (simboloAtual == i) {
                return enviaCentral;
            }
            break;
        case analisaSolo:
            if (simboloAtual == i) {
                return enviaCentral;
            }
            break;
        case enviaCentral:
            if (simboloAtual == o) {
                return enviaCentral;
            } else if (simboloAtual == n) {
                return confirmado;
            }
            break;
        case confirmado:
            if (simboloAtual == '$') {
                return ocioso;
            }
            break;
        case retornaBase:
            if (simboloAtual == '$') {
                return recarregaBateria;
            }
            break;
        case recarregaBateria:
            if (simboloAtual == '$') {
                return desligado;
            }
            break;
    }
    return estadoAtual; // se nÃ£o houver transiÃ§Ã£o para o sÃ­mbolo atual, permanece no estado atual
}
    
    // funÃ§Ã£o que verifica se a sequÃªncia de sÃ­mbolos Ã© aceita ou rejeitada pelo autÃ´mato
int verificaSequencia(char* sequencia) {
    int tamanho = strlen(sequencia);
    Estado estadoAtual = desligado; // estado inicial Ã© desligado
    for (int i = 0; i < tamanho; i++) {
        estadoAtual = proximoEstado(estadoAtual, sequencia[i] - 'a'); // converte o caractere em um sÃ­mbolo do alfabeto
    }
    return estadoAtual == retornaBase; // se o estado final Ã© retornaBase, a sequÃªncia Ã© aceita; caso contrÃ¡rio, Ã© rejeitada
}

int main() {
    char sequencia[] = "ahbeeffgioonhmiooonhbck"; // exemplo de sequÃªncia
    if (verificaSequencia(sequencia)) {
        printf("Sequencia aceita\n");
    } else {
        printf("Sequencia rejeitada\n");
    }
    return 0;
}