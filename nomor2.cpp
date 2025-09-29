#include <iostream>
#include <string>

using namespace std;

// checks vowel character
bool isVowel(char c){
    return ( c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Reverse consonants string
string revCons(string passwords){
    string digits = " "; 
    for (int i = passwords.size()-1; i >= 0; i--){  
        digits += passwords[i];
    }

    return digits;

}

// construct password

string makePass(string inputWord){ 
    // remove vowels
    string consonant = ""; // declare a variable to store pass string
    for (char c : inputWord ){ // for every letter (char c) in string loop through
        if (!isVowel(c)) consonant = consonant + c; // if letter isVowel, store it in consonant variable

    }

    string reversed = revCons(consonant); // reverse consonant variable

    // basically, if you want to turn char inro ascii, use conversion from char --> int
    int asciiVal = (int)inputWord[0]; // take the first (index 0) letter of the input in original form
    string asciiStr = to_string(asciiVal); // turn ASCII integer into string 

    int mid = reversed.size()/2; // split the consonant 
    string password = reversed.substr(0, mid) + asciiStr + reversed.substr(mid); // use .substr() to get substring that was split in half
    return password;


}

string decodePass(string password){
    int start = -1, end = -1;
    string digits = "";
    //function to find where the digit ends and start
    for (int i = 0; i < password.size(); i++) {
        if (isdigit(password[i])) {
        if (start == -1) start = i; // first digit
        end = i; // last digit
        digits += password[i];
    }
}

    for (int i =0; i < password.size(); i++){
        if (isdigit(password[i])){
            digits = digits + password[i]; // Take the digit

        }
    }

    int convertedDigits = stoi(digits); // turn ASCII string into integer with stoi() function
    char charVal = (char)convertedDigits; // convert integer into char


    string withoutDigits = password.substr(0, start) + password.substr(end+1); //
    string oriConsonant = revCons(withoutDigits); // reversing consonant string

    string decodedPass = string(1, charVal) + oriConsonant;
    return decodedPass;


}


int main(){
    cout << "Pick what you wanna do" << endl;
    cout << "1. Make password \n";
    cout << "2.  Decode \n";
    cout << endl;
    
    int choice = 2;

    cin >> choice;

    switch(choice){
        case 1: {
        string inputWord;
        cout << "Enter your word here to turn it into password \n";
        cin >> inputWord;
        string passOut = makePass(inputWord);
        cout << "Word : " << inputWord << " --> Password: " << passOut << endl;
        break;
        }

        case 2: {
        string password;
        cout << "Enter the pass here to decode \n";
        cin >> password;
        string decodeOut = decodePass(password);
        cout << "Password : " << password << "--> Word: " << decodeOut << endl;
        break;
        }
        
    }


    return 0;

    
}