// FILE: quiz.hpp
// AUTHOR: Jacob Seaman
// DATE: 5/27/23

// ABOUT:  will hold objects of type question
#include <iostream>
#include<vector>
#include "question.hpp"
class Quiz{
  public:

    std::vector<Question> *questions = new std::vector<Question>;
  //constructor
    Quiz(std::string fileName);

    std::vector<Question>* getQuestions();
  
  
  //otherfunctions
    void change_questions( std::vector<Question> *input);
    void print_all_questions();
  
  //destructor
    ~Quiz();
};