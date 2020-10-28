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

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();

        vector<int> allocated(n);
        // Scan from left to right to find the initial allocation.
        for (int i = 1, inc = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                allocated[i] = max(inc++, allocated[i]);
            else
                inc = 1;
        }

        // Scan from right to left to update the allocation.
        for (int j = n - 2, inc = 1; j >= 0; --j) {
            if (ratings[j] > ratings[j + 1])
                allocated[j] = max(inc++, allocated[j]);
            else
                inc = 1;
        }

        return accumulate(&allocated[0], &allocated[0] + n, n);
    }
};

vector<vector<int>> initializeData(int lineCount = 1) {
    freopen("C:\\Users\\fengy\\Desktop\\io\\in.txt", "r", stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ   
    freopen("C:\\Users\\fengy\\Desktop\\io\\\\out.txt", "w", stdout); //����ض���������ݽ�������out.txt�ļ���   
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

void releaseData() {
    fclose(stdin);         //�ر��ļ�   
    fclose(stdout);        //�ر��ļ�   
}

void printData(vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>>& v = initializeData();

    Solution so;
    cout << so.candy(v[0]) << endl;

    releaseData();
    return 0;
}