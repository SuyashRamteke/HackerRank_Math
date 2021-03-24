#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// Complete the solve function below.
double solve(vector<vector<int>> coordinates) {
    double max_x =0;// std::numeric_limits<double>::min();
    double min_x =0;// std::numeric_limits<double>::max();
    double max_y = 0;//std::numeric_limits<double>::min();
    double min_y = 0;//std::numeric_limits<double>::max();

    for(size_t i = 0; i < coordinates.size(); i++)
    {
        if(coordinates[i][0] > max_x) 
        max_x = coordinates[i][0];
        if(coordinates[i][0] < min_x) 
        min_x = coordinates[i][0];
        if(coordinates[i][1] > max_y) 
        max_y = coordinates[i][1];
        if(coordinates[i][1] < min_y) 
        min_y = coordinates[i][1];
    }

    double dx = std::abs(max_x - min_x);

    double dy = std::abs(max_y - min_y);

    double dxy1 = std::sqrt(std::pow(max_x, 2.0) + std::pow(max_y, 2.0));

    double dxy2 = std::sqrt(std::pow(max_x, 2.0) + std::pow(min_y, 2.0));

    double dxy3 = std::sqrt(std::pow(min_x, 2.0) + std::pow(max_y, 2.0));

    double dxy4 = std::sqrt(std::pow(min_x, 2.0) + std::pow(min_y, 2.0));

    std::vector<double> res;
    res.push_back(dx);
    res.push_back(dy);
    res.push_back(dxy1);
    res.push_back(dxy2);
    res.push_back(dxy3);
    res.push_back(dxy4);

    std::sort(res.begin(), res.end());

    return res[5];

}

int main()
{
   int n;
cin >> n;
cin.ignore(numeric_limits<streamsize>::max(), '\n');

vector<vector<int>> coordinates(n);
for (int coordinates_row_itr = 0; coordinates_row_itr < n; coordinates_row_itr++) {
    coordinates[coordinates_row_itr].resize(2);

    for (int coordinates_column_itr = 0; coordinates_column_itr < 2; coordinates_column_itr++) {
        cin >> coordinates[coordinates_row_itr][coordinates_column_itr];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double result = solve(coordinates);

//fout.precision(12);
cout << std::fixed <<setprecision(12)<< result << "\n";

//fout.close();

return 0;
}
