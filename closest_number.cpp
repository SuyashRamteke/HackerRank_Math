#include <bits/stdc++.h>
#include<math.h>
using namespace std;

vector<string> split_string(string);

/*
 * Complete the closestNumber function below.
 */
long long int closestNumber(long long int a, long long int b, long long int x) {
    /*
     * Write your code here.
     */
     long long int ans;
     
     long long int c = pow(a,b);
     long long int r = (c%x);
    float q=x/2;
   // cout<<(1%7);

    if(b==0)
    return 0;

    if(c==1)
    return 1;
    
    if(r<=floor(q))
    ans = c-r;
    else
    ans = c+(x-r);

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

        long long int result = closestNumber(a, b, x);

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
