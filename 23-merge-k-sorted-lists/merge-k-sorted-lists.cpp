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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue< pair<int , ListNode*> , vector< pair<int , ListNode*>> , greater< pair<int , ListNode*>>> pq;
        for(auto head : lists){
            if( head){
                pq.push({ head->val , head });
            }
        }
        ListNode* Dnode= new ListNode(-1);
        ListNode* temp = Dnode;
        while(!pq.empty()){
            auto p = pq.top();
            ListNode* node = p.second;
            int nodeVal = p.first;
            pq.pop();
            if(node->next){
                pq.push({ node->next->val , node->next});
            }
            temp->next= node;
            temp->next->val = node->val;
            temp = temp->next;

        }

        return Dnode->next;
        
    }
};