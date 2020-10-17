#pragma warning(disable:4996)
#include <cstdio>
#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        while (min <= max) {
            int mid = min + (max - min) / 2;
            if (target == nums[mid]) {
                return mid;
            }

            // [mid, max] increase.
            if (nums[mid] < nums[max]) {
                if (target > nums[mid] && target <= nums[max]) {
                    min = mid + 1;
                }
                else {
                    max = mid - 1;
                }
            }
            // [min, mid] increase.
            else {
                if (target >= nums[min] && target < nums[mid]) {
                    max = mid - 1;
                }
                else {
                    min = mid + 1;
                }
            }
        }

        return -1;
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
    int index = so.search(v[0], 7);
    cout << index << endl;

    releaseData();
    return 0;
}