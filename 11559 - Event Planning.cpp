#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N, B, H, W;

    cout << "Give #participants, #budget, #hotels, #weeks: ";
    while (cin >> N >> B >> H >> W) {
        int minCost = INT_MAX;

        for (int i = 0; i < H; ++i) {
            int pricePerPerson;
            cout << "Price per each person: ";
            cin >> pricePerPerson;

            cout << "Beds available for " << W << " weeks: ";
            for (int j = 0; j < W; ++j) {
                int bedsAvailable;
                cin >> bedsAvailable;

                if (bedsAvailable >= N) {
                    int totalCost = pricePerPerson * N;
                    if (totalCost <= B) {
                        minCost = min(minCost, totalCost);
                    }
                }
            }
        }

        if (minCost == INT_MAX) {
            cout << "stay home" << endl;
        } else {
            cout << "Minimum cost: " << minCost << endl;
        }

        cout << "\nGive #participants, #budget, #hotels, #weeks (or Ctrl+D to exit): ";
    }

    return 0;
}
