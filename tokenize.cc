#include "cc2.hpp"

namespace cc2
{
    std::vector<Token> tokenize(const char *input)
    {
        Lexer *lex = new Lexer(input);
        std::vector<Token> tok = lex->tokenize();
        return tok;
    }

    std::vector<Token> Lexer::tokenize()
    {
        for (;;)
        {
            char cur_char = this->cur_char();

            // 数値
            if ('0' <= cur_char && cur_char <= '9')
            {
            }
        }
    }
    char Lexer::cur_char() const
    {
        char c = *(this->_input + this->_pos);
        return c;
    }
}
