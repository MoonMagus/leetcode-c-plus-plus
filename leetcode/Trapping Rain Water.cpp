#pragma warning(disable:4996)
#include <cstdio>
#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// T:O(n), S:O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int peak = 0;
        for (int i = 0; i < n; ++i) {
            if (height[i] > height[peak])
                peak = i;
        }

        int water = 0;
        for (int i = 0, left = 0; i < peak; ++i) {
            left = max(left, height[i]);
            water += left - height[i];
        }

        for (int i = n - 1, right = 0; i > peak; --i) {
            right = max(right, height[i]);
            water += right - height[i];
        }

        return water;
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
    vector<vector<int>> v = initializeData();

    Solution so;
    cout << so.trap(v[0]) << endl;

    releaseData();
    return 0;
}