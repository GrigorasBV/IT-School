//---------------------------------------------------------------------------

#ifndef QuestionFormH
#define QuestionFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TQuestionForm : public TForm
{
__published: // Componente gestionate de IDE
    TLabel *QuestionLabel;
    TRadioButton *Answer1RadioButton;
    TRadioButton *Answer2RadioButton;
    TRadioButton *Answer3RadioButton;
    TButton *ConfirmButton;
    TLabel *Label2;
    TLabel *PointsLabel;
    void __fastcall Answer1RadioButtonChange(TObject *Sender);
    void __fastcall Answer2RadioButtonChange(TObject *Sender);
    void __fastcall Answer3RadioButtonChange(TObject *Sender);
    void __fastcall ConfirmButtonClick(TObject *Sender);
private: // Declaratii utilizator
public:  // Declaratii utilizator
    __fastcall TQuestionForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQuestionForm *QuestionForm;
//---------------------------------------------------------------------------
#endif 