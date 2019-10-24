#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <string>

#include "graph.h"

using namespace std;

Graph::Graph()
{
  cout << "List of cities: " << endl;
  cout << "===============" << endl;

  root = new Node("Bucharest", 0);
  Node *Giurgiu = new Node("Giurgiu", 1);
  Node *Pitesti = new Node("Pitesti", 2);
  Node *Craiova = new Node("Craiova", 3);
  Node *RimnicuVilcea = new Node("Rimnicu Vilcea", 4);
  Node *Fagaras = new Node("Fagaras", 5);
  Node *Sibiu = new Node("Sibiu", 6);
  Node *Drobeta = new Node("Drobeta", 7);
  Node *Mehadia = new Node("Mehadia", 8);
  Node *Lugoj = new Node("Lugoj", 9);
  Node *Timisoara = new Node("Timisoara", 10);
  Node *Arad = new Node("Arad", 11);
  Node *Zerind = new Node("Zerind", 12);
  Node *Oradea = new Node("Oradea", 13);
  Node *Urziceni = new Node("Urziceni", 14);
  Node *Hirsova = new Node("Hirsova", 15);
  Node *Eforie = new Node("Eforie", 16);
  Node *Valslui = new Node("Valslui", 17);
  Node *Iasi = new Node("Iasi", 18);
  Node *Neamt = new Node("Neamt", 19);

  cout << endl
       << "with Bucharest as the starting point." << endl
       << "==============="
       << endl;

  Valslui->connect(Iasi);

  Iasi->connect(Neamt);

  Hirsova->connect(Eforie);

  RimnicuVilcea->connect(Craiova);
  RimnicuVilcea->connect(Sibiu);

  Craiova->connect(Drobeta);

  Drobeta->connect(Mehadia);

  Mehadia->connect(Lugoj);

  Lugoj->connect(Timisoara);

  Timisoara->connect(Arad);

  Arad->connect(Zerind);
  Arad->connect(Sibiu);

  Zerind->connect(Oradea);

  Sibiu->connect(Oradea);

  Urziceni->connect(Hirsova);
  Urziceni->connect(Valslui);

  Fagaras->connect(Sibiu);

  Pitesti->connect(RimnicuVilcea);
  Pitesti->connect(Craiova);

  root->connect(Giurgiu);
  root->connect(Pitesti);
  root->connect(Fagaras);
  root->connect(Urziceni);
}

void Graph::bfs(string target)
{
  bool *visited = new bool[20];
  for (int i = 0; i < 20; i++)
    visited[i] = false;

  queue<Node *> Q;
  vector<Node *> *edges;

  cout << "\n";

  Q.push(root);
  visited[0] = true;

  while (!Q.empty())
  {
    Node *t = Q.front();

    Q.pop();

    if (*t == target)
    {
      cout << "Arrived at " + target << endl;
      break;
    }

    cout << "Visited " + t->getValue() << endl;

    edges = &(t->getEdges());

    for (int i = 0; i < edges->size(); i++)
    {
      Node *curr = (*edges)[i];
      int id = curr->getId();

      if (!visited[id])
      {
        visited[id] = true;
        Q.push(curr);
      }
    }
  }

  cout << endl;
}

bool Graph::dfsUntil(Node *n, bool visited[], string target)
{
  visited[n->getId()] = true;

  if (*n == target)
  {
    root = n;
    cout << "Arrived at " << target << endl
         << endl;
    cout << "Starting point is now " << root->getValue() << endl;
    return true;
  }

  cout << "Visited " << n->getValue() << endl;

  vector<Node *> *edges = &(n->getEdges());

  for (int i = 0; i < edges->size(); i++)
  {
    Node *curr = (*edges)[i];

    if (!visited[curr->getId()] && dfsUntil(curr, visited, target))
      return true;
  }
}

void Graph::dfs(string target)
{
  bool *visited = new bool[20];
  for (int i = 0; i < 20; i++)
    visited[i] = false;

  cout << endl;

  dfsUntil(root, visited, target);

  cout << endl;
}

bool Graph::ldsUntil(Node *n, bool visited[], string target, int limit)
{
  visited[n->getId()] = true;

  if (*n == target)
  {
    cout << "Arrived at " << target << endl;
    return true;
  }

  cout << "Visited " << n->getValue() << endl;

  if (limit <= 1)
    return false;

  vector<Node *> *edges = &(n->getEdges());
  for (auto i = edges->begin(); i != edges->end(); i++)
  {
    if (!visited[(*i)->getId()] && ldsUntil(*i, visited, target, limit - 1))
      return true;
  }

  return false;
}

/**
 * INCOMPLETE SEARCHING ALGORITHM
 */
void Graph::lds(string target, int limit)
{
  bool *visited = new bool[20];
  for (int i = 0; i < 20; i++)
    visited[i] = false;

  cout << endl;

  bool result = ldsUntil(root, visited, target, limit);

  if (!result)
    cout << "Didn't get to " + target + " before LDS finished... :(" << endl;

  cout << endl;
}

void Graph::ids(string target, int maxDepth)
{
  bool didFind = false;

  cout << endl;

  for (int i = 1; i <= maxDepth; i++)
  {
    bool *visited = new bool[20];
    for (int i = 0; i < 20; i++)
      visited[i] = false;

    int digits = 0, number = i;
    while (number != 0)
    {
      number /= 10;
      digits++;
    }

    cout << "Performing LDS search with depth of " << i << endl;
    cout << "====================================" << string(digits, '=') << endl;

    if (ldsUntil(root, visited, target, i))
    {
      didFind = true;
      break;
    }

    cout << endl;
  }

  if (!didFind)
    cout << "Didn't get to " + target + " before IDS finished... :(" << endl;

  cout << endl;
}