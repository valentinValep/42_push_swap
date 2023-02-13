make
valgrind ./push_swap "2 	1 3 6 5 8"
echo "NEXT"
./push_swap "5 2 3 4 8" | ./checker "5 2 	3 4 8" #== true
