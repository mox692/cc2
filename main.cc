#include "cc2.hpp"
#include <stdio.h>
#include <iostream>

using namespace cc2;
using namespace std;

int main(int argc, const char **argv)
{
    const char *input = get_input(argc, argv);
    printf("input is %s\n", input);

    vector<Token> tokens = tokenize(input);

    vector<Node> nodes = parse(tokens);

    code_gen(nodes);
}
