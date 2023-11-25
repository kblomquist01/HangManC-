#pragma once
#include <string>
#include <iostream>
class Gallows
{
public:
    Gallows(std::string displayWord){
        setGallows(0, "________");
        setGallows(1, "|      |");
        setGallows(2, "|");
        setGallows(3, "|");
        setGallows(4, "|");
        setGallows(5, "|");
        setGallows(6, "guess: " + displayWord);
        setGallows(7, "unguessed letters: abcdefghijklmnopqrstuvwxyz");
    }
    void hangPiece();
    void displayGallows();
    std::string getGallows(int index);
    void setGallows(int index, std::string newLine);
private:
    std::string gallows[8];
};

