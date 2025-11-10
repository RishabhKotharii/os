echo "Enter the first number :-"
read a
echo "Enter the second number :-"
read b
echo "Enter your choice to perform :-
1) Add
2) Subs
3) Mul
4) Div "
read choice 
case $choice in 
1) echo "Result = `expr $a + $b`"
;;
2) echo "Result = `expr $a - $b`"
;;
3) echo "Result = `expr $a \* $b`"
;;
4) echo "Result = `echo " scale =2;$a/$b" | bc` "
esac 