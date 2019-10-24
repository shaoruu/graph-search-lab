#include <iostream>

#include "graph.h"

using namespace std;

int main()
{
  Graph g;

  string s;

  while (true)
  {
    cout << "Looking for: ";

    getline(cin, s);

    g.dfs(s);
  }
}