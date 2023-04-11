/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null || head.next==null){
            return null;
        }
        ListNode fwd= head;

        while(--n>0){
            fwd= fwd.next;
        }
        
        ListNode bkd= head;

        ListNode prv= head;
        
        while(fwd.next != null){
            prv= bkd;
            fwd= fwd.next;
            bkd= bkd.next;
        }
        if(bkd==head)
        {
            return head.next; 
        }
        
        // if(cur != null && prv != null)
            prv.next= bkd.next;
        // else{
        //     prv= null;
        // }
        // if(prv==head)
        // {
        //     return head.next;
        // }
        return head;
    }
    }