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

