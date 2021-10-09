#include <iostream>

using namespace std;

int main() {
    // Dias em cada mês específico
    int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Data, corridas e distância
    int mes, dias_mar, dist_total = 6;
    // Leitura da data (mês atual)
    cin >> mes;
    // O mês tem menos que 31 dias
    if (dias[mes - 1] < 31) {
        // Dois dias de maratona
        dias_mar = 2;
    // Possui exatamente 31 dias
    } else {
        // Três dias de maratona
        dias_mar = 3;
    }
    // Cálculo da distância, mês par
    if (mes % 2 == 0) {
        // Apenas incrementa o padrão
        dist_total += mes/2 * 3;
    // Caso o mês seja ímpar
    } else {
        // Subtrai 1, tornando-o par
        dist_total += (mes - 1)/2 * 3;
    }
    // --------------------------------------------
    // Opcional, detecta o nome do mês
    string nomes[12] = {
        "Janeiro", "Fevereiro", "Março", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    // Imprime corridas e distância
    cout << nomes[mes - 1] + ": " << dias_mar << " corridas de " << dist_total << " km.";
    return 0;
}