#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

template <typename T>
struct NodeAB {
    T data;
    shared_ptr<NodeAB> left;
    shared_ptr<NodeAB> right;

    NodeAB(const T &element, shared_ptr<NodeAB> l = nullptr, shared_ptr<NodeAB> r = nullptr) : data (element), left (l), right (r){}
};

template <typename T>
class ArbolBinario {
    public:
        ArbolBinario (){
            root = nullptr;
        }

        ArbolBinario (const T &element, const ArbolBinario<T> &leftchild = ArbolBinario(), const ArbolBinario<T> &rightchild = ArbolBinario()){
            root = make_shared<NodeAB<T>> (element, leftchild.root, rightchild.root);
        }

        bool isNull () const;
        bool isLeaf () const;
        ArbolBinario<T> getLeftChild () const;
        ArbolBinario<T> getRightChild () const;
        const T& getValue () const;
        void preOrder () const;
        void inOrder () const;
        void postOrder () const;

    protected:
        shared_ptr<NodeAB<T>> root;
        ArbolBinario(shared_ptr<NodeAB<T>> newRoot) : root (newRoot) {}
};

template <typename T>
bool ArbolBinario<T>::isNull () const{
    return root == nullptr;
}

template <typename T>
bool ArbolBinario<T>::isLeaf () const{
    return isNull () || (root->left == nullptr && root->right == nullptr);
}

template <typename T>
ArbolBinario<T> ArbolBinario<T>::getLeftChild () const{
    if (isNull ()){
        throw runtime_error ("Trying getLeftChild() from an empty tree.");
    }

    return ArbolBinario (root->left);
}

template <typename T>
ArbolBinario<T> ArbolBinario<T>::getRightChild () const{
    if (isNull ()){
        throw runtime_error ("Trying getRightChild() from an empty tree.");
    }

    return ArbolBinario (root->right);
}

template <typename T>
const T& ArbolBinario<T>::getValue () const{
    if (isNull()){
        throw runtime_error ("Trying getValue() from an empty tree.");
    }

    return root->data;
}

template <typename T>
void ArbolBinario<T>::preOrder () const{
    if (isNull ()){
        return;
    }

    cout << root->data << " ";

    getLeftChild ().preOrder();
    getRightChild ().preOrder();
}

template <typename T>
void ArbolBinario<T>::inOrder () const{
    if (isNull ()){
        return;
    }
    
    getLeftChild ().inOrder ();

    cout << root->data << " ";
    
    getRightChild ().inOrder ();
}

template <typename T>
void ArbolBinario<T>::postOrder () const{
    if (isNull ()){
        return;
    }

    getLeftChild ().postOrder ();

    getRightChild (). postOrder ();

    cout << root->data << " ";
}

#endif