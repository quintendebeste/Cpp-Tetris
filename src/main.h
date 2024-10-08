#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "NodeStruct.h"

const int windowWidth = 1000;
const int windowHeight = 1000;
sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tetris");
std::vector<char> pieceShapes = {'I', 'L', 'J', 'O', 'T', 'S', 'Z'};
std::vector<std::vector<char>> bag;
char holdingPiece = ' ';
int bagSize = 3;
std::vector<Node> gridArray;

bool gameover = false;
int points = 0;
int level = 1;

float multiplier = 1.5f;

#include "piece.h"
#include "utilities.cpp"

const float FPS = 60;
float frameCounter = 0;
float interval = FPS;


sf::Event event;

bool genPiece = true;
std::vector<Piece> pieceArray;

float keyPressframeCounter = 0;
float keyPressInterval = 1 / multiplier;

float timeToHoldKey = 20 / multiplier;
float holdCounter = 0;
bool KeyHold = false;

bool KeyReleased = true;
sf::Keyboard::Key pressedKey = sf::Keyboard::Unknown;

int main();

void gameloop(
    std::vector<Node>& gridArray,
    bool& genPiece,
    std::vector<Piece>& pieceArray,
    float& frameCounter,
    float& interval
);