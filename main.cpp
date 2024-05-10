#include <iostream>
#include <random>
#include <array>
#include <ctime>
#include <cmath>

using namespace std;

class Player {
private:
    string name;
    bool turn;
    bool win;

public:
    Player()
    {
        name = "PC";
        turn = false;
        win = false;
    }

    string getName()
    {
        return name;
    }
    void setName(string n)
    {
        name = n;
    }
    bool getTurn()
    {
        return turn;
    }
    void setTurn(bool t)
    {
        turn = t;
    }
    void printWin()
    {
        cout << '\n' << name << " wins!" << endl;
    }
};

//variables that are present in both recursive functions
char letter;
int digit;
int j = 65;

void recursiveGame(int, array<int, 5>&, Player, Player);
void recursivePC(int, size_t, int*&, Player, Player); //create another recursive function for user vs pc

int main()
{
    //variables that are present in multiple options
    int option;
    int tokens(0);
    string nom;
    Player p1;

    cout << "1- Two players (user vs. user)\n2- Two players (PC vs. user)\n3- Exit\nChoose an option: ";
    L:
    cin >> option;

    switch(option) {
        case 1: {
            Player p2;

            cout << "\nPlayer 1, enter your name: ";
            cin >> nom;
            p1.setName(nom);

            cout << "\nPlayer 2, enter your name: ";
            cin >> nom;
            p2.setName(nom);

            default_random_engine engine(static_cast<unsigned int>(time(0)));
            uniform_int_distribution<unsigned int>randomInt(0, 4);
            array<int, 5>heaps = { 0, 0, 0, 0, 0 };

            cout << "\nEnter the total number of tokens: ";
            cin >> tokens;
            uniform_int_distribution<unsigned int>randomTokens(0, 4);

            for (size_t i = 0; i < heaps.size(); i++)
            {
                heaps[i]++;
            }


            for (int i = 1; i <= tokens - 5; i++)
            {
                heaps[randomInt(engine)]++;
            }

            p1.setTurn(true);
            p2.setTurn(false);

            recursiveGame(tokens, heaps, p1, p2);

            break;
        }
        case 2: {
            Player pc;
            size_t numberOfHeaps;

            cout << "\nEnter the number of heaps: ";
            cin >> numberOfHeaps;

            int *piles = new int[numberOfHeaps]; //we use pointer because the size of the array changes, so we need a dynamic variable

            for (size_t i = 0; i < numberOfHeaps; i++) {

                piles[i]=pow(2,i);
                tokens += pow(2,i);
            }

            cout << "\nPlayer 1, enter your name: ";
            cin >> nom;
            p1.setName(nom);

            pc.setTurn(true); //pc is more likely to win if pc plays first
            p1.setTurn(false);

            recursivePC(tokens, numberOfHeaps, piles, pc, p1);

            break;
        }
        case 3:
            cout << "\nGoodbye." << endl;
            break;
        default:
            cout << "Please enter a valid option: ";
            goto L;
    }

    return 0;
}

void recursiveGame(int t, array<int, 5>& rows, Player j1, Player j2)
{
    if (t <= 0) //base case
    {
        j = 65;
        for (size_t i = 0; i < rows.size(); i++)
        {
            cout << endl;
            cout << (char)j << ": ";
            j++;
            for (int j = 1; j <= rows[i]; j++)
            {
                cout << "O ";
            }
            cout << endl;
        }

        if (j1.getTurn() == false) { //we put false otherwise it reports the other player as the winner
            j1.printWin();
        }
        else if (j2.getTurn() == false) {
            j2.printWin();
        }
    }

    else { //recursive case
        j = 65;
        for (size_t i = 0; i < rows.size(); i++)
        {
            cout << endl;
            cout << (char)j << ": ";
            j++;
            for (int j = 1; j <= rows[i]; j++)
            {
                cout << "O ";
            }
            cout << endl;
        }

        if (j1.getTurn() == true) {
            cout << "\nIt's " << j1.getName() << "'s turn!" << endl;
        }
        else {
            cout << "\nIt's " << j2.getName() << "'s turn!" << endl;
        }

        //cout << "There's " << t << " tokens remaining!" << endl;

        cout << "\nChoose one or two tokens from a pile: ";
        cin >> letter >> digit;

        while (digit != 1 && digit != 2) {
        cout << "You can only remove 1 or 2 tokens! Try again: ";
        cin >> letter >> digit;
        }

        if (digit == 1) {
            for (size_t i = 0; i < rows.size(); i++) {
                if ((int)letter == (char)(i+65)) { //since the number of heaps changes, a loop was created that checks if the letter we input matches a letter from a heap
                    rows[i]--;
                }
            }
        }
        else if (digit == 2) {
            for (size_t i = 0; i < rows.size(); i++) {
                if ((int)letter == (char)(i+65)) {
                    rows[i]--;
                    rows[i]--;
                }
            }
        }

        if (j1.getTurn() == true) {
            j1.setTurn(false);
            j2.setTurn(true);
            recursiveGame(t - digit, rows, j1, j2);
        }
        else {
            j2.setTurn(false);
            j1.setTurn(true);
            recursiveGame(t - digit, rows, j1, j2);
        }
    }
}

void recursivePC(int t, size_t h, int*& rows, Player com, Player j1)
{
    int maximum(0);
    int duplicate(0);

    if (t <= 0) //base case
    {
        j = 65;
        for (size_t i = 0; i < h; i++) {
            cout << endl;
            cout << (char)j << ": ";
            j++;
            for (int j = 1; j <= rows[i]; j++) {
                cout << "O ";
            }
            cout << endl;
        }

        if (com.getTurn() == false) {
            com.printWin();
        }
        else if (j1.getTurn() == false) {
            j1.printWin();
        }
    }
    else { //recursive case
        j = 65;
        for (size_t i = 0; i < h; i++)
        {
            cout << endl;
            cout << (char)j << ": ";
            j++;
            for (int j = 1; j <= rows[i]; j++)
            {
                cout << "O ";
            }
            cout << endl;
        }

        if (com.getTurn() == true) {
            cout << "\nIt's " << com.getName() << "'s turn!" << endl;
        }
        else {
            cout << "\nIt's " << j1.getName() << "'s turn!" << endl;
        }

        if (com.getTurn() == true) {
            if (t % 2 == 0) { //if the number of tokens is even, the pc is gonna remove 2 tokens
                maximum = rows[0]; //we want the pc to remove tokens from the heap with the highest amount of tokens
                for (size_t i = 0; i < h; i++) {
                    if (rows[i] > maximum) {
                        maximum = rows[i];
                    }
                }
                for (size_t i = 0; i < h; i++) {
                    if (rows[i] == maximum) {
                        rows[i]--;
                        if (rows[i] == 0) {
                            digit = 1;
                            break;
                        }
                        rows[i]--;
                        digit = 2; //pc took 2 tokens, so have to update the number of tokens
                        break; //putting a break because otherwise if there are 2 heaps with the same number of tokens, the pc will remove tokens from the 2 heaps
                    }
                }
            }
            else if (t % 2 == 1) { //otherwise, if the number of tokens is odd, the pc is gonna remove 1 token
                maximum = rows[0];
                for (size_t i = 0; i < h; i++) {
                    if (rows[i] > maximum) {
                        maximum = rows[i];
                    }
                }
                //check if there are 2 rows with the same even number of tokens
                for (size_t i = 0; i < h; i++) {
                    for (size_t j = 0; j < h; j++) {
                        if (rows[j] == rows[i] && rows[j] % 2 == 0 && rows[i] % 2 == 0 && i != j) {
                            duplicate = rows[j];
                        }
                    }
                }

                //situation 1: there are duplicate heaps and they are not empty
                for (size_t i = 0; i < h; i++) {
                    if (rows[i] == duplicate && duplicate != 0) {
                        for (size_t j = 0; j < h; j++) {
                            if (duplicate != maximum && rows[j] == duplicate) { //case 1.1: pc removes a token from one of the duplicate heaps
                                rows[j]--;
                                break;
                            }
                            else if (rows[j] != 0 && rows[j] != duplicate) { //case 1.2: pc removes a token not from the duplicate heaps
                                rows[j]--;
                                break;
                            }
                        }
                        digit = 1;
                        break;
                    }

                    //situation 2: there are no duplicate heaps
                    else if (rows[i] == maximum) {
                        rows[i]--; //pc removes a token from the heap with the highest number of tokens
                        digit = 1;
                        break;
                    }
                }
            }
        } //end of algorithm

        else if (j1.getTurn() == true) {
            cout << "\nChoose one or two tokens from a pile: ";
            cin >> letter >> digit;

            while (digit != 1 && digit != 2) {
            cout << "You can only remove 1 or 2 tokens! Try again: ";
            cin >> letter >> digit;
            }
            if (digit == 1) {
                for (size_t i = 0; i < h; i++) {
                    if ((int)letter == (char)(i+65)) { //since the number of heaps changes, a loop was created that checks if the letter we input matches a letter from a heap
                        rows[i]--;
                    }
                }
            }
            else if (digit == 2) {
                for (size_t i = 0; i < h; i++) {
                    if ((int)letter == (char)(i+65)) {
                        rows[i]--;
                        rows[i]--;
                    }
                }
            }
        }

        if (com.getTurn() == true) {
            com.setTurn(false);
            j1.setTurn(true);
            recursivePC(t - digit, h, rows, com, j1);
        }
        else {
            j1.setTurn(false);
            com.setTurn(true);
            recursivePC(t - digit, h, rows, com, j1);
        }
    }
}
