//Fermín Nieto
//A01707069

#ifndef SPLAY_H
#define SPLAY_H

#include <string>
#include <sstream>


template <class T>
class SplayTree {
private:
    // Estructura de nodo
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node* parent;

        Node(T val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root;

    // Zig derecha
    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right) y->right->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    // Zig izquierda
    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    // Movimientos zig y zig-zag para llevar un nodo a la raíz
    void splay(Node* x) {
        while (x->parent) {
            if (!x->parent->parent) {
                if (x == x->parent->left) rotateRight(x->parent);
                else rotateLeft(x->parent);
            } else if (x == x->parent->left && x->parent == x->parent->parent->left) {
                rotateRight(x->parent->parent);
                rotateRight(x->parent);
            } else if (x == x->parent->right && x->parent == x->parent->parent->right) {
                rotateLeft(x->parent->parent);
                rotateLeft(x->parent);
            } else if (x == x->parent->right && x->parent == x->parent->parent->left) {
                rotateLeft(x->parent);
                rotateRight(x->parent);
            } else {
                rotateRight(x->parent);
                rotateLeft(x->parent);
            }
        }
    }

    // Helpers
    
    Node* find_helper(T val) {
        Node* current = root;
        while (current) {
            if (val == current->value) {
                splay(current);
                return current;
            }
            if (val < current->value) current = current->left;
            else current = current->right;
        }
        return nullptr;
    }

    void inorder_helper(Node* node, std::string& result) const {
        if (node == nullptr) return;
        inorder_helper(node->left, result);
        result += std::to_string(node->value) + " ";
        inorder_helper(node->right, result);
    }

    void preorder_helper(Node* node, std::string& result) const {
        if (node == nullptr) return;
        result += std::to_string(node->value) + " ";
        preorder_helper(node->left, result);
        preorder_helper(node->right, result);
    }

public:
    SplayTree() : root(nullptr) {}

    // Añadir
    void add(T val) {
        if (!root) {
            root = new Node(val);
            return;
        }
        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            if (val < current->value) current = current->left;
            else if (val > current->value) current = current->right;
            else return;  // El valor ya existe
        }
        Node* newNode = new Node(val);
        newNode->parent = parent;
        if (val < parent->value) parent->left = newNode;
        else parent->right = newNode;
        splay(newNode);
    }

    // Eliminar
    void remove(T val) {
        Node* node = find_helper(val);
        if (!node) return;

        Node* left = node->left;
        Node* right = node->right;

        if (!left) {
            root = right;
            if (right) right->parent = nullptr;
        } else if (!right) {
            root = left;
            left->parent = nullptr;
        } else {
            left->parent = nullptr;
            root = left;
            Node* rightmost = left;
            while (rightmost->right) rightmost = rightmost->right;
            splay(rightmost);
            rightmost->right = right;
            right->parent = rightmost;
        }

        delete node;
    }

    //Ayudador

    bool find(T val) {
        Node* node = find_helper(val);
        return node != nullptr;
    }

    std::string inorder() {
        std::string result = "[";
        inorder_helper(root, result);
        if (!result.empty() && result.back() == ' ') result.pop_back();
        result += "]";
        return result;
    }

    std::string preorder() {
        std::string result = "[";
        preorder_helper(root, result);
        if (!result.empty() && result.back() == ' ') result.pop_back();
        result += "]";
        return result;
    }
};

#endif // SPLAY_H