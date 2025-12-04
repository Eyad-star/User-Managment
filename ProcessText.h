#pragma once
#include<iostream>
#include"InputDate.h"
#include"Enum.h"
#include"Struct.h"
#include<vector>
using namespace std;


namespace ProccessText
{

    bool IsSpaceInStartText(string Text)
    {
        if(Text[0] == ' ')
        {
            return true;
        }

        return false;
    }
    bool IsSpaceInRightText(string Text)
    {
        if(Text[Text.length() - 1] == ' ')
            return true;

        return false;    
    }
    string DeleteSpaceFromLeft(string Text)
    {

        while (IsSpaceInStartText(Text))
        {
            Text = Text.substr(1, Text.length());
        }
        
        return Text;
    }

    string DeleteSpaceFromRight(string Text)
    {
        while(IsSpaceInRightText(Text))
        {
            Text = Text.substr(0, Text.length() - 2);
        }
        
        return Text;
    }
    bool isEveryTextIsSpace(const string& Text)
    {
        size_t Sum = 0;
        for(const char &i : Text)
        {
            if(i == ' ')
                Sum++;
        }
        
        return (Sum == Text.length());
    }
    string DeletSpaceFromLeftAndRight(string Text)
    {
        
        if(IsSpaceInRightText(Text) || IsSpaceInStartText(Text))
        {
            Text = DeleteSpaceFromLeft(Text);
            Text = DeleteSpaceFromRight(Text);
        }     

        return Text;    
    }
    string DeletSpaceFromLeftAndRightAndMiddle(string Text)
    {
        string NewText = "";
        for (size_t i = 0; i < Text.length(); i++)
        {
            if(Text[i] != ' ')
                NewText += Text[i]; 
        }
        return NewText;
        
    }
    bool IsThisSymbolInEmail(char Symbol,const string& Text)
    {
        for (const char &i : Text)
        {
            if(i == Symbol)
                return true;
        }
        
        return false;
    }
    string ChekFromNameUser (string Name)
    {
        if(isEveryTextIsSpace(Name))
            Name = Input::ReadText("Please Enter Name Not Space : ");

        Name = DeletSpaceFromLeftAndRight(Name);

        return Name;    
    }
    string ChekEmail(string TextEmail)
    {
        TextEmail = DeletSpaceFromLeftAndRightAndMiddle(TextEmail);
        while (!IsThisSymbolInEmail('@', TextEmail))
        {
            TextEmail = Input::ReadText("Please Enter New Email And This @ : ");
        }
        
        return DeletSpaceFromLeftAndRightAndMiddle(TextEmail); ;
    }
    void AddToVector(vector<string>& arrWord, const string& Word)
    {
        arrWord.push_back(Word);
    }
    char ReadOneChar(string Message)
    {
        char OneChar = 'f';
        cout<<Message<<"\n";
        cin>>OneChar;

        return OneChar;
    }
    vector<string> SplitText(string Text, string Seprator)
    {
        short Pos = 0;
        vector<string> vWord;
        string OneWord = "";
        while ((Pos = Text.find(Seprator)) != string::npos)
        {
            OneWord = Text.substr(0, Pos);
            AddToVector(vWord, OneWord);
            Text.erase(0, Pos + Seprator.length());

        }
        
        AddToVector(vWord, Text);
        
        return vWord;
    }
    short IsNum(short Asci)
    {
        return( Asci >= 48 && Asci <= 57);
    }

    bool IsLetter(short Asci)
    {
        return ( 
                (Asci >= 65 && Asci <= 90 )     
            ||
                (Asci >= 95 && Asci <= 122 )
               );
    }
    short CounterCharInText(MyEnum::enTextComponents TypeChar, const string& Text)
    {
        short Sum = 0;
        switch (TypeChar)
        {
            case MyEnum::enTextComponents::Num:
            {
                for (const char & i : Text)
                {
                    if(IsNum(i))
                        ++Sum;
                }
                
            }
            break;
            case MyEnum::enTextComponents::Symbol:
            {
                for (const char & i : Text)
                {
                    if(!IsNum(i) && !IsLetter(i))
                        ++Sum;
                }
            }
            break;
            case MyEnum::enTextComponents::CharSmall:
            {
                for (const char & i : Text)
                {
                    if(islower(i))
                        ++Sum;
                }
            }
            break;
            case MyEnum::enTextComponents::CharCapital:
            {
                for (const char & i : Text)
                {
                    if(isupper(i))
                        ++Sum;
                }
            }
            break;
            
        }


        return Sum;
    }
    bool IsSymbol(short Asci)
    {
        return ( !IsLetter(Asci) && !IsNum(Asci));
    }
    bool SymbolInPassWord(const string& PassWord)
    {
        for(const char &i : PassWord)
        {
           if(IsSymbol(i))
                return true; 
        }
        
        return false;
    }
    string GetSpace(short Num)
    {
    string Spaces = "";
    for (short i = 0; i < Num; i++)
        Spaces += " ";
    
    return Spaces;
    }      
    string ConvertStructToLine(const MyStruct::stInfoAccountUser& InfoOneAccount)
    {
        string Line = "";
        
        Line += InfoOneAccount.Name + "//";
        Line += to_string(InfoOneAccount.Age) +  "//";
        Line += InfoOneAccount.Email +  "//";
        Line += InfoOneAccount.PassWord  + "//";
        Line += to_string(InfoOneAccount.DateCreated.Day) + "-";
        Line += to_string(InfoOneAccount.DateCreated.Month) +  "-";
        Line += to_string(InfoOneAccount.DateCreated.Year);

        return Line;
    } 
    string ChekPassWord(string PassWord)
    {
        PassWord = DeletSpaceFromLeftAndRight(PassWord);
        // bool NumCapitalIsCorrect = CounterCharInText(MyEnum::enTextComponents::CharCapital, PassWord) > 3;
       
        while ((PassWord.length() <= 5))
        {
            PassWord = Input::ReadText("\nEnter PassWord Big 5");
        }
        
        return DeletSpaceFromLeftAndRight(PassWord);
    }

}