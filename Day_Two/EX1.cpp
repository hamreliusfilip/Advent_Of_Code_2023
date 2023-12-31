#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>

struct Cubes {
    int amount = 0;
    std::string color;
};

std::vector<Cubes> read_cube(std::string& str);

int main() {
    
    std::string path = "/Users/filiphamrelius/Documents/Advent_Of_Code/Advent_Of_Code/Input.txt";
    std::ifstream Data(path);
    
    if (!Data) {
        std::cout << "File error.\n";
        return 0;
    }
    
    Cubes RedCubes = {12, "red"};
    Cubes GreenCubes = {13, "green"};
    Cubes BlueCubes = {14, "blue"};
    
    int sumIds = 0;
    int counter = 1;
    
    std::vector<Cubes> cubeVec;
    std::string str;
    bool skipIteration;
    
    while(std::getline(Data, str,'\n')){
        
        std::replace(str.begin(), str.end(), ';', '\n');
        
        cubeVec = read_cube(str);
        skipIteration = false;
        
        for (int i = 0; i < cubeVec.size(); i++) {
            
            skipIteration = (cubeVec[i].color == "red" && cubeVec[i].amount > RedCubes.amount) ||
            (cubeVec[i].color == "green" && cubeVec[i].amount > GreenCubes.amount) ||
            (cubeVec[i].color == "blue" && cubeVec[i].amount > BlueCubes.amount) ? true : false;
            
            if (skipIteration) break;
        }
        
        if (skipIteration) {
            counter++;
            continue;
        }else{
            sumIds += counter;
            counter++;
        }
    }
    std::cout << "The sum of the ids with possible games are: " << sumIds << std::endl;
}

std::vector<Cubes> read_cube(std::string& str) {
    
    std::regex pattern(R"(Game \d+:)");
    str = std::regex_replace(str, pattern, "");
    
    std::istringstream line_stream(str);
    
    int amount;
    std::string color;
    
    std::vector<Cubes> cubeVec;
    Cubes tempcube;
    
    while(line_stream >> amount >> color){
        color.erase(std::remove(color.begin(), color.end(), ','), color.end());
        cubeVec.push_back({amount, color});
    }
    return cubeVec;
}
