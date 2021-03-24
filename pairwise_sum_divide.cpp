#include <bits/stdc++.h>
#include <vector>
#include <math.h>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
long long int solve(vector<int> a) {
long long int sz=a.size();
long long int one=0, two=0;
long long int num = 1;
long long int den = 1;

//cout<<sz<<" ";
long long int i, j=0;
for(i=0; i<sz; i++)
{
    /*for(j=i+1; j<sz; j++)
    {
        sum = sum + (a[i]+a[j])/(a[i]*a[j]);
    }*/

    if(a[i]==1)
    one++;

    if(a[i]==2)
    two++;   
}
cout<<one<<two;
//for(j=0; j<one; j++)
do
{
    num=num*(sz-j);
    den=den*(j+1);
    j++;
}
while(j<one);

double comb = num/den; 

long long int ans = one*(one-1) + two*(two-1)/2 + one*(sz-one);

return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int a_count;
        cin >> a_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(a_count);

        for (int i = 0; i < a_count; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        long long int result = solve(a);

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
