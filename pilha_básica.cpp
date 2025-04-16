//Estudos de Pilha

#include <iostream>

using namespace std;

#define tam 100 //tamanho maximo da pilha

class pilha {
	private:
	int arr[tam];
	int topo;
	
	public:
	pilha() {
		topo = -1; //pilha começa vazio
	}
	bool pilhaEmpty() {
		return topo == -1;
	}
	bool pilhaFull() {
		return topo == tam - 1;
	}
	
	void push(int valor) { //push(valor) coloca um valor no topo da pilha
		if (pilhaFull()) {
			cout << "Pilha cheia!";
			return;
		}
		topo++;
		arr[topo] = valor;
	}
	void pop() { //pop() remove o valor do topo
		if (pilhaEmpty()) {
			cout << "Pilha vazia!";
			return;
		}
		topo--;
	}
	int top() {
		if (pilhaEmpty()) {
			cout << "Pilha vazia!";
			return -1;
		}
		return arr[topo];
	}
};

int main() {
	pilha p;
	
	p.push(30);
	p.push(80);
	p.push(56);
	p.push(3);
	
	cout << "Topo da pilha é: " << p.top() << endl; //Deve imprimir o valor no topo da pilha, no caso 3
	
	p.pop();
	
	cout << "Novo topo: " << p.top() << endl; //Deve imprimir o valor no topo após retirar o topo anterior, no caso 56
	
	return 0;
}
