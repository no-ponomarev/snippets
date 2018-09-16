#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>

using namespace std;

using pair_t = pair<short, short>;
using matrix_t = vector<vector<char>>;

bool dfs(int& dots, matrix_t& matrix, int i, int j, int rows, int cols) {
    stack<pair_t> s;

    s.push(pair_t{i, j});

    while (!s.empty()) {
        auto p = s.top();
        s.pop();
        auto x = p.first;
        auto y = p.second;

        if (matrix[x][y] == '#' || matrix[x][y] == '*') {
            continue;
        }

        --dots;
        matrix[x][y] = '*';

        if (x > 0) {
            s.push(pair_t{x - 1, y});
        }
        if (x < rows - 1) {
            s.push(pair_t{x + 1, y});
        }
        if (y > 0) {
            s.push(pair_t{x, y - 1});
        }
        if (y < cols - 1) {
            s.push(pair_t{x, y + 1});
        }
    }

    return dots == 0;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    matrix_t matrix;
    matrix.resize(rows);
    int dots = 0;
    for (auto& row : matrix) {
        row.reserve(cols);
        copy_n(istream_iterator<char>(cin), cols, back_inserter(row));
        for (auto& col : row) {
            if (col == '.') {++dots;}
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '.') {
                if (dfs(dots, matrix, i, j, rows, cols)) {
                    cout << "Yes";
                    return 0;
                }
                cout << "No";
                return 0;
            }
        }
    }
    return 0;
}
