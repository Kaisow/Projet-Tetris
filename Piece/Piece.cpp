#include "Piece.hpp"

Piece::Piece()
{
    //Vide mais obligé d'être déclarer car autre constructeur créé
}

//Constructeur de la piece
Piece::Piece(int k, int o)
{
    kind = k;
    orientation = o;
}

//Constructeur de copie
Piece::Piece(const Piece &p)
{
    kind = p.kind;
    orientation = p.orientation;
    color = p.color;
    posX = p.posX;
    posY = p.posY;
}

//Configuration du type
void Piece::setKind(int k)
{
    kind = k;
}

//Configuration de l'orientation
void Piece::setOrientation(int o)
{
    orientation = o;
}

//Obtention du type
int Piece::getKind()
{
    return kind;
}

//Obtention de l'orientation
int Piece::getOrientation()
{
    return orientation;
}

//Configuration de la couleur
void Piece::setColor(int c)
{
    color = c;
}

//Onbtention de la couleur
int Piece::getColor()
{
    return color;
}

//Configuration de la ordonnée
void Piece::setPosX(int x)
{
    posX = x;
}

int Piece::getPosX()
{
    return posX;
}

//Configuration de l'ordonnée
void Piece::setPosY(int y)
{
    posY = y;
}

//Configuration de l'abscisse
int Piece::getPosY()
{
    return posY;
}
