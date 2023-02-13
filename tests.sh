echo "+000000001" "5" "3" "-5"
./push_swap "+000000001" "5" "3" "-5" | ./checker "+000000001" "5" "3" "-5" #== true
echo "+ 000000001" "5" "3" "-5"
./push_swap "+ 000000001" "5" "3" "-5" | ./checker "+ 000000001" "5" "3" "-5" #== false
echo "+52"
./push_swap "+52" | ./checker "+52" #== true
echo "+52" "-5"
./push_swap "+52" "-5" | ./checker "+52" "-5" #== true
echo "52"
./push_swap "52" | ./checker "52" #== true
echo ""
./push_swap "" | ./checker "" #== false
echo " "
./push_swap " " | ./checker " " #== false
echo "  "
./push_swap "  " | ./checker "  " #== false
echo "5" "4" "3"
./push_swap "5" "4" "3" | ./checker "5" "4" "3" #== true
echo "5" "1" "0" "2"
./push_swap "5" "1" "0" "2" | ./checker "5" "1" "0" "2" #== true
echo "5 1 + 000000 2"
./push_swap "5 1 + 000000 2" | ./checker "5 1 + 000000 2" #== false
echo "5" "" "0" "2"
./push_swap "5" "" "0" "2" | ./checker "5" "" "0" "2" #== false
echo "5 4A 3"
./push_swap "5 4A 3" | ./checker "5 4A 3" #== false
echo "5 2 3 4 8"
./push_swap "5 2 3 4 8" | ./checker "5 2 3 4 8" #== true
echo "42 -500 -2845 -21 54784 1541"
./push_swap "42 -500 -2845 -21 54784 1541" | ./checker "42 -500 -2845 -21 54784 1541" #== true
echo "42" "500" "-2845" "-21" " 54784" "1541"
./push_swap "42" "500" "-2845" "-21" " 54784" "1541" | ./checker "42" "500" "-2845" "-21" " 54784" "1541" #== true
echo "52 14 15"
./push_swap "52 14 15" | ./checker "52 14 15" #== true
echo "e1 2 3 4 5"
./push_swap "e1 2 3 4 5" | ./checker "e1 2 3 4 5" #== false
echo "1 2 4 3 5e"
./push_swap "1 2 4 3 5e" | ./checker "1 2 4 3 5e" #== false
echo "1 2 3 4 5e"
./push_swap "1 2 3 4 5e" | ./checker "1 2 3 4 5e" #== false
echo "+" "52"
./push_swap "+" "52" | ./checker "+" "52" #== false
echo "1 2 3"
./push_swap "1 2 3" | ./checker "1 2 3" #== true
echo " 1 2 3"
./push_swap " 1 2 3" | ./checker " 1 2 3" #== true
echo "1 2 3 "
./push_swap "1 2 3 " | ./checker "1 2 3 " #== true
echo " 1 2 3 "
./push_swap " 1 2 3 " | ./checker " 1 2 3 " #== true
echo " 1   2               3 "
./push_swap " 1   2               3 " | ./checker " 1   2               3 " #== true
echo "1 2 3 4 5"
./push_swap "1 2 3 4 5" | ./checker "1 2 3 4 5" #== true
echo "5 4 3 2 1"
./push_swap "5 4 3 2 1" | ./checker "5 4 3 2 1" #== true
echo "5" "3" "2" "1"
./push_swap "5" "3" "2" "1" | ./checker "5" "3" "2" "1" #== true
echo " 5" "3  " " 2" " 1"
./push_swap " 5" "3  " " 2" " 1" | ./checker " 5" "3  " " 2" " 1" #== true
echo "4" "000000000000000000000000000000000000000000000000000000002"
./push_swap "4" "000000000000000000000000000000000000000000000000000000002" | ./checker "4" "000000000000000000000000000000000000000000000000000000002" #== true
echo " 5" "8"
./push_swap " 5" "8" | ./checker " 5" "8" #== true
echo "05 02"
./push_swap "05 02" | ./checker "05 02" #== true
echo "2147483647 -2147483648"
./push_swap "2147483647 -2147483648" | ./checker "2147483647 -2147483648" #== true
echo "0002147483647 -002147483648"
./push_swap "0002147483647 -002147483648" | ./checker "0002147483647 -002147483648" #== true
echo "05 08 0009 00010 2"
./push_swap "05 08 0009 00010 2" | ./checker "05 08 0009 00010 2" #== true
echo "05 5 005"
./push_swap "05 5 005" | ./checker "05 5 005" #== false
echo "-00" "00"
./push_swap "-00" "00" | ./checker "-00" "00" #== false
echo "052 02"
./push_swap "052 02" | ./checker "052 02" #== true
echo "-0" "0"
./push_swap "-0" "0" | ./checker "-0" "0" #== false
echo "0" "-0"
./push_swap "0" "-0" | ./checker "0" "-0" #== false
echo "-10" "-23"
./push_swap "-10" "-23" | ./checker "-10" "-23" #== true
echo "-0"
./push_swap "-0" | ./checker "-0" #== true
echo "4 2 3" "5"
./push_swap "4 2 3" "5" | ./checker "4 2 3" "5" #== true
echo "5" "4" "3"
./push_swap "5" "4" "3" | ./checker "5" "4" "3" #== true
echo "10 5 4 2 1 3 6 9"
./push_swap "10 5 4 2 1 3 6 9" | ./checker "10 5 4 2 1 3 6 9" #== true
echo "5-2"
./push_swap "5-2" | ./checker "5-2" #== false
echo "5+2"
./push_swap "5+2" | ./checker "5+2" #== false
echo "2-5"
./push_swap "2-5" | ./checker "2-5" #== false
echo "2+5"
./push_swap "2+5" | ./checker "2+5" #== false
echo "2" "" "3"
./push_swap "2" "" "3" | ./checker "2" "" "3" #== false
echo "3" "" "2"
./push_swap "3" "" "2" | ./checker "3" "" "2" #== false
echo "" ""
./push_swap "" "" | ./checker "" "" #== false
echo "" " "
./push_swap "" " " | ./checker "" " " #== false
echo " " ""
./push_swap " " "" | ./checker " " "" #== false
echo "   " " " "   "
./push_swap "   " " " "   " | ./checker "   " " " "   " #== false
echo "   " "-" "   "
./push_swap "   " "-" "   " | ./checker "   " "-" "   " #== false
echo "   " "-a" "   "
./push_swap "   " "-a" "   " | ./checker "   " "-a" "   " #== false
echo "   -a   "
./push_swap "   -a   " | ./checker "   -a   " #== false
echo "++52"
./push_swap "++52" | ./checker "++52" #== false
echo "+-52"
./push_swap "+-52" | ./checker "+-52" #== false
echo "9 2147483648 5"
./push_swap "9 2147483648 5" | ./checker "9 2147483648 5" #== false
echo "9 -2147483649 8"
./push_swap "9 -2147483649 8" | ./checker "9 -2147483649 8" #== false
echo "9 214748364842 5"
./push_swap "9 214748364842 5" | ./checker "9 214748364842 5" #== false
echo "9 -21474836494 8"
./push_swap "9 -21474836494 8" | ./checker "9 -21474836494 8" #== false
echo "8 -214748364945465565656"
./push_swap "8 -214748364945465565656" | ./checker "8 -214748364945465565656" #== false
echo "25 514748364945465565656"
./push_swap "25 514748364945465565656" | ./checker "25 514748364945465565656" #== false
echo "4" "999999999999999"
./push_swap "4" "999999999999999" | ./checker "4" "999999999999999" #== false
echo "12          "
./push_swap "12          " | ./checker "12          " #== true
echo "454845456689864" "5455464454545"
./push_swap "454845456689864" "5455464454545" | ./checker "454845456689864" "5455464454545" #== false
