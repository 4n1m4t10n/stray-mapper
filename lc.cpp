#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(int x) {
        string t = to_string(x);
        int length = t.length();
        bool isP = true;

        for (int i = 0; i < length/2; i++)
        {
            cout << length/2;
            cout << t.at(i)  << " " << t.at(length - 1 - i);
            if (t.at(i) != t.at(length - 1 - i))
                isP = false;
        }

        return isP;
    }

int main() {
    int x = 121;
    isPalindrome(x);
}