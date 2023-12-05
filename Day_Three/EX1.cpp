#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void print_sum(std::vector<int>& vec);
std::vector<int> adjacent(std::ifstream& is);
int get_number(std::string, int& i);
bool valid_character(char a);

int main(){
    
    std::string path = "/Users/filiphamrelius/Documents/Advent_Of_Code/Advent_Of_Code/Input.txt";
    std::ifstream Data(path);
    
    std::vector<int> vec;
    
    if (!Data) {
        std::cout << "File error.\n";
        return 0;
    }
    
    vec = adjacent(Data);
    print_sum(vec);
}

std::vector<int> adjacent(std::ifstream& is){
    
    std::vector<int> vec;
    std::string line;
    std::string previousLine;
    std::string lineBelow;
    int number = 0;
    
    while(getline(is, line, '\n')){
        
        std::streampos currentPos = is.tellg();
        
        for(int i = 0; i < line.size(); i++){
            
            if(std::isdigit(line[i])){
                
                /* ---------- LEFT ----------- */ // DONE
                if(valid_character(line[i-1])){
                    number = get_number(line, i);
                    vec.push_back(number);
                }
                
                /* ---------- RIGHT ----------- */ // DONE
                if(valid_character(line[i+1]) or valid_character(line[i+2]) or valid_character(line[i+3])){
                    number = get_number(line, i);
                    vec.push_back(number);
                }
                
                /* ---------- UNDER ----------- */
                if (getline(is, lineBelow, '\n')){
                    is.seekg(currentPos);
                    for (int j = std::max(0, i - 1); j < i + 5 && j < lineBelow.size(); j++) {
                        if(valid_character(lineBelow[j])){
                            number = get_number(line, i);
                            vec.push_back(number);
                            std::cout << number << std::endl;
                        }
                    }
                }
                
                /* ---------- OVER ----------- */
                for (int j = std::max(0, i - 1); j < i + 5 && j < previousLine.size(); j++) {
                    if(valid_character(previousLine[j])){
                        number = get_number(line, i);
                        vec.push_back(number);
                    }
                }
            }
        }
        previousLine = line;
    }
    return vec;
}

int get_number(std::string str, int& i){
    
    int number = 0;
    
    if (std::isdigit(str[i + 2])) {
        number = (str[i] - '0') * 100 + (str[i + 1] - '0') * 10 + (str[i + 2] - '0');
        i += 3;
        return number;
    } else if (std::isdigit(str[i + 1])) {
        number = (str[i] - '0') * 10 + (str[i + 1] - '0');
        i += 2;
        return number;
    } else {
        number = str[i] - '0';
        i++;
        return number;
    }
}

void print_sum(std::vector<int>& vec){
    
    int sum = 0;
    for(int i : vec) sum += i;
    std::cout << "The sum of all of the part numbers in the engine schematic is: " << sum << std::endl;
}

bool valid_character(char a){
    if (a != '.' && a != '\n' && !isdigit(a) && a != '\0' && !iscntrl(a)) return true;
    return false;
}

