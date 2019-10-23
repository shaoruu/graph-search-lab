#include <vector>

#include "node.h"

class Graph
{
private:
  Node *root;

  string dfsUntil(Node *, bool *, string target);

public:
  Graph();

  string bfs(string);

  string dfs(string);
};