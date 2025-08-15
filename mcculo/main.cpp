#include <iostream>
#include <string>
#include "McCulo.h"
using namespace std;

int main() {
    int a, b;
    string gate;

    cout << "Primer input (0 o 1): ";
    cin >> a;

    cout << "segundo input (0 or 1): ";
    cin >> b;

    cout << "ingresa puerta *usar MAYUSCULAS* (AND, OR, NOR, NAND, NOT, XOR, XNOR): ";
    cin >> gate;

    int result = -1;

    if (gate == "AND")       result = AND().activate({a, b});
    else if (gate == "OR")   result = OR().activate({a, b});
    else if (gate == "NOR")  result = NOR().activate({a, b});
    else if (gate == "NAND") result = NAND().activate({a, b});
    else if (gate == "NOT")  result = NOT().activate({a}); 
    else if (gate == "XOR")  result = XOR(a, b);
    else if (gate == "XNOR") result = XNOR(a, b);
    else {
        cout << "Invalid gate name!" << endl;
        return 1;
    }

    cout << "Output: " << result << endl;

    return 0;
}
