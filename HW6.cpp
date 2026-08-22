#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> prizes;
    int val;

    cout << "Enter positive integers one per line (enter 0 or a negative number to end):" << endl;
    while (cin >> val && val > 0) {
        prizes.push_back(val);
    }

    int n = prizes.size();
    if (n == 0) {
        cout << "No prizes entered." << endl;
        return 0;
    }

    // dp[i] stores the maximum prize that can be collected from the first i buttons
    vector<int> dp(n + 1, 0);
    dp[1] = prizes[0];

    for (int i = 2; i <= n; ++i) {
        // Max of skipping the current button OR picking it + the max from two steps back
        dp[i] = max(dp[i - 1], dp[i - 2] + prizes[i - 1]);
    }

    cout << "\nTotal max prize: " << dp[n] << endl;

    vector<int> selected_prizes;
    int i = n;

    // Backtrack through the DP array to find the optimal selection of buttons
    while (i > 0) {
        if (i == 1 || dp[i] != dp[i - 1]) {
            selected_prizes.push_back(prizes[i - 1]);
            i -= 2;
        }
        else {
            i -= 1;
        }
    }

    reverse(selected_prizes.begin(), selected_prizes.end());

    cout << "Optimal selection of buttons: ";
    for (size_t j = 0; j < selected_prizes.size(); ++j) {
        cout << selected_prizes[j] << (j == selected_prizes.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}