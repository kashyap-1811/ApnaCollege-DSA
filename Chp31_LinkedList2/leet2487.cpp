#include <bits/stdc++.h>

using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

    ListNode* reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *succ = nullptr;

        if(head != nullptr) succ = head->next;

        while(succ != nullptr)
        {
            curr->next = prev;
            prev = curr;
            curr = succ;
            succ = succ->next;
        }

        if(curr != nullptr)
            curr->next = prev;

        return curr;
    }

    ListNode* removeNodes(ListNode* head) {        
        head = reverse(head);

        ListNode *temp1 = head;
        ListNode *temp2 = head->next;

        while(temp2 != nullptr)
        {
            if(temp2->val < temp1->val)
            {
                ListNode *todelete = temp2;
                temp2 = temp2->next;
                temp1->next = temp2;
                todelete->next = nullptr;
                delete todelete;

                // temp1->next = temp2->next;
                // temp2->next = nullptr;
                // temp2 = temp1->next;
            }
            else
            {
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
        }

        return reverse(head);
    }

    void print(ListNode *head)
    {
        ListNode *temp = head;

        while(temp != nullptr)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

int main()
{
    ListNode *head = new ListNode(5);
    head->next = new ListNode(15);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    print(head);
    print(removeNodes(head));
    return 0;
}