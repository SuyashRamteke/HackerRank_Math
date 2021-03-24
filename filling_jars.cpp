#include <bits/stdc++.h>
#include<cmath>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
long long int solve(int n, vector<vector<long int>> operations) {
    long int size=operations.size();
    long long int sum=0;
    for (long int i=0; i<size; i++)
    {
        sum=sum+(operations[i][1]-operations[i][0]+1)*operations[i][2];
    }
    long long int avg=floor(sum/n);
    //cout<<size;

    return avg;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    long int n = stol(nm[0]);

    long int m = stol(nm[1]);

    vector<vector<long int>> operations(m);
    for (int operations_row_itr = 0; operations_row_itr < m; operations_row_itr++) {
        operations[operations_row_itr].resize(3);

        for (int operations_column_itr = 0; operations_column_itr < 3; operations_column_itr++) {
            cin >> operations[operations_row_itr][operations_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long int result = solve(n, operations);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
