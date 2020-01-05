/*
  This is my first program in C++ to be shared here. (3 months studying Computer Engineering)
  Some variables are on spanish, like maximo or mejor_pos but i think this doesn't matter
  Bully me with your inner comments, i'm ready :`)
  All advices are appreciated!
*/

#include <iostream>
#include <stdio.h>

using namespace std;

void startart()
{
    cout << "\n////////////////////////////////////////////////";
    cout << "\n//     ///////  /////       //       //       //";
    cout << "\n// ////  /////  ///// ///// ///// ///// ////////";
    cout << "\n// ///// //// // //// ///// ///// ///// ////////";
    cout << "\n// ///// //// // ////       ///// /////       //";
    cout << "\n// ///// /// //// ///  ////////// /////////// //";
    cout << "\n// ///// ///      /// / ///////// /////////// //";
    cout << "\n// ////  // ////// // // //////// /////////// //";
    cout << "\n//     //// ////// // ///   ///// /////       //";
    cout << "\n////////////////////////////////////////////////\n";
    cout << "An basic dart point counter. Made by neonCrosshair\n\n";
}

class player
{
private:
    string name;
    int points=0;
public:
    string seename()
    {
        return name;
    }
    int seepoints()
    {
        return points;
    }
    void setname(string newname)
    {
        name = newname;
    }
    void add(int amount)
    {
        points += amount;
    }
};

int main()
{
    const int MAXPLAYERS=4;
    player players[MAXPLAYERS];
    int nplayers, nrounds, i, j, loaniadido, maximo, mejor_pos;
    string entry;
    startart();
    do
    {
        cout << "Number of players: ";
        cin >> nplayers;
        if (nplayers < 0 || nplayers > 4)
            cout << "[x] Number of players must be between 0 and 4" << endl;
    } while (nplayers < 0 || nplayers > 4);
    for (i=0; i < nplayers; i++)
    {
        cout << "Player " << i+1 << " name: ";
        cin >> entry;
        players[i].setname(entry);
    }
    do
    {
        cout << "\nNumber of rounds: ";
        cin >> nrounds;
        if (nrounds < 0 || nrounds > 10)
            cout << "[x] Number of players must be between 0 and 10" << endl;
    } while (nrounds < 0 || nrounds > 10);
    cout << "\nGame started!" << endl;
    for (i=0; i < nrounds; i++)
    {
        cout << "\nRound " << i+1 << endl;
        for (j=0; j < nplayers; j++)
        {
            do
            {
                cout << players[j].seename() << ": ";
                cin >> loaniadido;
                if (loaniadido < 0 || loaniadido > 60)
                    cout << "[x] Number of points must be between 0 and 60" << endl;
            } while (loaniadido < 0 || loaniadido > 60);
            players[j].add(loaniadido);
        }
    }
    cout << "\n[*] GAME OVER [*]" << endl;
    for (i=0; i < nplayers; i++)
    {
        cout << players[i].seename() << ": " << players[i].seepoints() << endl;
    }
    maximo = players[0].seepoints();
    for (i=0; i < nplayers; i++)
    {
        if (players[i].seepoints() > maximo)
            maximo = players[i].seepoints();
        for (j=0; j < nplayers; j++)
        {
            if (maximo == players[j].seepoints())
                mejor_pos = j;
        }
    }
    cout << "\nWINNER: " << players[mejor_pos].seename() << " [" << players[mejor_pos].seepoints() << "]\n";
    cout << "Program finished, if you want to start a new game, relaunch it." << endl << "Press any key to close";
    getchar();
    return 0;
}
