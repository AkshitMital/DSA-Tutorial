#include <iostream>
#include <vector>
#include <utility>
#include<stack>

using namespace std;

class Solution {
private:
    int solve(vector<int>& heights){
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            int l = i, r = i;
            while(l > 0 && heights[l-1] >= heights[i]){
                l--;
            }
            while(r < heights.size() - 1 && heights[r+1] >= heights[i]){
                r++;
            }
            int width = r - l + 1;
            int area = width * heights[i];
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows == 0) return 0;
        vector<int> heights(cols, 0);
        int maxArea = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            int area = solve(heights);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    Solution solution;
    int maxArea = solution.maximalRectangle(matrix);

    cout << "Maximal Rectangle Area: " << maxArea << endl;

    return 0;
}