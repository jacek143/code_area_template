#!/bin/bash
IS_ANY_ERROR=false
COMMON_CHECKS=modernize-*,cppcoreguidelines-*,readability-*,bugprone-*,clang-analyzer-*,google-*,hicpp-*,misc-*,performance-*
for FILE_TO_CHECK in $@
do
    printf "checking statically %s\n" ${FILE_TO_CHECK}
    if [[ ${FILE_TO_CHECK} == *"/tests.cpp" ]]; then
        MODIF=''',-cppcoreguidelines-owning-memory,-*-special-member-functions'''
    fi
    ERROR_LOG=$(clang-tidy -p build --quiet --warnings-as-errors=* -checks=${COMMON_CHECKS}${MODIF} ${FILE_TO_CHECK} 2>/dev/null)
    if !(test -z "${ERROR_LOG}")
    then
        IS_ANY_ERROR=true
        printf '%s\n' "${ERROR_LOG[@]}"
    fi
done

if (${IS_ANY_ERROR})
then 
    exit 1
fi
