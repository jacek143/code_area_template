./cmake.sh

for FILE_TO_CHECK in $(find sources | grep '.cpp')
do
    if [[ ${FILE_TO_CHECK} == *"/tests.cpp" ]]; then
        MODIF=''',-cppcoreguidelines-owning-memory,-cppcoreguidelines-special-member-functions'''
    fi
    clang-tidy -p build -checks=cppcoreguidelines-*${MODIF} ${FILE_TO_CHECK}
done
