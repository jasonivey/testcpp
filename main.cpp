#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int, char**)
{
    auto vec = vector<int>{1, 2, 3, 4};
    vector<string> vec1 = {"hello", "world", "this", "is", "a", "sentence"};
    std::for_each(vec.begin(), vec.end(), [](int &x){cout << ++x << endl;});
    //foreach(vec.begin(), vec.end(), (
    copy(begin(vec), end(vec), ostream_iterator<int>(cout, ", "));
    cout << endl;
    copy(cbegin(vec1), cend(vec1), ostream_iterator<string>(cout, " "));
    cout << endl;
    
    cout << "\nhello world\n";     
    return EXIT_SUCCESS;
}
