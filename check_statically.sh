#!/bin/bash -e
IS_ANY_ERROR=false
COMMON_CHECKS=modernize-*,cppcoreguidelines-*,readability-*,bugprone-*,clang-analyzer-*,google-*,hicpp-*,misc-*,performance-*,portability-*
for FILE_TO_CHECK in $@
do
    printf "checking statically %s\n" ${FILE_TO_CHECK}
    if [[ ${FILE_TO_CHECK} == *"/tests.cpp" ]]; then
        MODIF=''',-cppcoreguidelines-owning-memory,-*-special-member-functions'''
    fi
    clang-tidy-7 -p build --quiet --warnings-as-errors=* -checks=${COMMON_CHECKS}${MODIF} ${FILE_TO_CHECK}
done
