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
    
    std::vector<Cubes> cubeVec;
    std::string str;
    bool skipIteration;
    
    int red = 0;
    int green = 0;
    int blue = 0;
    
    int power = 0;
    
    while(std::getline(Data, str,'\n')){
        
        red = 0;
        green = 0;
        blue = 0;
        
        std::replace(str.begin(), str.end(), ';', '\n');
        
        cubeVec = read_cube(str);
        skipIteration = false;
        
        for (int i = 0; i < cubeVec.size(); i++) {
            
            if(cubeVec[i].color == "red"){
                if(red < cubeVec[i].amount) red = cubeVec[i].amount;
            }
            
            if(cubeVec[i].color == "green"){
                if(green < cubeVec[i].amount) green = cubeVec[i].amount;
            }
            
            if(cubeVec[i].color == "blue"){
                if(blue < cubeVec[i].amount) blue = cubeVec[i].amount;
            }
        }
        power += red*green*blue;
    }
    std::cout << "The sum of the power: " << power << std::endl;
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

