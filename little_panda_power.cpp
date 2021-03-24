#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
long long int power(long long int x, long long int y, long long int z)
{
    if(y==0)
    return 1;

    long long int expo=1;
    while(y>0)
    {
        if(y%2==1)
        expo = ((x%z)*(expo%z))%z;

        y=y/2;
        x=((x%z)*(x%z))%z;

    }
return expo;

}

long long int phi(long long int n)
{
      long long int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

long long int solve(long long int a, long long int b, long long int n) {

long long int ans; 
long long int inv;
if(b>0)
{
    ans = power(a,b,n);
}

else if(b==0)
ans = 1;

else
{   
    b=(-1)*b;
    inv = power(a,phi(n)-1,n);
    ans = power(inv,b,n);
        //cout<<n+b;
}

return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string abx_temp;
        getline(cin, abx_temp);

        vector<string> abx = split_string(abx_temp);

        long long int a = stoll(abx[0]);

        long long int b = stoll(abx[1]);

        long long int x = stoll(abx[2]);

        long long int result = solve(a, b, x);

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
