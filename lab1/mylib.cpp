#include <iostream>
#include "mylib.h"
//#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
string remove_duplicates(string str) {
        string result = "";

        for (int i = 0; i < str.length(); i++) {
            if (i == 0) {
                if (str[i] == str[i + 1]) {
                    result += "(" + string(1, str[i]) + ")";
                } else {
                    result += str[i];
                }
            } else {
                if (str[i] != str[i - 1]) {
                    if (str[i] == str[i + 1]) {
                        result += "(" + string(1, str[i]) + ")";
                    } else {
                        result += str[i];
                    }

                }
            }
        }
        return result;
    }
string transformation(string line){

            // Розділяємо рядок на символи
            string digits = "";
            string other_chars = "";
            for (char c: line) {
                if (isdigit(c)) {
                    digits += c;
                } else {
                    other_chars += c;
                }
            }
            reverse(other_chars.begin(), other_chars.end());
            //digits = remove_duplicates(digits);
            digits = remove_duplicates(digits);
            string transformed_line = digits + " " + other_chars;
            return transformed_line;
            // Записуємо перетворений рядок у вихідний файл
        }
void writeLineInput(){
    fstream first("first.txt", ios::app);
    fstream second("second.txt");
    //перевірка на відкритість файлів і введення
    if (!first.is_open() || !second.is_open()) {
        cout << "Error" << endl;
        return;
    } else {
        cout << "Enter string for file: " << endl;
        string str;
        //cin>>str;
        cin.ignore();
        getline(cin, str);

        writeLineOutput(str);

        first << str+"\n";
       // ofstream file1("first.txt", ofstream::trunc);
       // file1.close();
    }
    first.close();
    second.close();
}
void writeLineOutput(string str){
    fstream first1("first.txt");
    fstream second("second.txt", ios::app);
    if (!first1.is_open() || !second.is_open()) {
        cout << "Error" << endl;
        return;
    }else {
        string line;
        second << transformation(str) << endl;
    }
    first1.close();
    second.close();
}
void showContent(){
    fstream first2("first.txt");
    fstream second2("second.txt");
    if (!first2.is_open() || !second2.is_open()) {
        cout << "Error" << endl;
        return;
    }else {
        cout << "Input file contents:" << endl;
        if (first2.peek() == std::ifstream::traits_type::eof()) {
            cout << "File is empty\n" << endl;
        } else {
            cout << first2.rdbuf() << endl;
        }
        cout << "Output file contents:" << endl;
        if (second2.peek() == std::ifstream::traits_type::eof()) {
            cout << "File is empty\n" << endl;
        } else {
            cout << second2.rdbuf() << endl;
        }
    }
    first2.close();
    second2.close();
}
int showMenu(){
    cout<<"Choose action:\n1 ---> Write line in the file\n2 ---> Input content of files"<<endl;
    cout<<"3 ---> Clear content from files\n4 ---> Close\nYour choice: "<<endl;
    int a;
    cin>>a;
    return a;
}
void clearContent(){
    ofstream file1("first.txt", ofstream::trunc);
    ofstream file2("second.txt", ofstream::trunc);
    if (!file1.is_open() || !file2.is_open()) {
        cout << "Error" << endl;
        return;
    }
    file1.close();
    file2.close();
}

