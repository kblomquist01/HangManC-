// HangMan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include "Gallows.h"
int main()
{
    srand((int)time(0));
    std::cout << "press enter to play";
    std::cin.ignore();
    std::string secretWords[10] = {"peace", "peas", "christmas", "joy", "alphabet", "cans", "seven", "eight", "nine", "ten"};
    std::string secret = secretWords[rand() % 10];
    std::string displayWord = "";
    std::string lettersToGuess = "abcdefghijklmnopqrstuvwxyz";

    for (char letter : secret) {
        displayWord += "-";
    }
    
    Gallows gallows(displayWord);

    bool gameEnd = false;
    while (!gameEnd) {//displayWord != secret || gallows == "|"){
        gallows.displayGallows();
        std::string guess;
            std::cout << "please enter your 1 character or guess the word: ";

        std::cin >> guess;
        std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower);
         
        int index = 0;
        bool correctGuess = false;
        if(guess.length() == 1){
            for (char letter : lettersToGuess) {
                if (letter == guess[0]) {
                    lettersToGuess = lettersToGuess.substr(0, index) + lettersToGuess.substr(index + 1);
                    gallows.setGallows(7, "unguessed letters: " + lettersToGuess);
                    correctGuess = false;
                    break;
                }
                else {
                    correctGuess = true;
                }
                index += 1;

            }
            index = 0;
            for (char letter : secret) {
                if (letter == guess[0]) {
                    displayWord = displayWord.substr(0, index) + guess[0] + displayWord.substr(index + 1);
                    gallows.setGallows(6, "guess: " + displayWord);
                    correctGuess = true;
                }

                index += 1;

              }

             if (!correctGuess) {
                  gallows.hangPiece();
             }
             if (displayWord == secret) {
                  gameEnd = true;
                  std::cout << "secret word was " + secret;
             }
             if (gallows.getGallows(4).length() == 11) {
                gameEnd = true;
                gallows.displayGallows();
            }
        }
        else {
            if (secret == guess) {
                gameEnd = true;
                std::cout << "secret word was " + secret;
            }
            else {
                gallows.hangPiece();
            }
        }

    }

}
