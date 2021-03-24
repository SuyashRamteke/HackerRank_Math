#include <bits/stdc++.h>
#include <math.h>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
long long int solve(long long int n, long long int k) {

long double D = pow(n,2)-4*k*n;
long long int ans;

if(D<=0)
return n-1;

else
{
    long double r = sqrt(D);
    long double r1 = (n-r)/2;
    long double r2 = (n+r)/2;
    long int g1 = floor(r1);
    long int g2 = floor(r2);
    
    if((r2<=1)||(r1>=n-1))
    ans = n-1;

    else if((r1<1)&&(r2>n-1))
    ans = 0;

    else if((r1==1)&&(r2>n-1))
    ans = 1;

    else if((r1<1)&&(r2==n-1))
    ans = 1;

    else if((r1==1)&&(r2==n-1))
    ans = 2;

    else if((r1>1)&&(r2<n-1))
    {
       // int g = floor(r);
        if(r1-g1==0)
        ans = g1-1 + n-g2+1;

        else
        ans = g1-1 + n-g2;
    }

    else if((r1==1)&&(r2<n-1))
    {
        ans = g2;
    }

    else if((r1>1)&&(r2==n-1))
    {
        if(r1-g1==0)
        ans = n-g1;

        else
        ans = n-g1-1;
    }
    else
    ans = -1;

    

}

return ans;





}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        long long int n = stoll(nk[0]);

        long long int k = stoi(nk[1]);

        long long int result = solve(n, k);

        fout << result << "\n";
    }

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
