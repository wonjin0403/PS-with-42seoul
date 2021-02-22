#include <iostream>

using namespace std;

int n, m;
const int PN =23;
const int HASH_SIZE = 100002;
const int NODE_SIZE = 500003;

struct Node {
	int data;
	Node* next;
};
Node node[NODE_SIZE];

int idx;
unsigned int get_key(int data)
{
	unsigned int key = 0, p = 1;
	if (data < 0) data *= -1;
	data *= PN;
	return (data%HASH_SIZE);
}
struct List {
	Node* head;
	void add(int data)
	{
		Node *newNode = head;
		head = &node[idx++];
		head->data = data;
		head->next = newNode;
	}
};
List hasha[HASH_SIZE];


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		int key = get_key(x);
		hasha[key].add(x);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		int key = get_key(x);
		Node *temp = hasha[key].head;
		int flag = 0;
		while (temp != 0)
		{
			if (temp->data == x)
			{
				flag = 1;
				break;
			}
			temp = temp->next;
		}
		if (flag == 1) printf("1\n");
		else printf("0\n");
	}
}
