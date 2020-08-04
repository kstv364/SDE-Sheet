Node* rotate(Node* head, int k)
{

    if (head) {
        Node * p = head;
        int l = 1;
        while (p->next) {
            p = p->next;
            l++;
        }
        k = k % l;
        if (k > 0) {
            p -> next = head;
            Node *prev = nullptr;
            while (k--) {
                prev = head;
                head = head->next;
            }
            if (prev) prev->next = NULL;
        }
        return head;
    }

    return NULL;
}
