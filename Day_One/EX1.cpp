#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int ReadFile(std::ifstream& is);
std::vector<int> ReadLine(std::ifstream& is);
int calcLine(std::vector<int> vec);

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
    std::vector<int> resultVector;
    
    while(is){
        vec = ReadLine(is);
        sum += calcLine(vec);
    }
    return sum;
}

int calcLine(std::vector<int> vec){
    
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
    
    std::getline(is, str);
    
    for (char c : str) {
        if (std::isdigit(c)) {
            vec.push_back(c - '0');
        }
    }
    return vec;
}
