#pragma once
#include"ToolsFile.h"
using namespace std;
namespace Security
{

    void BackUpInfoUsers(const string& InfoUserOneLine, string NameFile)
    {
        ToolFile::AddOneLineToFile(InfoUserOneLine, NameFile);
    }  
} 
