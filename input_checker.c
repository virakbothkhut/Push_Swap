./push_swap abc def ghi
./push_swap 1 2 3 3
./push_swap 2147483648 1 2
./push_swap 1 2 3 4 5 x
./push_swap 1 2 3 4 5  ra   

./checker_linux 0 9 1 8 2 7 3 6 4 5
sa
pb
rrr
./checker_linux 3 1 4 2 5
sa
ra

./checker_linux 10 20 30 40 50
pb
ra
ra
sa
pb

./push_swap 42
./push_swap 0 1 2 3
./push_swap 0 1 2 3 4 5 6 7 8 9

ARG="2 1 0"; ./push_swap $ARG | ./checker $ARG

ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG

ARG="5 3 9 1 7"; ./push_swap $ARG | ./checker $ARG

ARG=$(shuf -i 1-100 -n 5 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG

