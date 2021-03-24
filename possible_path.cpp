#include <bits/stdc++.h>
#include<cstdlib>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.

int gcd(int a, int b) {
return b == 0 ? a : gcd(b, a % b);
}


/*string solve(long long int a, long long int b, long long int x, long long int y) {

string ans;

return ans;
}*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string abxy_temp;
        getline(cin, abxy_temp);

        vector<string> abxy = split_string(abxy_temp);

        long long int a = stoll(abxy[0]);

        long long int b = stoll(abxy[1]);

        long long int x = stoll(abxy[2]);

        long long int y = stoll(abxy[3]);
        string result;

        if (gcd(abs(x),abs(y)) == gcd(abs(a),abs(b)))
        {
        result="YES";
        } 
        else 
        {
            result="NO";
        }
        

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
