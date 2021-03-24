#include <set>
#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;

    set<int> s;
    for (int i = 0; i < N; i++)
    {
      int a;
      cin >> a;
      s.insert(a);
    }

    bool divisor_exists = false;
    for (int d = 2; d <= 100000; d++)
    {
      int cnt = 0;
      for (int a : s) cnt += (a % d == 0);

      if (cnt == s.size())
      {
        divisor_exists = true;
        break;
      }
    }

    cout << (divisor_exists ? "NO" : "YES") << '\n';
  }
}
