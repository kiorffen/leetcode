/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/01/18
* @brief  
*
**/

#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        queue<Node*> q;
        q.push(node);
        map<Node*, Node*> m;

        while (!q.empty()) {
            Node* node_old = q.front();
            q.pop();
            Node* node_new = new Node(node_old->val, {});
            m[node_old] = node_new;

            for (auto tn:node_old->neighbors) {
                if (m.find(tn) == m.end()) {
                    q.push(tn);
                }
            }
        }

        for (auto p:m) {
            for (auto neighbor:p.first->neighbors) {
                p.second->neighbors.push_back(m.find(neighbor)->second);
            }
        }

        return m.find(node)->second;
    }

    Node* cloneGraph1(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        map<Node*, Node*> m;
        dfs(node, m);

        return m.find(node)->second;
    }

    void dfs(Node* node, map<Node*, Node*>& m) {
        if (m.find(node) != m.end()) {
            return;
        }

        Node* node_new = new Node(node->val, node->neighbors);
        m[node] = node_new;
        for (int i=0; i<node->neighbors.size(); i++) {
            if (m.find(node->neighbors[i]) == m.end()) {
                dfs(node->neighbors[i],m);
            }
            node_new->neighbors[i] = node->neighbors[i];
        }
    }

    void printGraph(Node* node) {
        queue<Node*> q;
        q.push(node);
        map<int, Node*> m;
        while (!q.empty()) {
            Node* tmp = q.front();
            q.pop();
            m[tmp->val] = tmp;
            cout << "val: " << tmp->val << endl;
            for (auto n:tmp->neighbors) {
                cout << n->val << " ";
                if (m.find(n->val) == m.end()) {
                    q.push(n);
                    //cout << "insert: " << n->val << endl;
                    m[n->val] = n;
                }
            }
            cout << endl;
        }
    }
};

class GraphNode {
    int val;
    vector<GraphNode*> neighbors;

    GraphNode() {}

    GraphNode(int _val, vector<GraphNode*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

int main() {
    Solution s;

    Node* node1 = new Node(1,{});
    Node* node2 = new Node(2,{});
    Node* node3 = new Node(3,{});
    Node* node4 = new Node(4,{});

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    cout << "old" << endl;;
    s.printGraph(node1);
    Node* ret = s.cloneGraph1(node1);
    cout << "new" << endl;;
    s.printGraph(ret);

    return 0;
}
