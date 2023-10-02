// FILE: quiz.hpp
// AUTHOR: Jacob Seaman
// DATE: 5/27/23

// ABOUT:  will hold objects of type question
#include <iostream>
#include "quiz.hpp"
#include <fstream>
#include<vector>
#include <sstream>
#include <nlohmann/json.hpp>



  Quiz::Quiz(std::string fileName){

      std::ifstream in_stream;

	    in_stream.open(fileName);

	    nlohmann::json j;

	    in_stream >> j;

    
      for (nlohmann::json& token : j["results"]) {
        std::string placeholder=token.dump();
    Quiz::questions->push_back(Question(placeholder, true));
}

        //using new constructor, by adding the boolean variable, passing the string itself and not the filename
        
        
    }

std::vector<Question>* Quiz::getQuestions(){
  
  return Quiz::questions;
}
void Quiz::change_questions(std::vector<Question> *input){
  Quiz::questions=input;
}
  
  //otherfunctions
    void Quiz::print_all_questions(){
      for(Question token: *Quiz::questions){
        std::cout<<"\nNext Question: \n"<<std::endl;
        token.printQuestion();
      }
    }
  
  //destructor
    Quiz::~Quiz(){
      
    
    }

