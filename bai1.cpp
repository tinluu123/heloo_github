#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* p;
};

Node* createNode(int idata) {
	Node* newNode = new Node;
	newNode->data = idata;
	newNode->p = NULL;
	return newNode;
}

void xuat(Node *headNode) {
	Node* node = new Node;
	node = headNode;
	while (node->p != NULL) {
		if (node != headNode)
			cout << node->data << " ";
		node = node->p;
	}
	cout << endl;
}

void taoChuoi(Node* headNode, Node* tailNode, int data) {
	
	Node* node = new Node;
	node = headNode;
	while (node->p != tailNode) {
		node = node->p;
	}
	Node* newNode = createNode(data);
	node->p = newNode;
	newNode->p = tailNode;

}

int main() {
	Node* headNode = createNode(NULL);
	Node* tailNode = createNode(NULL);
	headNode->p = tailNode;
	int n;
	cout << "Nhap n ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tempData;
		cout << "Nhap so thu " << i + 1 << " ";
		cin >> tempData;
		taoChuoi(headNode, tailNode, tempData);

	}
	cout << "Danh sach " << n << " so nguyen vua nhap" << endl;
	xuat(headNode);

	Node* headNode2 = createNode(NULL);
	Node* tailNode2 = createNode(NULL);
	headNode2->p = tailNode2;
	for (int i = 10; i <= 20; i++)
	{
		if (i % 2 == 0) {
			taoChuoi(headNode2, tailNode2, i);
		}

	}
	cout << "Danh sach cac so nguyen chan" << endl;
	xuat(headNode2);
	return 0;

	
}