#pragma warning(disable:4996)
#include <cstdio>
#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find the first increase num from back.
        const int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the first larger num from back.
        for (int j = n - 1; j >= i; j--) {
            if (nums[j] > nums[i]) {
                int t = nums[j];
                nums[j] = nums[i];
                nums[i] = t;
                break;
            }
        }

        // Reverse [pivot + 1, n - 1].
        reverse(nums.begin() + i + 1, nums.end());
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
    so.nextPermutation(v[0]);
    printData(v);

    releaseData();
    return 0;
}