#include<bits/stdc++.h>

struct Node {
    int val;
    Node* left;
    Node* right;
};

class Tree {
    Node* root = NULL;

    Node* createNode(int val){
        Node* temp = new Node;
        temp->val = val;
        temp->right = NULL;
        temp->left = NULL;
        return temp;
    }

    Node* _insert_node_(Node* root, int val){
        if (root == NULL) return createNode(val);
        std::queue<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            Node* curr = nodes.front();
            nodes.pop();
            if (curr->left != NULL && curr->right != NULL){
                nodes.push(curr->left);
                nodes.push(curr->right);
            } else if (curr->left != NULL){
                curr->right = createNode(val);
                return root;
            } else {
                curr->left = createNode(val);
                return root;
            }
        }
        return root;
    }

    Node* _delete_node_val_(Node* root, int val){
        return root;
    }

    Node* _delete_node_(Node* root){
        if (root == NULL || (root->left == NULL && root->right == NULL)) return NULL;
        std::queue<std::pair<Node*, Node*>> q;
        q.push({NULL, root});
        std::pair<Node*, Node*> curr;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if (curr.second->left != NULL){
                q.push({curr.second, curr.second->left});
            }
            if (curr.second->right != NULL){
                q.push({curr.second, curr.second->right});
            }
        }
        if (curr.first->left->val == curr.second->val){
            curr.first->left = NULL;
            curr.second = NULL;
        } else {
            curr.first->right = NULL;
            curr.second = NULL;
        }
        return root;
    }

    void _inorder_traversal_(Node* root){
        if (root == NULL) return;
        _inorder_traversal_(root->left);
        std::cout << root->val << " ";
        _inorder_traversal_(root->right);
    }

    void _preorder_traversal_(Node* root){
        if (root == NULL) return;
        std::cout << root->val << " ";
        _preorder_traversal_(root->left);
        _preorder_traversal_(root->right);
    }

    void _postorder_traversal_(Node* root){
        if (root == NULL) return;
        _postorder_traversal_(root->left);
        _postorder_traversal_(root->right);
        std::cout << root->val << " ";
    }

    int _height_(Node* root){
        if (root == NULL) return 0;
        return std::max(_height_(root->left), _height_(root->right)) + 1;
    }

    void _inorder_iterative_(Node* root){
        if (root == NULL) return;
        std::stack<Node*> s;
        Node* curr = root;
        while(curr != NULL || !s.empty()) {
            while(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            Node* temp = s.top();
            s.pop();
            std::cout << temp->val << " ";
            curr = temp->right; 
        }
        return;
    }

    void _preorder_iterative_(Node* root){
        if (root == NULL) return;
        std::stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* curr = s.top();
            std::cout << curr->val << " ";
            s.pop();
            if (curr->right)
                s.push(curr->right);
            if (curr->left)
                s.push(curr->left);
        }
        return;
    }

    void _postorder_iterative_(Node* root){
        if (root == NULL) return;
        std::stack<Node*> s;
        std::stack<int> output;
        s.push(root);
        while(!s.empty()){
            Node* curr = s.top();
            output.push(curr->val);
            s.pop();
            if (curr->left)
                s.push(curr->left);
            if (curr->right)
                s.push(curr->right);
        }
        while(!output.empty()){
            std::cout << output.top() << " ";
            output.pop();
        }
    }

    void _levelorder_(Node* root){
        if (root == NULL) return;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            std::cout << curr->val << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    void _spiral_traversal_(Node* root){
        if (root == NULL) return;
        std::stack<Node*> s1;
        std::stack<Node*> s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            while(!s1.empty()){
                Node* curr = s1.top();
                s1.pop();
                std::cout << curr->val << " ";
                if (curr->right)
                    s2.push(curr->right);
                if (curr->left)
                    s2.push(curr->left);
            }
            while(!s2.empty()){
                Node* curr = s2.top();
                s2.pop();
                std::cout << curr->val << " ";
                if (curr->left)
                    s1.push(curr->left);
                if (curr->right);
                    s1.push(curr->right);
            }
        }
    }

    void _nodesCount_(Node* root, int & count){
        if (root == NULL) return;
        count++;
        _nodesCount_(root->left, count);
        _nodesCount_(root->right, count);
    }

    void _nonLeafNodes_(Node* root, int & count){
        if (root == NULL) return;
        if (root->left != NULL || root->right != NULL) count++;
        _nonLeafNodes_(root->left, count);
        _nonLeafNodes_(root->right, count);
    }

    int _leafNodes_(Node* root){
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        return _leafNodes_(root->left) + _leafNodes_(root->right);
    }

    void _minNode_(Node* root, int & minval){
        if (root == NULL) return;
        if (root->val < minval) minval = root->val;
        _minNode_(root->left, minval);
        _minNode_(root->right, minval);
    }

    void _maxNode_(Node* root, int & maxval){
        if (root == NULL) return;
        if (root->val > maxval) maxval = root->val;
        _maxNode_(root->left, maxval);
        _maxNode_(root->right, maxval);
    }

    int _maxDepth_(Node* root){
        if (root == NULL) return 0;
        return std::max(_maxDepth_(root->left), _maxDepth_(root->right)) + 1;
    }

    int _minDepth_(Node* root){
        if (root == NULL) return 0;
        return std::min(_minDepth_(root->left), _minDepth_(root->right)) + 1;
    }

    bool _binarySearchTree_(Node* root){
        if (root == NULL) return true;
        if (root->left != NULL)
            if (root->left->val > root->val) return false;
        if (root->right != NULL)
            if (root->right->val < root->val) return false;
        return _binarySearchTree_(root->left) && _binarySearchTree_(root->right);
    }

    int _maxWidth_(Node* root){
        if (root == NULL) return 0; 
        std::stack<struct Node*> s1;
        std::stack<struct Node*> s2;
        s1.push(root); 
        int maxlen = -1;
        while (!s1.empty() || !s2.empty()) { 
            while (!s1.empty()) { 
                maxlen = std::max(maxlen, (int)s1.size());
                struct Node* temp = s1.top(); 
                s1.pop(); 
                if (temp->right) 
                    s2.push(temp->right); 
                if (temp->left) 
                    s2.push(temp->left); 
            } 
            while (!s2.empty()) { 
                maxlen = std::max(maxlen, (int)s2.size());
                struct Node* temp = s2.top(); 
                s2.pop(); 
                if (temp->left) 
                    s1.push(temp->left); 
                if (temp->right) 
                    s1.push(temp->right); 
            } 
        } 
        return maxlen;
    } 

    int _diameter_(Node* root){
        if (root == NULL) return 0;
        int lh = _height_(root->left);
        int rh = _height_(root->right);

        int ld = _diameter_(root->left);
        int rd = _diameter_(root->right);

        return std::max(lh + rh + 1, std::max(ld, rd));
    }

    bool _searchNode_(Node* root, int key){
        if (root == NULL) return false;
        if (root->val == key) return true;
        return _searchNode_(root->left, key) && _searchNode_(root->right, key);
    }

public:

    Tree(){

    }

    ~Tree(){

    }

    void insertNode(int val);
    void deleteNode(int val);
    void inorder();
    void preorder();
    void postorder();
    int height();
    void inorderIter();
    void preorderIter();
    void postorderIter();
    void levelorder();
    void levelorderIter();
    void spiralTraversal();
    int nodesCount();
    int nonLeafNodes();
    int leafNodes();
    int minNode();
    int maxDepth();
    int maxNode();
    int minDepth();
    bool binarySearchTree();
    int maxWidth();
    int diameter();
    bool searchNode(int key);
    
};

void Tree::insertNode(int val){
    root = _insert_node_(root, val);
}

void Tree::deleteNode(int val = -1){
    if (val == -1) 
        root = _delete_node_(root);
    else
        root = _delete_node_val_(root, val);
}

void Tree::inorder(){
    _inorder_traversal_(root);
    std::cout << std::endl;
}

void Tree::preorder(){
    _preorder_traversal_(root);
    std::cout << std::endl;
}

void Tree::postorder(){
    _postorder_traversal_(root);
    std::cout << std::endl;
}

int Tree::height(){
    return _height_(root);
}

void Tree::inorderIter(){
    _inorder_iterative_(root);
    std::cout << std::endl;
}

void Tree::preorderIter(){
    _preorder_iterative_(root);
    std::cout << std::endl;
}

void Tree::postorderIter(){
    _postorder_iterative_(root);
    std::cout << std::endl;
}

void Tree::levelorder(){
    _levelorder_(root);
    std::cout << std::endl;
}

void Tree::spiralTraversal(){
    _spiral_traversal_(root);
    std::cout << std::endl;
}

int Tree::nodesCount(){
    int count = 0;
    _nodesCount_(root, count);
    return count;
}

int Tree::nonLeafNodes(){
    int count = 0;
    _nonLeafNodes_(root, count);
    return count;
}

int Tree::leafNodes(){
    return _leafNodes_(root);
}

int Tree::minNode(){
    int minval = 10e8;
    _minNode_(root, minval);
    return minval;
}

int Tree::maxNode(){
    int maxval = -10e8;
    _maxNode_(root, maxval);
    return maxval;
}

int Tree::maxDepth(){
    return _maxDepth_(root);
}

int Tree::minDepth(){
    return _minDepth_(root);
}

bool Tree::binarySearchTree(){
    return _binarySearchTree_(root);
}

int Tree::maxWidth(){
    return _maxWidth_(root);
}

int Tree::diameter(){
    return _diameter_(root);
}

bool Tree::searchNode(int key){
    return _searchNode_(root, key);
}
















