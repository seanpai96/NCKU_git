FILENAME="$1"
echo "gcc -o ${FILENAME%.*} $1 -Lm"
gcc -o "${FILENAME%.*}" "$1" -Lm
./"${FILENAME%.*}"
