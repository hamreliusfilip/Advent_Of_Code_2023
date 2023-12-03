#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int ReadFile(std::ifstream& is);
std::vector<int> ReadLine(std::ifstream& is);
int calcLine(std::vector<int>& vec);

int main() {
    
    std::string path = "/Users/filiphamrelius/Documents/Advent_Of_Code/Advent_Of_Code/EX1_Input.txt";
    
    std::ifstream Data(path);
    
    if (!Data) {
        std::cout << "File error.\n";
        return 0;
    }
    
    int Total = ReadFile(Data);
    
    std::cout << "The total value is " << Total << std::endl;
}

int ReadFile(std::ifstream& is){
    
    std::vector<int> vec;
    int sum = 0;
    
    while(is){
        vec = ReadLine(is);
        sum += calcLine(vec);
    }
    return sum;
}

int calcLine(std::vector<int>& vec){
    
    if(vec.size() == 0){
        return 0;
    }else if(vec.size() == 1){
        return vec[0]*10 + vec[0];
    }else{
        return vec[0]*10 + vec[vec.size()-1];
    }
}

std::vector<int> ReadLine(std::ifstream& is){
    
    std::string temp;
    std::string str;
    std::vector<int> vec;
    std::vector<std::string> num = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    std::getline(is, str);

    for (int i = 0; i < str.size(); i++){
        
        char c = str[i];
        
        if (std::isdigit(c)) {
            vec.push_back(c - '0');
        }
        
        for (int j = 0; j < num.size(); j++){
            
            std::string tempNumber = num[j]; // Test number from num string vec
            
            if (str.size() >= i + tempNumber.size()){ // Is there enough of chars ahead to be a number?
                
                if (str.substr(i, tempNumber.size()) == tempNumber){ // Starting index at i and length of number
                    vec.push_back(j+1); // Not zero indexed
                }
            }
        }
    }
    return vec;
}



