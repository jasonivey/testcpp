#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include <boost/filesystem.hpp>

using namespace std;

vector<string> GetFileNames(const string& p) {
    using namespace boost::filesystem;
    vector<string> filenames;
    try {
        transform(directory_iterator(p),
                  directory_iterator(),
                  back_inserter(filenames),
                  [&filenames](const directory_entry& entry) { return entry.path().string(); });
    } catch (const std::exception& ex) {
        cerr << "caught exception " << ex.what() << endl;
    }
    return filenames;
}

int main(int argc, char*argv[]) {
    if (argc < 2) {
        cerr << "ERROR: must pass a directory as an argument to the binary" << endl;
        return EXIT_FAILURE;
    }
    cout << "Finding all the files within directory: " << argv[1] << endl;
    const vector<string> &filenames = GetFileNames(argv[1]);
    copy(begin(filenames), end(filenames), ostream_iterator<string>(cout, "\n"));
    return EXIT_SUCCESS;
}
