#pragma warning(disable:4996)
#include <cstdio>
#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<vector<int>> initializeData(int lineCount = 1) {
    freopen("C:\\Users\\fengy\\Desktop\\io\\in.txt", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取   
    freopen("C:\\Users\\fengy\\Desktop\\io\\\\out.txt", "w", stdout); //输出重定向，输出数据将保存在out.txt文件中   
    vector<vector<int>> v = vector<vector<int>>(lineCount);

    // Read data from text file.
    string line;
    for (int i = 0; i < lineCount && getline(cin, line); ++i) {
        istringstream iss(line);
        int number;
        while (iss >> number)
            v[i].push_back(number);
    }

    return v;
}

void printData(vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

vector<ListNode*> initializeList(int lineCount = 1) {
    freopen("C:\\Users\\fengy\\Desktop\\io\\in.txt", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取   
    freopen("C:\\Users\\fengy\\Desktop\\io\\\\out.txt", "w", stdout); //输出重定向，输出数据将保存在out.txt文件中   
    vector<ListNode*> listTable;

    // Read data from text file.
    string line;
    for (int i = 0; i < lineCount && getline(cin, line); ++i) {
        istringstream iss(line);
        int number;
        ListNode* head = NULL;
        ListNode* cur = NULL;
        while (iss >> number) {
            ListNode* node = new ListNode(number);
            if (head == NULL)
                head = node;

            if (cur)
                cur->next = node;
            cur = node;
        }

        listTable.push_back(head);
    }

    return listTable;
}

void printList(vector<ListNode*> listTable) {
    for (int i = 0; i < listTable.size(); ++i) {
        ListNode* cur = listTable[i];
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
}

void releaseData() {
    fclose(stdin);         //关闭文件   
    fclose(stdout);        //关闭文件   
}

// *********************************************************************************************************
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 0)
            return head;

        ListNode guard(-1);
        guard.next = head;

        // Find the slow and fast pointer.
        int steps = k;
        ListNode* rear = head;
        ListNode* prev = &guard;
        ListNode* post = nullptr;
        while (head != nullptr) {
            while (--steps) {
                rear = rear->next;
                if (rear == nullptr)
                    return guard.next;
            }

            post = rear->next;
            reverseList(prev, post);
            prev = head;
            head = post;
            rear = post;
            steps = k;
        }

        return guard.next;
    }

private:
    // Return the new head the reversed list.
    void reverseList(ListNode* prev, ListNode* post) {
        if (prev == nullptr || prev->next == post)
            return;

        ListNode guard(-1);
        ListNode* head = prev->next;
        ListNode* cur = nullptr;
        ListNode* last = prev->next;
        while (head != post) {
            cur = head;
            head = head->next;

            cur->next = guard.next;
            guard.next = cur;
        }

        last->next = post;
        prev->next = guard.next;

        return;
    }
};

int main() {
    vector<ListNode*> list = initializeList();

    vector<ListNode*> result;
    Solution so;
    result.push_back(so.reverseKGroup(list[0], 2));
    printList(result);

    releaseData();
    return 0;
}