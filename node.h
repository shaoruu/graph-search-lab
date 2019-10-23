#include <vector>
#include <string>

using namespace std;

class Node
{
private:
  string value;
  int id;

  vector<Node *> edges;

public:
  Node(string, int);

  void connect(Node *);

  string getValue() const;

  vector<Node *> &getEdges();

  const int getId();

  bool isLeaf() const;

  bool operator==(const Node &) const;

  bool operator==(string) const;
};
