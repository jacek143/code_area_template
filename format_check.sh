IS_ANY_DIFF=false
for CHECKED in $(find sources | grep '.cpp\|\.h')
do
    FORMATTED=$(mktemp)
    clang-format ${CHECKED} > ${FORMATTED}
    DIFF=$(diff --unified --label formatted ${FORMATTED} --label ${CHECKED} ${CHECKED})
    if !(test -z "${DIFF}")
    then
        IS_ANY_DIFF=true
        printf '%s\n' "${DIFF[@]}"
    fi
    rm ${FORMATTED}
done

if (${IS_ANY_DIFF})
then 
    exit 1
fi
