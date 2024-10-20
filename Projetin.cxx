#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#define Retorne return

using namespace std;

// Função para quebrar uma linha
void pularLinha() {
    cout << "\n";
}

// DESENHANDO O BONECO conforme as vidas diminuem
void desenho(int vidas) {
    cout << "\n_____\n";
    cout << "    |\n";
    if (vidas < 5) cout << "  ( x x )\n"; else cout << "    |\n";
    if (vidas < 4) cout << "   \\|/  \n"; else cout << "    |\n";
    if (vidas < 3) cout << "    |   \n"; else cout << "    |\n";
    if (vidas < 2) cout << "   / \\  \n"; else cout << "  __|__\n";
}

// Função para verificar se a palavra foi completamente descoberta
bool palavraCompleta(string simbolo) {
    return simbolo.find('_') == string::npos;
}

int main() {

    setlocale(LC_ALL, "portuguese");

    typedef int inteiro;
    typedef char caractere;
    typedef bool boleano;

    boleano menu = true; // Controle do menu principal
    boleano jogar_novamente = true; // Controle para reiniciar o jogo
    inteiro opt; // Para escolha no menu

    do {
        cout << "********************";
        cout << "\nJOGO DA FORCA\n";
        cout << "\n#Autor: Ronny\nDate: 20/10/24#";
        desenho(5); // Boneco inicial sem partes desenhadas
        pularLinha();
        pularLinha();

        cout << setw(16) << "1: INICIAR";
        pularLinha();
        cout << setw(16) << "2: SAIR";
        cout << "\n********************";
        cout << "\nDigite Uma Opcão [1/2]: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                // Começo do jogo
                string palavra_secreta;
                caractere letra;
                inteiro vidas = 5;
                vector<char> letras_erradas; // Armazena letras erradas

                cout << "\nDefina Uma Palavra: ";
                cin >> palavra_secreta;

                // Inicializa a string com underscores
                string simbolo(palavra_secreta.length(), '_');

                // Loop principal do jogo
                while (vidas > 0 && !palavraCompleta(simbolo)) {
                    cout << "\n\n\tQuantidade De Letras: " << palavra_secreta.length() << endl;
                    desenho(vidas); // Desenha o boneco conforme as vidas

                    cout << "\nPalavra: ";
                    for (inteiro i = 0; i < simbolo.length(); i++) {
                        cout << simbolo[i] << ' ';
                    }

                    cout << "\n\nLetras erradas: ";
                    for (char letra_errada : letras_erradas) {
                        cout << letra_errada << ' ';
                    }

                    // Entrada da letra
                    cout << "\n\n\tDigite uma letra: ";
                    cin >> letra;

                    // Verifica se a letra está na palavra
                    boleano acertou = false;
                    for (inteiro i = 0; i < palavra_secreta.length(); i++) {
                        if (palavra_secreta[i] == letra) {
                            simbolo[i] = letra;
                            acertou = true;
                        }
                    }

                    // Se não acertou, perde uma vida e adiciona a letra às erradas
                    if (!acertou) {
                        vidas--;
                        letras_erradas.push_back(letra);
                    }

                    pularLinha();
                }

                // Verificação de vitória ou derrota
                if (palavraCompleta(simbolo)) {
                    cout << "\nPARABÉNS! Você acertou a palavra: " << palavra_secreta << endl;
                } else {
                    desenho(vidas);
                    cout << "\nVocê perdeu! A palavra era: " << palavra_secreta << endl;
                }

                // Pergunta se deseja jogar novamente
                char opcao;
                cout << "\nDeseja jogar novamente? (s/n): ";
                cin >> opcao;
                if (opcao == 'n' || opcao == 'N') {
                    jogar_novamente = false;
                    cout << "\nOBRIGADO POR JOGAR VOLTE SEMPRE!\n";
                }

                break;
            }

            case 2:
                cout << "\nOBRIGADO POR JOGAR VOLTE SEMPRE!\n";
                menu = false;
                break;

            default:
                cout << "OPÇÃO INVÁLIDA!";
                break;
        }

    } while (menu && jogar_novamente);

    Retorne 0;
}
