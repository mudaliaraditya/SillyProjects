
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<cmath>


#define ZERO "0"


using namespace std;



 enum class  CEMENU_ACTIONS : long
{
  CEMENU_ACTION_INVALID            = 0,
  CEMENU_ACTION_ADD                = 1,
  CEMENU_ACTION_SUB                = 2,
  CEMENU_ACTION_DIV                = 3,
  CEMENU_ACTION_MUL                = 5,
  CEMENU_ACTION_DEC_CON_TO_HEX     = 6,
  CEMENU_ACTION_HEX_CON_TO_DEC     = 7,
  CEMENU_ACTION_DEGREE_TO_RADIAN   = 8,
  CEMENU_ACTION_RADIAN_TO_DEGREE   = 9,
};

map<string, int>     g_cHexMap;
map<string, string>  g_cBinaryHexMap;

void initialize()
{
   g_cHexMap.insert(pair<string,long>("0",0));
   g_cHexMap.insert(pair<string,long>("1",1));
   g_cHexMap.insert(pair<string,long>("2",2));
   g_cHexMap.insert(pair<string,long>("3",3));
   g_cHexMap.insert(pair<string,long>("4",4));
   g_cHexMap.insert(pair<string,long>("5",5));
   g_cHexMap.insert(pair<string,long>("6",6));
   g_cHexMap.insert(pair<string,long>("7",7));
   g_cHexMap.insert(pair<string,long>("8",8));
   g_cHexMap.insert(pair<string,long>("9",9));
   g_cHexMap.insert(pair<string,long>("A",10));
   g_cHexMap.insert(pair<string,long>("B",11));
   g_cHexMap.insert(pair<string,long>("C",12));
   g_cHexMap.insert(pair<string,long>("D",13));
   g_cHexMap.insert(pair<string,long>("E",14));
   g_cHexMap.insert(pair<string,long>("F",15));
   
   g_cBinaryHexMap.insert(pair<string, string>("0000", "0"));
   g_cBinaryHexMap.insert(pair<string, string>("0001", "1"));
   g_cBinaryHexMap.insert(pair<string, string>("0010", "2"));
   g_cBinaryHexMap.insert(pair<string, string>("0011", "3"));
   g_cBinaryHexMap.insert(pair<string, string>("0100", "4"));
   g_cBinaryHexMap.insert(pair<string, string>("0101", "5"));
   g_cBinaryHexMap.insert(pair<string, string>("0110", "6"));
   g_cBinaryHexMap.insert(pair<string, string>("0111", "7"));
   g_cBinaryHexMap.insert(pair<string, string>("1000", "8"));
   g_cBinaryHexMap.insert(pair<string, string>("1001", "9"));
   g_cBinaryHexMap.insert(pair<string, string>("1010", "A"));
   g_cBinaryHexMap.insert(pair<string, string>("1011", "B"));
   g_cBinaryHexMap.insert(pair<string, string>("1100", "C"));
   g_cBinaryHexMap.insert(pair<string, string>("1101", "D"));
   g_cBinaryHexMap.insert(pair<string, string>("1110", "E"));
   g_cBinaryHexMap.insert(pair<string, string>("1111", "F"));
}

int GetHexToDecimal(std::string sHex)
{
  int lnHexPosition = 0;
  int lnCharVal = sHex.length();
  int lnCounter = 0;
  int lnPowerMul = 0;
  int lnDecimalVal = 0;
  int lnPowerVal = 1;
  for( ; lnCounter < lnCharVal; lnCounter++)
  {
    char lcCharVal = (sHex[lnCounter]);
    string lcString = &lcCharVal;
    char lcBuff[2] = {0};
    strncpy (lcBuff,lcString.c_str(),1);
   
   map<string,int>::iterator lcIter4 = g_cHexMap.find((lcBuff));
   
    lnPowerVal  = 1;
    lnPowerMul = lnCounter;
    while (lnPowerMul != 0)
    {
        lnPowerVal *= 16;
        --lnPowerMul;
    }
    lnDecimalVal += ((lcIter4->second)*(lnPowerVal));
  }
  return lnDecimalVal;
}

string GetDecimalToHex(string sDecimal)
{
    int lnFactoriser = 2;
    string lcBinaryNo ="";
    int lnNo = stol( sDecimal);
    int lnRemainder = 0;
    while(lnNo != 0)
    {
        lnRemainder = lnNo%2;
        lnNo = lnNo/2;
        lcBinaryNo = to_string(lnRemainder) + lcBinaryNo;
    }
    
    
    int lnDivBy4 = lcBinaryNo.length()%4;
    
    while(lnDivBy4 != 0)
    {
       
       lcBinaryNo = ZERO + lcBinaryNo;
       lnDivBy4 = lcBinaryNo.length()%4;
    }
    
    char lcBuffer[5] = {0};
    string lcHex = "";
    string lcSingleChar = "";
    int lnNoOfIterations = lcBinaryNo.length()/4;
    for(int lnNo = 0; lnNo < lnNoOfIterations; lnNo++)
    {
        strncpy(lcBuffer , lcBinaryNo.c_str() + (4*lnNo), 4);
        string lcVal = lcBuffer;
        map<string, string>::iterator lcIter = g_cBinaryHexMap.find(lcVal);
        if(lcIter != g_cBinaryHexMap.end())
       {
           lcSingleChar = ( lcIter)->second;
           lcHex =   lcHex + lcSingleChar;
       }
    }
    return lcHex;
}


int main()
{
  initialize();
  int lnChoice = 0;
  while(true)
  {
     cout << (int)CEMENU_ACTIONS::CEMENU_ACTION_INVALID           << ") makes no sense" << endl;
     cout << (int)CEMENU_ACTIONS::CEMENU_ACTION_ADD               << ") add two nos" << endl;
     cout << (int)CEMENU_ACTIONS::CEMENU_ACTION_SUB               << ") subtracts two nos" << endl;
     cout << (int)CEMENU_ACTIONS::CEMENU_ACTION_DIV               << ") divides two nos" << endl;
     cout << (int)CEMENU_ACTIONS::CEMENU_ACTION_MUL               << ") multiplies two nos" << endl;
     cout << (int)CEMENU_ACTIONS::CEMENU_ACTION_DEC_CON_TO_HEX    << ") converts Decimal to Hex" << endl;
     cout << (int)CEMENU_ACTIONS::CEMENU_ACTION_HEX_CON_TO_DEC    << ") converts Hex to Decimal" << endl;
     cout << (int)CEMENU_ACTIONS::CEMENU_ACTION_DEGREE_TO_RADIAN  << ") converts degree to radian" << endl;
     cout << (int)CEMENU_ACTIONS::CEMENU_ACTION_RADIAN_TO_DEGREE  << ") converts radian to degree" << endl;

     cin >> lnChoice;
     switch(lnChoice)
     {
        case (int) CEMENU_ACTIONS::CEMENU_ACTION_INVALID:
        {
        }
        break;
     
        case (int) CEMENU_ACTIONS::CEMENU_ACTION_ADD :
        {
       
           int lnX = 0;
           int lnY = 0;
           cout << "enter the two nos to be added" << endl;
           cin >> lnX >> lnY;
           cout << "the ans is " << lnX + lnY << endl; 
        }
        break;
    
        case (int) CEMENU_ACTIONS::CEMENU_ACTION_SUB  :
        {
           int lnX = 0;
           int lnY = 0;
           cout << "enter the two nos to be subtracted" << endl;
           cin >> lnX >> lnY;
           cout << "the ans is " << lnX - lnY << endl;
       }
       break;
   
       case (int) CEMENU_ACTIONS::CEMENU_ACTION_DIV :
       {
          int lnX = 0;
          int lnY = 0;
          cout << "enter the two nos to be divided" << endl;
          cin >> lnX >> lnY;
           cout << "the ans is " << lnX / lnY << endl; 
       }
       break;

      case (int) CEMENU_ACTIONS::CEMENU_ACTION_MUL:
      {
         int lnX = 0;
         int lnY = 0;
         cout << "enter the two nos to be multiplied" << endl;
         cin >> lnX >> lnY;
         cout << "the ans is " << lnX * lnY << endl; 
     }
     break;

     case  (int) CEMENU_ACTIONS::CEMENU_ACTION_DEC_CON_TO_HEX :
     { 
        string lcHexVal = "";
        cin >> lcHexVal;
        cout << GetDecimalToHex(lcHexVal) << endl;
     }
     break;

    case (int)CEMENU_ACTIONS::CEMENU_ACTION_HEX_CON_TO_DEC   :
    {
       string lcHexVal = "";
       cin >> lcHexVal;
       cout << GetHexToDecimal(lcHexVal) << endl;
    }
    break;

    case  (int)CEMENU_ACTIONS::CEMENU_ACTION_DEGREE_TO_RADIAN : 
    {
     string lcInput = "";
     cin >> lcInput;
     cout << stol(lcInput)* M_PI/180 << endl;
    }
    break;

    case   (int)CEMENU_ACTIONS::CEMENU_ACTION_RADIAN_TO_DEGREE :
    {
     string lcInput = "";
     cin >> lcInput;
     cout << stol(lcInput)* 180/M_PI << endl; 
    }
    break;
   }
    
  }
  
}
