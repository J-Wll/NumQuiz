#include <iostream>
#include <ctype.h>
#include <ctime>
#include <limits>
#include <cstdlib>

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
  return rand() % (max - min +1) + min;  
}

int generateOperands(char dif){
  if (dif == 'E'){
    return randomInt(1,9);
  }
  else if (dif == 'M'){
    return randomInt(10,99);
  }
  else{
    return randomInt(1000,9999);
  }
  
}

char randomOperator(int num1){return num1%2==0 ? '+' : '-';}

int calculateResult(int num1, int num2, char oper){
  if (oper == '+'){
    return num1 + num2;
  }
  return num1-num2;
}

// Prompts and takes user input of answer
long int displayProblem(int num1, int num2, char oper){
  
}

// Returns true/false depending on answer
bool isCorrect(int result, int answer){
  
}

void displayMessage(){
  // Outputs correct or incorrect, and displays if the user has another chance
}

void displayFinalResults(){
  // Tally of correct and incorrect answers
}

int main() {
  srand(time(NULL));
  const char difficulty = displayMenu();  
  cout << difficulty;
  // for (int i = 0; i<1000; i++){
  // cout << "\n"<<randomInt(10, 100);};
  const int num1 = generateOperands(difficulty);
  const int num2 = generateOperands(difficulty);
  const char oper = randomOperator(num1);
  const int result = calculateResult(num1, num2, oper);
  

  cout << "\n" << num1 << " " << oper << " " << num2 << "\n";
  cout << "= " << result;
  
}