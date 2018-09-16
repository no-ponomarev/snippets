/* https://marcoarena.wordpress.com/2016/03/13/cpp-competitive-programming-io/ */

// 1. Lonely values

int N, M;
cin >> N >> M;

// 2. Read a sequence of numbers, length of the sequence is passed just before

int length; cin >> length;
vector<int> sequence; sequence.reserve(length);
copy_n(istream_iterator<int>(cin), length, back_inserter(sequence));

// 3. Matrix into a vector of vectors

int rows, cols; cin >> rows >> cols; 
vector<vector<int>> matrix; matrix.resize(rows); 
for (auto& row : matrix)
{    
   row.reserve(cols); 
   copy_n(istream_iterator<int>(cin), cols, back_inserter(row)); 
}

// 4. Get line (ws discards EOL delimiter)

cin >> N >> std::ws;
getline(cin, line);

// 5. Complet tests input
// N T
// a1 a2 ... aN
// t1
// t2
// ...
// tT

int N, T, t; cin >> N >> T;
vector<int> arr; arr.reserve(N);
copy_n(istream_iterator<int>(cin), N, back_inserter(arr));
// pre-process here
while (T--) 
{
  cin >> t;
  // solve here
}


// Output

// 1. Simple 
cout << ans1 << " " << ans2 << "\n";

// 2. Sequence like vector

copy(begin(v), end(v), ostream_iterator<int>(cout)); // default separator is ' '

// or

copy(begin(v), end(v)-1, ostream_iterator<int>(cout, ',')); // all but last
cout << v.back(); // last
