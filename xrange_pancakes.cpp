#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
vector<int> solve(vector<vector<int>> operations, int n, int m) {

vector<int> ans(2);

int a = 0;
//int b = 1;

int vert = n;
int rofl = m;

cout<<rofl<<" "<<vert;

int rot = 0;
int flip = 0;

int i;
for(i=0; i<rofl; i++)
{
    if(operations[i][0]==1)
    {
        a = (a+operations[i][1])%vert;
        //cout<<a<<" ";
      //  b = (b+operations[i][1])%vert; 
        rot++;
    }

    else
    {
        a = (vert-a+operations[i][1])%vert;

       // cout<<a<<" ";
        
    //    b = (vert-b+operations[i][1])%vert;
        flip++; 
    }
}
cout<<rot<<" "<<flip;
//cout<<5<<" "<<a;

if(/*(rot%2==1)&&*/(flip%2==0))
{
    ans[0] = 1;
    ans[1] = (vert-a);

}

else
{
    ans[0] = 2;
    ans[1] = a;
}

return ans;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> operations(m);

    for (int i = 0; i < m; i++) {
        operations[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> operations[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = solve(operations,n,m);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
