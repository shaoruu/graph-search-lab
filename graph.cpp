#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

#include "graph.h"

using namespace std;

Graph::Graph() : root(new Node("Bucharest", 0))
{
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

string Graph::bfs(string target)
{
  bool *visited = new bool[20];
  for (int i = 0; i < 20; i++)
    visited[i] = false;

  queue<Node *> Q;
  vector<Node *> *edges;
  string path = "\n";

  Q.push(root);
  visited[0] = true;

  while (!Q.empty())
  {
    Node *t = Q.front();

    Q.pop();

    if (*t == target)
      return path + "Arrived at " + target + "\n";

    path += "Visited " + t->getValue() + "\n";

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

  return path;
}

string Graph::dfs(string target)
{
  bool *visited = new bool[20];
  for (int i = 0; i < 20; i++)
    visited[i] = false;

  stack<Node *> Q;
  vector<Node *> *edges;
  string path = "\n";

  Q.push(root);
  visited[0] = true;

  while (!Q.empty())
  {
    Node *t = Q.top();

    Q.pop();

    if (*t == target)
      return path + "Arrived at " + target + "\n";

    path += "Visited " + t->getValue() + "\n";

    edges = &(t->getEdges());
    // reverse(edges->begin(), edges->end());

    for (int i = 0; i < edges->size(); ++i)
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

  return path;
}
