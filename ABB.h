#ifndef ABB_H
#define ABB_H
#include <iostream>
#include <stdexcept>
#include <memory>
#include "ArbolBinario.h"

using namespace std;

template <typename T>
class ABB : public ArbolBinario<T> {
    public:
        ABB (){
            ArbolBinario<T> ();
        }
        
        bool insert (const T &element);
        bool erase (const T &element);
        const T* find (const T &element);
    
    private:
        bool insert (shared_ptr<NodeAB<T>> &localRoot, const T &element);
        bool erase (shared_ptr<NodeAB<T>> &localRoot, const T &element);
        const T* find (shared_ptr<NodeAB<T>> &localRoot, const T &element);
        void replaceParent (shared_ptr<NodeAB<T>> &oldRoot, shared_ptr<NodeAB<T>> &localRoot);      
};

template <typename T>
const T* ABB<T>::find (const T &element){

    return find (this->root, element);

}

template <typename T>
const T* ABB<T>::find (shared_ptr<NodeAB<T>> &localRoot, const T &element){
    if (localRoot == nullptr){
        return nullptr;
    }
    else if (element < localRoot->data){
        return find (localRoot->left, element);
    }
    else if (element > localRoot->data){
        return find (localRoot->right, element);
    }
    else{
        return &(localRoot->data);
    }

}

template <typename T>
bool ABB<T>::insert (const T &element){
    
    return insert (this->root, element);

}

template <typename T>
bool ABB<T>::insert (shared_ptr<NodeAB<T>> &localRoot, const T &element){
    if (localRoot == nullptr){
        localRoot = make_shared<NodeAB<T>>(element);
        return true;
    }
    else{
        if (element < localRoot->data){
            return insert (localRoot->left, element);
        }
        else if (element > localRoot->data){
            return insert (localRoot->right, element);
        }
        else{
            return false;
        }
    }
}

template <typename T>
bool ABB<T>::erase (const T &element){
    return erase (this->root, element);
}

template <typename T>
bool ABB<T>::erase (shared_ptr<NodeAB<T>> &localRoot, const T &element){
    if (localRoot == nullptr){
        return false;
    }
    else{
        if (element < localRoot->data){
            return erase (localRoot->left, element);
        }
        else if (element > localRoot->data){
            return erase (localRoot->right, element);
        }
        else{
            if (localRoot->left == nullptr){
                localRoot = localRoot->right;
            }
            else if (localRoot->right == nullptr){
                localRoot = localRoot->left;
            }
            else{
                shared_ptr<NodeAB<T>> oldRoot = localRoot;
                replaceParent (oldRoot, localRoot->left);
            }

            return true;
        }
    }
}

template <typename T>
void ABB<T>::replaceParent (shared_ptr<NodeAB<T>> &oldRoot, shared_ptr<NodeAB<T>> &localRoot){
    if (localRoot->right != nullptr){
        replaceParent (oldRoot, localRoot->right);
    }
    else{
        oldRoot->data = localRoot->data;
        localRoot = localRoot->left;
    }
}

#endif