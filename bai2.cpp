#include <iostream>

using namespace std;

struct HangHoa {
	string maHang;
	string loaiHang;
	string tenHang;
	int soLuong;
	int donGia;
	bool quaTang;
};

struct Node
{
	HangHoa hanghoa;
	Node* p;
};

HangHoa khoiTao(HangHoa hangHoa, string maHang, string loaiHang, string tenHang, int soLuong, int donGia, bool quaTang) {
	hangHoa.maHang = maHang;
	hangHoa.loaiHang = loaiHang;
	hangHoa.tenHang = tenHang;
	hangHoa.soLuong = soLuong;
	hangHoa.donGia = donGia;
	hangHoa.quaTang = quaTang;
	return hangHoa;
}

Node* taoNode(HangHoa hanghoa) {
	Node* node = new Node;
	node->hanghoa = hanghoa;
	node->p = NULL;
	return node;
}


void taoChuoi(Node* headNode, Node* tailNode, HangHoa hanghoa) {
	Node* node = new Node;
	node = headNode;
	while (node->p != tailNode) {
		node = node->p;
	}
	Node* newNode = taoNode(hanghoa);
	node->p = newNode;
	newNode->p = tailNode;
}

void xuat(Node* headNode) {
	Node* node = new Node;
	node = headNode;
	while (node->p != NULL) {
		if (node != headNode)
		{
			cout << node->hanghoa.maHang << "\t ";
			cout << node->hanghoa.loaiHang << "\t ";
			cout << node->hanghoa.tenHang << "\t ";
			cout << node->hanghoa.soLuong << "\t ";
			cout << node->hanghoa.donGia << "\t ";
			cout << node->hanghoa.quaTang << "\t \n";
		}
		node = node->p;
	}
	cout << endl;
}

int main() {
	HangHoa hanghoa;
	Node* headNode = taoNode(hanghoa);
	Node* tailNode = taoNode(hanghoa);
	headNode->p = tailNode;
	//headNode = tailNode = NULL;
	HangHoa hangHoa[3];
	hangHoa[0] = khoiTao(hangHoa[0], "MH01", "Banh Snack", "Snack cua", 1000, 10, true);
	hangHoa[1] = khoiTao(hangHoa[1], "MH02", "Keo\t", "Keo mut", 500, 2, false);
	hangHoa[2] = khoiTao(hangHoa[2], "MH03", "Banh trang", "Bon bon", 600, 6, true);
	taoChuoi(headNode, tailNode, hangHoa[0]);
	taoChuoi(headNode, tailNode, hangHoa[1]);
	taoChuoi(headNode, tailNode, hangHoa[2]);
	xuat(headNode);
}