/*
-Using the contents of the element we "hash" it, converting it into an int key
-key = Element % tableSize
-using that key we place the element within the hash table at that int
-Every element in a hash table is called a bucket
*/

/*
 Quadratic probing
 -key % tableSize + c1*i + c2*i^2 = newKey
 if(newKey is FULL){
    i++;
    -key % tableSize + constant1*increment + constant2*(increment*increment) = newKey
 }
*/

//TODO
//Impliment chaining on buckets
//Impliment hash search
//Impliment quadratic probing for placement

#include <iostream>
using namespace std;

int open_Addressing_Collision_Resolution(string hashTable[],int tableSize, int key){
    cout << "checking collision" << "(tableSize: " << tableSize << " key: " << key << ")..."<< endl;
    bool foundSpot = false;
    bool looped = false;
    
    //This is a Linear Probing sequence
    while(foundSpot == false){
        if(key > tableSize){
            key = 0;
            if(looped){
                return -1;
            }
            looped = true;
            cout << "looped..." << endl;
        }
        if(hashTable[key] == ""){
            foundSpot = true;
        }else{
            key++;
        }
    }
    cout << "returning key: " << key << endl;
    return key;
}

int hashing(string hashTable[], int tableSize, string name){
    cout<<"hashing..."<<endl;
    int key = 0;
    for(int i=0; i < name.length();i++){
        key += int(name[i]);
    }
    key = key%tableSize;
    key = open_Addressing_Collision_Resolution(hashTable, tableSize, key);
    cout << "Hash Result: " << key << endl;
    return key;
}

void addToTable(string hashTable[], int tableSize, string name){
    cout << "adding to table..." << endl;
    int key = hashing(hashTable, tableSize, name);
    if(key != -1){
        hashTable[key] = name;
    }else{
        cout << "ERROR: Array is full, cannot add more elements." << endl;
    }

}
void printLine(int size){
    string lines = "";
    for(int i=0;i<size;i++){
        lines += "-";
    }
    cout << lines << endl;
}

int countCharacter(string hashTable[], int tableSize){
    int count =0;
    for(int i = 0; i < tableSize; i++){
        count += hashTable[i].length()+1;
        if(hashTable[i] != ""){
            count++;
        }
    }
    return count;
}

void printHashTable(string hashTable[], int tableSize){
    printLine(countCharacter(hashTable, tableSize));
    for(int i=0; i < tableSize+1;i++){
        cout << hashTable[i] << "|";
    }
    cout << endl;
    printLine(countCharacter(hashTable, tableSize));
}

int main(int argc, const char * argv[]) {
    string hashTable[10];
    int tableSize = 10-1;
    addToTable(hashTable, tableSize,"gamer");
    addToTable(hashTable, tableSize,"fill");
    addToTable(hashTable, tableSize,"lamer");
    addToTable(hashTable, tableSize,"lamer");
    addToTable(hashTable, tableSize,"lamer");
    addToTable(hashTable, tableSize,"lamer");
    addToTable(hashTable, tableSize,"lamer");
    addToTable(hashTable, tableSize,"lamer");
    addToTable(hashTable, tableSize,"lamer");
    addToTable(hashTable, tableSize,"lamer");
    addToTable(hashTable, tableSize,"lamer");
    printHashTable(hashTable, tableSize);
    return 0;
}
