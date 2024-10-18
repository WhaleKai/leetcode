#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}

int main(){
    // 输入
    vector<int> input = {3, 2, 0, -4};
    int pos = 1;
    // 构建输入链表
    ListNode *head;
    int n = input.size();
    ListNode *cur = new ListNode(0);
    ListNode *pre = cur;
    for (int i = 0; i < n; i++){
        cur->next = new ListNode(input[i]);
        cur = cur->next;
    }
    if(pos != -1){
        ListNode *node = pre;
        for (int i = 0; i <= pos; i++){
            node = node->next;
        }
        cur->next = node;
    }
    // 输出结果
    bool result = hasCycle(pre->next);
    cout << boolalpha << result;

    return 0;
}