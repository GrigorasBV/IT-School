//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#pragma hdrstop

#include "RegistrationForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyRegistrationForm *MyRegistrationForm;
//---------------------------------------------------------------------------
__fastcall TMyRegistrationForm::TMyRegistrationForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// Salveaza datele utilizatorului in fisier
void __fastcall TMyRegistrationForm::SaveButtonClick(TObject *Sender)
{
   fstream myFile;
   myFile.open("registrededUsers.txt",ios::app);
   if(myFile.is_open()){
   AnsiString name= nameEdit->Text;
   AnsiString age= ageEdit->Text;
   AnsiString username= usernameEdit->Text;
   AnsiString password= passwordEdit->Text;

   myFile<<name<<","<<age<<","<<username<<","<<password<<"\n";
   myFile.close();

   this->Close();
   }
}

// Reseteaza campurile formularului
void __fastcall TMyRegistrationForm::FormShow(TObject *Sender)
{
    nameEdit->Text = "";
    ageEdit->Text = "";
    usernameEdit->Text = "";
    passwordEdit->Text = "";
}
//---------------------------------------------------------------------------
