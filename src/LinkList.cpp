#include<iostream>
using namespace std;
 
typedef struct listnode {
	int data;
	struct listnode* next;
}listnode , *list;
 
void print(list head);
list reverse(list head);
list fill(list head); //默认用1-10填充链表
 
int main() 
{
	//初始化链表头节点
	listnode* head;
	head = (listnode*)malloc(sizeof(listnode));
	head->next = NULL;
	head->data = -1;
	list linklist = fill(head);
	print(head);
	reverse(head);
	print(head);
	getchar();
	return 0;
}
 
list reverse(list head)
{
	if (head->next == NULL || head->next->next == NULL)
	{
		return head;   /*链表为空或只有一个元素则直接返回*/
	}
 
	list t = NULL;
	list p = head->next;
	list q = head->next->next;
	while (q != NULL)
	{
		t = q->next;
		q->next = p;
		p = q;
		q = t;
	}
 
	/*此时q指向原始链表最后一个元素，也是逆转后的链表的表头元素*/
	head->next->next = NULL;  /*设置链表尾*/
	head->next = p;           /*调整链表头*/
	return head;
}
 
list fill(list head)
{	
	listnode *p, *q;
	p = head;
	for (int i = 0; i < 10; i++) 
	{
		q = (listnode*)malloc(sizeof(listnode));
		q->data = i + 1;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return head;
}
 
void print(list head)
{
	list p;
	p = head->next;
	while(p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
