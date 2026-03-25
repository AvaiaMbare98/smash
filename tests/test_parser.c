#include <stdio.h>
#include <criterion/criterion.h>
#include <string.h>

Test(test_parser, test){
    cr_assert(strlen("") == 0);
}