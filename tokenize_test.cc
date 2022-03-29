#include <cctest/cctest.h>
#include "cc2.hpp"

using namespace cc2;
int main()
{
    CC_TEST_START;
    {
        char *input = (char *)"0";
        Lexer *lex = new Lexer(input);
        ASSERT_INT("test cur_char()", '0', lex->cur_char());
    }
    CC_TEST_END;
}
