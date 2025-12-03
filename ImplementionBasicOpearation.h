#pragma once
using namespace std;
#include<iostream>
#include "ProcessText.h"
#include "InputDate.h"
#include "Struct.h"
#include"ToolsFile.h"
namespace BasicOperation
{
    
    MyStruct::stInfoAccountUser CreaeOneAccount()
    {
        MyStruct::stInfoAccountUser OneAccount;


        OneAccount.Name = ProccessText::DeletSpaceFromLeftAndRight(Input::ReadText("Please Enter Your Full Name : "));
        OneAccount.Age = Input::ReadPostiveNumberSmall("Please Enter Your Age : ", 15, 100);
    
        Input::ReadDate(OneAccount.DateCreated);

        OneAccount.Email = ProccessText::ChekEmail(Input::ReadText("Please Enter Your Email :"));
    
        OneAccount.PassWord = ProccessText::ChekPassWord(Input::ReadText("Please Enter PassWord"));
    
    
        return OneAccount;
    
    }
    void CreatesManyAccount()
    {
        MyStruct::stInfoAccountUser InfoAccounts;
        char AddMoreUser = 'N';
        do
        {
      
        InfoAccounts = CreaeOneAccount();
        ToolFile::SaveOneAccountToFile(ProccessText::ConvertStructToLine(InfoAccounts));
        cout<<"\nDo You Add Anthor User ? \n";
        cin>>AddMoreUser;
        } while (tolower(AddMoreUser) == 'y');
    
    }
    void PrintUserSignIn(const vector <MyStruct::stInfoAccountUser>& Info, const MyStruct::stSignIn& InfoSignIn )
    {
        bool Find = false;
        for(const MyStruct::stInfoAccountUser &OneUserInfo : Info)
        {
            if(OneUserInfo.Name == InfoSignIn.Name )
            {  
         
                if(OneUserInfo.Email == InfoSignIn.Email)
                {
                    Find = true;
                    Show::PrintCardUser(OneUserInfo);
                    break;
                }
            }
      

        }
   
   if(!Find)
      cout<<"\nNot Find Your Account. \n";
   
   
}

    void SignIn()
    {
            vector<MyStruct::stInfoAccountUser> InfoEvery;
            ToolFile::GetEveryUsersAsStruct(InfoEvery);

            MyStruct::stSignIn InfoSignIn;
            InfoSignIn.Name = Input::ReadText("\nPlease Enter Your Name   : ");
            InfoSignIn.Email = Input::ReadText("\nPlease Enter Your Email :");
            PrintUserSignIn(InfoEvery, InfoSignIn);
    }
    
    void PrintEveryUsers()
    {
        vector<MyStruct::stInfoAccountUser> vEveryUser;
        ToolFile::GetEveryUsersAsStruct(vEveryUser);

        for (const MyStruct::stInfoAccountUser &OneUser : vEveryUser)
                Show::PrintCardUser(OneUser);
        
    }
    
    void DeleteOneUser(string NameUserDelet)
    {
        
        vector<MyStruct::stInfoAccountUser> InfoEvery;
        ToolFile::GetEveryUsersAsStruct(InfoEvery);
        
        for (const MyStruct::stInfoAccountUser &OneUser : InfoEvery)
        {
            if( !(NameUserDelet == OneUser.Name) )
                ToolFile::SaveOneAccountToFileAndDeleteLast(ProccessText::ConvertStructToLine(OneUser));
        }
        
    }
    bool IsUserInDataBase(string NameUserDelet)
    {
        
        vector<MyStruct::stInfoAccountUser> InfoEvery;
        ToolFile::GetEveryUsersAsStruct(InfoEvery);
        
        for (const MyStruct::stInfoAccountUser &OneUser : InfoEvery)
        {
            if((NameUserDelet == OneUser.Name) )
                return true;
        }

        return false;
        
    }
    MyStruct::stInfoAccountUser GetOneStrcut(string Name)
    {
        vector<MyStruct::stInfoAccountUser> InfoEvery;
        ToolFile::GetEveryUsersAsStruct(InfoEvery);
        
        for (const MyStruct::stInfoAccountUser &OneUser : InfoEvery)
        {
            if((Name == OneUser.Name) )
                return OneUser;
        }

        
    }
    void DeletUsers()
    {
        
        
        char DeleteSure = 'n';

        char DeleteMore = 'N';

        do
        {

           string NameUserDelete = Input::ReadText("Please Enter Name USer Do You Delete .");
           if(IsUserInDataBase(NameUserDelete))
           {
                Show::PrintCardUser(GetOneStrcut(NameUserDelete));
                DeleteSure = ProccessText::ReadOneChar("\nSure. Delete This User.");

                if( tolower(DeleteSure) != 'n')
                    DeleteOneUser(NameUserDelete);
           }
           else
                cout<<"This User Not Find .\n"; 

               
           DeleteMore = ProccessText::ReadOneChar("Do You Delete Anthor ? ");
        } while (DeleteMore == 'Y' || DeleteMore == 'y');
    
        
    }
    void ChekOperationFromManger(MyEnum::enChoseManager Chose)
    {
        if(Chose == MyEnum::enChoseManager::Show)
            PrintEveryUsers();

        else if (Chose == MyEnum::enChoseManager::Delete)
            DeletUsers();        
    }
    void MangerUser()
    {
        MyEnum::enChoseManager Chose = (MyEnum::enChoseManager) Input::ReadPostiveNumberSmall("Please Enter From This : ", 1, 2);
        
        ChekOperationFromManger(Chose);
    }

  
} 