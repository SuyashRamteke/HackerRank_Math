#include <bits/stdc++.h>
#include<iostream>
#include <cstdlib>
using namespace std;

vector<string> split_string(string);



int main()
{
    int n;
    int h=0, v=0, out;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int x[n], y[n];
    for (int n_itr = 0; n_itr < n; n_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        x[n_itr] = (stoi(xy[0]));
        y[n_itr] = (stoi(xy[1]));
    
    }

    for(int j=1; j<n; j++)
    {
        int ly=(abs(y[j]))^(abs(y[j-1]));
        int lx=(abs(x[j]))^(abs(x[j-1]));
        
        if(lx!=0)
        h++;
        
        if(ly!=0)
        v++;

        //cout<<ly<<lx<<n;
    }
    
    if((v==0)||(h==0))
    cout<<"YES";
    else
    cout<<"NO";

    //cout<<abs(-5);
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
