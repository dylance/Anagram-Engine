#ifndef  HW4_AUX
#define  HW4_AUX

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Anagram {

private:
	string list[25][27][400];

	int track[25][27] = { { 0 } };

	ifstream fin;

public:

	bool openFile();

	bool sameLetters(string key, string word);

	void loadArray();

	void checkWord();

	void checkKey(int l, string searchKey,  bool &match, int &tempSize, int &count2);

	void checkWord(int i, string searchKey,  bool &match, int &tempSize, int &count2, int &tempchar);

	void checkAnagram(int i, int &sizee, int &size2, string &key, string &word, int &count);

	void checkAnagram2(int j, int &size2, string &key, string &word, int &i, int &count);


};






#endif // !
