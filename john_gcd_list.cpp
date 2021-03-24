#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int gcd(int a, int b)
{
    if (b==0)
    return a;

    return gcd(b, a%b);
}

vector<int> solve(vector<int> a) 
{
int i;

int sz=a.size();
std::vector<int> b(sz+1);
b[0]=a[0];
for(i=0; i<sz-1; i++)
{
    b[i+1]=(a[i]*a[i+1])/(gcd(a[i+1],a[i]));
    //b[i]=a[i];
   // cout<<a[i]<<" "<<b[i+1];
}
b[sz]=a[sz-1];

//return b;*/
return b;
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

        for (int a_itr = 0; a_itr < a_count; a_itr++) {
            int a_item = stoi(a_temp[a_itr]);

            a[a_itr] = a_item;
        }

        vector<int> result = solve(a);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
