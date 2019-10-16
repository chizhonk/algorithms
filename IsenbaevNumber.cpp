#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

class Node {
public:
    void addNeighbor(Node* node) {
        neighbors.insert(node);
    }

    int getINumber() {
        return INumber;
    }

    void setINumber(const int& n) {
        INumber = n;
    }

    void updateNeighborsINumbers() {
        for (auto& n :neighbors)
            if (n->getINumber() == -1) n->setINumber(INumber+1);
    }

    void mark() {
        marked = true;
    }

    bool getMarkedStatus() {
        return marked;
    }

    set<Node*>& getNeighbors() {
        return neighbors;
    }

private:
    set<Node*> neighbors;
    int INumber = -1;
    bool marked = false;
};

class Graph {
public:
    void addEdge(const string& a, const string& b) {
        Node* n1;
        Node* n2;
        if (nodes.count(a) == 0) {
            n1 = new Node;
            nodes[a] = n1;
        } else {
            n1 = nodes[a];
        }
        if (nodes.count(b) == 0) {
            n2 = new Node;
            nodes[b] = n2;
        } else {
            n2 = nodes[b];
        }
        n1->addNeighbor(n2);
        n2->addNeighbor(n1);
    }

    void printResult() {
        int i = 0;
        for (const auto& item : nodes) {
            i++;
            cout << item.first << " ";
            if (item.second->getINumber() == -1) cout << "undefined";
            else cout << item.second->getINumber();
            if (i != nodes.size()) cout << endl;
        }
    }

    void Ibfs() {
        if (nodes.count("Isenbaev") == 0) return;

        Node* Inode = nodes["Isenbaev"];
        Inode->setINumber(0);

        queue<Node*> q;
        q.push(Inode);
        while (!q.empty()) {
            Node* node = q.front();
            node->mark();
            node->updateNeighborsINumbers();
            q.pop();
            for (auto& n : node->getNeighbors())
                if (!n->getMarkedStatus()) q.push(n);
        }
    }

private:
    map<string, Node*> nodes;
};

int main() {
    int n;
    cin >> n;

    Graph G;
    for (int i = 0; i < n; ++i) {
        string a, b, c;
        cin >> a >> b >> c;
        G.addEdge(a, b);
        G.addEdge(b, c);
        G.addEdge(c, a);
    }

    G.Ibfs();
    G.printResult();

    return 0;
}

// Особые случаи:
// -- Isenbaev отсутствует в графе
