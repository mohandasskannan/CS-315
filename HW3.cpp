#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int m;
    cout << "Enter the number of trials: ";
    cin >> m;

    int n = 50;

    // 2d vector for buckets
    // buckets[bucket_idx][trial_num]
    vector<vector<int>> buckets(n, vector<int>(m, 0));

    // setup rng
    srand((unsigned)time(0));

    for (int t = 0; t < m; t++) {
        vector<int> A(n);
        int max_num = -1;

        // get 50 random numbers up to 3 digits
        for (int i = 0; i < n; i++) {
            A[i] = rand() % 1000;
            if (A[i] > max_num) {
                max_num = A[i];
            }
        }

        // map to buckets
        for (int i = 0; i < n; i++) {
            // hash formula from the pdf
            int idx = (A[i] * n) / (max_num + 1);
            buckets[idx][t]++;
        }
    }

    vector<double> avg_counts(n, 0.0);
    vector<double> devs(n, 0.0);

    double total_mean = 0.0;
    double total_dev = 0.0;

    cout << endl << "****** Mean of the count for each bucket across " << m << " trials" << endl;
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int t = 0; t < m; t++) {
            sum += buckets[i][t];
        }
        avg_counts[i] = sum / m;
        total_mean += avg_counts[i];

        cout << "Mean of the count for bucket " << i << ": "
            << fixed << setprecision(4) << avg_counts[i] << endl;
    }

    cout << endl << "Standard deviation of the count for each bucket across " << m << " trials:" << endl;
    for (int i = 0; i < n; i++) {
        double var_sum = 0;
        for (int t = 0; t < m; t++) {
            double diff = buckets[i][t] - avg_counts[i];
            var_sum += pow(diff, 2);
        }

        devs[i] = sqrt(var_sum / m);
        total_dev += devs[i];

        cout << "Standard deviation of the count for bucket " << i << ": "
            << fixed << setprecision(4) << devs[i] << endl;
    }

    // get the final averages
    double final_avg_mean = total_mean / n;
    double final_avg_dev = total_dev / n;

    cout << endl << "****** Average of means: " << final_avg_mean;
    cout << endl << "****** Average of standard deviations: " << final_avg_dev << endl;

    return 0;
}