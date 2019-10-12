# ${1} flags variable with "-"
# ${2} file variables
gcc *.c Libft/*.c
rm -f user.output
if [[ -n ${1} && ${1} = "-c" ]]; then
  echo "compile"
elif [[ -n ${1} && -z ${2} ]]; then
  ./a.out ${1} 1>>user.output
  ls ${1} 1>system.output
elif [[ -n ${2} && -n ${1} ]]; then
  ./a.out ${1} ${2} 1>>user.output
  ls ${1} ${2} 1>system.output
elif [[ -n ${2} && -z ${1} ]]; then
  ./a.out ${2} 1>>user.output
  ls ${2} 1>system.output
else
  ./a.out > user.output
  ls > system.output
fi
if ! [[ -n ${1} && ${1} = "-c" ]]; then
  diff -u system.output user.output
fi
