#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "game_of_life.h"
#include <string>

void testConstructorWithDefaultParameters(std::string in_file) {
    GameOfLife game(in_file);
    assert(game.GetWidth() == 10);
    assert(game.GetHeight() == 5);
    assert(game.GetGenerations() == 0);
    assert(game.GetAvailableGens() == 0);
}

void testConstructorWithLiveAndDeadCellParameters(std::string in_file, char in_liveCell, char in_deadCell) {
    // file.txt, liveCell, deadCell, pregens
    GameOfLife game(in_file, in_liveCell, in_deadCell);
    assert(game.GetLiveCell() == in_liveCell);
    assert(game.GetDeadCell() == in_deadCell);
}

void testNextGen(std::string in_file) {
    GameOfLife game(in_file);
    game.NextGen();
    assert(game.GetGenerations() == 1);
    // Add more assertions based on expected next generation state
}

void testNextNGen(std::string in_file) {
    GameOfLife game(in_file);
    game.NextNGen(5);
    assert(game.GetGenerations() == 5);
    // Add more assertions based on expected state after 5 generations
}

void testToggleCell(std::string in_file) {
    GameOfLife game(in_file);
    char before = game.GetSpecificCellString(1);
    game.ToggleCell(1);
    char after = game.GetSpecificCellString(1);
    assert(before != after);
}

void testToggleCellCoordinates(std::string in_file) {
    // Create a GameOfLife object
    GameOfLife game(in_file);
    
    // Test toggling a cell from dead to alive
    char before = game.GetSpecificCell(1,1);
    game.ToggleCell(1, 1);
    char after = game.GetSpecificCell(1, 1);
    assert(before != after);
}

void testIsStillLife(std::string in_file) {
    GameOfLife game(in_file);
    GameOfLife game1("/Users/willschmitz/Documents/Code/CPPMore/GameOfLifeFinal/GameOfLifeFinal/text/stillLife.txt");
    assert(!game.IsStillLife());
    int pastGen = game1.GetGenerations();
    assert(game1.IsStillLife());
    assert(pastGen == game1.GetGenerations());
    // Add more assertions after verifying some still life states
}

void testHistoryStorage(std::string in_file){
    GameOfLife game(in_file);
    game.NextNGen(100);
}

void testGenWindow(std::string in_file){
    GameOfLife game(in_file);
    std::cout << game.GenWindow(0, 0, game.GetHeight(), game.GetWidth()) << std::endl;
}

void testOperators(std::string in_file){
    GameOfLife game(in_file);
    int pastGenerations = game.GetGenerations();
    std::string pastState = game.GetCurrent();
    game += 1; // steps forward by i amount
    assert(game.GetGenerations() != pastGenerations);
    assert(game.GetCurrent() != pastState);
    std::cout << "game += 1 passed" << std::endl;
    game -= 1; // rolls the game backwards
    assert(game.GetGenerations() == pastGenerations);
    assert(game.GetCurrent() == pastState);
    std::cout << "game -= 1 passed" << std::endl;
    GameOfLife stepForwardGame = game + 1; // creates a copy of a game walked forwards by i amount
    assert(stepForwardGame.GetGenerations() == game.GetGenerations()+1);
    game += 1;
    assert(stepForwardGame.GetCurrent() == game.GetCurrent());
    assert(stepForwardGame.GetCurrent() != pastState);
    std::cout << "newGame = game + 1 passed" << std::endl;
    // GameOfLife stepBackGame = game - 1; // creates a copy of a game rolled back by i amount
    
    GameOfLife anotherGame(in_file);
    int anotherPastGenerations = anotherGame.GetGenerations();
    anotherGame--;
    assert(anotherGame.GetGenerations() != anotherPastGenerations);
    GameOfLife decrementedGame = --anotherGame;
    // game--; // post decrement
    // --game; // pre-decrement
    
    GameOfLife flippedGame = -game; // flips all the live and dead cells
    assert(flippedGame.GetCurrent() != game.GetCurrent());
}

int main() {
    std::string test_file = "/Users/willschmitz/Documents/Code/CPPMore/GameOfLifeFinal/GameOfLifeFinal/text/test.txt";
    std::cout << "TestFile: " << test_file << std::endl;
    
    testConstructorWithDefaultParameters(test_file);
    std::cout << "game(in_file) Passed" << std::endl;
    
    testConstructorWithLiveAndDeadCellParameters(test_file, '&', '$');
    std::cout << "game(in_file, LiveCell, DeadCell) Constructor Passed" << std::endl;
    
    testNextGen(test_file);
    std::cout << "NextGen() passed" << std::endl;
    testNextNGen(test_file);
    std::cout << "NextGen(int) passed" << std::endl;
    
    testToggleCell(test_file);
    std::cout << "ToggleCell() Passed" << std::endl;
    
    testToggleCellCoordinates(test_file);
    std::cout << "ToggleCellSpecific() Passed" << std::endl;
    
    testIsStillLife(test_file);
    std::cout << "IsStillLife() Passed" << std::endl;
    
    testHistoryStorage(test_file);
    std::cout << "History storage Passed" << std::endl;
    
    testGenWindow(test_file);
    std::cout << "GenWindow(0, 0, maxHeight, maxWidth) Passed" << std::endl;
    
    testOperators(test_file);
    std::cout << "OperatorTest Passed" << std::endl;
    
    std::cout << "All tests passed successfully" << std::endl;
    return 0;
}
