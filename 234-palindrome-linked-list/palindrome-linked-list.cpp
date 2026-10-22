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
    ListNode* reverse( ListNode* &head ){
        ListNode* prev = nullptr ;
        ListNode* curr = head;

        while( curr ){
            ListNode* nextnode = curr->next ;
            curr->next = prev;
            prev = curr ; 
            curr = nextnode ;
             
        }

        return prev ; 
    
    }

    bool isPalindrome(ListNode* head) {
        if( head== nullptr || head->next== nullptr ) return true ;

        ListNode* slow = head ;
        ListNode* fast = head ;

        while( fast->next && fast->next->next ){
            slow = slow->next ; 
            fast = fast->next->next ;

        } 
       ListNode* secondH = reverse(slow->next);    

       ListNode* first = head ;
       ListNode* second = secondH ;
       
       while( second ){
         if( first->val != second->val ) return false ;
         first = first->next ;
         second = second->next;

        }
      
      return true ;
     
    }
};