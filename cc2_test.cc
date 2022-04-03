#include <cctest/cctest.h>
#include "cc2.hpp"

using namespace cc2;
int main()
{
    CC_TEST_START;
    // test get_input()
    {
        const char *testinput[2];
        const char *input_str = "int main() {return 3;}";
        testinput[1] = input_str;
        const char *res = get_input(2, testinput);
        ASSERT_STR("get_input() test", res, testinput[1]);
    }
    CC_TEST_END;
}
