#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <string.h>
#include "parser.h"

Test(test_parser, arg_number){
    char input[] = "ls -l -a";

    cr_assert(eq(int, arg_parser(input).args_count, 3));
}