//Estudos de Pilha 2, Pilha com Nó (Ponteiro)

#include <iostream>

using namespace std;

struct noh {
	int dado;
	noh* proximo;
};

class pilha {
	private:
	noh* topo; //ponteiro para o topo da pilha
	
	public:
	pilha() {
		topo = nullptr; //ponteiro nulo no topo
	}
	~pilha() { //Destrutor para liberar memória, MUITO IMPORTANTE
		while (!pilhaEmpty()) {
			pop();
		}
	}
	
	bool pilhaEmpty() {
		return topo == nullptr;
	}
	
	void push(int valor) { //push(valor) coloca um valor no topo da pilha EMPILHAR
		noh* novo = new noh(); //Aloca um novo nó
		novo->dado = valor;
		novo->proximo = topo; //Novo aponta pra "proximo", que é o antigo novo
		topo = novo; //O valor de novo é atribuido ao topo, logo novo vira o topo
	}
	void pop() { //pop() remove o valor do topo DESEMPILHAR
		if (pilhaEmpty()) {
			cout << "Pilha vazia!";
			return;
		}
		noh* temporario = topo;
		topo = topo->proximo; //Topo agora é o proximo
		delete temporario; //Libera o antigo topo
	}
	int top() {
		if (pilhaEmpty()) {
			cout << "Pilha vazia!";
			return -1;
		}
		return topo->dado;
	}
};

int main() {
	pilha p;
	
	p.push(45);
	p.push(50);
	p.push(3);
	
	cout << "Topo da pilha é: " << p.top() << endl; //Deve imprimir o valor no topo da pilha, no caso 3
	
	p.pop();
	
	cout << "Novo topo: " << p.top() << endl; //Deve imprimir o valor no topo após retirar o topo anterior, no caso 56
	
	return 0;
}
