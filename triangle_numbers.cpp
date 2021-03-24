#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
int solve(int n) {
int ans;

if(n%4==0)
ans=3;
else if(n%4==2)
ans=4;
else 
ans=2;

return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
