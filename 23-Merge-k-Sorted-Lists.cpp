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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i =0 ; i < lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                pq.push(temp);
               temp = temp -> next;
            }
        }
        if(pq.empty())return NULL;
       ListNode* head = pq.top();
       pq.pop();
       ListNode* temp = head;
       while(!pq.empty()){
        ListNode* el = pq.top();
        pq.pop();
        temp -> next = el;
        temp = temp ->next;
       }
       temp -> next = NULL;
        return head;
    }
};