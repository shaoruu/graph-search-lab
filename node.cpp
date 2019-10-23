#include <vector>
#include <string>

#include "node.h"

Node::Node(string c, int id) : value(c), id(id)
{
}

void Node::connect(Node *n)
{
  n->getEdges().push_back(this);
  edges.push_back(n);
}

string Node::getValue() const
{
  return value;
}

vector<Node *> &Node::getEdges()
{
  return edges;
}

const int Node::getId()
{
  return id;
}

bool Node::isLeaf() const
{
  return edges.size() == 0;
}

bool Node::operator==(const Node &b) const
{
  return b.value == value;
}

bool Node::operator==(string other) const
{
  return value == other;
}