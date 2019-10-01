CHECKED=sources/prime_number/prime_number.cpp
FORMATTED=$(mktemp)
clang-format $CHECKED > $FORMATTED
RESULT=$(cmp $FORMATTED $CHECKED)

if test -z "$RESULT" 
then
      exit 0
else
      echo $RESULT
      exit 1
fi
