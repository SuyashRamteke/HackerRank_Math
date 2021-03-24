#include <bits/stdc++.h>
#include<cmath>
using namespace std;

vector<string> split_string(string);

/*
 * Complete the restaurant function below.
 */

int gcd(int a, int b)
{
    if(b==0)
    return a;

    return (gcd(b,a%b));

}

int restaurant(int l, int b) {
    /*
     * Write your code here.
     */
  
  int square=gcd(l,b);
  /*   int p=(l*b);
     int max;
     int square; 
     int i;
     //cout<<p;

for(i=1; i<=p; i++)
{   
    std::cout<<i;
    int s = pow(i,2);
    int c = p%s;
    
    if(c==0)
    {
        square=i^i;
        //cout<<square;
        //if(max<square)
        //max=square;
    }
}*/
int bread_piece = (l*b)/(pow(square,2));

return bread_piece;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string lb_temp;
        getline(cin, lb_temp);

        vector<string> lb = split_string(lb_temp);

        int l = stoi(lb[0]);

        int b = stoi(lb[1]);

        int result = restaurant(l, b);

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
