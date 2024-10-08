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

int main() {
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

   for(const auto & str : tokens)
      std::cout << str << std::endl;

   return 0;
}
