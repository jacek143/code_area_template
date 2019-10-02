./cmake.sh

IS_ANY_ERROR=false
for FILE_TO_CHECK in $(find sources | grep '.cpp')
do
    if [[ ${FILE_TO_CHECK} == *"/tests.cpp" ]]; then
        MODIF=''',-cppcoreguidelines-owning-memory,-cppcoreguidelines-special-member-functions'''
    fi
    ERROR_LOG=$(clang-tidy -p build --quiet --warnings-as-errors=* -checks=cppcoreguidelines-*${MODIF} ${FILE_TO_CHECK})
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
