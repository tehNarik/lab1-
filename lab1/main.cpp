#include "mylib.h"
using namespace std;
    int main() {
        while(true){
            int a = showMenu();
            switch(a){
                case 1:
                    writeLineInput();
                    break;
                case 2:
                    showContent();
                    break;
                case 3:
                    clearContent();
                    break;
                default:
                    return 0;
            }
        }
    }