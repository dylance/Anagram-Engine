#include <string>
#include <iostream>
#include <fstream>
#include "hw4_aux.h"


using namespace std;

bool Anagram::openFile()
{
	string file_name;
	cout << "Enter file name including the path: ";
	getline(cin, file_name);

	fin.open(file_name);

	if (fin.fail())
		return false;
	else
		return true;


}

void Anagram::loadArray() {


	string line;
	char letter;
	
	if (!(getline(fin, line)))
		return;


	int	size = line.size();

	letter = line[0];

	
	if (letter > 96 && letter < 123)
		letter = letter - 97;
	else if (letter > 64 && letter < 91)
		letter = letter - 65;
	else
		letter = 26;

	int num = letter;

	list[size - 1][num][track[size - 1][num]] = line;
	track[size - 1][num]++;

	loadArray();





}

void Anagram::checkAnagram2(int j, int &size2, string &key, string &word, int &i, int &count) {

	if (j == size2)
		return;



	if (key[i] == word[j])
	{

		word[j] = word[size2 - 1];
		count++;
		size2--;
		j++;
		return;


	}
	j++;
	checkAnagram2(j, size2, key, word, i, count);

}

void Anagram::checkAnagram(int i, int &sizee, int &size2, string &key, string &word, int &count) {


	if (i == sizee)
		return;

	checkAnagram2(0, size2, key, word, i, count);

	i++;

	checkAnagram(i, sizee, size2, key, word, count);

}

bool Anagram::sameLetters(string key, string word) {

	int sizee = key.size();
	int size2 = sizee;

	int count = 0;


	checkAnagram(0, sizee, size2, key, word, count);


	if (count == sizee)
		return true;
	else
		return false;


}

void Anagram::checkWord(int i, string searchKey,  bool &match, int &tempSize, int &count2, int &tempchar) {


	if (i == track[tempSize - 1][tempchar])
		return;


	match = sameLetters(searchKey, list[tempSize - 1][tempchar][i]);
	if (match) {

		cout << searchKey << " is an anagram with " << list[tempSize - 1][tempchar][i] << endl;
		count2++;
	}
	i++;

	checkWord(i, searchKey, match, tempSize, count2, tempchar);
}

void Anagram::checkKey(int l, string searchKey,  bool &match, int &tempSize, int &count2) {


	if (l == tempSize)
		return;


	int	tempchar = searchKey[l] ;
	
	if (tempchar > 96 && tempchar < 123)
		tempchar = tempchar - 97;
	else if (tempchar > 64 && tempchar < 91)
		tempchar = tempchar - 65;
	else
		tempchar = 26;
	

	checkWord(0, searchKey,  match, tempSize, count2, tempchar);


	l++; 
	checkKey(l, searchKey,  match, tempSize, count2);


}

void Anagram::checkWord() {

	bool match = false;
	int tempSize;



	string searchKey;




	
	cout << "Enter the word to search for: ";
	cin >> searchKey;

	if (searchKey == "!exit") {
		cout << "Bye!" << endl;
		return;
	}

	tempSize = searchKey.size();
	int count2 = 0;

	checkKey(0, searchKey, match, tempSize, count2);


	if (count2 < 1)
		cout << "no match was found." << endl;


	checkWord();

}
