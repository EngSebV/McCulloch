#ifndef MCCULO_H
#define MCCULO_H

#include <vector>
using namespace std;

class McCulo {
private:
    vector<int> weights;
    int threshold;

public:
    McCulo(const vector<int>& w, int t);
    int activate(const vector<int>& inputs) const;
};

McCulo AND();
McCulo OR();
McCulo NOR();
McCulo NAND();
McCulo NOT();

int XOR(int a, int b);
int XNOR(int a, int b);

#endif
