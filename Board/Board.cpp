#include "Board.hpp"

Board::Board()
{
    //Initialisation de toutes les cases de la grille � FREE (0 en valeur de tableau)
    for(int i = 0; i < BOARD_WIDTH; ++i)
        for(int j = 0; j < BOARD_HEIGHT; ++j)
            area[i][j].state = FREE;
}

int Board::getState(int i, int j)
{
    return area[i][j].state;
}

//Configuration de la pi�ce jouable
void Board::setCurrentPiece(Piece p)
{
    currentPiece = p;
}

//Pi�ce actuellement jou�e
Piece Board::getCurrentPiece()
{
    return currentPiece;
}


//(i, j): Les coordonn�es de la case � partir de laquelle floodfiller dans l'aire de jeu
//(px, py): Les coordonn�es de la case � partir de laquelle floodfiller dans la matrice de la pi�ce
//k: pour kind (type), le type de la pi�ce
//o: pour orientation, l'orientation de la pi�ce
//value: valeur avec laquelle remplir l'aire de jeu

void Board::flood(int i, int j, int px, int py, int k, int o, int value, bool visited[][SIZE])
{
    if(px < 0 || px >= SIZE || py < 0 || py >= SIZE || visited[px][py] || PIECES[k][o][px][py] == FREE)
        return;

    visited[px][py] = true;
    area[j][i].type = value; // On remplit la case de la valeur dans l'aire

    flood(i, j - 1, px, py - 1, k, o, value, visited);
    flood(i + 1, j, px + 1, py, k, o, value, visited);
    flood(i, j + 1, px, py + 1, k, o, value, visited);
    flood(i - 1, j, px - 1, py, k, o, value, visited);
}

//Surd�finition
void Board::flood(int i, int j, int px, int py, int k, int o, bool &flag, bool visited[][SIZE])
{
    if(px < 0 || px >= SIZE || py < 0 || py >= SIZE || visited[px][py] || PIECES[k][o][px][py] == FREE)
        return;

    visited[px][py] = true;

   /* Si on d�passe les limites de l'aire de jeu
    * ou si la case sur laquelle on est n'est pas vide
    */
    if(i < 0 || i >= BOARD_HEIGHT || j < 0 || j >= BOARD_WIDTH || area[j][i].state != FREE)
    {
        flag = false; // on met flag � false
        return;
    }

    flood(i, j - 1, px, py - 1, k, o, flag, visited);
    flood(i + 1, j, px + 1, py, k, o, flag, visited);
    flood(i, j + 1, px, py + 1, k, o, flag, visited);
    flood(i - 1, j, px - 1, py, k, o, flag, visited);
}

//Fonction appelant la fonction flood
void Board::floodFill(int i, int j, int px, int py, int k, int o, int value)
{
    bool visited[SIZE][SIZE];

    for(int l = 0; l < SIZE; ++l)
        for(int m = 0; m < SIZE; ++m)
            visited[l][m] = false;

    flood(i, j, px, py, k, o, value, visited);
}
//G�n�ration de la pi�ce
void Board::drawPiece(Piece p)
{
    int i = p.getPosX(); // On r�cup�re les ...
    int j = p.getPosY(); // ... coordonn�es de la pi�ce

    int k = p.getKind(); // On r�cup�re son type
    int o = p.getOrientation(); // et sa rotation

    switch(k) // En fonction de son type
    {
        case 0:
            p.setColor(CYAN); // On lui affecte la couleur appropri�e
            break;
        case 1:
            p.setColor(BLUE);
            break;
        case 2:
            p.setColor(ORANGE);
            break;
        case 3:
            p.setColor(YELLOW);
            break;
        case 4:
            p.setColor(GREEN);
            break;
        case 5:
            p.setColor(RED);
            break;
        case 6:
            p.setColor(GHOST);
            break;
        default:
            break;
    }
    //On fait le flood fill � partir du point de pivot de la pi�ce
    //et on remplir l'aire de jeu en fonction de la couleur de la pi�ce
    floodFill(i, j, PIVOT_X, PIVOT_Y, k, o, p.getColor());
}

//Effacement de la pi�ce
void Board::clearPiece(Piece p)
{
    int i = p.getPosX();
    int j = p.getPosY();

    int k = p.getKind();
    int o = p.getOrientation();

    floodFill(i, j, PIVOT_X, PIVOT_Y, k, o, FREE);
}

//Spawn d'une pi�ce
void Board::newPiece(Piece p)
{
    p.setPosX(ORIGIN_X); // On donne � la pi�ce les coordonn�es ...
    p.setPosY(ORIGIN_Y); // de l'origine

    drawPiece(p); // On la dessine

    setCurrentPiece(p); // On d�clare cette pi�ce comme pi�ce courante de l'aire de jeu
}

void Board::clear()
{
    for(int i = 0; i < BOARD_WIDTH; ++i)
    {
        for(int j = 0; j < BOARD_HEIGHT; ++j)
            area[i][j].state = FREE;
    }
}

//V�rifie si la pi�ce peut �tre d�plac�e vers x,y
bool Board::isCurrentPieceMovable(int x, int y)
{
    clearPiece(currentPiece); // D'abord on efface la pi�ce courante

    bool movable = true; // On suppose au d�part qu'on peut bouger la pi�ce

   //D�claration et initialisation du tableau pour le flood fill
    bool visited[SIZE][SIZE];

    for(int l = 0; l < SIZE; ++l)
        for(int m = 0; m < SIZE; ++m)
            visited[l][m] = false;

    int k = currentPiece.getKind(); // On r�cup�re le type ...
    int o = currentPiece.getOrientation(); // ... et l'orientation de la pi�ce

   /* On fait notre flood fill */
    flood(x, y, PIVOT_X, PIVOT_Y, k, o, movable, visited);

    drawPiece(currentPiece); // On redessine notre pi�ce

    return movable; // On renvoie le r�sultat
}

//V�rifie si la pi�ce peut effectu�e la rotation o
bool Board::isCurrentPieceRotable(int o)
{
    clearPiece(currentPiece);

    bool rotable = true;

    bool visited[SIZE][SIZE];

    for(int i = 0; i < SIZE; ++i)
        for(int j = 0; j < SIZE; ++j)
            visited[i][j] = false;

    int k = currentPiece.getKind();

    flood(currentPiece.getPosX(), currentPiece.getPosY(), PIVOT_X, PIVOT_Y, k, o, rotable, visited);

    drawPiece(currentPiece);

    return rotable;
}

// D�place la pi�ce d'une case vers le bas
void Board::moveCurrentPieceDown()
{
    int x = currentPiece.getPosX();
    int y = currentPiece.getPosY();

    if(isCurrentPieceMovable(x + 1, y)) // Si on peut bouger la pi�ce vers le bas
    {
        clearPiece(currentPiece); // On efface la pi�ce de son ancienne position
        currentPiece.setPosX(x + 1); // On incr�mente son ordonn�e

        drawPiece(currentPiece); // On la redessine � la nouvelle position
    }
}

// D�place la pi�ce d'une case vers la gauche
void Board::moveCurrentPieceLeft()
{
    int x = currentPiece.getPosX();
    int y = currentPiece.getPosY();

    if(isCurrentPieceMovable(x, y - 1))
    {
        clearPiece(currentPiece);
        currentPiece.setPosY(y - 1);

        drawPiece(currentPiece);
    }
}

// D�place la pi�ce d'une case vers la droite
void Board::moveCurrentPieceRight()
{
    int x = currentPiece.getPosX();
    int y = currentPiece.getPosY();

    if(isCurrentPieceMovable(x, y + 1))
    {
        clearPiece(currentPiece);
        currentPiece.setPosY(y + 1);

        drawPiece(currentPiece);
    }
}

// Tourne la pi�ce vers la gauche
void Board::rotateCurrentPieceLeft()
{
    int o = currentPiece.getOrientation(); // On r�cup�re l'orientation courante

    if(o > 0) // Si on n'est pas sur la 1�re orientation
        o--; // On peut d�cr�menter o
    else // Si non
        o = NB_ROTATIONS - 1; // On passe � la derni�re orientation

    if(isCurrentPieceRotable(o)) // Si on peut tourner la pi�ce
    {
        clearPiece(currentPiece); // On efface la pi�ce courante

        currentPiece.setOrientation(o); // On change son orientation
        drawPiece(currentPiece); // On la redessine avec la nouvelle orientation
    }
}

// Tourne la pi�ce vers la droite
void Board::rotateCurrentPieceRight()
{
    int o = currentPiece.getOrientation();

    if(o < NB_ROTATIONS - 1) // Si on n'est pas sur la derni�re orientation
        o++; // On peut incr�menter o
    else // Si non
        o = 0; // On passe � la 1�re orientation

    if(isCurrentPieceRotable(o))
    {
        clearPiece(currentPiece);

        currentPiece.setOrientation(o);
        drawPiece(currentPiece);
    }
}

//Supprime une ligne
void Board::deleteLine(int y)
{
    clearPiece(currentPiece); // On efface d'abord la pi�ce courante

        /* On d�place toutes les lignes � partir de y vers le haut
         * d'une case vers le bas
         */
    for(int j = y; j > 0; --j)
    {
        for(int i = 0; i < BOARD_WIDTH; ++i)
            area[i][j] = area[i][j-1];
    }

    drawPiece(currentPiece); // On la redessine
}

// Supprime les lignes pleines, renvoie le nombre de lignes supprim�es (utile pour les scores)
int Board::deletePossibleLines()
{
    int nbLinesDeleted = 0;

    for(int j = 0; j < BOARD_HEIGHT; ++j)
    {
        int i = 0;

        for(; i < BOARD_WIDTH && area[i][j].state != FREE; ++i);

        if(i == BOARD_WIDTH) // On a trouv� une ligne pleine
        {
            nbLinesDeleted++; // On incr�mente le nombre de lignes supprim�es
            deleteLine(j); // On supprime la ligne
        }
    }

    return nbLinesDeleted;
}

//Faire tomber la pi�ce actuellement jouable
void Board::dropCurrentPiece()
{
    int x = currentPiece.getPosX();
    int y = currentPiece.getPosY();

    while(isCurrentPieceMovable(x++, y)) // Tant qu'on peut toujours bouger la pi�ce vers le bas
        moveCurrentPieceDown(); // on le fait
}

// Teste si la pi�ce courante est tomb�e donc ne peut plus bouger
bool Board::isCurrentPieceFallen()
{
    int x = currentPiece.getPosX();
    int y = currentPiece.getPosY();

    if(isCurrentPieceMovable(x + 1, y)) // Si on peut encore la bouger vers le bas
        return false; // on renvoie faux

    return true; // si non on renvoie vrai
}

// La partie est elle finie
bool Board::isGameOver()
{
    for(int i = 0; i < BOARD_WIDTH; ++i)
    {
        if(area[i][0].state != FREE) // Si il y a un bloc sur la premi�re ligne de l'aire
            return true; // C'est que la partie est finie
    }

    return false;
}
