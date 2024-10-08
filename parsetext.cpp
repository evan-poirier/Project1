// Sample program to read and split text delimited by whitespace
// Uses C++ regular expression library function std::sregex_token_iterator
// For more details see:
// https://en.cppreference.com/w/cpp/regex/regex_token_iterator/regex_token_iterator
// https://docs.microsoft.com/en-us/cpp/standard-library/regular-expressions-cpp
// 
// To compile: g++ -std=c++20 parsetext.cpp
// To run: ./a.out < input.txt
// NOTE: This program reads input from the keyboard and the example shows
//       how to use I/O redirection to read from the file. In your homework, 
//       you MUST read the file name as a command-line argument and then 
//       read the contents of that file.

#include <iostream>
#include <vector>
#include <regex>
#include <map>
#include <string>
#include <algorithm>

/*
class Word {
   public:
      int appearances;
      std::string content;

      Word(int apps, std::string letters) {
         appearances = apps;
         content = letters;
      }
};
*/


int main() {

   // parse input text 

   std::string text;
   std::vector<std::string> tokens;
   const std::regex delim("\\s+"); 

   while (std::cin >> text) {
      auto begin = std::sregex_token_iterator(text.begin(), text.end(), delim, -1);
      auto end = std::sregex_token_iterator();
      for (std::sregex_token_iterator word = begin; word != end; word++) {
         tokens.push_back(*word);
      }
   }

   // insert each word into an map in O(n lg(n)) time
   // performs a map search in O(lg(n)) time, and then either 
   //    - increases the value of the pair pointed to by the iterator in O(1) time
   //    - inserts a new pair in O(lg(n)) time

   std::map<std::string, int> wordOccurrences;

   for (const auto & str : tokens) {
      auto it = wordOccurrences.find(str);

      if (it != wordOccurrences.end()) {
         it->second ++;
      } else {
         wordOccurrences.insert(std::pair<std::string, int>(str, 1));
      }
   }

   // fills a vector with all of the pairs from the map in O(n) time

   std::vector<std::pair<std::string, int>> wordsVector;

   for (const auto &wordPair : wordOccurrences) {
      wordsVector.push_back(wordPair);
   }

   // sorts the vector by the value of each pair (number of appearances) using std::stable_sort in O(n lg(n)) time
   std::sort(wordsVector.begin(), wordsVector.end(), [=](std::pair<std::string, int> &x, std::pair<std::string, int> &y) {
      return x.second > y.second;
   });

   for (const auto &wordPair : wordsVector) {
      std::cout << wordPair.first << ": " << wordPair.second << std::endl;
   }

   return 0;
}
