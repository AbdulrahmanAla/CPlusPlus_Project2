#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <map>
#include <istream>
#include <stdexcept>
#include <sstream>

 
using std::string, std::cin, std::cout, std::endl,  std::istream, std::map;


// This function open the file and check if the file is open and if it was it would return infstream to the file.
// If the file doesn't open it would return an erro message and throw a runtime Error.
// If the user entered any unsppourted characters the function would throw invalid argument with an error message.

std::ifstream OpenFile(string const &file_name) {
    std::ifstream input_file;
    input_file.open(file_name);
    if (input_file.is_open()){
        
        return input_file;
    }
    else if (!(input_file.is_open())){
        std::ostringstream oss;
        oss << "Error: Cannot open " << file_name<<".";
        throw std::runtime_error(oss.str());
    }
    else{
        throw std::invalid_argument("Error: Cannot open ");
    }
}
// this function would take the encoding input (word by word) 
// and store the first letter as a key and the other one as a value for that key.
std::map<char,char> GetMapForEncrypt(string const &inpt, map<char,char> &letter_pair){
	
	letter_pair[inpt.at(0)] = inpt.at(1);
	
	return letter_pair;
}



int main() {
  string file_name;
  cin >> file_name;
  // a try and catch blocks that would try openning the file using OpenFile function.
  // Storing the content of the file inside an input file stream and cathcing a runtime error.
  
  try{
        std::ifstream file_content =OpenFile(file_name);  
    }
    catch (std::runtime_error &e){
      //Storing the error message to ostringstream to be able to store the error message
      // and the file name in one cout statment.
        std::ostringstream oss;
        oss << "Error: Cannot open " << file_name<<".";
        cout << oss.str();
        return 1;
    }
    catch(std::invalid_argument &e){
      return 1;
    }
  //opening the file again to store it in a ifstream that can be used ouside of the try block.
  std::ifstream file_content =OpenFile(file_name);
  string line;
  string input;
	map<char,char> letter_pair;
	// this loop would take the letter pairs input and check if it is written in the correct format
  // otherwise it would throw a runtime_error. The correct format include only two letters and
  // the letter 'q' is not entered. 
  // The loop would continue unitl it hit EOF. 
  while(cin >> input ){
    try {

      if (static_cast<int>(input.size())<= 1 && input != "q"){
      throw std::runtime_error("Error: Unknown encoding 'input'.");

      }
      if (static_cast<int>(input.size()) > 2){
        throw std::runtime_error("Error: Unknown encoding 'input'.");
      }
      if(letter_pair.find(input.at(0)) != letter_pair.end()) {
        throw std::runtime_error("Error: Unknown encoding 'input'.");
      }

      GetMapForEncrypt(input,letter_pair);
    }// a cathch for the error was raised.
    catch(std::runtime_error &e){
      return 1;
      
    }
	}
  //creating an unordered_set to add the encrypted woords so that it would keep the order it was entered
  // and only get unique words inside the set.
  std::unordered_set<string> Set_contains_output;

  // looping through every line of the file
  while (getline(file_content,line)){
    
    //looping on every character of the line and applying the encryption/decryption on it.
    for(auto pos= line.begin(); pos !=line.end(); pos++){
      if(letter_pair.find(*pos) != letter_pair.end() ){
        *pos =letter_pair.at(*pos);
      }
    }
    
    //if the word was unique, it would output the line following it by endl.
    if (Set_contains_output.insert(line).second){
      cout <<line <<endl;
    }
    

  }  

  
  file_content.close();
  
}

    