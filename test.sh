# ${1} flags variable with "-"
gcc /Users/hspeeder/Desktop/School_42/Ft_ls/*.c /Users/hspeeder/Desktop/School_42/Ft_ls/Libft/*.c
/Users/hspeeder/Desktop/School_42/Ft_ls/a.out ${1} > user.output
ls ${1} > system.output
diff -u system.output user.output
