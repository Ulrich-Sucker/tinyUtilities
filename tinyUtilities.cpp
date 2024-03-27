#pragma region Docs
// ====================================================================================
// 	File Name:	tinyUtilities.cpp
//	Author:		Ulrich Sucker      
// -------------------------------------------------------------------------------------
// 	Version 00.00 - 2024-02-27
//   - Base
// -------------------------------------------------------------------------------------
#define tinyUtilities_cpp_Version "00.00.002"
// =====================================================================================
#pragma endregion

#pragma once

// ---- include public libs ------------------------------------------------------------ */
#include <iostream>
#include <string>

// ---- include local libs ------------------------------------------------------------- */
#include "tinyUtilities.hpp"


// ==== FUNCTION: arr_length ===========================================================
int arr_length(int arr[])
{
    int i;
    int count = 0;
    for(i=0; arr[i]!='\0'; i++)
    {
        
		std::cout << arr[i]  << std::endl;
		count++;
    }
    return count;
}

// ==== FUNCTION: convCSV2arr ==========================================================
int* convCSV2arr(std::string list)
{
	std::string restStr;
	std::string value;
	int counter = 0;
	int pointer = 0;

	// ---- Elemente zählen ------------------------
	restStr = list;
	do
	{
		pointer = restStr.find(",");
		if (pointer > 0){
			restStr = restStr.substr(pointer+1, restStr.length());
			counter ++;
		}
	} while ( pointer > 0 );
	counter ++;

	// ---- Array bauen ----------------------------------------------------------------
	int* array = new int[counter+1];
	array[0] = counter;		// Länge auf Platz 0 speichern
	restStr = list;

	for (int i = 1; i < counter+1; i++ ){
		pointer = restStr.find(",");
		value = restStr.substr(0, pointer);
		restStr = restStr.substr(pointer+1, restStr.length());

		array[i] = stoi(value);
		std:: cout << i << ":\t" << array[i] << std::endl;
	}
	return array;
}

// ==== FUNCTION: parseCommLineArgs ====================================================
bool parseCommLineArgs(int argc, char *argv[])
{
	
	return true;
}
