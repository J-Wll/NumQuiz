#include <iostream>
#include <ctype.h>
#include <ctime>
#include <limits>

using namespace std;

void invalidInput(){
  cout << "\n\033[1;31mInvalid input, please follow input requirements\033[0m\n\n"; 
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Prompts for and takes input of a char representing difficulty (Easy, Moderate, Advanced)
char displayMenu(){
  char dif;
  cout << "Welcome to NumQuiz\n\nEnter your desired difficulty (Please enter E, M or A):\nE) Easy\nM) Moderate\nA) Advanced\n";
  cin >> dif;
  dif = toupper(dif);
  if(dif == 'E' || dif == 'M' || dif == 'A'){
    return dif;
  } else {
    invalidInput();    
    return displayMenu();
  } 
}

// Returns a random integer between two arguments
int randomInt(int min, int max){
}

// Prompts and takes user input of difficulty
void generateOperands(char difficulty){
  
}

// Prompts and takes user input of answer
long int displayProblem(int operand1, int operand2){
  
}

// Returns true/false depending on answer
bool isCorrect(int operand1, int operand2, int answer){
  
}

void displayMessage(){
  // Outputs correct or incorrect, and displays if the user has another chance
}

void displayFinalResults(){
  // Tally of correct and incorrect answers
}

int main() {
  const char difficulty = displayMenu();  
  cout << difficulty;
  
}