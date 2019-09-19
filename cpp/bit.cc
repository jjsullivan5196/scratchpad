#include <iostream>
#include "bit.h"
using namespace std;

int main() {
    long q = 1, flips = 0;
    string str; cin >> str;

    for(char& c : str) { 
        if(c == '?') 
            q <<= 1; 
    }
    for(long i = 0; i < q; i++) {
        flips += count_inv(invl(i, str));
    }

    cout << flips % (long)(pow(10, 9) + 7) << '\n';
}
