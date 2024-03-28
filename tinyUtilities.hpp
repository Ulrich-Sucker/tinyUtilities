#pragma region Docs
// ====================================================================================
// 	File Name:	tinyUtilities.hpp
//	Author:		Ulrich Sucker      
// -------------------------------------------------------------------------------------
// 	Version 00.00 - 2024-02-27
//   - Base
// -------------------------------------------------------------------------------------

#define tinyUtilities_hpp_Version "00.01.009"

// =====================================================================================
#pragma endregion


// ---- include public libs ------------------------------------------------------------ */
#pragma once
#include <iostream>
#include <string>
#include <algorithm> 
#include <array> 

// ---- include local libs ------------------------------------------------------------- */
//#include "..\MAVLocalLib\MAVLocalLib.cpp"


// ---- Funktion Prototyps --------------------------------------------------------------
int arr_length(int arr[]);

int* convCSV2arr(std::string list);

bool parseCommLineArgs(int argc, char *argv[]);
