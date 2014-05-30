#include "../Hub/Hub.hpp"

//PIECE_H
#ifndef PIECE_HPP
#define PIECE_HPP

enum  Couleur{ CYAN , BLUE, ORANGE, YELLOW, GREEN, PURPLE, RED, GHOST }; // Les couleurs de chaque pi�ce, GHOST est pour la pi�ce fant�me

/* Les coordonn�es du point de pivot de la pi�ce */
const int PIVOT_X = 1;
const int PIVOT_Y = 2;

class Piece
{

private:
    int kind; // Le type de la pi�ce
    int orientation; // Orientation de la pi�ce
    int color; // Couleur de la piece

    int posX; // Ordonn�e sur la grille
    int posY; // Abscisse sur la grille

public:
    Piece(); //Constructeur par d�faut
    Piece(int k, int o);  //k = type de piece, o orientation
    Piece(const Piece &p); //Constructeur de copie

    void setKind(int k); //Permet de r�gler le type de pi�ce (logique)
    void setOrientation(int o); //Permet de r�gler son orientaiton (graphique)

    int getKind(); //Permet d'obtenir le type de la pi�ce (logique)
    int getOrientation(); //Permet d'obtenir son orientation (graphique)

    void setColor(int c); //Permet de r�gler la couleur de la pi�ce (logique)
    int getColor(); //Permet d'obtenir son orientation (graphique)

    void setPosX(int x); //Permet de configurer la position de la pi�ce sur l'ordonn�e (logique)
    int getPosX(); //Permet d'obtenir sa position sur l'ordonn�e (graphique)

    void setPosY(int y); //Permet de configurer la position de la pi�ce sur l'abscisse (logique)
    int getPosY(); //Permet d'obtenir sa position sur l'abscisse (graphique)
};

#endif //PIECE_H
