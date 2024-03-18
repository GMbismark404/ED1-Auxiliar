﻿//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <string>
#include "CSMemoria.h"
//---------------------------------------------------------------------------
using namespace std;


const int TamanoCelda = 35;
const int TamanoCeldaX = 80;
const int TamanoCeldaY = 35;

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:
	CSMemoria *a;
	int espacio_actual;
	int posX;
	int posY;
	int posXOcupado;
	int posYOcupado;
	int posXLibre;
	int posYLibre;
    void PintadoConBorde(int posX, int posY, String cad, TColor color);
	void PintadoLink(int posX, int posY, int Link);
	void Pintado(int posX, int posY, String cad, TColor color);	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
