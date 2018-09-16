#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int length; cin >> length;
    vector<int> sequence; sequence.reserve(length);
    copy_n(istream_iterator<int>(cin), length, back_inserter(sequence));

    int sum = 0;
    for (auto& n : sequence) sum += n;

    for (auto& i : sequence) {
        int remain = sum - i;
        if (remain <= i) { 
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;

    return 0;
}
