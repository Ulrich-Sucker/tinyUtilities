#pragma region Docs
// ====================================================================================
// 	File Name:	tinyUtilities.hpp
//	Author:		Ulrich Sucker      
// -------------------------------------------------------------------------------------
// 	Version 00.00 - 2024-02-27
//   - Base
// -------------------------------------------------------------------------------------
<<<<<<< HEAD
#define tinyUtilities_hpp_Version "00.01.007"
=======
#define tinyUtilities_hpp_Version "00.01.004"
>>>>>>> a4e53fb4f2ef79f1b3be076fb88682723641c17e
// =====================================================================================
#pragma endregion


// ---- include public libs ------------------------------------------------------------ */
#include <iostream>
<<<<<<< HEAD
#include <string>
#include <algorithm> 
#include <array> 

// ---- include local libs ------------------------------------------------------------- */
#include "..\MAVLocalLib\MAVLocalLib.cpp"


// ---- Funktion Prototyps --------------------------------------------------------------
int arr_length(int arr[]);

int* convCSV2arr(std::string list);

bool parseCommLineArgs(int argc, char *argv[]);
=======
#include <string

// ---- Funktion Prototyps --------------------------------------------------------------

int arr_length(int arr[]);

int* convCSV2arr(std::string list);
>>>>>>> a4e53fb4f2ef79f1b3be076fb88682723641c17e
