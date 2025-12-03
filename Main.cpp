#include<iostream>
#include "InputDate.h"
#include "ToolsFile.h"
#include "ProcessText.h"
#include"Enum.h"
#include "Struct.h"
#include"Show.h"
#include "ImplementionBasicOpearation.h"
using namespace std;

void CelanScreen()
{
   system("cls");
}



void ImplementionBasic()
{
   MyEnum::enChose Chose = (MyEnum::enChose) Input::ChoseeWahtDoYouDo();

   switch (Chose)
   {
      case MyEnum::enChose::CreatAccount:
      {
         CelanScreen();
         Show::ShowHeadersImplemention("Created Your Account.");
         BasicOperation::CreatesManyAccount();
         
      }
      break;

      case MyEnum::enChose::ManagerUsers:
      {
         CelanScreen();
         Show::ShowManagerMenu();
         BasicOperation::MangerUser();
      }break;

      case MyEnum::Sign_In:
      {
         CelanScreen();
         Show::ShowHeadersImplemention("Sign In ....");
         BasicOperation::SignIn();
      }break;
   }
}
void StartSystem()
{
   Show::ShowMainMenu();
   ImplementionBasic();
   
}

int main()
{

   
   StartSystem();
   
  
    
}