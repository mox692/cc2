#include "cc2.hpp"
#include <vector>
#include <iostream>

namespace cc2
{
    bool Token::eq(const Token tok1, const Token tok2)
    {
        if (tok1.num_val == tok2.num_val &&
            tok1.kind == tok2.kind &&
            tok1.str_val == tok2.str_val)
        {

            return true;
        }
        return false;
    }

    std::vector<Token> tokenize(const char *input)
    {
        Lexer *lex = new Lexer(input);
        std::vector<Token> tok = lex->tokenize();
        return tok;
    }

    std::vector<Token> Lexer::tokenize()
    {
        std::vector<Token> token_vec;
        for (;;)
        {
            char cur_char = this->cur_char();

            // 数値
            if (is_numeric(cur_char))
            {
                // 数値部分を読む
                std::vector<char> num_str;
                do
                {
                    num_str.push_back(cur_char);
                    cur_char = this->next_char();

                } while (is_numeric(cur_char));
                std::string nstr(num_str.begin(), num_str.end());
                Token tok = Token(TokenKind::Num, atoi(nstr.c_str()));
                token_vec.push_back(tok);
            }

            if (is_eof(cur_char))
            {
                break;
            }
        }
        return token_vec;
    }
    char Lexer::next_char()
    {
        this->_pos++;
        return this->cur_char();
    }
    char Lexer::cur_char() const
    {
        char c = *(this->_input + this->_pos);
        return c;
    }
}
