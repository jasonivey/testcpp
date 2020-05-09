// vim: awa:sts=4:ts=4:sw=4:et:cin:fdm=manual:tw=120:ft=cpp
// autowriteall, softtabstop, tabstop, shiftwidth, expandtab, cindent, foldmethod, textwidth, filetype

#if 0
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
#else

#include <boost/version.hpp>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cstdlib>

using namespace std;

int main(int argc, const char **argv) {
    cout << "Input arguments:\n";
    size_t count = 0;
    for_each(argv, argv + argc, [&count](const char *arg) {
        cout << "arg " << (++count) << ": " << arg << endl;
    });
    cout << "BOOST VERSON: " << BOOST_LIB_VERSION << endl;
    return EXIT_SUCCESS;
}
#endif
