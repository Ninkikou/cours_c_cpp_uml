#include <iostream>
#include <vector>
#include <cstdlib> // Pour system()

using namespace std;

const int largeur = 10;
const int hauteur = 10;
const char Joueur = 'P';
const char Mur = '#';
const char Libre = ' ';
int posX = 1;
int posY = 1;

vector<vector<char>> labyrinthe(hauteur, vector<char>(largeur, Libre));

void afficherLabyrinthe() {
    system("cls"); // Nettoie l'écran (Windows)
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            if (i == posY && j == posX) {
                cout << Joueur;
            } else {
                cout << labyrinthe[i][j];
            }
        }
        cout << endl;
    }
}

bool deplacerJoueur(char commande) {
    int dx = 0;
    int dy = 0;

    switch (commande) {
        case 'z': // haut
            dy = -1;
            break;
        case 's': // bas
            dy = 1;
            break;
        case 'q': // gauche
            dx = -1;
            break;
        case 'd': // droite
            dx = 1;
            break;
        default:
            cout << "Commande invalide." << endl;
            return false;
    }

    int nouvellePosX = posX + dx;
    int nouvellePosY = posY + dy;

    if (nouvellePosX >= 0 && nouvellePosX < largeur &&
        nouvellePosY >= 0 && nouvellePosY < hauteur &&
        labyrinthe[nouvellePosY][nouvellePosX] != Mur) {
        posX = nouvellePosX;
        posY = nouvellePosY;
        return true;
    }
    return false;
}

void initialiserLabyrinthe() {
    // Placer des murs autour du labyrinthe
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            if (i == 0 || j == 0 || i == hauteur - 1 || j == largeur - 1) {
                labyrinthe[i][j] = Mur;
            }
        }
    }
    // Ajouter quelques murs à l'intérieur
    labyrinthe[2][2] = Mur;
    labyrinthe[2][3] = Mur;
    labyrinthe[3][2] = Mur;
    labyrinthe[7][8] = Mur;
}

int main() {
    initialiserLabyrinthe();
    afficherLabyrinthe();

    char commande;
    while (true) {
        cout << "Déplacez-vous (z = haut, s = bas, q = gauche, d = droite), 'x' pour quitter: ";
        cin >> commande;

        if (commande == 'x') {
            break; // Quitter le jeu
        }

        if(deplacerJoueur(commande)) {
            afficherLabyrinthe();
        } else {
            cout << "Mouvement impossible !" << endl;
        }
    }

    return 0;
}
