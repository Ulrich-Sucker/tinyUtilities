#pragma region Docs
// ====================================================================================
// 	File Name:	tinyUtilities.cpp
//	Author:		Ulrich Sucker      
// -------------------------------------------------------------------------------------
// 	Version 00.00 - 2024-02-27
//   - Base
// -------------------------------------------------------------------------------------
#define tinyUtilities_cpp_Version "00.00.005"

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
bool parseCommLineArgs(int argumentCount, char *argValues[])
{


    std::cout << "argumentCount:\t" << argumentCount << std::endl;
    // Walk through list of strings until a NULL is encountered.
	for ( int i = 1; argValues[i] != NULL; ++i )
	{
		// ---- to be deleted ------------------------------------------------------
		std::cout << i << ": ";        // Prefix with numbers if /n specified
		std::cout << argValues[i] << "\n";
	}


	std::string val = "1,22,123,2134,23543";
	int* argList = convCSV2arr(val);
	//int* argList = convCSV2arr("1,22,123,2134,23543");
	int length = argList[0];
	length = arr_length(argList);

	std::cout << argList[3] << std::endl;




    bool numberLines = false;    // Default is no line numbers.
    if (argumentCount > 0)
	{ 
         numberLines = true;

		// Walk through list of strings until a NULL is encountered.
		for ( int i = 1; argValues[i] != NULL; ++i )
		{
			// ---- to be deleted ------------------------------------------------------
			//std::cout << i << ": ";        // Prefix with numbers if /n specified
			//std::cout << argValues[i] << "\n";

			std::string OptionStr = (std::string)argValues[i];
			std::string OptionVal;
			transform(OptionStr.begin(), OptionStr.end(), OptionStr.begin(), ::toupper); 
	
			// ---- [ -COM=13 ] --------------------------------------------------------
			if (OptionStr.find("-COM") == 0) {
				OptionVal = OptionStr.substr(5, OptionStr.length());
				std::cout << "COM-Port:\t" << OptionVal << std::endl; 
			}
			
			// ---- [ -BAUD=57600 ] -----------------------------------------------------
			if (OptionStr.find("-BAUD") == 0) {
				OptionVal = OptionStr.substr(6, OptionStr.length());
				std::cout << "Baudrate:\t" << OptionVal << std::endl; 
			}

			// ---- [ -ALL ] -----------------------------------------------------------
			if (OptionStr.find("-ALL") == 0) {
				std::cout << "Display:\tAll Messages" << std::endl; 
			}

			// ---- [ -SHORT=0,1,21 ] --------------------------------------------------
			if (OptionStr.find("-SHORT") == 0) {
				// ---- "-SHORT=0,1,21" ------------------------------------------------
				if (OptionStr.length() > 6) {
					OptionVal = OptionStr.substr(7, OptionStr.length());
					std::cout << "Short:\t\t" << OptionVal << std::endl;
					
					argList = convCSV2arr(OptionVal);
					for ( int i = 1; i <= argList[0]; i++ ){
						mavMessages[argList[i]].printShort = true;
					}
				}

				// ---- "-SHORT" -------------------------------------------------------
				else {
					std::cout << "Short\t\tAll Messages" << std::endl;
					// all short true
					for (int i = 0; i < mavMsgCnt; i++){
						mavMessages[i].printShort = true;
					}
				}
			}

			// ---- [ -LONG=0,1,21,23 ] ----------------------------------------------------
			if (OptionStr.find("-LONG") == 0) {
				// ---- "-LONG=0,1,21,23" ------------------------------------------------
				if (OptionStr.length() > 5) {
					OptionVal = OptionStr.substr(6, OptionStr.length());
					std::cout << "Long:\t\t" << OptionVal << std::endl;
				
					argList = convCSV2arr(OptionVal);

					for ( int i = 1; i <= argList[0]; i++ ){
						mavMessages[argList[i]].printLong = true;
					}
				}

				// ---- "-LONG" -------------------------------------------------------
				else {
					std::cout << "Long:\t\tAll Messages" << std::endl;
					// all Long true
					for (int i = 0; i < mavMsgCnt; i++){
						mavMessages[i].printLong = true;
					}					
				}
			}
    	}
	}
    return true;
};

