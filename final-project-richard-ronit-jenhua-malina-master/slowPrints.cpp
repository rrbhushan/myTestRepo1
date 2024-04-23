#include "slowPrints.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void slowStringPrint(string s, string name) {
    this_thread::sleep_for(chrono::milliseconds(500));
    int lineLength = 0;
    for (int i = 0; i < s.length(); i++) {
        if (lineLength > 100 && s[i] == ' ') {
            cout << "\n";
            for (int j = 0; j < name.length(); j++) {
                cout << " ";
            }
            lineLength = 0;
        }
        else {
            this_thread::sleep_for(chrono::milliseconds(30));
            cout << s[i];
        }
        lineLength++;
    }

}
