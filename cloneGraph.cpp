class Solution {
    unordered_map<int, Node *> s;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;

        // create new node
        Node *newnode = new  Node(node->val,
                                  vector<Node*>
                                  (node->neighbors));

        // insert node in map to keep track
        // of whiche nodes have already been made
        s.insert({newnode->val, newnode});


        // recursively create neighbors
        for (int i = 0; i < newnode->neighbors.size(); i++) {
            auto it = s.find(newnode->neighbors[i]->val);

            // only if they are not created yet
            if (it == s.end())
                newnode->neighbors[i] =
                    cloneGraph(newnode->neighbors[i]);
            else
                // if created just update pointer to the
                // created node
                newnode->neighbors[i] = it->second;
        }
        return newnode;
    }
};