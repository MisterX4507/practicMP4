#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;
int i;
class TREE {
private:
	struct Node{
	int data;
	Node *children[5];
	};
public:
	int maxlevel;	
	Node * root = NULL;
	Node * rec_addNode(int * data, Node * curNode) {
	if (!curNode) {
		curNode = new Node;
		curNode->data = *data;
		for (i = 0; i <= 4; i++) {
			curNode->children[i] = NULL;
		}
		return curNode;
	}
	int accidentn = rand() % 5;
	curNode->children[accidentn] = rec_addNode(data, curNode->children[accidentn]);
	return curNode;
	}
	void printing(Node * root, int level){
	if (root){
		cout << "Уровень = " << level << " Число = " << root->data << "\n";
		if (level > maxlevel) { maxlevel = level; }
		int k;
		for (k = 0; k <= 4; k++){
			printing(root->children[k], level + 1);
		}
	}
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	TREE a;
	for (int j = 1; j <= 12; j++) {
		int put; put = rand() % 50;
		a.root = a.rec_addNode(&put, a.root);
	}
	a.maxlevel = -1;
	a.printing(a.root, 0);
	cout << "Глубина дерева: " << a.maxlevel << "\n";
	system("pause");
	return 0;
}