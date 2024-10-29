// sample code to play tic tac to game using cpp code
// author: santanu mandal

#include<iostream>                                                      // including libraries header files
#include<cmath>

#define n 3                                                            // define n as 3

using namespace std;



void matrix_print(char arr[n][n]){                                      //printing arry using some good looking style

    cout << "_____________" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "| ";

        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " | ";
        }

        cout << endl;
        cout << "|___|___|___|" << endl;
        
    }

}



bool checker(char arr[n][n]){                                             // winner checker finction if some one win the match then this function return true value 
    if ((arr[0][0] == arr[0][1]) and (arr[0][1] == arr[0][2]))
    {
        return true;
    }
    else if ((arr[1][0] == arr[1][1]) and (arr[1][1] == arr[1][2]))      // simpley checking every winning possibility using if statement
    {
        return true;
    }
    else if ((arr[2][0] == arr[2][1]) and (arr[2][1] == arr[2][2]))
    {
        return true;
    }

    else if ((arr[0][0] == arr[1][0]) and (arr[1][0] == arr[2][0]))
    {
        return true;
    }
    else if ((arr[0][1] == arr[1][1]) and (arr[1][1] == arr[2][1]))
    {
        return true;
    }
    else if ((arr[0][2] == arr[1][2]) and (arr[1][2] == arr[2][2]))
    {
        return true;
    }

    else if ((arr[0][0] == arr[1][1]) and (arr[1][1] == arr[2][2]))
    {
        return true;
    }
    else if ((arr[2][0] == arr[1][1]) and (arr[1][1] == arr[0][2]))
    {
        return true;
    }
    else{                                                                 //if any one does not win else will return false and the game will continue
        return false;
    }
        
}




int main(){
    char arr[n][n] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    matrix_print(arr);                                                     // assign the array using numbers to clarify user the positions

    cout << "this is the number of every box in the game please remember it." << endl;

    

    char player1, player2;
    int selector;                                                         // variable declearing
    int k = 0;


    cout << "player 1 please select 'o' or 'x': ";                       // assign first user as player1 and let him/her to choose the sign 'o' or 'x' 
    cin >> player1;


    while (k==0)                                                         // using an while loop so user can not use any other symbol for the game
    {
        if(player1 == 'o' or player1 == 'x' or player1 == 'O' or player1 == 'X')
        {
            break;
        }
        else{
            cout << "sorry wrong selection try again: ";
            cin >> player1;
            k=0;
        }
    }
    


    if (player1 == 'o' or player1 == 'O')                                // according to player1's choice player2 aggign a sign            
    {
        player2 = 'x';
    }                                                                   
    else if(player1 == 'x' or player1 == 'X')
    {
        player2 = 'o';
    }



                                                                        // game running part for the code
    for (int i = 1; i <= 9; i++)                                        // according to game theory of tic-tac-to game is over or not there can be a maximum 9 moves so use itration 1 to =9
    {
        if (i%2 == 1)                                                   // here we start fron i = 1 and first move is for user 1 so use condition 1%2 == 1
        {
            cout << "player1 please select a box: ";
            cin >> selector;                                            // user input

            arr[(selector-1)/3][(selector-1)%3] = player1;              // math to get the location and then assign the symbol to that location      
            matrix_print(arr);    

            while (checker(arr))                                        // checking that after a perticuler move player 1 win or not if winnes then end the code running
            {
                cout << "player 1 is winner" << endl;
                return 0;
            }
                  
        }
        else                                                            // if it is not player1's turn then autometically this part run as similar to the first one
        {
            cout << "player2 please select a box: ";
            cin >> selector;

            arr[(selector-1)/3][(selector-1)%3] = player2;
            matrix_print(arr);

            while (checker(arr))                                        // checking that after a perticuler move player 1 win or not if winnes then end the code running
            {
                cout << "player 2 is winner" << endl;
                return 0;
            }
        }
        
    }

    matrix_print(arr);
    cout << "sorry draw match" << endl;                                 // in case of no onek win

    return 0;

}
