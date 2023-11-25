#include "Gallows.h"

void Gallows::displayGallows() {
    for (int i = 0; i < 8; i++) {
        std::cout << gallows[i] + "\n";
    }
}
void Gallows::hangPiece() {
    if (gallows[2].length() == 1) {
        gallows[2] += "    (\\";
    }
    else if (gallows[2].length() == 7) {
        gallows[2] += "_/)";
    }
    else if (gallows[3].length() == 1) {
        gallows[3] += "    ('-')";
    }
    else if (gallows[4].length() == 1) {
        gallows[4] += "   (\")";
    }
    else if (gallows[4].length() == 7) {
        gallows[4] += "_(\")";
    }
}

std::string Gallows::getGallows(int  index) {
    return gallows[index];
}

void Gallows::setGallows(int index, std::string newLine) {
    gallows[index] = newLine;
}