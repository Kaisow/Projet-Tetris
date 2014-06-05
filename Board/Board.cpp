#include "Board.hpp"

Board::Board()
{
    //Initialisation de toutes les cases de la grille à FREE (0 en valeur de tableau)
    for(int i = 0; i < BOARD_WIDTH; ++i)
        for(int j = 0; j < BOARD_HEIGHT; ++j)
            area[i][j].state = FREE;
}

int Board::getState(int i, int j)
{
    return area[i][j].state;
}

//Configuration de la pièce jouable
void Board::setCurrentPiece(Piece p)
{
    currentPiece = p;
}

//Pièce actuellement jouée
Piece Board::getCurrentPiece()
{
    return currentPiece;
}


//(i, j): Les coordonnées de la case à partir de laquelle floodfiller dans l'aire de jeu
//(px, py): Les coordonnées de la case à partir de laquelle floodfiller dans la matrice de la pièce
//k: pour kind (type), le type de la pièce
//o: pour orientation, l'orientation de la pièce
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

//Surdéfinition
void Board::flood(int i, int j, int px, int py, int k, int o, bool &flag, bool visited[][SIZE])
{
    if(px < 0 || px >= SIZE || py < 0 || py >= SIZE || visited[px][py] || PIECES[k][o][px][py] == FREE)
        return;

    visited[px][py] = true;

   /* Si on dépasse les limites de l'aire de jeu
    * ou si la case sur laquelle on est n'est pas vide
    */
    if(i < 0 || i >= BOARD_HEIGHT || j < 0 || j >= BOARD_WIDTH || area[j][i].state != FREE)
    {
        flag = false; // on met flag à false
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
//Génération de la pièce
void Board::drawPiece(Piece p)
{
    int i = p.getPosX(); // On récupère les ...
    int j = p.getPosY(); // ... coordonnées de la pièce

    int k = p.getKind(); // On récupère son type
    int o = p.getOrientation(); // et sa rotation

    switch(k) // En fonction de son type
    {
        case 0:
            p.setColor(CYAN); // On lui affecte la couleur appropriée
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
    //On fait le flood fill à partir du point de pivot de la pièce
    //et on remplir l'aire de jeu en fonction de la couleur de la pièce
    floodFill(i, j, PIVOT_X, PIVOT_Y, k, o, p.getColor());
}

//Effacement de la pièce
void Board::clearPiece(Piece p)
{
    int i = p.getPosX();
    int j = p.getPosY();

    int k = p.getKind();
    int o = p.getOrientation();

    floodFill(i, j, PIVOT_X, PIVOT_Y, k, o, FREE);
}

//Spawn d'une pièce
void Board::newPiece(Piece p)
{
    p.setPosX(ORIGIN_X); // On donne à la pièce les coordonnées ...
    p.setPosY(ORIGIN_Y); // de l'origine

    drawPiece(p); // On la dessine

    setCurrentPiece(p); // On déclare cette pièce comme pièce courante de l'aire de jeu
}

void Board::clear()
{
    for(int i = 0; i < BOARD_WIDTH; ++i)
    {
        for(int j = 0; j < BOARD_HEIGHT; ++j)
            area[i][j].state = FREE;
    }
}

//Vérifie si la pièce peut être déplacée vers x,y
bool Board::isCurrentPieceMovable(int x, int y)
{
    clearPiece(currentPiece); // D'abord on efface la pièce courante

    bool movable = true; // On suppose au départ qu'on peut bouger la pièce

   //Déclaration et initialisation du tableau pour le flood fill
    bool visited[SIZE][SIZE];

    for(int l = 0; l < SIZE; ++l)
        for(int m = 0; m < SIZE; ++m)
            visited[l][m] = false;

    int k = currentPiece.getKind(); // On récupère le type ...
    int o = currentPiece.getOrientation(); // ... et l'orientation de la pièce

   /* On fait notre flood fill */
    flood(x, y, PIVOT_X, PIVOT_Y, k, o, movable, visited);

    drawPiece(currentPiece); // On redessine notre pièce

    return movable; // On renvoie le résultat
}

//Vérifie si la pièce peut effectuée la rotation o
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

// Déplace la pièce d'une case vers le bas
void Board::moveCurrentPieceDown()
{
    int x = currentPiece.getPosX();
    int y = currentPiece.getPosY();

    if(isCurrentPieceMovable(x + 1, y)) // Si on peut bouger la pièce vers le bas
    {
        clearPiece(currentPiece); // On efface la pièce de son ancienne position
        currentPiece.setPosX(x + 1); // On incrémente son ordonnée

        drawPiece(currentPiece); // On la redessine à la nouvelle position
    }
}

// Déplace la pièce d'une case vers la gauche
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

// Déplace la pièce d'une case vers la droite
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

// Tourne la pièce vers la gauche
void Board::rotateCurrentPieceLeft()
{
    int o = currentPiece.getOrientation(); // On récupère l'orientation courante

    if(o > 0) // Si on n'est pas sur la 1ère orientation
        o--; // On peut décrémenter o
    else // Si non
        o = NB_ROTATIONS - 1; // On passe à la dernière orientation

    if(isCurrentPieceRotable(o)) // Si on peut tourner la pièce
    {
        clearPiece(currentPiece); // On efface la pièce courante

        currentPiece.setOrientation(o); // On change son orientation
        drawPiece(currentPiece); // On la redessine avec la nouvelle orientation
    }
}

// Tourne la pièce vers la droite
void Board::rotateCurrentPieceRight()
{
    int o = currentPiece.getOrientation();

    if(o < NB_ROTATIONS - 1) // Si on n'est pas sur la dernière orientation
        o++; // On peut incrémenter o
    else // Si non
        o = 0; // On passe à la 1ère orientation

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
    clearPiece(currentPiece); // On efface d'abord la pièce courante

        /* On déplace toutes les lignes à partir de y vers le haut
         * d'une case vers le bas
         */
    for(int j = y; j > 0; --j)
    {
        for(int i = 0; i < BOARD_WIDTH; ++i)
            area[i][j] = area[i][j-1];
    }

    drawPiece(currentPiece); // On la redessine
}

// Supprime les lignes pleines, renvoie le nombre de lignes supprimées (utile pour les scores)
int Board::deletePossibleLines()
{
    int nbLinesDeleted = 0;

    for(int j = 0; j < BOARD_HEIGHT; ++j)
    {
        int i = 0;

        for(; i < BOARD_WIDTH && area[i][j].state != FREE; ++i);

        if(i == BOARD_WIDTH) // On a trouvé une ligne pleine
        {
            nbLinesDeleted++; // On incrémente le nombre de lignes supprimées
            deleteLine(j); // On supprime la ligne
        }
    }

    return nbLinesDeleted;
}

//Faire tomber la pièce actuellement jouable
void Board::dropCurrentPiece()
{
    int x = currentPiece.getPosX();
    int y = currentPiece.getPosY();

    while(isCurrentPieceMovable(x++, y)) // Tant qu'on peut toujours bouger la pièce vers le bas
        moveCurrentPieceDown(); // on le fait
}

// Teste si la pièce courante est tombée donc ne peut plus bouger
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
        if(area[i][0].state != FREE) // Si il y a un bloc sur la première ligne de l'aire
            return true; // C'est que la partie est finie
    }

    return false;
}
