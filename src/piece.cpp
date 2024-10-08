#include "piece.h"

void Piece::calculatePiecePositions() {
    positions.clear();
    switch (shape) {
        case 'I':
            if(rotation % 2 == 0){
                positions.push_back({centerPosition.x, centerPosition.y + 1});
                positions.push_back({centerPosition.x, centerPosition.y - 1});
                positions.push_back({centerPosition.x, centerPosition.y - 2});
            }else{
                positions.push_back({centerPosition.x + 1, centerPosition.y});
                positions.push_back({centerPosition.x - 1, centerPosition.y});
                positions.push_back({centerPosition.x - 2, centerPosition.y});
            }
            break;

        case 'O':
            positions.push_back({centerPosition.x + 1, centerPosition.y});
            positions.push_back({centerPosition.x + 1, centerPosition.y + 1});
            positions.push_back({centerPosition.x, centerPosition.y + 1});
            break;

        case 'T':
            if(rotation == 1){
                positions.push_back({centerPosition.x, centerPosition.y - 1});
                positions.push_back({centerPosition.x + 1, centerPosition.y});
                positions.push_back({centerPosition.x - 1, centerPosition.y});
            }else if(rotation == 2){
                positions.push_back({centerPosition.x + 1, centerPosition.y});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
                positions.push_back({centerPosition.x, centerPosition.y - 1});
            }else if(rotation == 3){
                positions.push_back({centerPosition.x + 1, centerPosition.y});
                positions.push_back({centerPosition.x - 1, centerPosition.y});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
            }else if(rotation == 4){
                positions.push_back({centerPosition.x - 1, centerPosition.y});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
                positions.push_back({centerPosition.x, centerPosition.y - 1});
            }
            break;

        case 'S':
            if(rotation == 1){
                positions.push_back({centerPosition.x, centerPosition.y - 1});
                positions.push_back({centerPosition.x + 1, centerPosition.y - 1});
                positions.push_back({centerPosition.x - 1, centerPosition.y});
            }else if(rotation == 2){
                positions.push_back({centerPosition.x, centerPosition.y - 1});
                positions.push_back({centerPosition.x + 1, centerPosition.y});
                positions.push_back({centerPosition.x + 1, centerPosition.y + 1});
            }else if(rotation == 3){
                positions.push_back({centerPosition.x - 1, centerPosition.y + 1});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
                positions.push_back({centerPosition.x + 1, centerPosition.y});
            }else if(rotation == 4){
                positions.push_back({centerPosition.x - 1, centerPosition.y - 1});
                positions.push_back({centerPosition.x - 1, centerPosition.y});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
            }
            break;

        case 'Z':
            if(rotation == 1){
                positions.push_back({centerPosition.x, centerPosition.y - 1});
                positions.push_back({centerPosition.x - 1, centerPosition.y - 1});
                positions.push_back({centerPosition.x + 1, centerPosition.y});
            }else if(rotation == 2){
                positions.push_back({centerPosition.x + 1, centerPosition.y - 1});
                positions.push_back({centerPosition.x + 1, centerPosition.y});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
            }else if(rotation == 3){
                positions.push_back({centerPosition.x - 1, centerPosition.y});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
                positions.push_back({centerPosition.x + 1, centerPosition.y + 1});
            }else if(rotation == 4){
                positions.push_back({centerPosition.x - 1, centerPosition.y + 1});
                positions.push_back({centerPosition.x - 1, centerPosition.y});
                positions.push_back({centerPosition.x, centerPosition.y - 1});
            }
            break;

        case 'J':
            if(rotation == 1){
                positions.push_back({centerPosition.x - 1, centerPosition.y});
                positions.push_back({centerPosition.x + 1, centerPosition.y});
                positions.push_back({centerPosition.x - 1, centerPosition.y - 1});
            }else if(rotation == 2){
                positions.push_back({centerPosition.x, centerPosition.y - 1});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
                positions.push_back({centerPosition.x + 1, centerPosition.y - 1});
            }else if(rotation == 3){
                positions.push_back({centerPosition.x - 1, centerPosition.y});
                positions.push_back({centerPosition.x + 1, centerPosition.y});
                positions.push_back({centerPosition.x + 1, centerPosition.y + 1});
            }else if(rotation == 4){
                positions.push_back({centerPosition.x, centerPosition.y - 1});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
                positions.push_back({centerPosition.x - 1, centerPosition.y + 1});
            }
            break;

        case 'L':
            if(rotation == 1){
                positions.push_back({centerPosition.x - 1, centerPosition.y});
                positions.push_back({centerPosition.x + 1, centerPosition.y});
                positions.push_back({centerPosition.x + 1, centerPosition.y - 1});
            }else if(rotation == 2){
                positions.push_back({centerPosition.x, centerPosition.y - 1});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
                positions.push_back({centerPosition.x + 1, centerPosition.y + 1});
            }else if(rotation == 3){
                positions.push_back({centerPosition.x - 1, centerPosition.y});
                positions.push_back({centerPosition.x + 1, centerPosition.y});
                positions.push_back({centerPosition.x - 1, centerPosition.y + 1});
            }else if(rotation == 4){
                positions.push_back({centerPosition.x, centerPosition.y - 1});
                positions.push_back({centerPosition.x, centerPosition.y + 1});
                positions.push_back({centerPosition.x - 1, centerPosition.y - 1});
            }
            break;

        default:
            // Handle unknown shapes or errors
            std::cout << shape << std::endl;
            break;
    }
};

std::vector<sf::Vector2f> Piece::getAllPositions() {
    std::vector<sf::Vector2f> allPositions;
    for(sf::Vector2f position : positions){
        allPositions.push_back(position);
    }
    allPositions.push_back(centerPosition);

    return allPositions;
};

void Piece::moveDown(){
    positions.clear();
    centerPosition = {centerPosition.x, centerPosition.y + 1.f};
    calculatePiecePositions();
};

void Piece::moveLeft(){
    positions.clear();
    centerPosition = {centerPosition.x - 1.f, centerPosition.y};
    calculatePiecePositions();
};

void Piece::moveRight(){
    positions.clear();
    centerPosition = {centerPosition.x + 1.f, centerPosition.y};
    calculatePiecePositions();
};

void Piece::Rotate(){
    positions.clear();
    if(rotation >= 4){
        rotation = 1;
    }else{
        rotation++;
    }
    calculatePiecePositions();
};