#pragma once
using namespace std;

#include<iostream>
namespace MyStruct
{

    struct stDate
    {
        short Day = 0, Month = 0, Year = 0; 
    };
    
    struct stInfoAccountUser
    {
    string Name = "";
    string Email = "";
    string PassWord = "";
    stDate DateCreated;
    short Age = 0;
    


    };
    
    struct stSignIn
    {
        string Name = "", Email = "";
    };
    
    
} 
