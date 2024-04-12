#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int data;
    node *parent;
    vector<node *> childList;
    node(int data, node *parent)
    {
        this->data = data;
        this->parent = parent;
    }
};

class Tree
{
public:
    Tree(int data);
    void insertNode(int parData, int data);
    void deleteNode(int data);
    void printParent(int data);
    void printChild(int data);
    int compareChild(int data);

private:
    node *root;
    vector<node *> nodeList;

    int find(int data, vector<node *> &list);
};

Tree::Tree(int data)
{
    root = new node(data, NULL);
    nodeList.push_back(root);
}

int Tree::find(int data, vector<node *> &list)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->data == data)
        {
            return i;
        }
    }
    return -1;
}

void Tree::insertNode(int parData, int data)
{
    if (find(data, nodeList) != -1)
    {
        cout << -1 << endl;
        return;
    }
    int idx = find(parData, nodeList);
    if (idx == -1)
    {
        cout << -1 << endl;
        return;
    }

    node *parNode = nodeList[idx];
    node *newNode = new node(data, parNode);
    parNode->childList.push_back(newNode);
    nodeList.push_back(newNode);
}

void Tree::deleteNode(int data)
{
    int idx = find(data, nodeList);
    if (idx == -1)
    {
        cout << -1 << endl;
        return;
    }

    node *delNode = nodeList[idx];
    if (delNode == root)
    {
        return;
    }

    node *parNode = delNode->parent;
    for (int i = 0; i < delNode->childList.size(); i++)
    {
        parNode->childList.push_back(delNode->childList[i]);
        delNode->childList[i]->parent = parNode;
    }

    vector<node *> &child = parNode->childList;
    child.erase(child.begin() + find(data, child));
    nodeList.erase(nodeList.begin() + idx);
    delete delNode;
}

void Tree::printParent(int data)
{
    int idx = find(data, nodeList);
    if (idx <= 0)
    {
        cout << -1 << endl;
        return;
    }

    node *curNode = nodeList[idx];
    cout << curNode->parent->data << endl;
}

void Tree::printChild(int data)
{
    int idx = find(data, nodeList);
    if (idx == -1)
    {
        cout << -1 << endl;
        return;
    }
    vector<node *> &child = nodeList[idx]->childList;
    if (child.empty())
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < child.size(); i++)
    {
        if (i == child.size() - 1)
        {
            cout << child[i]->data;
        }
        else
        {
            cout << child[i]->data << " ";
        }
    }
    cout << endl;
}

int Tree::compareChild(int data)
{
    int idx = find(data, nodeList);
    if (idx == -1)
    {
        return -1;
    }
    vector<node *> &child = nodeList[idx]->childList;
    if (child.size() < 2)
    {
        return -1;
    }
    int maxChild{0};
    int minChild{10001};

    for (int i = 0; i < child.size(); i++)
    {
        if (child[i]->data >= maxChild)
        {
            maxChild = child[i]->data;
        }
        if (child[i]->data <= minChild)
        {
            minChild = child[i]->data;
        }
    }

    return maxChild + minChild;
}

int main()
{
    int T;
    cin >> T;

    Tree *tree = new Tree(1);

    string s;

    while (T--)
    {
        cin >> s;
        if (s == "insert")
        {
            int x;
            int y;
            cin >> x >> y;
            tree->insertNode(x, y);
        }
        else if (s == "delete")
        {
            int x;
            cin >> x;
            tree->deleteNode(x);
        }
        else if (s == "parent")
        {
            int x;
            cin >> x;
            tree->printParent(x);
        }
        else if (s == "child")
        {
            int x;
            cin >> x;
            tree->printChild(x);
        }
        else if (s == "min_maxChild")
        {
            int x;
            cin >> x;
            cout << tree->compareChild(x) << endl;
        }
    }

    return 0;
}