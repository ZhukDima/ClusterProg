SOURCES_DIRS="./include ./src ./test/main.cpp"

cpplint --headers="h" --linelength=120 --filter="-whitespace/tab" --filter="-runtime/int" --filter="-legal/copyright" --filter="-build/include_subdir" --filter="-build/include" --filter="-readability/casting" --filter="-legal/copyright" --repository=./ --root=./ --recursive $SOURCES_DIRS
cppcheck $SOURCES_DIRS
