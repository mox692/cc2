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

    class Token
    {
        Token();
    };
    std::vector<Token> tokenize(char *);

    class Lexer
    {
    public:
        Lexer(char *input) : _input(input), _pos(0), _token_vec({})
        {
        }
        std::vector<Token> tokenize();
        char cur_char() const;

    private:
        char *_input;
        int _pos;
        std::vector<Token> _token_vec;
    };

    class Node
    {
        Node();
    };
    std::vector<Node> parse(std::vector<Token>);

    void code_gen(std::vector<Node>);

    inline char *get_input(int argc, char **argv)
    {
        if (argc < 2)
        {
            PANIC("invalid input, argc: %d", argc);
        }
        return argv[1];
    }

}
