#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //计算字符串中每个字符的个数
    void helper(string s, unordered_map<char, int>& num) {
        for (int i = 0; i < s.length(); i++) {
            num[s[i]]++;
        }
    }
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> sNum;
        unordered_map<char, int> tNum;
        helper(s, sNum);
        helper(t, tNum);
        for(auto&[ch, num] : sNum){
            if(num != tNum[ch]){
                return false;
            }
        }
        return true;
    }
};