//Jacob Seaman
//6/16/23
//Quiz game main.cpp
/*
  Create a quiz game using the Quiz and Question class you created in the short assignment - use json, curl, and vector (or some other data structure class)

1. The quiz should produce different questions each time the game is run

2. The quiz should hide the correct answer amongst the incorrect answers in a random order

3. The quiz should show the user how many questions they got right and how many they got wrong

4. The quiz should ask the user if they want to play again
*/
#include <iostream>

#include "quiz.hpp"

#include <fstream>

#include<bits/stdc++.h>
#include <deque>
#include<cstdlib>



bool compareQuestions(Question x, Question y){
  return (x.getCategory() < y.getCategory());
}
int scoreEasy=0;

int scoreMedium=0;

int scoreHard=0;


int numberOfQuestions=0;
int score=0;



void printScore(){
  score=scoreEasy+2*scoreMedium+3*scoreHard;
  
  std::cout<<"You scored: "<<score<<" by answering\n"<<scoreEasy<<" Easy questions\n"<<scoreMedium<<" Medium questions\n"<<"and "<<scoreHard<<" Hard questions\n"<<"and got this amount of questions right: "<<scoreEasy+scoreMedium+scoreHard<<"\nout of this many questions: "<<numberOfQuestions<<"\nmeaning you got this many wrong: "<<numberOfQuestions-(scoreEasy+scoreMedium+scoreHard)<<"\n"<<std::endl;
}
int main(){
  
  
  srand((unsigned) time(NULL));
  char input;
  bool running=true;
  while(running==true){

  std::cout<<"input a letter 't' or 'T' if you wish this program to play more, enter 'f' or 'F' if you want this program to end\n"<<std::endl;
  
    scanf(" %c", &input);
    if(input=='t' || input=='T'){
  system("curl https://opentdb.com/api.php?amount=10 > data.txt");
  Quiz *my_quiz=new Quiz("data.txt");

  //print out unsorted questions
     /* std::cout<<"unsorted Questions:\n"<<std::endl;
  my_quiz->print_all_questions();*/

      //put all questions into a deque
      std::deque<Question> questionsDeque;

      
      for(Question token : *my_quiz->questions){

        questionsDeque.push_back(token);
      }
//take two or three parameters
      //sorting by category
      //comparative function is the third parameter, must have two parameters

      std::sort(questionsDeque.begin(), questionsDeque.end(), compareQuestions);
     my_quiz->questions->clear();
      for(Question token: questionsDeque){
        my_quiz->questions->push_back(token);
      }
      std::cout<<"\nQuestions sorted by category...\n"<<std::endl;
int size= my_quiz->questions->size();
      for(int i=0; i<size; i++){
        Question current= my_quiz->questions->at(i);
        numberOfQuestions++;
    std::cout<<"\nQuestion: \n"<< current.getQuestion()<<std::endl;
        std::vector<std::string> *incorrect_answers= current.getIncorrectAnswers();
        int correctPlacement=rand()%incorrect_answers->size();
        std::string possibleAnswers="\n";
        int step=0;
        for(int i=0; i<incorrect_answers->size()+1; i++){
          if(i==correctPlacement){
            possibleAnswers+="\""+current.getCorrectAnswer()+"\"\n";
            step++;
            
            }else{
          possibleAnswers+=incorrect_answers->at(i-step) +"\n";
          }
            
        }
        
        
        std::cout<<"\n Choose 1, 2, 3, or 4 corresponding to the row you believe the right answer to be on. Possible Answers: \n"<< possibleAnswers<<std::endl;
      int answerchoice;
    scanf(" %d", &answerchoice);
        
        if(answerchoice==correctPlacement+1){
        std::cout<<"\n Right! \n"<<std::endl;
          std::string diff=current.getDifficulty();
          if(diff.compare("easy")==0){
            scoreEasy++;
            
          }
          if(diff.compare("medium")==0){
            scoreMedium++;
            
          }else{
            scoreHard++;
          }
          
      }else{
        std::cout<<"\n Wrong! \n"<<std::endl;
      }
        
        printScore();
        std::cout<<"next question!\n"<<std::endl;
      }
      

  delete my_quiz;
    }else{
   if(input=='f' || input=='F'){
     printScore();
     std::cout<<"ending program..."<<std::endl;
     running=false;
   }else{
     std::cout<<"invalid input"<<std::endl;

   }
      
    }
  }
}
//valgrind --leak-check=full --show-leak-kinds=all ./run
