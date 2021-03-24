#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
string solve(vector<vector<int>> points) {

string ans;
int ax = points[1][0]-points[0][0];
int ay = points[1][1]-points[0][1];
int az = points[1][2]-points[0][2];

int bx = points[2][0]-points[1][0];
int by = points[2][1]-points[1][1];
int bz = points[2][2]-points[1][2];

int cx = points[3][0]-points[2][0];
int cy = points[3][1]-points[2][1];
int cz = points[3][2]-points[2][2];

int resz = az*((bx*cy)-(by*cx));
int resy = ay*((bz*cx)-(bx*cz));
int resx = ax*((by*cz)-(bz*cy));

//cout<<resx<<" "<<resy<<" "<<resz;

if((resx==0)&&(resy==0)&&(resz==0))
ans="YES";

else
ans="NO";

return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        vector<vector<int>> points(4);
        for (int points_row_itr = 0; points_row_itr < 4; points_row_itr++) {
            points[points_row_itr].resize(3);

            for (int points_column_itr = 0; points_column_itr < 3; points_column_itr++) {
                cin >> points[points_row_itr][points_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = solve(points);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
