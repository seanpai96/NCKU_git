FILENAME="$1"
gcc -o "${FILENAME%.*}" "$1" -lm
./"${FILENAME%.*}"
