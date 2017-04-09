#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;
int l;
class TREE {
private:
	struct Node{
	int data;
	Node **children = new Node* [l];
	};
public:
	int maxlevel, i;	
	Node * root = NULL;
	Node * rec_addNode(int * data, Node * curNode) {
	if (!curNode) {
		curNode = new Node;
		curNode->data = *data;
		for (i = 0; i <= l-1; i++) {
			curNode->children[i] = NULL;
		}
		return curNode;
	}
	int accidentn = rand() % l;
	curNode->children[accidentn] = rec_addNode(data, curNode->children[accidentn]);
	return curNode;
	}
	void printing(Node * root, int level){
	if (root){
		cout << "������� = " << level << " ����� = " << root->data << "\n";
		if (level > maxlevel) { maxlevel = level; }
		int k;
		for (k = 0; k <= l-1; k++){
			printing(root->children[k], level + 1);
		}
	}
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	TREE a; int n;
	cout << "������� ����������� ��������� ���������� �������� "; cin >> l;
	cout << "������� ���������� ����� "; cin >> n;
	for (int j = 1; j <= n; j++) {
		int put; put = rand() % 50;
		a.root = a.rec_addNode(&put, a.root);
	}
	a.maxlevel = -1;
	a.printing(a.root, 0);
	cout << "������� ������: " << a.maxlevel << "\n";
	system("pause");
	return 0;
}