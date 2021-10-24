#include <iostream>
#define max 4

using namespace std;

// Algarismo atual de cada dígito
int posicao[max];

// Função para reiniciar contagens
void restaurar(int tamanho, int digito) {
    // Detecta se há dígitos posteriores
    if (digito < tamanho) {
        // Começa a contar a partir da posição alvo
        for (int pos = digito; pos < tamanho; pos ++) {
            // Define os dígitos selecionados como 1
            // OBS: 1 é o valor mínimo para os dígitos
            posicao[pos] = 1;
        }
    }
}

// Checa quais dígitos não têm valor máximo
bool podeSomar(int tamanho, int maximo, int pos) {
    // Parte de uma posição específica no vetor
    for (pos; pos < tamanho; pos ++) {
        // Dígito selecionado é menor que o máximo
        if (posicao[pos] < maximo) {
            // Retorna que é possível fazer uma soma
            // OBS: Note que o return encerra a função aqui
            return true;
        }
    }
    // Todos os dígitos possuem valor máximo
    return false;
}

// Função recursiva, escreve uma nova senha
// OBS: Também realiza uma soma, preparando a próxima senha
int escreverSenha(int tamanho, int maximo) {
    // Quantidade de dígitos com valor máximo
    int maximizado = 0;
    // Passa por cada número no vetor posição
    for (int pos = 0; pos < tamanho; pos ++) {
        // Checa se o dígito atual está no máximo
        if (posicao[pos] == maximo) {
            maximizado ++;
        }
        // Escreve o dígito selecionado, mais um espaço
        cout << posicao[pos] << ' ';
    }
    // Se todos estiverem no máximo, encerra o sistema
    if (maximizado == tamanho) {
        return 0;
    }
    // Observa se uma restauração já foi solicitada
    bool restaurado = false;
    // Busca modificações em potencial, para cada dígito
    for (int pos = 0; pos < tamanho; pos ++) {
        // Aplica a função acima, detectando se é possível somar
        // OBS: Possível somar = dígito não alcançou o valor máximo
        bool somaPossivel = podeSomar(tamanho, maximo, pos);
        // Se estiver no máximo, e não for possível somar...
        if (posicao[pos] == maximo && not somaPossivel) {
            // ... então soma 1 ao dígito anterior
            // Exemplo: 1 1 3 se torna 1 2 1, em vez de 1 1 4
            posicao[pos - 1] ++;
            // Pede uma restauração dos dígitos à direita
            // OBS: Dígitos restaurados se tornam 1 novamente
            restaurar(tamanho, pos);
            restaurado = true;
        // Se for o último dígito, e restauração não solicitada...
        } else if (pos == tamanho - 1 && not restaurado) {
            // ... simplesmente soma 1 a este último dígito
            posicao[pos] ++;
        }
    }
    // Pula uma linha, para escrever a senha seguinte
    cout << endl;
    // Reativa a função, obtendo uma nova senha
    escreverSenha(tamanho, maximo);
}

int main() {
    // Recebe o tamanho e número máximo
    int tamanho, maximo;
    cin >> tamanho >> maximo;
    // Condições básicas para iniciar
    if (tamanho >= 1 && tamanho <= 4 && maximo >= 1 && maximo <= 6) {
        // Define o algarismo padrão como 1
        for (int pos = 0; pos < tamanho; pos ++) {
            posicao[pos] = 1;
        }
        // Dá início à função recursiva de escrita
        escreverSenha(tamanho, maximo);
    }
    return 0;
}
