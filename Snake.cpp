#include <cstdlib>
#include <ncurses.h>

bool gameOver;
const int width = 20, height = 20;
int x, y;
int eggX, eggY;
int score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

int tailX[width*2], tailY[height*2];
int nTail = 0;

void Setup(){

    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);

    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    eggY = (rand()%width)+1;
    eggX = (rand()%height)+1;
    score = 0;
}

void Draw(){
    clear();

    for(int i = 0;i < width+2;i++)
        mvprintw(0,i,"+");

    for(int i = 0;i < height+2;i++){
        for(int j = 0;j < width+2;j++){
            if(i ==0 | i == width+1)
                mvprintw(i,j,"+");
            else if(j ==0 | j == height+1)
                mvprintw(i,j,"+");
            else if ( i == y && j == x)
                mvprintw(i,j,"O");
            else if ( i == eggY && j == eggX)
                mvprintw(i,j,"X");
            else
                for(int k = 0;k < nTail;k++)
                    if(tailX[k] == j && tailY[k] == i)
                        mvprintw(i,j,"o");
        }
    }

    mvprintw(23,0,"Score %d",score);

    refresh();
}

void Input(){
    keypad(stdscr, TRUE);
    halfdelay(1);

    int c = getch();

    switch(c)
    {
    case KEY_LEFT:
        if(dir != RIGHT)
            dir = LEFT;
        break;
    case KEY_RIGHT:
        if(dir != LEFT)
            dir = RIGHT;
        break;
    case KEY_UP:
        if(dir != DOWN)
            dir = UP;
        break;
    case KEY_DOWN:
        if(dir != UP)
            dir = DOWN;
        break;
    case 'q': // instant quit game
        gameOver = true;
        break;
    }
}

void Logic(){

    int prevX = tailX[0];
    int prevY=  tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1;i < nTail;i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if(x > width || x < 1 || y < 1 || y > height)
        gameOver = true;

    if(x == eggX && y == eggY){
        score++;
        eggY = (rand()%width)+1;
        eggX = (rand()%height)+1;
        nTail++;
    }

    for(int i = 0;i < nTail;i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
}

int main(){

    Setup();

    while(!gameOver)
    {
        Draw();
        Input();
        Logic();        
    }

    getch();
    endwin();

    return 0;
}