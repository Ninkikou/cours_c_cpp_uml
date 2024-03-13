#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

const int M = 10;
const int N = 10;
const char CACHE = '-';
const char MINE = '*';
char affichage[M][N];

void initTab2DEntier0(int tab[M][N]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            tab[i][j] = 0;
        }
    }
}

void initTab2DCache() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            affichage[i][j] = CACHE;
        }
    }
}

void afficherChampCaches() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << affichage[i][j] << " ";
        }
        cout << "\n";
    }
}

int saisirNbMines() {
    int nb;
    do {
        cout << "Veuillez saisir le nombre de mines que vous voulez placer (1-" << M * N - 1 << "): ";
        cin >> nb;
    } while (nb <= 0 || nb > M * N - 1);
    return nb;
}

void initialiserChamp(int tab[M][N], int nb_mines) {
    srand(static_cast<unsigned>(time(nullptr)));
    while (nb_mines > 0) {
        int i = rand() % M;
        int j = rand() % N;
        if (tab[i][j] != 9) {
            tab[i][j] = 9;
            --nb_mines;
        }
    }
}

bool revelerCase(int tab[M][N], int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N) {
        cout << "Position hors limites.\n";
        return false;
    }
    if (tab[x][y] == 9) {
        affichage[x][y] = MINE;
        return true;
    } else {
        affichage[x][y] = '0' + tab[x][y];
        return false;
    }
}

int main() {
    int champ[M][N];
    initTab2DEntier0(champ);
    initTab2DCache();
    int nb_mines = saisirNbMines();
    initialiserChamp(champ, nb_mines);

    int x, y;
    bool mine_trouvee = false;

    while (!mine_trouvee) {
        afficherChampCaches();
        cout << "Entrez les coordonnees de la case a reveler (x y): ";
        cin >> x >> y;

        mine_trouvee = revelerCase(champ, x-1, y-1);
        if (mine_trouvee) {
            cout << "BOOM! Vous avez trouve une mine.\n";
            afficherChampCaches();
            break;
        }
    }

    return 0;
}
