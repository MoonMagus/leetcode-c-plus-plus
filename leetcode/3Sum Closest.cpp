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
    int threeSumClosest(vector<int>& nums, int target) {
        int l = nums.size();
        int r = 0;
        int min_gap = INT_MAX;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < l - 2; ++i) {
            int j = i + 1;
            int k = l - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int gap = abs(sum - target);
                if (gap < min_gap) {
                    min_gap = gap;
                    r = sum;
                }

                if (sum < target)
                    ++j;
                else if (sum > target)
                    --k;
                else
                    return target;
            }
        }

        return r;
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
    int sum = so.threeSumClosest(v[0], 1);
    cout << sum << endl;

    releaseData();
    return 0;
}