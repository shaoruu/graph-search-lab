#include <iostream>

#include "graph.h"

using namespace std;

int main()
{
  Graph g;

  string s;

  cout << "Looking for: ";

  while (getline(cin, s))
  {
    cout << g.bfs(s) << endl;

    cout << "Looking for: ";
  }
}