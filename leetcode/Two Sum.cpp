#pragma warning(disable:4996)
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        const int n = nums.size();
        for (int i = 0; i < n;++i) {
            if (m.find(target - nums[i]) != m.end()) {
                return { m[target - nums[i]], i };
            }
            
            m[nums[i]] = i;
        }

        return {};
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
    vector<int> result = s.twoSum(v, 12);
    if (result.size() == 2) {
        cout << "first_index: " << result[0] << endl << "second_index: " << result[1] << endl;
    }
    else {
        cout << "no result" << endl;
    }

    fclose(stdin);//�ر��ļ�   
    fclose(stdout);//�ر��ļ�   
    return 0;
}