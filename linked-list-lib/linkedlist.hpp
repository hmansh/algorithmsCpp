#include <bits/stdc++.h>
//
//    Create by hmansh : March 5 2021
//
#define inf 10e8;

struct Node {
    int val;
    Node* next;
};

class LinkedList {

    Node* head = NULL;
    int len = 0;

    Node* getNode(const int _val_){
        Node* temp = new Node;
        temp->val = _val_;
        temp->next = NULL;
        return temp;
    };

    Node* _insertFront_(int key){
        Node* newnode = getNode(key);
        if (head == NULL){
            head = newnode;
            return head;
        }
        newnode->next = head;
        return head = newnode;
    }

    Node* _insertLast_(int key){
        Node* newnode = getNode(key);
        if (head == NULL) {
            return head = newnode;
        }
        Node* temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newnode;
        return head;
    }

    Node* _deleteFront_(){
        if (head == NULL) return NULL;
        return head->next;
    }

    Node* _deleteLast_(){
        if (head == NULL || head->next == NULL) return NULL;
        Node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        temp->next = NULL;
        return head;
    }

    bool _search_(int key){
        if (head == NULL) return false;
        Node* temp = head;
        while(temp->val != key || temp != NULL) temp = temp->next;
        if (temp->val == key) return true;
        return false;
    }

    void _travel_(){
        if (head == NULL) return;
        Node* temp = head;
        while(temp!=NULL){
            std::cout << temp->val << "->";
            temp = temp->next;
        }
    }

    Node* _insertAt_(int key, int pos){
        if (pos > _length_()+1 || pos <= 0) return head;
        Node* newnode = getNode(key);
        if (pos == 1) {
            newnode->next = head;
            return newnode;
        }
        int curr = 1;
        Node* temp = head;
        while(curr < pos-1){
            temp = temp->next;
            curr++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        return head;
    }

    Node* _deleteAt_(int pos){
        if (pos > _length_()+1 || pos <= 0) return head;
        if (pos == 1) return head->next;
        int curr = 1;
        Node* temp = head;
        while(curr < pos-1){
            temp = temp->next;
            curr++;
        }
        temp->next = temp->next->next;
        return head;
    }

    int _maximum_(){
        if (head == NULL) return -inf;
        Node* temp = head;
        int max = temp->val;
        while(temp != NULL){
            if (temp->val > max) max = temp->val;
            temp = temp->next;
        }
        return max;
    }

    int _minimum_(){
        if (head == NULL) return inf;
        Node* temp = head;
        int min = temp->val;
        while(temp!=NULL){
            if (temp->val < min) min = temp->val;
            temp = temp->next;
        }
        return min;
    }

    int _successor_(int key){
        if (head == NULL) return -inf;
        Node* temp = head;
        while(temp->next!=NULL){
            if (temp->val == key) break;
            temp = temp->next;
        }
        if (temp->next == NULL) return -inf;
        return temp->next->val;
    }

    int _predecessor_(int key){
        if (head == NULL || head->val == key) return -inf;
        Node* temp = head;
        while(temp->next!= NULL){
            if (temp->next->val == key) break;
            temp = temp->next;
        }
        if (temp->next == NULL) return -inf;
        return temp->val;
    }

    int _length_(){
        if (head == NULL) return 0;
        this->len = 0;
        Node* temp = head;
        while(temp != NULL){
            this->len++;
            temp = temp->next;
        }
        return this->len;
    }

    Node* _center_(){
        if (head == NULL) return NULL;
        Node* mid = head;
        Node* end = head;
        if (end->next == NULL) return head;
        while(end->next->next != NULL){
            end = end->next->next;
            mid = mid->next;
            if (end->next == NULL) break;
        }
        return mid;
    }

    int _nthNodeFromLast_(int n){
        if (head == NULL) return -inf;
        int pos = 0;
        Node* fast = head;
        Node* slow = head;
        while(pos < n && fast != NULL) {
            fast = fast->next;
            pos++;
        }
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }

    void _reverseIter_(){
        if (head == NULL) return;
        std::stack<int> elements;
        Node* temp = head;
        while(temp!=NULL){
            elements.push(temp->val);
            temp = temp->next;
        }
        while(!elements.empty()){
            std::cout << elements.top() << "->";
            elements.pop();
        }
    }

    void _reverseRec_(Node* head){
        if (head == NULL) return;
        _reverseRec_(head->next);
        std::cout << head->val << "->";
    }

    void _removeDuplicates_(){
        if ( head == NULL || head ->next == NULL) return;
        Node* temp = head;
        std::set<int> res;
        res.insert(head->val);
        while(temp->next!=NULL){
            if (res.find(temp->next->val) != res.end()){
                temp->next = temp->next->next;
            } else {
                res.insert(temp->val);
                temp = temp->next;
            }
        }
        return;
    }

    Node* _reverseListIter_(Node* head){
        if (head == NULL || head->next == NULL) return head;
        Node* curr = head;
        Node* prev = NULL;
        Node* temp = head->next;
        while(temp != NULL){
            curr->next = prev;
            prev = curr;
            curr = temp;
            temp = temp->next;
        }
        curr->next = prev;
        return curr;
    }

    Node* _reverseListRec_(Node* head){
        if (head == NULL || head->next == NULL ) return head;
        Node* temp = _reverseListRec_(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }

    void swap(Node* a, Node* b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

    void _swapPairwise_(){
        if (head == NULL || head->next == NULL) return;
        Node* temp = head;
        while(temp->next != NULL){
            swap(temp, temp->next);
            temp = temp->next;
            if (temp->next == NULL) break;
            temp = temp->next;
        }
    }

    Node* _reverseGroup_(Node* head, int k){
        if (head == NULL || head->next == NULL) return head;
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;
        while(count < k && curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != NULL)
            head->next = _reverseGroup_(next, k);
        return prev;
    }

    Node* _sortlist_(){
        if (head == NULL || head->next == NULL) return head;
        Node* dummy = new Node;
        dummy->next = head;
        Node* prev = dummy;
        Node* curr = head;
        while(curr){
            if ((curr->next != NULL) && (curr->next->val < curr->val)){
                while((prev->next != NULL) && (prev->next->val < curr->next->val)){
                    prev = prev->next;
                }
                Node* temp = prev->next;
                prev->next = curr->next;                
                curr->next = curr->next->next;
                prev->next->next = temp;
                prev = dummy;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }

    public:

    LinkedList(){}
    ~LinkedList(){}

    int minimum();
    int maximum();
    int predecessor(int key);
    int successor(int key);
    int length();
    int center();
    int nthNodeFromLast(int n);
    void insertFront(int key);
    void insertLast(int key);
    void insertAt(int val, int pos);
    void deleteFront();
    void deleteLast();
    void deleteAt(int pos);
    void travel();
    void reverseIter();
    void reverseRec();
    void removeDuplicates();
    void reverseListRec();
    void reverseListIter();
    void swapPairwise();
    void reverseGroup(int k);
    void sortList();
    bool search(int key) ;
};

void LinkedList::insertFront(int key){
    head = _insertFront_(key);
}

void LinkedList::insertLast(int key){
    head = _insertLast_(key);
}

void LinkedList::deleteFront(){
    head = _deleteFront_();
}

void LinkedList::deleteLast(){
    head = _deleteLast_();
}   

bool LinkedList::search(int key){
    return _search_(key);
}

void LinkedList::travel(){
    _travel_();
    std::cout << "\n";
}

void LinkedList::insertAt(int key, int pos){
    head = _insertAt_(key, pos);
}

void LinkedList::deleteAt(int pos){
    head = _deleteAt_(pos);
}

int LinkedList::maximum(){
    return _maximum_();
}

int LinkedList::minimum(){
    return _minimum_();
}

int LinkedList::predecessor(int val){
    return _predecessor_(val);
}

int LinkedList::successor(int val){
    return _successor_(val);
}

int LinkedList::length(){
    return _length_();
}

int LinkedList::center(){
    return _center_()->val;
}

int LinkedList::nthNodeFromLast(int n){
    return _nthNodeFromLast_(n);
}

void LinkedList::reverseIter(){
    _reverseIter_();
    std::cout << std::endl;
}

void LinkedList::reverseRec(){
    _reverseRec_(head);
    std::cout << std::endl;
}

void LinkedList::removeDuplicates(){
    _removeDuplicates_();
}

void LinkedList::reverseListIter(){
    head = _reverseListIter_(head);
}

void LinkedList::reverseListRec(){
    head = _reverseListRec_(head);
}

void LinkedList::swapPairwise(){
    _swapPairwise_();
}

void LinkedList::reverseGroup(int k){
    head = _reverseGroup_(head, k);
}

void LinkedList::sortList(){
    head = _sortlist_();
}