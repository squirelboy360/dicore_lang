//
//  main.cpp
//  dicore_lang
//
//  Created by Tahiru Agbanwa on 2/8/25.
//

#include <iostream>
using namespace std;

int main (){
    string num = "hello0000";
    
    num+=5;  // Shifts the string by removing the first character
    
    cout << num << std::endl;  // Outputs: "ello"
    return 0;
}
