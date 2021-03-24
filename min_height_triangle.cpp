#include <bits/stdc++.h>

using namespace std;

int lowestTriangle(int base, int area){
    // Complete this function
    float c=0, h;
    for (h = 0; h<=2*area; h++)
    {
        c=h*base/2;
        if (c>=area)
            break;
    }
    return (h);
    
}

int main() {
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}
