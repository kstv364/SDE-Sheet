int intersectPoint(Node* h1, Node* h2)
{
    // Your Code Here
    unordered_set<Node *> st;
    while (h1) {
        st.insert(h1);
        h1 = h1->next;
    }
    while (h2) {
        if (st.find(h2) != st.end()) {
            // if found
            return h2->data;
        }
        h2 = h2->next;
    }
    return -1;
}


// Better
int length(Node *h1) {
    if (!h1) return 0;
    return 1 + length(h1->next);
}
int intersectPoint(Node* h1, Node* h2)
{
    // Your Code Here
    int l1 = length(h1), l2 = length(h2);
    while (l1 < l2) {
        h2 = h2->next;
        l2--;
    }
    while (l1 > l2) {
        h1 = h1->next;
        l1--;
    }
    while (h1) {
        if (h1 == h2) return h1->data;
        h1 = h1->next; h2 = h2->next;
    }
    return -1;
}

