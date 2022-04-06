#include <string>
#include <vector>

#ifndef PANIC
#define PANIC(...) (                          \
    {                                         \
        printf(__VA_ARGS__);                  \
        printf("Program exit with status 1"); \
        exit(1);                              \
    })
#else
#error panic is already defined
#endif

namespace cc2
{

    enum TokenKind
    {
        Num, // 0
    };

    class Token
    {
    public:
        Token(TokenKind kind, int num_val) : kind(kind), num_val(num_val){};
        Token(TokenKind kind, std::string str_val) : kind(kind), str_val(str_val){};

        static bool eq(const Token, const Token);

        TokenKind kind;
        int num_val;
        std::string str_val;

    private:
    };

    std::vector<Token> tokenize(const char *);

    class Lexer
    {
    public:
        Lexer(const char *input) : _input(input), _pos(0), _token_vec({})
        {
        }
        std::vector<Token> tokenize();
        char cur_char() const;
        char next_char();

    private:
        const char *_input;
        int _pos;
        std::vector<Token> _token_vec;
    };

    class Node
    {
        Node();
    };
    std::vector<Node> parse(std::vector<Token>);

    void code_gen(std::vector<Node>);

    // utility functions
    inline const char *get_input(int argc, const char **argv)
    {
        if (argc < 2)
        {
            PANIC("invalid input, argc: %d", argc);
        }

        // check that input has EOF.
        for (const char *pos = argv[1]; *pos != '\0'; pos = pos + 1)
        {
        }

        return argv[1];
    }

    inline bool is_numeric(char c)
    {
        if ('0' <= c && c <= '9')
            return true;
        return false;
    }
    inline bool is_eof(char c)
    {
        if (c == '\0')
            return true;
        return false;
    }
}
