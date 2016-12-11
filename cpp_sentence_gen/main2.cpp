#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <tuple>
#include <sstream>
#include <cstdlib>
#include <iterator>



using namespace std;


class Word {
  public:
    string word;
    int frequency;
};


//new one

map<string, vector<Word>> markov_mapping(vector<string> wordList){
  map<string, vector<Word>> newMap;
  
  if(newMap.empty()){
    
  }
  
  vector<Word> temp;
  for(int i = 0; i < wordList.size()-1; i++) {
      
    if(newMap.count(wordList.at(i)) == 0){
      //cout << wordList.at(i) << "not in map yet" << endl;
      Word firstWord;
      firstWord.word = wordList.at(i+1);
      vector<Word> list_of_words;
      list_of_words.push_back(firstWord);
      newMap[wordList.at(i)] = list_of_words;
    }
    else {
      //cout << wordList.at(i) << "already in map" << endl;
      temp = newMap.at(wordList.at(i));
      Word to_be_inserted;
      to_be_inserted.word = wordList.at(i + 1);
      temp.push_back(to_be_inserted);
      newMap[wordList.at(i)] = temp;
    }
  }
  return newMap;
}
//

string fileIn(string fileName){
    string text,line;
    ifstream file;
    file.open(fileName);
     if (file.is_open())
  {
    while ( getline (file,line) )
    {
      text = text + line + " ";
      //cout << text << endl;
    }
    file.close();
  }
  else cout << "Unable to open file" << endl; 
    file.close();


    return text;
}//reads in raw .txt files and returns string

vector<string> convertToWordList(string input) {
  string temp;
  int count = 1;
  vector<string> list;
  stringstream ssin(input);
  int i=0;
  while(ssin.good()){
    ssin >> temp;
    list.push_back(temp);
    ++i;
  
  }
  return list;
}



int main() {
    vector<string> files = {"Const.txt", "HillaryClinton.txt", "DonaldTrump.txt", "LilWayne.txt", "PrideAndPrej.txt", "StephenColbert.txt", "Iraq.txt"};

    string fileName;
    bool validFile = 0;
    
      while(!validFile) {
      cout << "Please enter the name of the text file to read (enter '-list' to see a list of available files) : ";
      cin >> fileName;
      if(fileName == "-list") {
        cout << endl;
        for(int j = 0; j < files.size() ; j++) {
          cout << files.at(j) << endl;
        }
        cout << endl;
      }
      else {
        for(int j = 0; j < files.size(); j++) {
          if(fileName == files.at(j)) {
            validFile = 1;
          }
        }
        if(!validFile) {
          cout << fileName << " is an invalid file name, make sure to include the '.txt', if this does not work then shut off your computer and throw it out the window!" << endl;
        }
      }
    }
    cout << "Now generating tweets in the style of " << fileName  << "......\n" << endl;
    string x;
    x = fileIn(fileName);
    
    
    vector<string> words = convertToWordList(x);

    
    map<string, vector<Word>> parsed_words = markov_mapping(words);
 
    Word current;
  
    srand(time(NULL));
    
    
    vector<string> tweet;
    int random;
    
    string inpt;
    
    while(inpt != "q") {
      int rnd = rand() % (words.size());
      vector<Word> temp = parsed_words.at(words.at(rnd));
      cout << words.at(rnd) << " ";
      
      for(int j = 0; j < 140; j++) {
        random = rand() % (temp.size());
        current = temp.at(random);
        cout << current.word << " ";
        temp = parsed_words.at(current.word);
      
      }
      cout << endl;
      cout << endl;
      
      cout << "Enter any key to generate another tweet or 'q' to quit : ";
      cin >> inpt;
      cout << endl;
    }
    
}
