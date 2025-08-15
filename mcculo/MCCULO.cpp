#include "MCCULO.h"
using namespace std;

McCulo::McCulo(const vector<int>& w, int t)
    : weights(w), threshold(t) {}

int McCulo::activate(const vector<int>& inputs) const {
    int sum = 0;
    for (size_t i = 0; i < inputs.size(); i++) {
        sum += inputs[i] * weights[i];
    }
    return (sum >= threshold) ? 1 : 0;
}

McCulo AND()  { return McCulo({1, 1}, 2); }
McCulo OR()   { return McCulo({1, 1}, 1); }
McCulo NOR()  { return McCulo({-1, -1}, 0); }
McCulo NAND() { return McCulo({-1, -1}, -1); }
McCulo NOT()  { return McCulo({-1}, 0); }

int XOR(int a, int b) {
    McCulo andn = AND();
    McCulo orr = OR();
    McCulo notn = NOT();

    int p1 = andn.activate({a, notn.activate({b})});
    int p2 = andn.activate({notn.activate({a}), b});
    return orr.activate({p1, p2});
}

int XNOR(int a, int b) {
    McCulo notn = NOT();
    return notn.activate({XOR(a, b)});
}
