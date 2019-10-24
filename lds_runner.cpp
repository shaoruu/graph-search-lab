#include <iostream>

#include "graph.h"

using namespace std;

int main()
{
  Graph g;

  string s;
  int limit;

  while (true)
  {
    cout << "Limit for LDS: ";

    cin >> limit;
    cin.ignore(1, '\n');

    cout << "Looking for: ";

    getline(cin, s);

    g.lds(s, limit);
  }
}