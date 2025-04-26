//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMyMainForm : public TForm
{
__published:	// Componente gestionate de IDE
	TButton *loginNavigationButton;
	TButton *registrationNavigationButton;
	void __fastcall registrationNavigationButtonClick(TObject *Sender);
	void __fastcall loginNavigationButtonClick(TObject *Sender);
private:	// Declaratii utilizator
public:		// Declaratii utilizator
	__fastcall TMyMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyMainForm *MyMainForm;
//---------------------------------------------------------------------------
#endif
