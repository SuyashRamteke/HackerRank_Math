#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Complete the solve function below.
string solve(long long int i) {

long double f = sqrtl(i);
cout<<f;
long long int root = floor(f);
string ans;

if(root%2==1)
ans = "odd";
else
ans = "even";

return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long long int i;
        cin >> i;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = solve(i);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
