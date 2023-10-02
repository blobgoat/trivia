#include <iostream>
#include "question.hpp"
#include <fstream>
#include<vector>
#include <sstream>
#include <nlohmann/json.hpp>


  Question::Question(std::string fileName){

    std::ifstream in_stream;

	in_stream.open(fileName);

	nlohmann::json j;

	in_stream >> j;
    Question::category=j["results"][0]["category"];
    Question::type=j["results"][0]["type"];
    Question::difficulty=j["results"][0]["difficulty"];
    Question::question=j["results"][0]["question"];
    Question::correct_answer=j["results"][0]["correct_answer"];

    for(nlohmann::json& token:j["results"][0]["incorrect_answers"]){
      Question::incorrect_answers->push_back(token.dump());
    }

   


  }
  
   Question::Question(std::string text, bool marker){


    std::istringstream in_stream(text);



	 nlohmann::json j;

	 in_stream >> j;

    Question::category=j["category"];
    Question::type=j["type"];
    Question::difficulty=j["difficulty"];
    Question::question=j["question"];
    Question::correct_answer=j["correct_answer"];


    for( nlohmann::json& token :j["incorrect_answers"]){
      std::string placeholder=token.dump();
      Question::incorrect_answers->push_back(placeholder);
      
   }

   }
  
  //otherfunctions
  void Question::printQuestion(){
  std::string vectorOutput;
bool start=true;
for(std:: string token : *Question:: incorrect_answers){
  if(start==true){
    vectorOutput=token;
    start=false;
  }else{
  vectorOutput+=", "+token;}
  
}

    std::cout<<"Category: " << Question::category<<", Type: "<< Question::type<< ", Difficulty: "<< Question::difficulty<<", Question: "<< Question::question<<", Correct Answer: "<< Question::correct_answer<< ", Incorrect Answers: "<< vectorOutput<< std::endl;
  }

std::string Question::getCategory(){

  return Question::category;

  
}
std::string Question::getQuestion(){
  return Question::question;
}
  std::string Question::getCorrectAnswer(){
    return Question::correct_answer;
  }
  std::string Question::getDifficulty(){
    return Question::difficulty;
  }
  std::vector<std::string>* Question::getIncorrectAnswers(){
    return Question::incorrect_answers;
  }

  //destructor
  Question::~Question(){
    
  }
