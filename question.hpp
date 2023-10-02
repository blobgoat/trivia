#include <iostream>
#include<vector>

class Question {


//class variables
//same as java
private:
  std::string category;
  std::string type;
  std::string difficulty;
  std::string question;
  std::string correct_answer;
  int sizeIncorrectAnswers;
  std::vector<std::string> *incorrect_answers = new std::vector<std::string>;

//functions
//constructor
public:
  Question(std::string fileName);
  Question(std::string text, bool marker);
  std::string getCategory();
  std::string getQuestion();
  std::string getCorrectAnswer();
  std::string getDifficulty();
  std::vector<std::string>* getIncorrectAnswers();

  
  
  //otherfunctions
  void printQuestion();
  
  
  //destructor
  ~Question();
};