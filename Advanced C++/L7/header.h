#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


template <typename T>
T maks (const T &a, const T &b){
    return a<b ? b : a;
}

template <class T>
class BST{
private:

    class Node{
    private:

    public:
        T value;
        Node* left;
        Node* right;

        Node(T value){
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node* root = nullptr;

    Node* deepcopy(Node* x){
        if(x != nullptr){
            Node* a = new Node(x->value);
            a->left = deepcopy(x->left);
            a->right = deepcopy(x->right);
            return a;
        }
        return nullptr;
    }

    void deepdel(Node* x){
        if(x != nullptr){
            deepdel(x->left);
            deepdel(x->right);
            delete x;
        }
    }

public:

    BST(){}

    BST(T value){
        this->root = new Node(value);
    }

    BST(initializer_list<T> values){
        for(unsigned int i = 0; i < values.size(); i++)
            this->put(*(values.begin()+i));
    }

    BST(const BST &tree){
        Node* x = tree.root;
        root = deepcopy(x);
    }

    BST(BST &&tree){
        root = tree.root;
        tree.root = nullptr;
    }

    BST& operator = (const BST &tree){
        Node *x = tree.root;
        root = deepcopy(x);
        return *this;
    }

    BST& operator = (BST &&tree){
        root = tree.root;
        tree.root = nullptr;
        return *this;
    }

    ~BST(){
        deepdel(root);
    }

    bool empty(){
        if (root == nullptr)
            return true;
        return false;
    }

    void put(T value){
        Node* a = new Node(value);

        Node* x = root, *last = nullptr;
        while(x != nullptr){
            last = x;
            if(value <= x->value)
                x = x->left;
            else
                x = x->right;
        }

        if(last == nullptr)
            root = a;
        else {
            if (value <= last->value)
                last->left = a;
            else
                last->right = a;
        }
    }

    bool find(T value){
        Node* x = root;
        while(x != nullptr){
            if(x->value == value){
                return true;
            }

            if(value <= x->value){
                x = x->left;
            }
            else
                x = x->right;
        }
        return false;
    }

    bool pop(T value){
        Node* x = root;
        while(x != nullptr){
            if(x->value == value) {
                Node *next, *prev;
                while (x != nullptr){

                    if (x->left != nullptr) {
                        next = x->left;
                        x->value = next->value;
                    }
                    else if (x->right != nullptr) {
                        next = x->right;
                        x->value = next->value;
                    }
                    else {
                        next = nullptr;
                        if(prev->left == x)
                            prev->left = nullptr;
                        else
                            prev->right = nullptr;
                        delete x;
                    }

                    prev = x;
                    x = next;
                }

                return true;
            }

            if(value <= x->value){
                x = x->left;
            }
            else
                x = x->right;

        }
        return false;
    }

    T max(){
        if(this->empty())
            throw range_error("The tree is empty.");

        Node* x = root;
        while(x->right != nullptr)
            x = x->right;

        return x->value;
    }

    T min(){
        if(this->empty())
            throw range_error("The tree is empty.");

        Node* x = root;
        while(x->left != nullptr)
            x = x->left;

        return x->value;
    }

};