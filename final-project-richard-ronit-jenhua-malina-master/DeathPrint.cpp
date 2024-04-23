#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void DeathPrint(string s) {
    this_thread::sleep_for(chrono::milliseconds(500));
    int lineLength = 0;
    for (int i = 0; i < s.length(); i++) {
        if (lineLength > 100 && s[i] == ' ') {
            cout << "\n         ";
            lineLength = 0;
        }
        else {
            this_thread::sleep_for(chrono::milliseconds(150));
            cout << s[i];
        }
        lineLength++;
    }

}
