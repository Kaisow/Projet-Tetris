#include "../Hub/Hub.hpp"

Board::Board()
{
    //Initialisation de toutes les cases de la grille � FREE (0 en valeur de tableau)
    for(int i = 0; i < BOARD_WIDTH; ++i)
        for(int j = 0; j < BOARD_HEIGHT; ++j)
            area[i][j] = FREE;
}

//Configuration de la pi�de jouable
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
    area[j][i] = value; // On remplit la case de la valeur dans l'aire

    flood(i, j - 1, px, py - 1, k, o, value, visited);
    flood(i + 1, j, px + 1, py, k, o, value, visited);
    flood(i, j + 1, px, py + 1, k, o, value, visited);
    flood(i - 1, j, px - 1, py, k, o, value, visited);
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
        case I:
            p.setColor(CYAN); // On lui affecte la couleur appropri�e
            break;
        case J:
            p.setColor(BLUE);
            break;
        case L:
            p.setColor(ORANGE);
            break;
        case O:
            p.setColor(YELLOW);
            break;
        case S:
            p.setColor(GREEN);
            break;
        case T:
            p.setColor(PURPLE);
            break;
        case Z:
            p.setColor(RED);
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
            area[i][j] = FREE;
    }
}
