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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head ;
        int cnt = 0 ;
        while(temp){
            cnt++;
            temp = temp->next ;
        }

        int ind = 0 ;
        int dltind = cnt - n ;
       
        // handle if deleting head 
        if( dltind == 0 ){
            ListNode* p = head ;
            p = head ->next ;
            return p ;
            
        }

        ListNode* back = nullptr;
        temp = head ;
        while(temp){
          
          if(ind == dltind){
            back->next = temp->next ;
            delete temp ;
            return head;
          }
        
            back = temp ;
            temp = temp->next ;
            
            ind++;
          
        }

    return nullptr; 
    }
};