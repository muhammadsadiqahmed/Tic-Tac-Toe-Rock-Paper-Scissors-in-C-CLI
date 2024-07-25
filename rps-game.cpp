#include <iostream>
#include <time.h>
#include <cctype>
using namespace std;
int main(){
    char userChoose;
    do{
        cout << "Enter your choose :\n'r' Rock\n'p' Paper\n's' Scissors\n";
        cin >> userChoose;
        userChoose = tolower(userChoose);
    }while (userChoose != 'r' && userChoose != 'p' && userChoose != 's');
    srand(time(0));
    int randCh = (rand() % 3) + 1;
    char computerChoose;
    switch (randCh){
    case 1:
        computerChoose = 'r';
        if(userChoose == 'r'){cout << "Draw!\n";}
        else if(userChoose == 'p'){cout << "You Win!\n";}
        else{cout << "You Lost!\n";}break;
    case 2:
        computerChoose = 'p';
        if(userChoose == 'p'){cout << "Draw!\n";}
        else if(userChoose == 's'){cout << "You Win!\n";}
        else{cout << "You Lost!\n";}break;
    case 3:
        computerChoose = 's';
           if(userChoose == 's'){cout << "Draw!\n";}
        else if(userChoose == 'r'){cout << "You Win!\n";}
        else{cout << "You Lost!\n";}break;}
    cout << "Your choose is: " << userChoose << endl;
    cout << "Computer choose is: " << computerChoose << endl;
    return 0;}