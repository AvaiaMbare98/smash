#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <string.h>
#include "parser.h"

Test(test_parser, arg_number){
    char input[] = "ls -l -a";
    tokenized_line tok_line = arg_parser(input);

    cr_assert(eq(int, tok_line.num, 3));

    strcpy(input, "cd /..");
    tok_line = arg_parser(input);

    cr_assert(eq(int, tok_line.num, 2));
}

Test(test_parser, empty_string){
    char input[] = "";
    tokenized_line tok_line = arg_parser(input);

    cr_assert(eq(int, tok_line.num, 0));
}

Test(test_parser, empty_spaces){
    char input[] = "      ls        -l      a      ";
    tokenized_line tok_line = arg_parser(input);

    cr_assert(eq(int, tok_line.num, 3));
    cr_assert(eq(str, tok_line.args[0], "ls"));
    cr_assert(eq(str, tok_line.args[1], "-l"));
    cr_assert(eq(str, tok_line.args[2], "a"));
}

Test(test_parser, memory_test){
    char input[] = "Di a da in con su per tra fra sbo";
    tokenized_line tok_line = arg_parser(input);

    cr_assert(eq(int, tok_line.num, 10));
}