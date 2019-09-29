./cmake.sh
clang-tidy -p build -checks=cppcoreguidelines-* -line-filter="$(< .lintignore)" sources/*/*.cpp
