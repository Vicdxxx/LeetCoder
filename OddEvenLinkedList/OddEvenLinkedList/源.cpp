#include<iostream>
#include<cmath>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
public:
	ListNode* oddEvenList2(ListNode* head)
	{
		if (!head)
		{
			return head;
		}
		ListNode* first=head;
		ListNode* second = head->next;;
		ListNode* tmp = second;
		while (second&&second->next)
		{
			first->next = second->next;
			first = first->next;
			second->next = first->next;
			second = second->next;
		}
		first->next = tmp;

		return head;
	}
	ListNode* oddEvenList1(ListNode* head)
	{
		if (!head)
			return head;
		ListNode* first = head;
			ListNode* second = head->next;
		ListNode* temp = second;
		while (second && second->next)
		{
			first->next = second->next;
			first = first->next;
			second->next = first->next;
			second = second->next;
		}
		first->next = temp;
		return head;
	}
	ListNode* oddEvenList(ListNode* head) {
		int idx = 1;
	
		ListNode* tmp1 = head;
		ListNode* tmp2 = head;
		while (tmp1->next!=NULL)
		{
			tmp1 = head;
			tmp2 = head;
			idx++;
			int move = idx / 2;
			if (idx % 2==0)
			{
				for (int j = 0; j < move;j++)
				{
					for (int k = 0; k < 2 * move-1-j; k++)
					{
						tmp1 = tmp1->next;
					}
					for (int k = 0; k < 2 * move - 2 - j; k++)
					{
						tmp2 = tmp2->next;
					}
						tmp1 = tmp1->next;
						tmp2->next = tmp1->next;
						tmp2 = tmp1;
						tmp1 = tmp1->next;
						tmp2->next = tmp1->next;
						tmp1->next = tmp2;
				}
			}
		}
		return head;
	}
};

void main()
{



	cin.get();
}