#include <iostream>
#include <bits/stdc++.h>
using namespace std;
static bool cmp (vector < int >a, vector < int >b)
{
  if (a[0] != b[0])
    {
      return a[0] < b[0];
    }
  else
    {
      return a[1] > b[1];
    }
}

int main ()
{
  int t;
  cin >> t;
  vector < vector < int >>v;
  while (t--)
    {
      int x, y, z;
      cin >> x >> y >> z;
      vector < int >c;
      c.push_back (x);
      c.push_back (y);
      c.push_back (z);
      v.push_back (c);
    }
  sort (v.begin (), v.end (), cmp);
  for (int i = 0; i < v.size (); i++)
    {
      cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
    }
  return 0;
}
