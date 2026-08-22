#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> prizes;
    int input;

    cout << "Enter prize values (enter 0 or a negative number to quit): " << endl;

    // Read integers. Stop if the input is 0 or negative.
    while (cin >> input && input > 0) {
        prizes.push_back(input);
    }

    int n = prizes.size();
    if (n == 0) {
        cout << "Total prize collected with the Greedy Algorithm: 0" << endl;
        return 0;
    }

    // Keep track of which buttons are still allowed to be clicked
    vector<bool> available(n, true);
    int total_prize = 0;

    // Greedy algorithm: keep picking the maximum available prize
    while (true) {
        int max_val = -1;
        int max_idx = -1;

        // Scan the array to find the highest prize that hasn't been disabled
        for (int i = 0; i < n; i++) {
            if (available[i] && prizes[i] > max_val) {
                max_val = prizes[i];
                max_idx = i;
            }
        }

        // If no more buttons are available, we're done
        if (max_idx == -1) {
            break;
        }

        // Collect the prize
        total_prize += max_val;

        // Disable the chosen button and its immediate neighbors
        available[max_idx] = false;
        if (max_idx > 0) {
            available[max_idx - 1] = false;
        }
        if (max_idx < n - 1) {
            available[max_idx + 1] = false;
        }
    }

    cout << "Total prize collected with the Greedy Algorithm: " << total_prize << endl;

    return 0;
}