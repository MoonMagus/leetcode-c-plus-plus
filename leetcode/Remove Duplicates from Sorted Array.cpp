#pragma warning(disable:4996)
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        const int n = nums.size();
        int index = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[index] != nums[i]) {
                nums[++index] = nums[i];
            }
        }

        return index + 1;
    }
};


int main() {
    freopen("C:\\Users\\fengy\\Desktop\\io\\in.txt", "r", stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ   
    freopen("C:\\Users\\fengy\\Desktop\\io\\\\out.txt", "w", stdout); //����ض���������ݽ�������out.txt�ļ���   

    int a;
    vector<int> v;
    while (cin >> a) {
        v.push_back(a);
    }

    Solution s;
    int result = s.removeDuplicates(v);
    cout << result << endl;
    for (int i = 0; i < result; ++i)
        cout << v[i] << " ";
    cout << endl;

    fclose(stdin);//�ر��ļ�   
    fclose(stdout);//�ر��ļ�   
    return 0;
}