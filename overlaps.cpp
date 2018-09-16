// https://stackoverflow.com/questions/2244964/finding-number-of-overlaps-in-a-list-of-time-ranges
// https://en.wikipedia.org/wiki/Sweep_line_algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

using matrix_t = vector<vector<int>>;

struct stime_t
{
    int value;
    bool isStart;
};

int main() {
    int rows, cols;
    cin >> rows;
    cols = 2;

    matrix_t matrix;
    matrix.resize(rows);

    for (auto& row : matrix) {
        row.reserve(cols);
        copy_n(istream_iterator<int>(cin), cols, back_inserter(row));
    }

    vector<stime_t> session;
    session.reserve(rows*cols);

    for (int i = 0; i < rows; i++) {
        session.push_back(stime_t{matrix[i][0], true});
        session.push_back(stime_t{matrix[i][1], false});
    }

    int max_value = 0;
    int current_value = 0;

    sort(session.begin(), session.end(), [](stime_t a, stime_t b){
        return a.value <= b.value;
    });

    for (auto& time : session) {
        if (time.isStart) ++current_value;
        else --current_value;
        max_value = max(current_value, max_value);
    }

    cout << max_value << endl;

    return 0;
}
