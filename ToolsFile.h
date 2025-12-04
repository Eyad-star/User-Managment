#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include "ProcessText.h"
using namespace std;
namespace ToolFile
{
    void AddOneLineToFile(const string& Line, string NameFile)
    {
        fstream MyFile;
        MyFile.open(NameFile, ios::app);
        if(MyFile.is_open())
        {
            MyFile<<Line<<"\n";
        }
        else
            cout<<"\nNot Opened File !.";


    }
    void AddOneLineToFileAndDeleteLast(const string& Line)
    {
        fstream MyFile;
        MyFile.open("D:\\ProjectUsers\\DateUsers.txt", ios::out);
        if(MyFile.is_open())
        {
            MyFile<<Line<<"\n";
        }
        else
            cout<<"\nNot Opened File !.";


    }
    void SaveOneAccountToFileAndDeleteLast(const string& Account)
    {
        AddOneLineToFileAndDeleteLast(Account);
    }
    void SaveOneAccountToFile(const string& Account, string NameFile)
    {
        AddOneLineToFile(Account, NameFile);
    }
    

    MyStruct::stInfoAccountUser ConvertOneLineToStruct(const string& Line, const string& Sep)
    {
        vector<string> arrWors = ProccessText::SplitText(Line, Sep);
        MyStruct::stInfoAccountUser Info;

        Info.Name     = arrWors[0];
        Info.Age      = stoi(arrWors[1]);
        Info.Email = arrWors[2];
        Info.PassWord = arrWors[3];
        //-------SplitDateAlone------------
        vector<string> arrDate = ProccessText::SplitText(arrWors[4], "-");
        
        Info.DateCreated.Day   =   stoi(arrDate[0]);
        Info.DateCreated.Month =   stoi(arrDate[1]);
        Info.DateCreated.Year  =   stoi(arrDate[2]);

        return Info;
         
    }

    void GetLinesFromFile(vector<string>& EveryLines)
    {
        fstream MyFile;
        string OneLine = "";
        
        MyFile.open("D:\\ProjectUsers\\DateUsers.txt",  ios::in);
        if(MyFile.is_open())
        {
            while (getline(MyFile, OneLine))
            {
                ProccessText::AddToVector(EveryLines, OneLine);
            }
            
            MyFile.close();
        }
    }

    void GetEveryUsersAsStruct(vector<MyStruct::stInfoAccountUser>& arrEveryInfoUSers)
    {
        vector<string> arrAsLine;
        GetLinesFromFile(arrAsLine);

        for (const string &OneLine : arrAsLine)
            arrEveryInfoUSers.push_back(ConvertOneLineToStruct(OneLine, "//"));
        
    }
}
