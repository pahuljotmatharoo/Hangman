#include <cmath>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

string RandomWord() {
    //for picking the random word
    srand(static_cast<unsigned int>(std::time(nullptr)));
    vector <string> words = { "cat", "dog", "bear", "fox", "bird", "horse", "lion", "zerba", "whale", "tiger", "wolf", "snail", "owl", "bison", "snake", "crab", "dhole", "dragonfly", "donkey", "falcon", "walrus"};
    int random = rand() % words.size();
    string picked = words[random];
    return picked;
}

int main()
{
    bool loop = true;
    //Choice of possible words (Add more)

    //Computer chosen word vector
    vector <char> charactersc;

    //Player word vector
    vector <char> charactersp;

    vector <char> user;

    vector <char> dashes;

    int strikes = 1;
 
    string guessing = RandomWord();
    cout << "Welcome to Hangman!, the computer has picked a random ANIMAL, and you have to guess its name!\n";
    cout << "\nThe word has " << guessing.size() << " letters\n";

    for (int i = 0; i < guessing.size(); i++) {
        dashes.push_back('_');
    }
    
    //Putting computer word into vector
    for (int i = 0; i < guessing.size(); i++) {
        charactersc.push_back(guessing[i]);
    }

    cout << "\nWhat is your first letter guess?\n";

    int size = charactersc.size();

    bool found = false;

    char choice; 

    //Checking guess with vector from computer
    while (strikes <= 8 && user.size() < size ) {
        cout << "\n";
        cin >> choice;
        for (int j = 0; j < charactersc.size(); j++) {
            if (charactersc[j] == choice) {
                found = true;
                cout << "Correct Guess \n";
                user.push_back(choice); 
                dashes[j] = choice;
                break;
            } 
            else {
                found = false;
            }
            }

        for (int i =  0; i < dashes.size(); i++) {
            cout << dashes[i];
        }

        if (!found) {
        cout << "Wrong, Strike " << strikes << " Try again \n";
        loop = true;
        strikes++;
        }
        cout << "\n";
    } 
    //while loop end

    if (size == user.size()) {  
        cout << "\n" << "You Won! Congradulations! \n"; 
    }

    else {
        cout << "You lost, the word was " << guessing << " Better luck next time! \n";
    }
}