bool util(Node *r1, Node *r2) {
	if (!r1 and !r2) return true;
	if (r1 and r2 and r1->data == r2->data) {
		return util(r1->left, r2->right) and util(r1->right, r2->left);
	}
	return false;
}
// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root)
{
	return util(root, root);
}