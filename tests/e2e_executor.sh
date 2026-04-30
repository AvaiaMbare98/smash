#!/bin/bash

##### Declarations

# Color codes for terminal output
GREEN='\e[32m'
RED='\e[31m'
DEF='\e[0m'
failed_tests=0 # Failed tests counter

##### Functions

run_test() {

    # Little note to future self: "local" is used to declare 
    # a variable with local scope. I know, it's pretty obvious,
    # but coming from C I thought that a variable declared inside the function
    # automatically had local scope. Good to know!
    local test_name="$1"
    local command="$2"

    local expected=$(eval "$command")
    local actual=$(echo "$command" | ../smash)

    if [[ "$actual" != *"$expected"* ]]; then
        ((failed_tests++))
        echo -e ${RED}[FAIL]${DEF}" $test_name" 
        echo "    -> Command : $command"
        echo "    -> Expected : '$expected'"
        echo "    -> Actual : '$actual'"
    else
        echo -e ${GREEN}[PASS]${DEF}" $test_name"
    fi
}

##### Main

run_test "BASE - Print working directory" "pwd"

if [ $failed_tests -gt 0 ]; then # -gtis equivalent to ">" in C
    echo "$failed_tests tests failed."
    exit 1
else
    echo "All tests passed."
    exit 0
fi