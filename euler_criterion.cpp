#include <bits/stdc++.h>
#include <math.h>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
long long int power(long long int x, long long int y, long long int z)
{
    long long int expo=1;
    

    cout<<x<<" "<<y<<" "<<z;
    if(y==0)
    return 1;

    while(y>0)
    {
        if(y%2==1)
        expo = ((x%z)*(expo%z))%z;

        y=y/2;
        x=((x%z)*(x%z))%z;
    }  
    
    return (expo);

}

string solve(long long int a, long long int m) {

long long int t = power(a,(m-1)/2, m);

cout<<t;

string ans; 

if(a==0)
return "YES";

if(t==1)
ans = "YES";

else
ans = "NO";

return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string am_temp;
        getline(cin, am_temp);

        vector<string> am = split_string(am_temp);

        long long int a = stoll(am[0]);

        long long int m = stoll(am[1]);

        string result = solve(a, m);

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
