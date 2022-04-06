#include <cctest/cctest.h>
#include "cc2.hpp"

using namespace cc2;
int main()
{
    CC_TEST_START;

    // test Lexer.tokenize()
    {
        const char *test_input = "333";
        Lexer *lex = new Lexer(test_input);
        std::vector<Token> tok_vec = lex->tokenize();
        std::vector<Token> expect = std::vector<Token>{Token(TokenKind::Num, 333)};
        if (tok_vec.size() != expect.size())
        {
            fprintf(stderr, "ERR\n");
        }

        for (int i = 0; i < tok_vec.size(); i++)
        {
            EQ("get_input() test", tok_vec.at(i), expect.at(i));
        }
    }

    CC_TEST_END;
}
