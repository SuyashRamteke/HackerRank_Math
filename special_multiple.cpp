#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// Complete the solve function below.
long int solve(int n) 
{
    long int arr[4000000];
    //int* arr= (int*)malloc(64*sizeof(int));
    arr[0]=9;
    arr[1]=90;
    //int* arr2 = (int*)realloc(arr, 64*sizeof(int));
    int pow=1, index=0;
    long int ans;
    int i;
    double c;
    
    if(arr[0]%n==0)
    ans=arr[0];
    
    else if(arr[1]%n==0)
    ans=arr[1];
    
    else
    {
    for(i=2;i<=sizeof(arr); i++)
    {
        c=log2(i+1);
        if(c-floor(c)==0)
        {
            arr[i]=9*(std::pow(10,c));
            pow=i;
        }
        else
        {
            arr[i]=arr[pow]+arr[i-pow-1];
        }

        cout<<" "<<i;
        if(arr[i]%n==0)
        {
            //index=i;
            break;
        }
    }
    ans=arr[i];
    }
    //int g=std::pow(2,2);
   //cout<<i;
    //cout<<9009%7;
return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long int result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
