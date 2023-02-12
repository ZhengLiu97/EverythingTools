#pragma once

#include <iostream>
#include <string>
//#include < vector>

#ifdef CPPEVERYTHINGDLL_EXPORTS
#define CPPEVERYTHINGDLL_API __declspec(dllexport)
#else
#define CPPEVERYTHINGDLL_API __declspec(dllimport)
#endif

extern "C" CPPEVERYTHINGDLL_API int get_full_file_path(char* search_string, char* full_path[]);