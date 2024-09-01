//Caeser cipher is a method in which each letter is shifted along the alphabet by a given number
//EX. shift of 2 would make A->C
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string in_phrase;
    int in_shift = 0;
    int in_direction = 0;
    cout << "Please input a string: ";
    cin >> in_phrase;
    cout << "Input shift amount (1-26): ";
    cin >> in_shift;
    cout << "would you like a Left or Right shift (-1,1): ";
    cin >> in_direction;
    cout << in_phrase << "->" << in_shift << endl;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string result = "";
    
    for(int i=0; i < in_phrase.length();i++){
        int alphabeticPlacement = 0;
        for(int j=0;j < 26;j++){
            if(in_phrase[i] == alphabet[j]){
                alphabeticPlacement = j;
                alphabeticPlacement += in_shift;
                alphabeticPlacement *= in_direction;
                
                if(alphabeticPlacement <= 0){
                    alphabeticPlacement += 26;
                }
                
                if(alphabeticPlacement >= 26){
                    alphabeticPlacement -= 26;
                }
                cout << in_phrase[i] << " alphabetic#" << j << " -" << in_shift << "-> " << alphabet[alphabeticPlacement] << endl;
                result += alphabet[alphabeticPlacement];
            }
        }
    }
    cout << result << endl;
    return 0;
}
