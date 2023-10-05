#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <limits>

using namespace std;

void invalidInput() {
  cout << "\n\033[1;31mInvalid input\033[0m\n";
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Prompts for and takes input of a char representing difficulty (Easy,
// Moderate, Advanced)
char displayMenu() {
  char dif;
  cout << "Welcome to NumQuiz\n\nEnter your desired difficulty (Please enter "
          "E, M or A):\nE) Easy\nM) Moderate\nA) Advanced\n";
  cin >> dif;
  dif = toupper(dif);
  if (dif == 'E' || dif == 'M' || dif == 'A') {
    return dif;
  } else {
    invalidInput();
    return displayMenu();
  }
}

// Returns a random integer between two arguments
int randomInt(int min, int max) { return rand() % (max - min + 1) + min; }

int generateOperands(char dif) {
  if (dif == 'E') {
    return randomInt(1, 9);
  } else if (dif == 'M') {
    return randomInt(10, 99);
  } else {
    return randomInt(1000, 9999);
  }
}

char randomOperator(int num1) { return num1 % 2 == 0 ? '+' : '-'; }

int calculateResult(int num1, int num2, char oper) {
  if (oper == '+') {
    return num1 + num2;
  }
  return num1 - num2;
}

// Prompts and takes user input of answer
long displayProblem(int num1, int num2, char oper) {
  long answer;
  cout << "\n\nWhat is:\n"
       << num1 << " " << oper << " " << num2 << "?"
       << "\n";
  cin >> answer;
  if (cin.fail()){
    invalidInput();
    return displayProblem(num1, num2, oper);
  }
  return answer;
}

// Returns true/false depending on answer
bool isCorrect(int result, int answer) {
  return result == answer ? true : false;
}

void displayMessage(bool correct, int chances, int correctTally) {
  // Outputs correct or incorrect, and displays if the user has another chance
  if (correct) {
    cout << "\n\033[1;32mCorrect answer!\033[0m\n";
  } else {
    cout << "\n\033[1;31mIncorrect\033[0m";
    if (chances >= 2) {
      cout << "\nYou have " << chances - 1 << " chances remaining\n";
    } else {
      cout << "\n\033[1;31mQuestion over\033[0m\n";
    }
  }
}

void displayFinalResults() {
  // Tally of correct and incorrect answers
}

int main() {
  int chances = 2;
  int correctTally = 0;
  const int questions = 10;
  srand(time(NULL));
  const char difficulty = displayMenu();
  cout << difficulty;
  // for (int i = 0; i<1000; i++){
  // cout << "\n"<<randomInt(10, 100);};

  // Outer loop for all the questions
  for (int i = 0; i < questions; i++) {
    chances = 2;
    int num1 = generateOperands(difficulty);
    int num2 = generateOperands(difficulty);
    char oper = randomOperator(num1);
    int result = calculateResult(num1, num2, oper);
    // Inner loop for each question (chances)
    while (chances > 0) {
      long answer = displayProblem(num1, num2, oper);
      bool correct = isCorrect(result, answer);
      displayMessage(correct, chances, correctTally);
      if (correct) {
        correctTally += 1;
        break;
      } else {
        chances -= 1;
        // if (chances < 1) {
        //   continue;
        // }
      }
    }
  }
  cout << "You got " << correctTally << " right!";

  // cout << "\n" << num1 << " " << oper << " " << num2 << "\n";
  // cout << "= " << result;
}