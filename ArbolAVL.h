#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

template <typename T>
struct NodeAVL {
    T data;
    NodeAVL *left = nullptr;
    NodeAVL *right = nullptr;
    int height = 0;
};

template <typename T>
class ArbolAVL{
    public:
        ArbolAVL (){
            root = nullptr;
        }

        void insert (const T& element);
        void erase (const T& element);
        void inOrder ();
        void cargarArchivo (ofstream &archivo);

    private:
        int getHeight (NodeAVL<T> *nodo);
        int maxValue (int a, int b);
        int getBalance (NodeAVL<T> *nodo);
        NodeAVL<T>* newNode (const T& value);
        NodeAVL<T>* minValueNode (NodeAVL<T> *root);
        NodeAVL<T>* rotateRight (NodeAVL<T> *nodo);
        NodeAVL<T>* rotateLeft(NodeAVL<T> *nodo);
        NodeAVL<T>* insert (NodeAVL<T> *node, const T& value);
        NodeAVL<T>* erase (NodeAVL<T> *node, const T& value);
        void inOrder (NodeAVL<T> *root);
        void cargarArchivo (NodeAVL<T> *node, ofstream &archivo);

        NodeAVL<T>* root = new NodeAVL<T> ();
};

template <typename T>
int ArbolAVL<T>::getHeight (NodeAVL<T> *nodo){
    if (nodo == nullptr){
        return 0;
    }

    return nodo->height;
}

template <typename T>
int ArbolAVL<T>::maxValue (int a, int b){
    return  (a > b) ? a : b;
}

template <typename T>
int ArbolAVL<T>::getBalance (NodeAVL<T> *nodo){
    if (nodo == nullptr){
        return 0;
    }

    return getHeight (nodo->left) - getHeight (nodo->right);
}

template <typename T>
NodeAVL<T>* ArbolAVL<T>::newNode (const T& value){
    NodeAVL<T> *nodo = new NodeAVL<T> ();

    nodo->data = value;
    nodo->left = nullptr;
    nodo->right = nullptr;
    nodo->height = 1;

    return nodo;
}

template <typename T>
NodeAVL<T>* ArbolAVL<T>::minValueNode (NodeAVL<T> *nodo){
    NodeAVL<T> *current = nodo;

    while (current->left != nullptr){
        current = current->left;
    }

    return current;
}

template <typename T>
NodeAVL<T>* ArbolAVL<T>::rotateRight (NodeAVL<T> *nodo){
    NodeAVL<T> *nodoX = nodo->left;
    NodeAVL<T> *aux = nodoX->right;

    nodoX->right = nodo;
    nodo->left = aux;

    nodo->height = maxValue (getHeight (nodo->left), getHeight (nodo->right)) + 1;
    nodoX->height = maxValue (getHeight (nodoX->left), getHeight (nodoX->right)) + 1;

    return nodoX;
}

template <typename T>
NodeAVL<T>* ArbolAVL<T>::rotateLeft(NodeAVL<T> *nodo){
    NodeAVL<T> *nodoY = nodo->right;
    NodeAVL<T> *aux = nodoY->left;

    nodoY->left = nodo;
    nodo->right = aux;

    nodo->height = maxValue (getHeight (nodo->left), getHeight (nodo->right)) + 1;
    nodoY->height = maxValue (getHeight (nodoY->left), getHeight (nodoY->right)) + 1;

    return nodoY;
}

template <typename T>
void ArbolAVL<T>::insert (const T& element){
    root = insert (this->root, element);
}

template <typename T>
NodeAVL<T>* ArbolAVL<T>::insert (NodeAVL<T> *node, const T& value){
    if (node == nullptr){
        return (newNode (value));
    }

    if (value < node->data){
        node->left = insert (node->left, value);
    }
    else if (value > node->data){
        node->right = insert (node->right, value);
    }
    else{
        return node;
    }
    
    node->height = 1 + maxValue (getHeight(node->left), getHeight (node->right));
    int balance = getBalance (node);

    if (balance > 1 && value < node->left->data){
        return rotateRight (node);
    }

    if (balance < -1 && value > node->right->data){
        return rotateLeft (node);
    }

    if (balance > 1 && value > node->left->data){
        node->left = rotateLeft (node->left);
        return rotateRight (node);
    }

    if (balance < -1 && value < node->right->data){
        node->right = rotateRight (node->right);
        return rotateLeft (node);
    }

    return node;
}

template <typename T>
void ArbolAVL<T>::erase (const T& element){
    root = erase (this->root, element);
}

template <typename T>
NodeAVL<T>* ArbolAVL<T>::erase (NodeAVL<T> *node, const T& value){
    if (node == nullptr){
        return node;
    }

    if (value < node->data){
        node->left = erase (node->left, value);
    }
    else if (value > node->data){
        node->right = erase (node->right, value);
    }
    else{
        if ((node->left == nullptr) || (node->right == nullptr)){
            NodeAVL<T> *temp = node->left ? node->left : node-> right;

            if (temp == nullptr){
                temp = node;
                node = nullptr;
            }
            else{
                *node = *temp;
            }

            free (temp);
        }
        else{
            NodeAVL<T> *temp = minValueNode (node->right);

            node->data = temp->data;

            node->right = erase (node->right, temp->data);
        }
    }

    if (node == nullptr){
        return node;
    }

    node->height = 1 + maxValue (getHeight (node->left), getHeight (node->right));
    int balance = getBalance (node);

    if (balance > 1 && getBalance (node->left) >= 0){
        return rotateRight (node);
    }

    if (balance > 1 && getBalance (node->left) < 0){
        node->left = rotateLeft (node->left);
        return rotateRight (node);
    }

    if (balance < -1 && getBalance (node->right) <= 0){
        return rotateLeft (node);
    }

    if (balance < -1 && getBalance (node->right) > 0){
        node->right = rotateRight (node->right);
        return rotateLeft (node);
    }

    return node;
}

template <typename T>
void ArbolAVL<T>::inOrder (){
    inOrder (this->root);
}

template <typename T>
void ArbolAVL<T>::inOrder (NodeAVL<T> *node){
    if (node != nullptr){
        inOrder (node->left);

        cout << node->data << " ";

        inOrder (node->right);
    }
}

template <typename T>
void ArbolAVL<T>::cargarArchivo (ofstream &archivo){
    cargarArchivo (this->root, archivo);
}

template <typename T>
void ArbolAVL<T>::cargarArchivo (NodeAVL<T> *node, ofstream &archivo){
    if (node != nullptr){
        cargarArchivo (node->left, archivo);

        archivo << node->data;

        cargarArchivo (node->right, archivo);
    }
}

#endif