#include "../Hub/Hub.hpp"

//PIECE_H
#ifndef PIECE_HPP
#define PIECE_HPP

enum  Couleur{ CYAN , BLUE, ORANGE, YELLOW, GREEN, PURPLE, RED, GHOST }; // Les couleurs de chaque pièce, GHOST est pour la pièce fantôme

/* Les coordonnées du point de pivot de la pièce */
const int PIVOT_X = 1;
const int PIVOT_Y = 2;

class Piece
{

private:
    int kind; // Le type de la pièce
    int orientation; // Orientation de la pièce
    int color; // Couleur de la piece

    int posX; // Ordonnée sur la grille
    int posY; // Abscisse sur la grille

public:
    Piece(); //Constructeur par défaut
    Piece(int k, int o);  //k = type de piece, o orientation
    Piece(const Piece &p); //Constructeur de copie

    void setKind(int k); //Permet de régler le type de pièce (logique)
    void setOrientation(int o); //Permet de régler son orientaiton (graphique)

    int getKind(); //Permet d'obtenir le type de la pièce (logique)
    int getOrientation(); //Permet d'obtenir son orientation (graphique)

    void setColor(int c); //Permet de régler la couleur de la pièce (logique)
    int getColor(); //Permet d'obtenir son orientation (graphique)

    void setPosX(int x); //Permet de configurer la position de la pièce sur l'ordonnée (logique)
    int getPosX(); //Permet d'obtenir sa position sur l'ordonnée (graphique)

    void setPosY(int y); //Permet de configurer la position de la pièce sur l'abscisse (logique)
    int getPosY(); //Permet d'obtenir sa position sur l'abscisse (graphique)
};

#endif //PIECE_H
