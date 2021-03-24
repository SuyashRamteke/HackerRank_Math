#include <bits/stdc++.h>
#include<vector>
using namespace std;

// Complete the solve function below.
double solve(vector<long int> balls) {
double sum ;
int sz=balls.size();

for(int i=0; i<sz; i++)
{
    sum=sum+balls[i];
}

return sum/2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int balls_count;
    cin >> balls_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<long int> balls(balls_count);

    for (int balls_itr = 0; balls_itr < balls_count; balls_itr++) {
        int balls_item;
        cin >> balls_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        balls[balls_itr] = balls_item;
    }

    double result = solve(balls);

    fout << std::fixed << setprecision(1) << result << "\n";

    fout.close();

    return 0;
}
