#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <numeric>
#include <exception>
#include <optional>

using namespace std;
using namespace std::literals;

static void test() {
    //throw "here is the const char *";
    //throw "here is the const string &"s;
    //throw runtime_error("here is the std::runtime_error"s);
    //throw 123;
}

int main(int /*argc*/, char ** /*argv*/)
{
    cout << "__cplusplus: " << __cplusplus << endl;
#if 0
    if (argc <= 1) {
        printf("usage: %s number ...\n", *argv);
        return EXIT_FAILURE;
    }
#endif

    try {
        test();
    } catch (const exception &ex) {
        cerr << "caught std::exception: " << ex.what() << endl;
    } catch (const char *msg) {
        cerr << "caught const char * exception: " << msg << endl;
    } catch (const string &msg) {
        cerr << "caught const string & exception: " << msg << endl;
    } catch (...) {
        cerr << "caught some random crap!" << endl;
    }

    return EXIT_SUCCESS;
}

