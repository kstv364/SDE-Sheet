void inorder(Node *root, int n, vector<Node *> &s, vector<Node *> &p) {
    if (root) {
        s.push_back(root);
        if (root->data == n)
            p = vector<Node*>(s);
        inorder(root->left, n , s, p);
        inorder(root->right, n , s , p);
        s.pop_back();
    }
}

Node* lca(Node* root , int n1 , int n2 )
{
    vector<Node * > p1, p2, s;
    inorder(root, n1, s, p1);
    inorder(root, n2, s, p2);
    if (p1.size() == 0 and p2.size() == 0)
        return nullptr;
    if (p1.size() > 0 and p2.size() > 0) {
        int m = min(p1.size(), p2.size());
        Node * ans = nullptr;
        for (int i = 0; i < m; i++) {
            if (p1[i] == p2[i])
                ans = p1[i];
        }
        return ans;
    }
    else {
        return p1.size() > 0 ? p1[p1.size() - 1] : p2[p2.size() - 1];
    }
}