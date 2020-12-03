#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <list>

using namespace std;

template <class T> class SplayTree;

template <class T> //Clase principal
class Node{
private:
	T value;
	int size;
	Node *left, *right, *parent;
	Node<T>* succesor();
	Node<T>* rot_right(Node<T>*);
	Node<T>* rot_left(Node<T>*);
public:
	Node(T);
	Node<T>*add(T);
	Node<T>*find(T);
  void inorder(stringstream&) const;
	void verArbol(stringstream&) const;
	void preorder(stringstream&) const;

	Node<T>* splay(Node<T>*,Node<T>*); //Clase amiga
	friend class SplayTree<T>;
};

template <class T> //Constructor clase node
Node<T>::Node(T val): value(val),size(0),left(0),right(0),parent(0) {}

template <class T> //El add unicamente funciona para el momento de leer el archivo
Node<T>* Node<T>::add(T val){
	if(val < value){
		if(left != 0){
			return left->add(val);
		}
		else{
			left = new Node<T>(val);
			left->parent = this;
			return left;
		}
	}
	else{
		if(right != 0){
			return right->add(val);
		}else{
			right = new Node<T>(val);
			right->parent = this;
			return right;
		}
	}
	size++;
}

template<class T>
Node<T>* Node<T>::find(T val){
	if(val == value){
		cout << "El personaje buscado es: " << value;
		return this;
	}
	else if (val < value){
		if(left != 0)
			return left->find(val);
		else
			return this;
	}
	else if (val > value){
		if(right != 0)
			return right->find(val);
		else
			return this;
	}
	cout << "El personaje buscado es: " << value;
	return 0;
}

template<class T> //Funcion para encontrar el sucesor de un nodo
Node<T>* Node<T>::succesor(){
	Node<T> *le,*ri;

	le = left;
	ri = right;

	if(right == 0){
		if(left != 0){
			left = 0;
		}
		if(le)
			le->parent = 0;
		return le;
	}

	if(right->left == 0){
		right = right->right;
		if(right)
			right->parent = parent;
		if(ri){
			ri->right = 0;
			ri->parent = 0;
		}
		return ri;
	}

	Node<T> *p,*c;
	p = right;
	c = right->left;
	while(c->left != 0){
		p = c;
		c = c->left;
	}
	p->left = c->right;
	if(p->left != 0)
		p->left->parent = p;
	c->right = 0;
	return c;
}

//Estas dos funciones sirven para moverse por el arbol de izquierda a derecha

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* x){
	Node<T> *y = x->left;
	x->left = y->right;
	if(y->right)
		y->right->parent = x;
	y->right = x;

	y->parent = x->parent;
	x->parent = y;

	if(y->parent){
		if(y->parent->left && y->parent->left->value == x->value)
			y->parent->left = y;
		else
			y->parent->right = y;
	}
	return y;
}

template<class T>
Node<T>* Node<T>::rot_left(Node<T>*x){
	Node<T> *y = x->right;
	x->right = y->left;
	if(y->left)
		y->left->parent = x;
	y->left = x;

	y->parent = x->parent;
	x->parent = y;

	if(y->parent){
		if(y->parent->left && y->parent->left->value == x->value)
			y->parent->left = y;
		else
			y->parent->right = y;
	}
	return y;
}

template<class T>
Node<T>* Node<T>::splay(Node<T>* root, Node<T>* x){
	while(x->parent != 0){

		if(x->parent->value == root->value){
			if(x->parent->left && x->parent->left->value == x->value){
				rot_right(x->parent);
			}else{
				rot_left(x->parent);
			}
		}else{
			Node<T>*p = x->parent;
			Node<T>*g = p->parent;
			if(p->left && g->left &&
				x->value == p->left->value && p->value == g->left->value){
				rot_right(g);
				rot_right(p);
			}else if(p->right && g->right &&
			 x->value == p->right->value && p->value == g->right->value){
				rot_left(g);
				rot_left(p);
			}else if(p->left && g->right &&
			 x->value == p->left->value && p->value == g->right->value){
				rot_right(p);
				rot_left(g);
			}else{
				rot_left(p);
				rot_right(g);
			}
		}
	}

	return x;
}

template <class T> //Funcion inorder
void Node<T>::inorder(stringstream &aux) const {
	if(left != 0){
		left->inorder(aux);
	}
	if(aux.tellp() != 1){
		aux << "\n";
	}
	aux << value;
	if(right != 0){
		right->inorder(aux);
	}
}

template <class T> //Funcion preorder
void Node<T>::preorder(stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T> //Funcion que sirve para imprimir todo el arbol y poder ver donde estan sus nodos, si son roots y de que lado estan
void Node<T>::verArbol(stringstream &aux) const {
	if (parent != 0){
		aux << "\n 		Nodo: " << value << endl;
		aux << " 		Parent: " << parent->value << endl;
	}else
		aux << "\n 		Root: " << value << endl;
	if (left != 0)
		aux << " <----- Left: " << left->value;
	if (right != 0)
		aux << " Right -----> : " << right->value;
	aux << "\n";

	if (left != 0) {
		left->verArbol(aux);
	}
	if (right != 0) {
		right->verArbol(aux);
	}
}

template<class T>
class SplayTree{
private:
	Node<T> *root;
	int size;
public:
	SplayTree();
	~SplayTree();
	void add(T);
	bool find(T);
	void transcribir(string);
  string verArbol() const;
	string inorder() const;
	string preorder() const;
	bool empty() const;
};

template <class T> //Constructor clase amiga
SplayTree<T>::SplayTree():root(0), size(0) {}

template<class T> //Destructor clase amiga
SplayTree<T>::~SplayTree() {
}

template<class T>
bool SplayTree<T>::empty() const{
	return (root == 0);
}

template<class T>
void SplayTree<T>::add(T val){
	if(root != 0){
		Node<T>* added = root->add(val);
		root = root->splay(root,added);
	}
	else{
		root = new Node<T>(val);
	}
	size++;
}

template<class T> //Funcion que busca el personaje en el arbol
bool SplayTree<T>::find(T val){
	if(root != 0){
		Node<T>* found = root->find(val);
		if (found == 0){
			cout << "El personaje no existe en el arbol" << endl;
			return false;
		}
		root = root->splay(root,found);
		cout << "El personaje buscado es: " << root->value;
		return(root->value == val);
	}

	else{
		cout << "El personaje buscado no existe en el arbol" << endl;
		return false;
	}
}

template<class T>
string SplayTree<T>::inorder() const{
	stringstream aux;

	aux << "";
	if(!empty()){
		root->inorder(aux);
	}
	aux << "";
	return aux.str();
}

template<class T>
string SplayTree<T>::preorder() const{
	stringstream aux;

	aux << "[";
	if(!empty()){
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template<class T>
string SplayTree<T>::verArbol() const{
	stringstream aux;

	aux << "\n ///////////////////////// ";
	if(!empty()){
		root->verArbol(aux);
	}
	aux << " ///////////////////////// \n";
	return aux.str();
}

template <class T>
bool verArchivo(SplayTree<T>& myTree, string nombrearch) {
	ifstream arch(nombrearch);
	if (!arch) {
		cout << "No se encuentra el archivo: " << nombrearch << endl;
		return false;
	}
	string linea;
	while (getline(arch, linea)) { //saca una linea del archivo y lo guarda en string linea
		if (linea.size() > 0) {
			myTree.add(linea);
		}
	}
	arch.close();
	return true;
}

template <class T>
void SplayTree<T>::transcribir(string myfile){
	ofstream arch;
    arch.open (myfile);
	if (arch.is_open()){
		arch << inorder();
	}
	arch.close();
}

void buscarPersonaje(ifstream &archivo, string personajeBuscado){
    archivo.open("ejemplo.txt", ios::in);
    string personaje, edad, elemento;
    int aux = 0;
    archivo >> personaje;
    while(!archivo.eof() && aux == 0){
        archivo >> edad;
        archivo >> elemento;
        if(personaje == personajeBuscado){
            cout << "El personaje es: " << endl;
            cout << personaje << " " << edad << " " << elemento << endl;
            aux = 1;
        }
        archivo >> personaje;
    }
    archivo.close();
    if (aux == 0){
        cout << "El personaje no existe en el arbol" << endl;
    }
}

#endif
