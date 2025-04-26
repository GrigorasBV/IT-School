//---------------------------------------------------------------------------

#include <fmx.h>
#include <queue>
#include <random>
#pragma hdrstop

#include "QuestionForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

// Clasa pentru intrebari
class Question{
public:
	const char* Text;
	const char* Answer1;
	const char* Answer2;
	const char* Answer3;
	int CorrectAnswer;

Question(){}
Question(const char* text, const char* ans1, const char* ans2, const char* ans3, int correctAns){
Text=text;
Answer1=ans1;
Answer2=ans2;
Answer3=ans3;
CorrectAnswer=correctAns;
}
};

// Incarca si amesteca intrebarile
std::queue<Question>LoadQuestion(){
   Question q1=Question("Ce unitate de masura se foloseste pentru capacitatea de stocare a unui hard disk?","Byte","Gram","Metru",1);
   Question q2=Question("Care dintre urmatoarele este un sistem de operare?","Bing","Edge","Windows",3);
   Question q3=Question("Ce dispozitiv este folosit pentru a introduce text intr-un calculator?","Mouse","Tastatura","Scaner",2);
   Question q4=Question("Ce dispozitiv este folosit pentru a introduce text intr-un calculator?","Mouse","Tastatura","Scaner",2);
   Question q5=Question("Care este protocolul standard pentru transferul de fisiere pe internet?","HTTP","FTP","SMTP",2);
   Question q6=Question("Ce limbaj de programare este folosit pentru dezvoltarea aplicatiilor mobile Android?","Python","Java","C++",2);
   Question q7=Question("Ce tip de memorie este volatila si se sterge cand calculatorul este oprit?","ROM","RAM","HDD",2);
   Question q8=Question("Care este cel mai popular motor de cautare pe internet?","Bing","Google","Yahoo",2);
   Question q9=Question("Ce protocol este folosit pentru a accesa pagini web?","FTP","HTTP","SMTP",2);
   Question q10=Question("Ce tip de software protejeaza calculatorul de virusi?","Browser","Antivirus","Word",2);

   // Creeaza vector de intrebari
   Question allQuestions[] = {q1, q2, q3, q4, q5, q6, q7, q8, q9, q10};
   
   // Initializeaza generatorul de numere aleatoare
   std::random_device rd;
   std::mt19937 g(rd());
   
   // Amesteca intrebarile
   std::shuffle(std::begin(allQuestions), std::end(allQuestions), g);

   std::queue<Question> questions;
   
   // Adauga intrebarile amestecate in coada
   for(int i = 0; i < 10; i++) {
       // Creeaza vector de raspunsuri cu pozitiile originale
       struct Answer {
           const char* text;
           int originalPosition;
       };
       
       Answer answers[] = {
           {allQuestions[i].Answer1, 1},
           {allQuestions[i].Answer2, 2},
           {allQuestions[i].Answer3, 3}
       };
       
       // Amesteca raspunsurile
       std::shuffle(std::begin(answers), std::end(answers), g);
       
       // Gaseste noua pozitie a raspunsului corect
       int newCorrectAnswer = 0;
       for(int j = 0; j < 3; j++) {
           if(answers[j].originalPosition == allQuestions[i].CorrectAnswer) {
               newCorrectAnswer = j + 1;
               break;
           }
       }
       
       // Creeaza intrebare cu raspunsuri randomizate
       Question randomizedQuestion(
           allQuestions[i].Text,
           answers[0].text,
           answers[1].text,
           answers[2].text,
           newCorrectAnswer
       );
       
       questions.push(randomizedQuestion);
   }

   return questions;
}

std::queue<Question> questions;
Question currentQuestion;
int selectedAnswer;
int points=0;

TQuestionForm *QuestionForm;
//---------------------------------------------------------------------------
__fastcall TQuestionForm::TQuestionForm(TComponent* Owner)
	: TForm(Owner)
{
questions=LoadQuestion();
currentQuestion=questions.front();

QuestionLabel->Text=currentQuestion.Text;
Answer1RadioButton->Text=currentQuestion.Answer1;
Answer2RadioButton->Text=currentQuestion.Answer2;
Answer3RadioButton->Text=currentQuestion.Answer3;

questions.pop();
PointsLabel->Text=points;

}
//---------------------------------------------------------------------------
// Seteaza raspunsul selectat la 1
void __fastcall TQuestionForm::Answer1RadioButtonChange(TObject *Sender)
{
  selectedAnswer=1;
}
//---------------------------------------------------------------------------

// Seteaza raspunsul selectat la 2
void __fastcall TQuestionForm::Answer2RadioButtonChange(TObject *Sender)
{
  selectedAnswer=2;
}
//---------------------------------------------------------------------------

// Seteaza raspunsul selectat la 3
void __fastcall TQuestionForm::Answer3RadioButtonChange(TObject *Sender)
{
   selectedAnswer=3;
}
//---------------------------------------------------------------------------

// Verifica raspunsul si trece la urmatoarea intrebare
void __fastcall TQuestionForm::ConfirmButtonClick(TObject *Sender)
{
 if(selectedAnswer==currentQuestion.CorrectAnswer) {
 points++;
 PointsLabel->Text=points;
 }

 if(!questions.empty()){
 currentQuestion=questions.front();

   QuestionLabel->Text=currentQuestion.Text;
   Answer1RadioButton->Text=currentQuestion.Answer1;
   Answer2RadioButton->Text=currentQuestion.Answer2;
   Answer3RadioButton->Text=currentQuestion.Answer3;

   questions.pop();
   Answer1RadioButton->IsChecked=false;
   Answer2RadioButton->IsChecked=false;
   Answer3RadioButton->IsChecked=false;

 }
 else {
 ConfirmButton->Enabled=false;
 ConfirmButton->Text="Sfarsit";
 }
}
//--------------------------------------------------------------------------- 