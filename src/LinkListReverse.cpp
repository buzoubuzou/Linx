#include<iostream>
using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
ListNode* reverseList(ListNode* head) {

ListNode*cur = NULL;

ListNode*pre = head;

if(head == NULL||head->next==NULL)
{
return head;
}

while(pre!=NULL)
{
ListNode* p = pre->next;
pre->next = cur;
cur = pre;
pre = p;
}
return cur;
}
};

int main()
{
ListNode* head = new ListNode(1);
ListNode* sec = new ListNode(4);
ListNode* thr = new ListNode(5);
ListNode* fou = new ListNode(9);

head->next = sec;
sec->next = thr;
thr->next = fou;
fou->next = nullptr;

Solution s;
ListNode*p_head = s.reverseList(head);

while(p_head!=nullptr)
{
cout <<p_head->val<<endl;
p_head = p_head->next;
}
}
