﻿#include <iostream>
#include<string>

#include <vcl.h>
#pragma hdrstop

// ********
// ********

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

// *****************************************************************************
// *****************************************************************************
// Get Id Data Encomming

String getDataId(String d) {
	String res = "NULL";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 5) == "@@11=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 5, j - i - 5);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1
				}
			}

		}

	}
	return res;
}

// *****************************************************************************
// *****************************************************************************
// Get All Info Ask Bid Server

String getAsk(String d) {
	String res = "0";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 5) == "@@16=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 5, j - i - 5);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1
				}
			}

		}

	}
	return res;
}

// Bid
String getBid(String d) {
	String res = "0";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 5) == "@@17=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 5, j - i - 5);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1
				}
			}

		}

	}
	for (int i = 0; i < res.Length(); i++) {
		if ((res.SubString(i, 1) == "@") || (res.SubString(i, 1) == "=")) {
			res = "0";
		}
	}

	return res;
}

String getServer(String d) {
	String res = "NULL";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 4) == "@@8=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 4, j - i - 4);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1

				}
			}

		}

	}

	return res;

}

String getLotSize(String d) {
	String res = "NULL";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 5) == "@@14=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 5, j - i - 5);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1

				}
			}

		}

	}

	return res;
}

String getDigits(String d) {
	String res = "NULL";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 5) == "@@13=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 5, j - i - 5);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1

				}
			}

		}

	}

	return res;
}

String getNameComp(String d) {
	String res = "NULL";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 4) == "@@6=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 4, j - i - 4);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1

				}
			}

		}

	}

	return res;

}

String getLavreg(String d) {
	String res = "NULL";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 4) == "@@5=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 4, j - i - 4);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1

				}
			}

		}

	}

	return res;
}

String getLogin(String d) {
	String res = "NULL";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 5) == "@@11=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "::") {
					res = d.SubString(i + 5, j - i - 5);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1

				}
			}

		}

	}

	return res;
}

String getSpread(String d) {
	String res = "NULL";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 5) == "@@19=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 5, j - i - 5);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1

				}
			}

		}

	}

	return res;
}

String getHours(String d) {
	String res = "NULL";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 5) == "@@18=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 5, j - i - 5);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1

				}
			}

		}

	}

	return res;
}

String getTrades(String d) {
	String res = "NULL";
	int N = d.Length();
	for (int i = 0; i < N; i++) {
		if (d.SubString(i, 5) == "@@20=") {
			for (int j = i + 5; j < N; j++) {
				if (d.SubString(j, 2) == "@@") {
					res = d.SubString(i + 5, j - i - 5);
					j = N + 2; // Exit From Loop 2
					i = j; // Exit From Loop 1

				}
			}

		}

	}

	return res;
}

// *****************************************************************************
// *****************************************************************************
// Timing http://www.functionx.com/cppbuilder/topics/datetime.htm
String getTime() {
	TDateTime RightNow = Time();
	unsigned short Hours, Minutes, Seconds, Milliseconds;
	RightNow.DecodeTime(&Hours, &Minutes, &Seconds, &Milliseconds);
	String res = Date().FormatString(L"dd-mm-yyyy") + " " + Hours + ":" +
		Minutes + ":" + Seconds + ":" + Milliseconds;
	return res;
}

// getIndex
String getSymbolFromId(String id) {
	String res = "";
	for (int i = 0; i < id.Length(); i++) {
		if (id.SubString(i, 1) == ':') {
			i += 2;
			for (; i <= id.Length(); i++) {
				res += id[i];
			}
		}
	}
	return res;
}

// *****************************************************************************
// *****************************************************************************
// WriteConsole Testing Perpess

void WriteLn(String text);

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

/*double Prix(String x) {
	double p = StrToFloat(x);
		p = StrToFloat(StringReplace(x, '.', ',',TReplaceFlags() << rfReplaceAll));

   return p;
} */

double Prix(String x,int Digits) {
    //c(x);
	double  p = StrToInt( x.SubString(  0,x.Length() - Digits -1)  )*pow(10.0, Digits) ;
			if(Digits!=0){
				String fx =  x.SubString( x.Length() - Digits+1,x.Length() ) ;
				if(fx.Length()!=0){
                   p+= StrToInt( fx )  ;
				   p=p/pow(10.0, Digits);
				}

			}

   return p;
}


bool isId(String str) {
	bool res = false;
	for (int i = 0; i < str.Length(); i++) {
		if (str.SubString(i, 2) == "::") {
			res = true;
			i = str.Length();
		}
	}
	return res;
}

int RoundSpread(double pips, int Digits) {

	return int(pips * pow(10.0, Digits) + 0.1);

}

int MaxInt_(int a1, int a2) {
	if (a2 > a1) {
		return a2;
	}
	else {
		return a1;
	}
}

int MinInt_(int a1, int a2) {
	if (a2 < a1) {
		return a2;
	}
	else {
		return a1;
	}
}

String OpenOrder(String ID, String Type, String Size, String Comment) {
	String res = "NULL";

	if (Type == "0") {
		res = "702=0@1@" + ID + "@2@" + Size + "@3@" + Comment +"@4@" + "@5@";
	}
		if (Type == "1") {
			res = "701=1@1@" + ID + "@2@" + Size + "@3@" + Comment +	"@4@" + "@5@";
		}

				if (Type == "7") {
						res = "703=7@1@" + ID + "@2@" + Size + "@3@" + Comment +	"@4@" + "@5@";
				}




	return res;
}

String CloseOrder(String ID, String Type, String Size, String Comment) {
	String res = "NULL";

	if (Type == "7") {
		res = "703=7@1@" + ID + "@2@" + Size + "@3@" + Comment +"@4@" + "@5@";
	}





	return res;
}



String Testy( String d){
	  String h="Null";
	  h = d.SubString(  d.Length()-20 , d.Length()-10   );

      return h ;
}
int getTickV12(String d){
	String res = "";
	int sum =0;
	int u =0;
	for(int i=0;i<d.Length();i++){
		if( d.SubString( i,1 )==" " && u==0  && i<d.Length() ){
			i++;
			u++;
			res="";
			for(;d.SubString( i,1 )!=":" && i<d.Length() ;i++){
			 res+= d.SubString( i,1 );
			}
			sum += StrToInt(res)*1000*60*60;
		}

		if( d.SubString( i,1 )==":" && u==1 && i<d.Length()  ){
			i++;
			u++;
			res="";
			for(;d.SubString( i,1 )!=":" && i<d.Length() ;i++){
			 res+= d.SubString( i,1 );
			}
			sum += StrToInt(res)*1000*60;
		}

		if( d.SubString( i,1 )==":" && u==2  && i<d.Length() ){
			i++;
			u++;
			res="";
			for(;d.SubString( i,1 )!=":" && i<d.Length() ;i++){
			 res+= d.SubString( i,1 );
			}
			sum += StrToInt(res)*1000;
		}

		if( d.SubString( i,1 )==":" && u==3  && i<d.Length() ){
			i++;
			u++;
			res="" + d.SubString( i,d.Length() ) ;
			sum += StrToInt(res);
		}


	}

	res = sum ;
	return sum;
}

int getMini(String d){
	String res = "";
	int sum =0;
	int u =0;
	for(int i=0;i<d.Length();i++){
		if( d.SubString( i,1 )==" " && u==0  && i<d.Length() ){
			i++;
			u++;
			res="";
			for(;d.SubString( i,1 )!=":" && i<d.Length() ;i++){
			 res+= d.SubString( i,1 );
			}
			sum += StrToInt(res)*60;
		}

		if( d.SubString( i,1 )==":" && u==1 && i<d.Length()  ){
			i++;
			u++;
			res="";
			for(;d.SubString( i,1 )!=":" && i<d.Length() ;i++){
			 res+= d.SubString( i,1 );
			}
			sum += StrToInt(res);
		}






	}

	res = sum ;
	return sum;
}
