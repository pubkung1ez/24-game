#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const double verysmall = 1e-9;

bool check(double prob[], int n) {
    if(n == 1) {
        return abs(prob[0] - 24) < verysmall;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            double storage[4];
            int count = 0;

            for(int k = 0; k < n; k++) {
                if(k != i && k != j) {
                    storage[count] = prob[k];
                    count++;
                }
            }

            double a = prob[i];
            double b = prob[j];

            // +

            //count เป็น 2
            storage[count] = a + b;
            // count + 1 เพื่อให้เป็นเลข 3
            if (check(storage, count + 1)) {
                return true;
            }

            // -

            storage[count] = a - b;
            if (check(storage, count + 1)) {
                return true;
            }

            // *

            storage[count] = a * b;
            if (check(storage, count + 1)) {
                return true;
            }

            // /

            if(abs(b) != 0) {
                storage[count] = a / b;
                if (check(storage, count + 1)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool permutation (double prob[]) {
    sort(prob, prob + 4);

    do {
        if(check(prob, 4)) {
            return true;
        }
    } while(next_permutation(prob, prob + 4));
    return false;
}

int main() {
    double arr1[4] = {2,9,4,3};

    cout << permutation(arr1) << endl; // output: 1 (solvable) 
}