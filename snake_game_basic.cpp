#include <iostream>
#include <cstdlib>
using namespace std;

const int width = 40;
const int height = 20;

int x = width / 2;
int y = height / 2;

int bodyX[100], bodyY[100];
int nTail=0;


int foodX = rand()%(width-2) + 1;
int foodY = rand()%(height-2) + 1;

int score = 0;

void draw(){
    system("clear"); //clear the screen(linux/mac) , use "cls" on windows
    
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(i==0 || i == height - 1 || j == 0 || j == width-1){
                cout << "x"; //border
            }
            else if (i == y && j == x){
                cout << "0"; // snake head
            }
            else if (i== foodY && j == foodX) {
                cout << "*";
            }
            else {
                bool print = false;
                for(int k=0; k < nTail; k++){
                    if(bodyX[k] == j && bodyY[k] == i){
                        cout << "o"; //snake body
                        print = true;
                    }
                }
                if(!print){
                    cout << " "; //empty space
                }
            }
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir = STOP;

void logic(){
    int prevX = bodyX[0];
    int prevY = bodyY[0];
    int prev2X, prev2Y;
    bodyX[0] = x;
    bodyY[0] = y;
    for(int i = 1; i < nTail; i++){
        prev2X = bodyX[i];
        prev2Y = bodyY[i];
        bodyX[i]=prevX;
        bodyY[i]=prevY;
        prevX = prev2X;
        prevY = prev2Y;
        
    }
    switch(dir){
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }
    if(x <=0 || x >= width-1 || y<=0 || y >= height-1){
        cout << "Game Over! Final Score:" << score << endl;
        exit(0);
    }

    if(x == foodX && y == foodY){
        score++;
        foodX = rand()%(width-2) + 1;
        foodY = rand()%(height-2) + 1;
        nTail++;
    }
}

void input(){
    char c;
    cout << "Enter direction (WASD): ";
    cin>>c;
    switch(c){
        case 'a': dir = LEFT; break;
        case 'd': dir = RIGHT; break;
        case 'w': dir = UP; break;
        case 's': dir = DOWN; break;
        default: dir = STOP; break;
    }
}

int main() {
    dir = STOP;
    while(true) {
        draw();
        input();
        logic();
        //small delay
        for (volatile int i = 0; i < 10000000; i++);
    }
    return 0;
}
