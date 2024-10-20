#include<iostream>
#include<vector>

using namespace std;

// 链表listNode结构体
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *second) : val(x), next(second) {}
};

// 删除节点函数
ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode *slow = new ListNode();
    slow->next = head;
    ListNode *fast = slow;
    for (int i = 0; i <= n; i++){
        fast = fast->next;
    }
    if(!fast)
        return head->next;
    while(fast){
        slow = slow->next;
        fast = fast->next;
    }
    if(n==1)
        slow->next = nullptr;
    else
        slow->next = slow->next->next;

    return head;
}

int main(){
    // 输入
    vector<int> input = {1};
    int n = 1;
    // 处理输入
    ListNode *head = new ListNode(input[0]);
    ListNode *end = head;
    int size = input.size();
    for (int i = 1; i < size; i++){
        end->next = new ListNode(input[i]);
        end = end->next;
    }
    // 执行得到结果
    ListNode *result = removeNthFromEnd(head, n);
    // 处理结果并输出
    vector<int> output;
    while(result){
        output.push_back(result->val);
        result = result->next;
    }
    cout << "[";
    for (int i : output){
        cout << i << ", ";
    }
    if(!output.empty())
        cout << "\b\b";
    cout << "] " << endl;

    return 0;
}