#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T; 
    cin >> T;
    cin.ignore(); 

    while (T--) {
        int n;
        cin >> n;
        cin.ignore(); 

        vector<int> actions(n); 
        int position = 0;

        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin, line);

            if (line == "LEFT") {
                actions[i] = -1;
            } else if (line == "RIGHT") {
                actions[i] = 1;
            } else { 
                int index = stoi(line.substr(8)) - 1;
                actions[i] = actions[index];
            }

            position += actions[i];
        }

        cout << position << endl;
    }

    return 0;
}
