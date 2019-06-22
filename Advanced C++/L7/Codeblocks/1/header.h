#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

template < class T >
class op{
public:
    static bool eq (T a, T b){
        return a == b;
    }
    static bool comp (T a, T b){
        return a <= b;
    }
};

template < class T >
class op <T*>{
    public:
    static bool eq (T a, T b){
        return *a == *b;
    }
    static bool comp (T a, T b){
        return *a <= *b;
    }
};

template <>
class op < const char * >{
    public:
    static bool eq (const char * a, const char * b){
        string a1 = a;
        string b1 = b;
        if(a1.compare(b1) == 0)
            return true;
        return false;
    }
    static bool comp (const char * a,const char * b){
        string a1 = a;
        string b1 = b;
        if(a1.compare(b1) <= 0)
            return true;
        return false;
    }
};

template < class T >
class op2{
public:
    static bool eq (T a, T b){
        return a == b;
    }
    static bool comp (T a, T b){
        return a >= b;
    }
};

template <class T, class C = op<T> >
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
            if(C::comp(value,x->value))
                x = x->left;
            else
                x = x->right;
        }

        if(last == nullptr)
            root = a;
        else {
            if (C::comp(value,last->value))
                last->left = a;
            else
                last->right = a;
        }
    }

    bool find(T value){
        Node* x = root;
        while(x != nullptr){
            if(C::eq(value,x->value)){
                return true;
            }

            if(C::comp(value,x->value)){
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
            if(C::eq(value,x->value)) {
                Node *next = nullptr, *prev = nullptr;
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
                        if(prev != nullptr){
                            if(prev->left == x)
                                prev->left = nullptr;
                            else
                                prev->right = nullptr;
                        }
                        else
                            root = nullptr;
                        delete x;
                    }

                    prev = x;
                    x = next;
                }

                return true;
            }

            if(C::comp(value,x->value)){
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

template <class T >
class BST<T*, C = op<T> >{
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
            if(C::comp(value,x->value))
                x = x->left;
            else
                x = x->right;
        }

        if(last == nullptr)
            root = a;
        else {
            if (op<T>::comp(value,last->value))
                last->left = a;
            else
                last->right = a;
        }
    }

    bool find(T value){
        Node* x = root;
        while(x != nullptr){
            if(op<T>::eq(value,x->value)){
                return true;
            }

            if(op<T>::comp(value,x->value)){
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
            if(op<T>::eq(value,x->value)) {
                Node *next = nullptr, *prev = nullptr;
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
                        if(prev != nullptr){
                            if(prev->left == x)
                                prev->left = nullptr;
                            else
                                prev->right = nullptr;
                        }
                        else
                            root = nullptr;
                        delete x;
                    }

                    prev = x;
                    x = next;
                }

                return true;
            }

            if(op<T>::comp(value,x->value)){
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


template <>
class BST<const char *>{
private:

    class Node{
    private:

    public:
        const char * value;
        Node* left;
        Node* right;

        Node(const char * value){
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

    BST(const char * value){
        this->root = new Node(value);
    }

    BST(initializer_list<const char *> values){
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

    void put(const char * value){
        Node* a = new Node(value);

        Node* x = root, *last = nullptr;
        while(x != nullptr){
            last = x;
            if(op<const char *>::comp(value,x->value))
                x = x->left;
            else
                x = x->right;
        }

        if(last == nullptr)
            root = a;
        else {
            if (op<const char *>::comp(value,last->value))
                last->left = a;
            else
                last->right = a;
        }
    }

    bool find(const char * value){
        Node* x = root;
        while(x != nullptr){
            if(op<const char *>::eq(value,x->value)){
                return true;
            }

            if(op<const char *>::comp(value,x->value)){
                x = x->left;
            }
            else
                x = x->right;
        }
        return false;
    }

    bool pop(const char * value){
        Node* x = root;
        while(x != nullptr){
            if(op<const char *>::eq(value,x->value)) {
                Node *next = nullptr, *prev = nullptr;
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
                        if(prev != nullptr){
                            if(prev->left == x)
                                prev->left = nullptr;
                            else
                                prev->right = nullptr;
                        }
                        else
                            root = nullptr;
                        delete x;
                    }

                    prev = x;
                    x = next;
                }

                return true;
            }

            if(op<const char *>::comp(value,x->value)){
                x = x->left;
            }
            else
                x = x->right;

        }
        return false;
    }

    const char * max(){
        if(this->empty())
            throw range_error("The tree is empty.");

        Node* x = root;
        while(x->right != nullptr)
            x = x->right;

        return x->value;
    }

    const char * min(){
        if(this->empty())
            throw range_error("The tree is empty.");

        Node* x = root;
        while(x->left != nullptr)
            x = x->left;

        return x->value;
    }
};
