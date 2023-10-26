#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::vector<char>> create_vector(){
    std::ifstream lotnisko("Lotnisko_tekst.txt");
    if(lotnisko.is_open()){
        std::vector<std::vector<char>> airport;
        std::string str_lotnisko;
        while(lotnisko.good()){
            lotnisko >> str_lotnisko;
            std::vector<char> inside;
            for(int i=0;i<str_lotnisko.length();i++){
                inside.push_back(str_lotnisko[i]);
            }
            airport.push_back(inside);
        }
        return airport;   
    }
}

void longest_finder(std::vector<std::vector<char>> airport, int lenght, int lines){
    int logest_x = 0;
    int longest_y = 0;
    for(auto x:airport){
        for(auto y:x){
            int count_in_row = 0;
            if(y == '.'){
                count_in_row++;
                if(count_in_row > longest_y){
                    longest_y = count_in_row;
                }
            } else{
                if(count_in_row > longest_y){
                    longest_y = count_in_row;
                    count_in_row = 0;
                }
            }
        }
    }
}

int main(){

    auto airport = create_vector();
    int lenght = airport[0].size();
    int lines = 2;

    longest_finder(airport, lenght, lines);


    return 0;
}