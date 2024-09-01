#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

//VARIABLES: Grid
const int sizeOfGrid = 3;
double halfGrid = floor(sizeOfGrid/2);
int halfSizeInt = halfGrid;
int grid[sizeOfGrid][sizeOfGrid];

//VARIABLES: Player
int playerNumber = 0;
int playerPositionX = 1;
int playerPositionY = 1;
string choices[4] = {"up","right","down","left"};
int totalMoves = 6;

//VARIABLES: Game
bool isGame = false;
int roundCount = 0;
int goalNumber = 0;
int moveCount = 0;

//VARIABLES: Scoresheet
fstream inFile;
fstream outFile;
struct userScore{
  int score;
  string userName;
};
userScore currentUserScore;
vector <userScore> scoreStorage;

//SCORESHEET
//ITERATION: removes data in scoreStorage array until empty
void clearScoreArray(){
    while(scoreStorage.size() > 0){
        scoreStorage.pop_back();
    }
}

//ITERATION: Formats the display of the score array
void displayArray(){
    for(int n = 0; n < scoreStorage.size();n++){
        cout << "+-----------+" << endl;
        cout << scoreStorage[n].userName << endl;
        cout << "+-----------+" << endl;
    }
}

void checkForFile(){
    inFile.open("users.txt");
    if(!inFile.is_open()){
        std::ofstream inFile ("users.txt");
        inFile << "0 gamer"<< "\n" << std::endl;
    }
}

//ARRAY, ITERATION, FILEIO, CONTROL :Opens the score sheet file, reads it, turns it into variables in a struct and stores the structs in an array for sorting
void scoreSheetToArray(){
    clearScoreArray();
    checkForFile();
    string textLine;
    while(getline(inFile, textLine)){
        int lineLength = textLine.length();
        if(lineLength > 0){
            string tempScore = "";
            string tempName = "";
            bool spaceSeen = false;
            userScore newUserScore;
            for (int i = 0; i < lineLength; i++) {
                if(textLine[i] == ' '){
                    spaceSeen = true;
                    continue;
                }
                if(spaceSeen){
                    tempName += textLine[i];
                }else{
                tempScore += textLine[i];
                }
            }
            if(tempScore!=""){
                int convertedScore = stoi(tempScore);
                newUserScore.score = convertedScore;
                newUserScore.userName = tempName;
                scoreStorage.push_back(newUserScore);
                spaceSeen = false;
            }
        }
    }
    inFile.close();
}

//ARRAY, ITERATION, CONTROL: This will sort our score sheet array from lowest score to heighest
void bubbleSort(){
    bool swapped = false;
    if(scoreStorage.size() > 0){
        do{
        swapped = false;
        for(int n = 0; n < scoreStorage.size()-1; n++){
            if(scoreStorage[n].score > scoreStorage[n+1].score){
                userScore storage = scoreStorage[n];
                scoreStorage[n] = scoreStorage[n+1];
                scoreStorage[n+1] = storage;
                swapped = true;
            }
        }
    } while(swapped);
    }
}

//ARRAY, ITERATION, CONTROL: This will display the score board in reverse order so that it goes highest score to lowest
void displayScores(){
    scoreSheetToArray();
    bubbleSort();
    for(int n = scoreStorage.size(); n >= 0; n--){
        if(!scoreStorage[n].userName.empty()){
            cout << scoreStorage[n].score << " " << scoreStorage[n].userName << endl;
        }
    }
}

//FILEIO, CONTROL: After losing the current user's username will be written with their score to the score sheet
void writeToScoreSheet(){
    currentUserScore.score = roundCount;
        outFile.open("users.txt", std::ios_base::app);
    if(outFile.is_open()){
        outFile << currentUserScore.score << " " << currentUserScore.userName << "\n";
        outFile.close();
    }
}


//INTRODUCTION
//INPUT, OUTPUT, CONTROL: ask for the name that will be stored, error catching for invalid inputs
void askForName(){
    cout << "Enter your user name: ";
    cin >> currentUserScore.userName;
    if(!cin.good()){ //if user gives a bad input, an infinite loop can occur
        cin.ignore(1000);  //dump the bad input
        cin.clear();  //resetting cin to take in a new input
        system("clear");
        askForName();
    }
}
//ITERATION: This will take in numbers from the board to combine into a goal number
void createGoalNumber(){
    int min = 0;
    int max = 3;
    goalNumber = 0;
    for(int i = 0; i < 2; i++){
        int randNum = rand()%(max-min + 1) + min;
        int randNumTwo = rand()%(max-min + 1) + min;
        goalNumber += grid[randNum][randNumTwo];
    }
}
//ITERATION: Creates randomly generated numbers to be placed in each grid cell
void populateMap(){
    for(int x = 0; x < sizeOfGrid; x++){
        for(int y = 0; y < sizeOfGrid; y++){
            int min = -3;
            int max = 10;
            int randNum = rand()%(max-min + 1) + min;
            grid[y][x] = randNum;
        }   
    }
    grid[halfSizeInt][halfSizeInt] = 0;
    createGoalNumber();
}
//This is a function that executes functions that only run at the start
void introduction(){
    askForName();
    populateMap();
    isGame = true;
}


//GAME_LOOP
//ARRAY, ITERATION, CONTROL: through the 2D array to display the board state
void displayGrid() {
    cout << endl;
    cout << "+-----GOAL:" << goalNumber << "----ROUND:" << roundCount << "----+" << endl;
    cout << "|                          |" << endl;
    for(int x = 0; x < sizeOfGrid; x++){
        cout << "|     ";
        for(int y = 0; y < sizeOfGrid; y++){
            if(x == playerPositionY && y == playerPositionX){
                if(playerNumber > 9){
                    cout << " " << ">" << playerNumber << "<" << "";
                }else{
                    cout << " " << ">" << playerNumber << "<" << " ";
                }
            }else{
                if(grid[y][x] > 9 || grid[y][x] < 0){
                    cout << "  " << grid[y][x] << " ";
                }else{
                    cout << "  " << grid[y][x] << "  ";
                }

            }
        }
        cout << "      |";
        cout << endl;
        cout << "|                          |" << endl;
    }
    cout << "|      MOVES LEFT:" << totalMoves - moveCount << "        |" << endl;
}
//ARRAY: Whichever square the player moved to we add it to their total and set the value of the square to 0
void addToPlayerNumber(){
    playerNumber += grid[playerPositionX][playerPositionY];
    grid[playerPositionX][playerPositionY] = 0;
}

//ALGORITHMS, INTERACTION, CONTROL: Handles moving the player based on their choice and checks for incorrect inputs
void movePlayer( int playerChoice){
    if(playerChoice == 1){          //up
        if(playerPositionY > 0){
            playerPositionY -= 1;
            moveCount++;
            addToPlayerNumber();
        }else{
            cout << "Cannot Move there" << endl;
        }
    }else if(playerChoice == 2){    //right
        if(playerPositionX < 2){
            playerPositionX += 1;
            moveCount++;
            addToPlayerNumber();
        }else{
            cout << "Cannot Move there" << endl;
        }

    }else if(playerChoice == 3){    //down
        if(playerPositionY < 2){
            playerPositionY += 1;
            moveCount++;
            addToPlayerNumber();
        }else{
            cout << "Cannot Move there" << endl;
        }
    }else if(playerChoice == 4){    //left
            if(playerPositionX > 0){
                playerPositionX -= 1;
                moveCount++;
                addToPlayerNumber();
                
        }else{
            cout << "Cannot Move there" << endl;
        }
    }
    cout << choices[playerChoice] << endl;
}
//ARRAY, ITERATION: Will cycle through the options to move and will ask what the player will do
void displayMoveOptions(){
    cout << "+----+-------+------+------+" << endl;
    cout << "| ";
    for(int i=0; i < 4;i++){
        cout << choices[i] << " | ";
    }
    cout << endl;
    cout << "+-1--+---2---+---3--+---4--+" << endl;
    int playerChoice = 5;
    cout << "Input a number 1-4: ";
    cin >> playerChoice;
        if(!cin.good()){ //if user gives a bad input, an infinite loop can occur
        cin.ignore(1000);  //dump the bad input
        cin.clear();  //resetting cin to take in a new input
        system("clear");
        playerChoice = 5;
        displayMoveOptions();
    }
    movePlayer(playerChoice);
}
//called when player runs out of moves, displays the score sheet and ends the program
void gameOver(){
    isGame = false;
    writeToScoreSheet();
    system("clear");
    cout << "!!!-----------GAME OVER-----------!!!" << endl;
    displayScores();
    cout << endl;
    cout << "!!!-----------GAME OVER-----------!!!" << endl;
}
//ALGORITHM, CONTROL: Called every move to see if your current number equals the goal number
void checkForWin(){
    if(playerNumber == goalNumber){
        cout << "You won this round!" << endl;
        roundCount++;
        moveCount = 0;
        system("clear");
        populateMap();
        playerPositionX = halfSizeInt;
        playerPositionY = halfSizeInt;
        playerNumber = 0;
    }else{
        if(moveCount >= totalMoves){
            gameOver();
        }
    }
}
//ITERATION: Houses all functions executed to complete a game loop
void gameLoop(){
    system("clear");
    displayGrid();
    displayMoveOptions();
    checkForWin();
    if(isGame){
        gameLoop();
    }
}

//Main function called at the start with a declaration of how we will randomize our numbers with a seed based on time
int main(){
    srand((unsigned) time(NULL));
    introduction();
    gameLoop();
    return 0;
}
