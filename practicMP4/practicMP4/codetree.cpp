#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;
int i;
struct Node{
	int data;
	Node *children[5];
};

Node * rec_addNode(int * data, Node * curNode) {
	if (!curNode) {
		curNode = new Node;
		curNode->data = *data;
		for (i = 0; i <= 4; i++) {
			curNode->children[i] = NULL;
		} cout << curNode->data << "\n";
		return curNode;
	}
	int accidentn = rand() % 5; cout << accidentn << " ";
	curNode->children[accidentn] = rec_addNode(data, curNode->children[accidentn]); cout << curNode->data << "€€\n";
	return curNode;
}
void printing(Node * root, int level){
	if (root){
		cout << "level=" << level << " data=" << root->data << "\n"; int k;
		for (k = 0; k <= 4; ++k){
			printing(root->children[k], level + 1);
		}
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	Node * root = NULL;
	for (int j = 1; j <= 12; j++) {
		int put; put = rand() % 50;
		cout << "„исло, которое пытаютс€ запихать " << put << " "; root = rec_addNode(&put, root);
	}
	printing(root, 0);
	return 0;
}