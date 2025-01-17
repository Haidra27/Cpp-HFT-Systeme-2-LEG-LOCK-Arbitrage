﻿#include <iostream>
#include<string>
#include <fstream>
#include <vcl.h>
#pragma hdrstop
#include "fn.cpp"
#include <System.IOUtils.hpp>

// *****************************************************************************
// *****************************************************************************
// struct Les Var
int MaxData = 3000;
int isSavingDataActive=1;


struct SymbolInfo {
	String id;
	String Name;
	String Login;
	String Leverage;
	String Company;
	String Server;
	String TaillDuContrat;
	String Digits;
};

struct Symbol {
	SymbolInfo Info;
	int iLast;
	String AskCurrent;
	String BidCurrent;
	String DateCurrent;
	String SpreadCurrent;
	String OrdesCurrent;
    String HoursCurrent;
	String Date[3000];
	String Ask[3000];
	String Bid[3000];
};

struct Trade {
	String Comment;
	String Type;
	String Size;
	String Symbol;
	String Profit;

};

// *****************************************************************************
// *****************************************************************************
// variables
String consoleMSG = "NULL";

Symbol sym[20];
String symId[20];
int MaxiSym = 20, iSym = 0;

String msgClient1 ="NULL",msgClient2 = "NULL";
//*******************
// R22
int R22_state = -1;// No Opennig Trade And Can Run Stratige

// *****************************************************************************
// *****************************************************************************
// Redefition
String getDataId(String d);
void c(String str);
bool isNewSym(String id);
String getAsk(String d);
String getBid(String d);
String getTime();
int getIndexFromId(String id);
String getServer(String d);
String getLavreg(String d);
String getlogin(String d);
String getNameComp(String d);
 String getLotSize(String d);
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// les Set Function
void setConsoleMSG(String str) {
	consoleMSG = str;
}

void setisSavingDataActive(int val){
	isSavingDataActive = val;
}
void setMsgClient1(String msg){
   msgClient1 = msg;
   c(msg);
}
void setMsgClient2(String msg){
   msgClient2 = msg;
   c(msg);
}
void setR22_state(int var){ R22_state=var ;}
// *****************************************************************************
// *****************************************************************************
// Les Get Function
String getConsoleMSG() {
	return consoleMSG;
}

int getiSym() {
	return iSym;
}

String getId(int index) {
	return symId[index];
}

int getR22_state(){ return R22_state ; }

// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// HandleIncomingData

void HandleIncomingData(String data) {
	//c(data);
	if (data != "") {
		String id;
		String ask, bid;
		id = getDataId(data);

		// c("............................. "+getTime() );
		if (isNewSym(id)) { // New Symbol Incoming

			symId[iSym]                    = id;
			sym[iSym].Info.id              = id;
			sym[iSym].Info.Server          = getServer(data);
			sym[iSym].Info.Leverage        = getLavreg(data);
			sym[iSym].Info.Login           = getLogin(data);
			sym[iSym].Info.Company         = getNameComp(data);
			sym[iSym].Info.TaillDuContrat  = getLotSize(data);
			sym[iSym].Info.Digits          = getDigits(data);

			sym[iSym].AskCurrent=getAsk(data);
			sym[iSym].BidCurrent=getBid(data);
            sym[iSym].DateCurrent= getTime();

			String Trades = getTrades(data);
			c(" New Symbol:"+sym[iSym].Info.Company+" ID:"+id);
			//c( Trades );
			// SymbolInfoFillingIn(id,data);
			iSym++;

		}
		else { // New Data From Exixting Symbol
			ask = getAsk(data);
			bid = getBid(data);
			int index = getIndexFromId(id);
			if (index != -1) {
				 if(isSavingDataActive==1)
				 {
					if (sym[index].iLast >= MaxData - 1) {
						sym[index].iLast = 0;
					}
					sym[index].Date[sym[index].iLast] = getTime();
					sym[index].Ask[sym[index].iLast] = ask;
					sym[index].Bid[sym[index].iLast] = bid;
					sym[index].iLast++;
                 }

				sym[index].DateCurrent= getTime();
				sym[index].AskCurrent=ask;
				sym[index].BidCurrent=bid;
				sym[index].OrdesCurrent= getTrades(data);
				sym[index].SpreadCurrent=getSpread(data);
				sym[index].HoursCurrent =  getHours(data);
				String Trades = getHours(data);



			}
		}
		// c("......................... "+getTime() );

		//c(data);
	}
}



// @@1=2.13@@11=2089000528::EURUSD@@2=-1@@5=200@@6=Darwinex@@7=Haidra27@@8=Darwinex-Demo@@13=2@@14=1@@16=1.18080000@@17=1.18077000@@
// *****************************************************************************
// *****************************************************************************
// Test Is New Encomming Symbol

bool isNewSym(String id) {
	bool res = true;
	for (int i = 0; i < iSym; i++) {

		if (symId[i] == id) {
			res = false;
			i = iSym + 2;
		}
	}
	return res;
}

// *****************************************************************************
// *****************************************************************************
// getIndex

int getIndexFromId(String id) {
	int i = 0, res = -1;
	for (; i < iSym; i++) {
		if (symId[i] == id) {
			res = i;
		}
	}
	return res;
}
// get Server
String getServerInInfo(int index) {
	return sym[index].Info.Server;
}
// get Tikets
int getTikets(int index) {
	return sym[index].iLast;
}
String getTimeForFile() {
	TDateTime RightNow = Time();
	unsigned short Hours, Minutes, Seconds, Milliseconds;
	RightNow.DecodeTime(&Hours, &Minutes, &Seconds, &Milliseconds);
	String res = Date().FormatString(L"ddmmyyyy") + "-" + Hours + "-" +
		Minutes + "-" + Seconds + "-" + Milliseconds;
	return res;
}
void SavingAll() {
	String date, ask, bid;
	String SavingDir1 = getTimeForFile();
	// c("***************************************************> "+SavingDir1);
	TDirectory::CreateDirectory("Data/" + SavingDir1);
	for (int i = 0; i < iSym; i++) {
		String name = "sdfds.d";

	}

}
String getDataById( String Id ){
	String res = "NULL";
	int i = getIndexFromId(Id) ;
	 res = sym[i].DateCurrent ;
	 return res ;
}
String getAskById( String Id ){
	String res = "NULL";
	int i = getIndexFromId(Id) ;
	 res = sym[i].AskCurrent ;
	 return res ;
}
String getBidById( String Id ){
	String res = "NULL";
	int i = getIndexFromId(Id) ;
	 res = sym[i].BidCurrent ;
	 return res ;
}
int getDigitsById( String Id ){
	int res = -1;
	int i = getIndexFromId(Id) ;
	 res = StrToInt( sym[i].Info.Digits ) ;
	 return res ;
}
String getSpreadById( String Id ){
     String res = "NULL";
	int i = getIndexFromId(Id) ;
	 res = sym[i].SpreadCurrent ;
	 return res ;
}
String getOrdersById( String Id ){
	String res = "NULL";
	int i = getIndexFromId(Id) ;
	 res = sym[i].OrdesCurrent ;
	 return res ;
}
double getFerstProfitByID(String Id1){
	double AllProfit1 =0;
		String Orders = "11"+getOrdersById(Id1);
				String X = "##x";
				int    iX =1 ;
				int Long =0;
				bool b=true;
				for(;b;){
					String u = X+iX,y="#"+IntToStr(iX)+"#";
					double profit = 0;
					if ( Orders.Pos(u)!=0 ){
						String Line = Orders.SubString( Orders.Pos(u)   ,  Orders.Pos(y) - Orders.Pos(u) );
						profit = Prix(   Line.SubString( Line.Pos("Profit")+6 , Line.Pos("Comment") - Line.Pos("Profit")-6  )  , 2);
						AllProfit1+=profit;

					}else{b=false;}
					iX++;
					Long= Long + Orders.Pos(u);
				}
	return AllProfit1 ;
}
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************

/*

 ï»¿#include <iostream>
 #include<string>
 #include "Symbol.cpp"


 // *************************************************************************
 // *************************************************************************
 void WriteLn(String text);

 // *************************************************************************




 // *************************************************************************
 // *************************************************************************
 // Global Var
 int iTime = 0;



 // ***********************************************************************
 #include <iostream>
 #include<string>


 //***********************************************************************
 void c(String text) ;




 //***********************************************************************

 struct Symbol {    String id; String name; String login; String leverage; String company; String server; int    TaillDuContrat ;};
 //*****************************************************************************
 Symbol Sym[30];
 int    iSym=0;

 //****************************************************************************
 int getNbSymol(){return iSym;}
 void setNbSymbol(int NewNb){iSym=NewNb;}


 // Timer Alert In Cosole
/*String Message = "Haidra", oMessage = "Haidra";

 String isMessageChange() {

 if (Message != oMessage) {
 Message = oMessage;
 return "T";
 }
 else {
 return "F";
 }
 }

 String getMessage() {
 return Message;
 }

 void setMessage(String srt) {
 Message = srt;
 }
 //*************************************************************************

 Symbol s2[10];

 void c(String str) {
 WriteLn(str);
 }

 void WriteLn(String text)
 { // http://bcbjournal.org/articles/vol2/9812/WriteLn_for_CBuilder.htm
 static HANDLE handle;
 if (!handle) {
 AllocConsole();
 handle = GetStdHandle(STD_OUTPUT_HANDLE);
 }
 text += "\n";
 WriteConsole(handle, text.c_str(), text.Length(), 0, 0);
 }

 // Seters and Geters
 void setiTime(int newI){ iTime  = newI; }
 int getiTime(){ 	 return iTime ;  }
 void cTime(){ iTime++; }

 //**************************************************************************

 void HandleIncomingData(String data){
 c("IncomingData ");
 c(data);

 }




 c("******************************************************");
 setConsoleMSG(id);
 for(int  i=0;i<iSym;i++){
 c(symId[i]+"-------");
 }




 */
