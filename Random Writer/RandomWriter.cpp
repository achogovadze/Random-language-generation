/*
* File: RandomWriter.cpp
* ----------------------
* Name: [TODO: enter name here]
* Section: [TODO: enter section leader here]
* This file is the starter project for the Random Writer problem.
* [TODO: rewrite the documentation]
*/

#include <iostream>
#include <fstream>
//#include "console.h"
#include "simpio.h"
#include <string>
#include "map.h"
#include "vector.h"
#include "random.h"

using namespace std;

static const int gen_num = 2000;

bool inOrder(int order);
void readInfo(ifstream &stream, int order, Map<string, Vector<char> > &map);
void generateText(Map<string, Vector<char> > &map);
char generateChar(Map<string, Vector<char> > &map, string &start);
string findMost(Map<string, Vector<char> > &map);
char toLower (char &ch);

int main() {
	string filename = getLine("Enter the source text: ");
	ifstream stream(filename.c_str());
	while (!stream){
		stream.clear();
		cout << "Unable to open that file. Try again." << endl;
		filename = getLine("Enter the source text: ");
		stream.open(filename.c_str());
	}
	int order = getInteger("Enter the Markov order [1-10]: ");
	while (!inOrder(order)){
		cout << "The value is out of range." << endl;
		order = getInteger("Enter the Markov order [1-10]: ");
	}
	Map<string, Vector<char> > map;
	cout << "Processing file..." << endl;
	readInfo(stream, order, map);
	cout << "File processed, generating text..." << endl;
	generateText(map);
	return 0;
}

// this method checks if entered order number is correct, in bounds from 0 to 10 incluseive.
bool inOrder(int order){
	if (order >= 1 && order <= 10)
		return true;
	return false;
}

// this method reads entered file and stores information.
void readInfo(ifstream &stream, int order, Map<string, Vector<char> > &map){
	char ch;
	string word;
	if (stream >> noskipws >> ch){
		word += ch;
		for (int i = 0; i < order -1; i++){
			if (stream >> noskipws >> ch)
				word += ch;
		}
		word = toLowerCase(word);
		if (word.length() == order){
			if (stream >> noskipws >> ch){
				toLower(ch);
				map[word] += ch;
			}
		}
		while (1){
			word = word.substr(1) + ch;
			if (word.length() == order){
				if (stream >> noskipws >> ch){
					toLower(ch);
					map[word] += ch;
				} else {break;}
			}
		}
	}
}

// this method generates text with size of gen_num symbols.
void generateText(Map<string, Vector<char> > &map){
	string result;
	string start = findMost(map);
	for (int i = 0; i < gen_num; i++){
		result += generateChar(map, start);
	}
	cout << result << endl;
}


// this method generates random character based on occurance.
char generateChar(Map<string, Vector<char> > &map, string &start){
	Vector<char> vect = map[start];
	char result = vect[randomInteger(0,vect.size() -1)];
	start = start.substr(1) + result;
	return result;
}

// this method finds the most used set of characters to start generating random text.
string findMost(Map<string, Vector<char> > &map){
	int max = 0;
	string result;
	foreach (string word in map){
		if (map[word].size() > max){
			max = map[word].size();
			result = word;
		}
	}
	return result;
}

// this method converts character to lowercase.
char toLower (char &ch){
	if (ch >= 'A' && ch <= 'Z')
		ch = 'a' + ch - 'A';
	return ch;
}
