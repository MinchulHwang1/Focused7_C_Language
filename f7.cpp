/*
* File : f7.cpp
* Project : Focused 7
* Programmer : Minchul Hwang
* Firstversion : 2022-11-12
* Descroption : This program use file I/O functions to extract text file called "myTextFile.txt" and Binary file called "myBinaryFile.data"
*               Each file has their own line as requirement.
*               the code is open the file write and close including error check.
*/


#include<stdio.h>
#pragma warning(disable: 4996) // required by Visual Studio


int main() {
	
	int i = 1;
	int limit_line = 3;
	char letter[81] = {0};

	FILE* textFile = fopen("myTextFIle.txt", "w");

	//Checking error to open file.
	if (textFile == NULL) {
		printf("Can't open file for writing\n");
		return 0;
	}

	//Write line of text before open file
	for (i; i < limit_line; i++) {
		if (fprintf(textFile, "This is line %d.\n", i) < 0) {
			printf("Can not write line to file\n");
			return 0;
		}
	}
	
	//Check error when close file
	if (fclose(textFile) != 0) {
		printf("Can't close file\n");
		return 0;
	}
	
	//open the previously written file for reading
	textFile = fopen("myTextFIle.txt", "r");

	if (textFile == NULL) {
		printf("Can't open file\n");
		return 0;
	}

	while (fgets(letter, sizeof letter, textFile) != 0){
		// File close when it is end of file.
		if (feof(textFile)){
			break;
		}
		// if there is an error in file
		if (ferror(textFile)){
			printf("Error to read file\n");
			
			if (fclose(textFile) != 0){
				printf("Can't close file\n");
				return 0;
			}
			return 0;
		}
	}
	
	//Binary file from here.

	const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };
	unsigned short kBD[11];
	char binaryLetter[81];
	int array_limit = 10;
	int array_element = 11;

	FILE* binaryFile = fopen("myBinaryFile.data", "wb");
	
	//Checking error to open file.
	if (binaryFile == NULL) {
		printf("Can't open file for writing \n");
		return 0;
	}
	
	//write the file
	if (fwrite(kBinaryData, sizeof(const unsigned short), array_element, binaryFile) < array_element) {

		printf("Can't write to file\n");
		return 0;
	}

	if (fclose(binaryFile) != 0) {
		printf("Can't close file for writing\n");
		return 0;
	}
	
	binaryFile = fopen("myBinaryFile.data", "rb");
	
	if (fread(kBD, sizeof(const unsigned short), array_element, binaryFile) < array_element) {
		printf("Error to read file\n");
		
		return 0;
	}
	
	if (fclose(binaryFile) != 0) {
		
		printf("Can't close read file\n");
		return 0;
	}
	
	return 0;
}