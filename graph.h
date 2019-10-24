#include <vector>

#include "node.h"

class Graph
{
private:
  Node *root;

  bool dfsUntil(Node *, bool[], string);

  bool ldsUntil(Node *, bool[], string, int);

public:
  Graph();

  // Breadth First Search
  void bfs(string);

  // Depth First Search
  void dfs(string);

  // Limited Depth Search
  void lds(string, int);

  // Iterative Deepening Search
  void ids(string, int);
};