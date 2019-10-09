# ${1} flags variable with "-"
# ${2} file variables
gcc *.c Libft/*.c
if [[ -n ${1} && -z ${2} ]]; then
  ./a.out ${1} > user.output
  ls ${1} > system.output
elif [[ -n ${2} && -n ${1} ]]; then
  ./a.out ${1} ${2} > user.output
  ls ${1} ${2} > system.output
elif [[ -n ${2} && -z ${1} ]]; then
  ./a.out ${2} > user.output
  ls ${2} > system.output
else
  ./a.out > user.output
  ls > system.output
fi
diff -u system.output user.output
