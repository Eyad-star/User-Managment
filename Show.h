#pragma once
#include<iostream>
#include "ProcessText.h"
using namespace std;
namespace Show
{
   void ShowMainMenu()
   {
        cout<<string(40, '=')<<"\n";
        cout<<string(40, '=')<<"\n";
    
        cout<<ProccessText::GetSpace(10)<<"[1] : Sign In.\n";
        cout<<ProccessText::GetSpace(10)<<"[2] : Create New Account.\n";
        cout<<ProccessText::GetSpace(10)<<"[3] : User Manager.\n";
   
        cout<<string(40, '=')<<"\n";
        cout<<string(40, '=')<<"\n";
    
   }  

   void ShowHeadersImplemention(const string& Messgae)
   {
        cout<<string(40, '=')<<"\n";
        cout<<string(10, ' ');
        cout<<Messgae<<"\n";
        cout<<string(40, '=')<<"\n";
   } 
   
   void PrintCardUser(const MyStruct::stInfoAccountUser& InfoUser)
   {
        cout<<string(40, '-')<<"\n";
        cout<<"Name     : "<<InfoUser.Name<<"\n";
        cout<<"Age      : "<<InfoUser.Age<<"\n";
        cout<<"Email    : "<<InfoUser.Email<<"\n";
        cout<<"PassWord : "<<InfoUser.PassWord<<"\n";
        cout<<"Date     : ";
        cout<<InfoUser.DateCreated.Day<<"-"<<InfoUser.DateCreated.Month<<"-"<<InfoUser.DateCreated.Year;
        cout<<"\n";
        cout<<string(40, '-')<<"\n";
   }

   void ShowManagerMenu()
   {
        cout<<string(40, '=')<<"\n";
        cout<<string(40, '=')<<"\n";
    
        cout<<ProccessText::GetSpace(10)<<"[1] : Show Al User.\n";
        cout<<ProccessText::GetSpace(10)<<"[2] : Delete User.\n";
   
        cout<<string(40, '=')<<"\n";
        cout<<string(40, '=')<<"\n";
    
   } 

} 
