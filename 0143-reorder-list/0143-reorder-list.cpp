/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode* prev=head;
        ListNode* curr=head->next;
        head->next=NULL;
        
        while(prev!=NULL and curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head->next==NULL){
            return;
        }
        
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        
        ListNode* l1=head;
        ListNode* l2=reverse(slow);
        
        while(prev){
            ListNode* tmp1=l1->next;
            ListNode* tmp2=l2->next;
            l1->next=l2;
            if (tmp1 == NULL) {
                break;
            }
            l2->next=tmp1;
            l1=tmp1;
            l2=tmp2;
        }
    }
};