#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &mat, vector<string> &ans, int row, int col, string path)
{
    int n = mat.size();

    if (row < 0 || col < 0 || row >= n || col >= n || mat[row][col] == 0 || mat[row][col] == -1)
    {
        return;
    }

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    mat[row][col] = -1;

    helper(mat, ans, row + 1, col, path + "D");
    helper(mat, ans, row - 1, col, path + "U");
    helper(mat, ans, row, col + 1, path + "R");
    helper(mat, ans, row, col - 1, path + "L");

    mat[row][col] = 1;
}

vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> ans;
    string path = "";
    helper(mat, ans, 0, 0, path);

    return ans;
}
int main()
{

    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};
    vector<string> ans = findPath(mat);
    if (ans.empty())
    {
        cout << "No path found" << endl;
    }
    else
    {
        for (string path : ans)
        {
            cout << path << endl;
        }
    }

    return 0;
}