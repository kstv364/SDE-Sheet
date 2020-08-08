unordered_map<Node*, int> mp;
int height(Node * root) {
    if (!root) return mp[nullptr] = 0;
    mp[root] = 1 + max(height(root->left), height(root->right));
    return mp[root];
}

bool util(Node * root) {
    if (!root ) return true;
    int diff = mp[root->left] - mp[root->right];
    if (diff <= 1 and diff >= -1)
        return util(root->left) and util(root->right);
    return false;
}
bool isBalanced(Node *root)
{
    mp.clear();
    height(root);
    return util(root);
}
