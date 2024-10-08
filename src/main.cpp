#include "main.h"

int main(){
    window.setSize(sf::Vector2u(windowWidth, windowHeight)); 

    window.setFramerateLimit(FPS);
    initGrid(gridArray);
    generateBag(pieceShapes, bag, bagSize);

    while (window.isOpen())
    {
        window.clear(sf::Color::Black);

        frameCounter++;
        keyPressframeCounter++;
        interval = FPS / multiplier;

        gameloop(gridArray, genPiece, pieceArray, frameCounter, interval);
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.display();
    }

    return 0;
}
void gameloop(std::vector<Node>& gridArray, bool& genPiece, std::vector<Piece>& pieceArray, float& frameCounter, float& interval){
    if(!gameover){

        generateBag(pieceShapes, bag, bagSize);
        if(genPiece == true){
            generatePiece(pieceArray, bag);
            genPiece = false;
        }

        if (frameCounter >= interval) {
            moveActivePieceDown(pieceArray);
            frameCounter = 0;
        }else{
            if (event.type == sf::Event::KeyPressed) {
                pressedKey = event.key.code;
            }

            if (event.type == sf::Event::KeyReleased) {
                KeyReleased = true;
                holdCounter = 0;
                KeyHold = false;
            }else{
                KeyReleased = false;
                holdCounter++;
            }

            if (holdCounter >= timeToHoldKey){
                KeyHold = true;
                holdCounter = 0;
            }

            if (keyPressframeCounter >= keyPressInterval) {
                movementActivePiece(pieceArray, pressedKey, KeyReleased, KeyHold);
                keyPressframeCounter = 0;
            }
        }
    }
    drawGrid(gridArray, pieceArray);
}