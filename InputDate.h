#pragma once
#include<iostream>
#include<limits>
#include<numeric>
#include "Struct.h"
using namespace std;


namespace Input
{
    short ReadPostiveNumberSmall(const string& Message, short From , short To)
    {
        short Num = 0;
        do
        {
            cout<<Message<<"\n";
            cin>>Num;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout<<"Please Enter Number Not Enter Letters !\n";
                cin>>Num;
            }
            
        } while ( (Num < 0) || (Num > To) || (Num < From));
        
        return Num;
    }
    
    short ChoseeWahtDoYouDo()
    {
        short Chsose = Input::ReadPostiveNumberSmall("Enter Chose From This : ", 1, 3);

        return Chsose;
    }
    int ReadPostiveOrNegtiveNumberLarge(const string& Message, short From, short To)
    {
        int Num = 0;
        do
        {
            cout<<Message<<From<<" To "<< To<<"\n";
            cin>>Num;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout<<"Please Enter Number Not Enter Letters !\n";
                cin>>Num;
            }
            
        } while ( (Num > To) || (Num < From) );
        
        return Num;
    }

    string ReadText(string Message)
    {
        string Text = "";
        cout<<Message<<"\n";
        getline(cin>> ws, Text);

        return Text;
    }
    bool IsDayInRange(short Day)
    {
        return (Day <= 31 && Day >= 1);
    }
    bool IsMonthInRange(short Month)
    {
        return (Month <= 12 && Month >= 1);
    }
    bool IsYearInRange(short Year)
    {
        return ( Year <= 2025 && Year >= 1900);
    }
    // short ChekDay(short Day)
    // {
    //     while (!IsDayInRange(Day))
    //     {
    //         Day = ReadPostiveNumberSmall("Enter Day From [1] To [31].", 1, 31);
    //     }
        
    //     return Day;
    // }
    // short ChekMonth(short Month)
    // {
    //     while (!IsMonthInRange(Month))
    //     {
    //         Month = ReadPostiveNumberSmall("Enter Month From [1] To [31].", 1, 12);
    //     }
        
    //     return Month;
    // }
    // short ChekYear(short Year)
    // {
    //     while (!IsYearInRange(Year))
    //     {
    //         Year = ReadPostiveNumberSmall("Enter Day From [1900] To [2025].", 1900, 2025);
    //     }
        
    //     return Year;
    // }

    void ReadDate(MyStruct::stDate& Date)
    {
        
        cout<<string(15, '=')<<"\n";
        cout<<string(5, ' ');
        cout<<"\"Date\"\n";
        cout<<string(15, '=')<<"\n";

        Date.Day = ReadPostiveNumberSmall("\nEnter Day : ", 1, 31);
        
        Date.Month = ReadPostiveNumberSmall("\nEnter Month : ", 1, 12);

        Date.Year = ReadPostiveNumberSmall("\nEnter Year : ", 1900 ,2025);
        
        
        
    }

    
}