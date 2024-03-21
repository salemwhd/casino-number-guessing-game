# Number Guessing Game

This is a simple number guessing game implemented in C++. In this game, the player is prompted to input their starting balance, then they can place bets and guess a number between 1 and 10. If their guess matches the randomly generated number, they win ten times the bet amount; otherwise, they lose their bet amount. The game continues until the player decides to end it or runs out of balance.

## How to Play

1. Compile the program using a C++ compiler.
2. Run the compiled executable.
3. Enter your starting balance when prompted.
4. Place your bet and guess a number between 1 and 10.
5. The program will inform you if you win or lose and update your balance accordingly.
6. You will be prompted if you want to play again. Enter 'Y' to continue or 'N' to end the game.

## Requirements

- C++ compiler

## Usage

```bash
$ g++ main.cpp -o number_guessing_game
$ ./number_guessing_game
```

## Features

  Simple Gameplay: Easy-to-understand rules make it accessible for all players.
    Fair Randomization: Randomly generated numbers ensure fairness in each round.
    Interactive Interface: Provides clear prompts and feedback to guide the player through the game.
    Multiple Rounds: Allows players to continue playing until they decide to end the game.
    Dynamic Balance: Tracks and updates the player's balance throughout the game.

## Example
```cpp
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
void game(int balance);
void process(int balance, int bet_amount, int guessed_num);
int main()
{

    int balance;


    cout<<"Put your balance on the table:\n";

    cin>>balance;
    game(balance);

    return 0;
}
void game(int balance)
{
    int bet_amount,guessed_num ;
    cout<<"How much money will you bet on?\n";
    cin>>bet_amount;
    if(balance-bet_amount>=0)
    {
    cout<<"Guess a number between (1,10)\n";
    cin>>guessed_num;
    process(balance,bet_amount,guessed_num);
    }
    else
    {
        cout<<"your balance isn't enough to bet on this amount\n";
        game(balance);

    }

}
void process(int balance,int bet_amount,int guessed_num)
{
    srand(time(0));
    int current_balance;
    int random_num= rand()%10+1;
    char r;
    cout<<"the number on the table is: "<<random_num<<"\n";

   if(guessed_num==random_num)
    {
        cout<<"Congrats, you have won "<<bet_amount*10<<"$"<<"\n";
        current_balance=balance+(bet_amount*10);

    }
    else
    {
         cout<<"sorry, you lost "<<bet_amount<<"\n";
         current_balance=balance- bet_amount;
    }
        cout<<"current balance is: "<<current_balance<<"$"<<"\n";

        if(current_balance>0)
       {


        cout<<"    Do you wanna play again?\n";
        cout<<"Y:Yes\n";
        cout<<"N:End game\n";

        cin>>r;
        if(r=='Y')
        {
            game(current_balance);
        }

        }

}

