#include <bits/stdc++.h>
#include<math.h>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
string solve(int r1, int r2, vector<int> p1, vector<int> a1, vector<int> p2, vector<int> a2) 
{

string ans;

double c = pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2)+pow(p1[2]-p2[2],2)-pow(r1+r2,2);
double b = (p1[0]-p2[0])*(a1[0]-a2[0])+(p1[1]-p2[1])*(a1[1]-a2[1])+(p1[2]-p2[2])*(a1[2]-a2[2]);
double a = pow(a1[0]-a2[0],2)+pow(a1[1]-a2[1],2)+pow(a1[2]-a2[2],2);

double D = pow(b,2)-a*c;

if((D>=0)&&(sqrt(D)>=b))
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
        string r1R2_temp;
        getline(cin, r1R2_temp);

        vector<string> r1R2 = split_string(r1R2_temp);

        int r1 = stoi(r1R2[0]);

        int r2 = stoi(r1R2[1]);

        string position1_temp_temp;
        getline(cin, position1_temp_temp);

        vector<string> position1_temp = split_string(position1_temp_temp);

        vector<int> position1(3);

        for (int i = 0; i < 3; i++) {
            int position1_item = stoi(position1_temp[i]);

            position1[i] = position1_item;
        }

        string acceleration1_temp_temp;
        getline(cin, acceleration1_temp_temp);

        vector<string> acceleration1_temp = split_string(acceleration1_temp_temp);

        vector<int> acceleration1(3);

        for (int i = 0; i < 3; i++) {
            int acceleration1_item = stoi(acceleration1_temp[i]);

            acceleration1[i] = acceleration1_item;
        }
        string position2_temp_temp;
        getline(cin, position2_temp_temp);

        vector<string> position2_temp = split_string(position2_temp_temp);

        vector<int> position2(3);

        for (int i = 0; i < 3; i++) {
            int position2_item = stoi(position2_temp[i]);

            position2[i] = position2_item;
        }

        string acceleration2_temp_temp;
        getline(cin, acceleration2_temp_temp);

        vector<string> acceleration2_temp = split_string(acceleration2_temp_temp);

        vector<int> acceleration2(3);

        for (int i = 0; i < 3; i++) {
            int acceleration2_item = stoi(acceleration2_temp[i]);

            acceleration2[i] = acceleration2_item;
        }

        string result = solve(r1, r2, position1, acceleration1, position2, acceleration2);

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
