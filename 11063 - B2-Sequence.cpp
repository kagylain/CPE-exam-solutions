#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool isB2Sequence(const vector<int>& seq) {
    int n = seq.size();


    for (int i = 0; i < n; ++i) {
        if (seq[i] <= 0 || (i > 0 && seq[i] <= seq[i - 1]))
            return false;
    }

    set<int> sums;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = seq[i] + seq[j];
            if (sums.count(sum))
                return false;
            sums.insert(sum);
        }
    }

    return true;
}

int main() {
    int n, caseNum = 1;
    while (cin >> n) {
        vector<int> seq(n);
        for (int i = 0; i < n; ++i) {
            cin >> seq[i];
        }

        bool valid = isB2Sequence(seq);

        cout << "Case #" << caseNum++ << ": ";
        if (valid)
            cout << "It is a B2-Sequence.";
        else
            cout << "It is not a B2-Sequence.";
        cout << "\n\n";
    }

    return 0;
}
