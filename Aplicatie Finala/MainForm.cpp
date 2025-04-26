//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "LoginForm.h"
#include "RegistrationForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyMainForm *MyMainForm;
//---------------------------------------------------------------------------
__fastcall TMyMainForm::TMyMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// Deschide formularul de login
void __fastcall TMyMainForm::loginNavigationButtonClick(TObject *Sender)
{
 MyLoginForm->Show();
}
//---------------------------------------------------------------------------
// Deschide formularul de inregistrare
void __fastcall TMyMainForm::registrationNavigationButtonClick(TObject *Sender)
{
  MyRegistrationForm->Show();
}