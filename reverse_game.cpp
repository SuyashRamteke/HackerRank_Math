#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int sol(int n, int k)
{
    int ans;
    if(k>=n/2)
        ans=2*(n-1-k);
    else
        ans=2*k+1;

        return ans;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string nk_temp;
    

    int n[t], k[t];
    for(int y=0; y<t; y++)
    {
        getline(cin, nk_temp);
    vector<string> nk = split_string(nk_temp);

    n[y] = stoi(nk[0]);

    k[y] = stoi(nk[1]);

    

    }


    int ans[t]; 
    for(int j=0; j<t; j++)
    {
        ans[j] = sol(n[j],k[j]);
        
        cout<<ans[j];
        cout<<"\n";
    }
    




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
