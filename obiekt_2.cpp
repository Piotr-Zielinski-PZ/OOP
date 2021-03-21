#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevaled;
};

class Minesweeper
{
    vector <vector <Field>> board;
    int width;
    int height;

public:
    Minesweeper();
    void debug_display();
};

Minesweeper::Minesweeper()
{
    width = 10;
    height = 10;
    board.resize (height, vector <Field>(width));
    board[0][0].hasMine = 1;
    board[1][1].isRevaled = 1;
    board[2][0].hasFlag = 1;
    board[2][0].hasMine = 1;
}

void Minesweeper::debug_display()
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            string mine = ".";
            string rev = ".";
            string flag = ".";

            if(board[j][i].hasMine)
            {
                mine = "M";
                if(board[j][i].isRevaled)
                {
                    rev = "o";
                    if(board[j][i].hasFlag)
                    {
                        flag = "f";
                        cout << "[" << mine << rev << flag << "] ";
                    }
                    else
                    {
                        cout << "[" << mine << rev << flag << "] ";
                    }
                }
                else if(board[j][i].hasFlag)
                {
                    flag = "f";
                    cout << "[" << mine << rev << flag << "] ";
                }
                else
                {
                    cout << "[" << mine << rev << flag << "] ";
                }
            }
            else if(board[j][i].isRevaled)
            {
                rev = "o";
                if(board[j][i].hasFlag)
                {
                    flag = "f";
                    cout << "[" << mine << rev << flag << "] ";
                }
                else
                {
                    cout << "[" << mine << rev << flag << "] ";
                }
            }
            else if(board[j][i].hasFlag)
            {
                flag = "f";
                cout << "[" << mine << rev << flag << "] ";
            }
            else
            {
                cout << "[" << mine << rev << flag << "] ";
            }
        }

        cout << endl;
    }
}

int main()
{
    Minesweeper Mine = Minesweeper(10, 10, EASY);
    Mine.debug_display();
}