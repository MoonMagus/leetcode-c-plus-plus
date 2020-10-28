#pragma warning(disable:4996)
#include <cstdio>
#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// T:O(mn), extra S:O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const size_t m = matrix.size();
        if (m == 0)
            return;
        const size_t n = matrix[0].size();
        bool row_has_zero = false;
        bool col_has_zero = false;
        // Check whether first row has zero.
        for (size_t j = 0; j < n; ++j)
            if (matrix[0][j] == 0) {
                row_has_zero = true;
                break;
            }

        // Check whether first col has zero.
        for (size_t i = 0; i < m; ++i)
            if (matrix[i][0] == 0) {
                col_has_zero = true;
                break;
            }

        // Save statistics on the first row and column.
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix zeros based on the first row and colmn.
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Set the first row and column based on row_has_zero and col_has_zero.
        if (row_has_zero) {
            for (size_t i = 0; i < n; ++i)
                matrix[0][i] = 0;
        }

        if (col_has_zero) {
            for (size_t j = 0; j < m; ++j)
                matrix[j][0] = 0;
        }
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

    releaseData();
    return 0;
}