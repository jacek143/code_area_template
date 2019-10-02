for CHECKED in $(find sources | grep '.cpp\|\.h')
do
    FORMATTED=$(mktemp)
    clang-format ${CHECKED} > ${FORMATTED}
    cp ${FORMATTED} ${CHECKED}
    rm ${FORMATTED}
done
