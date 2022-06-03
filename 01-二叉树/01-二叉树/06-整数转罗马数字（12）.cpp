#include<iostream>
using namespace std;
/*
	整数转罗马数字：
		先建立键值对：
			const pair<int, string> valueSymbols[] = {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"},
                str ans = "";
        然后从上往下开始遍历键值对：(for(const auto& [n, str] : valueSymbols))
            while(num > n){
                ans += str;
                num -= n;
            }
            直到(num==0){
                break;
            }
};
*/