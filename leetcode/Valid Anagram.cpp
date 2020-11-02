#pragma warning(disable:4996)
#include <cstdio>
#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <list>
#include <stack>
#include <queue>
#include <unordered_Set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct RandomListNode {
    int label;
    RandomListNode* next, * random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode* left, * right, * next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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

// T:O(n), S:O(256)
class Solution {
public:
    bool isAnagram(string s, string t) {
        const int ls = s.size();
        const int lt = t.size();

        if (ls != lt)
            return false;

        const int ASCII = 256;
        vector<int> count_s(ASCII, 0);
        vector<int> count_t(ASCII, 0);
        for (int i = 0; i < ls; ++i) {
            count_s[s[i]]++;
            count_t[t[i]]++;
        }

        for (int i = 0; i < ASCII; ++i) {
            if (count_s[i] != count_t[i])
                return false;
        }

        return true;
    }
};

int main() {
    vector<vector<int>> v = initializeData(1);
    Solution so;

    releaseData();
    return 0;
}