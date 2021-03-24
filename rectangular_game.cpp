#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// Complete the solve function below.
long long int solve(vector<vector<long long int>> steps) {

int N=steps.size();
long long int c=steps[0][0],d=steps[0][1];  
for (int i=0;i<N;i++)
{
    
    //cin >> a >> b;
    c = steps[i][0] >= c ? c : steps[i][0];
    d = steps[i][1] >= d ? d : steps[i][1];
}

long long int prod = c*d;

return c*d;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<long long int>> steps(n);
    for (int steps_row_itr = 0; steps_row_itr < n; steps_row_itr++) {
        steps[steps_row_itr].resize(2);

        for (int steps_column_itr = 0; steps_column_itr < 2; steps_column_itr++) {
            cin >> steps[steps_row_itr][steps_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

   long long int result = solve(steps);

    fout << result << "\n";

    fout.close();

    return 0;
}
