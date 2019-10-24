#include <vector>

#include "node.h"

class Graph
{
private:
  Node *root;

public:
  Graph();

  string bfs(string);

  string dfs(string);

  string lds(string, int);
};