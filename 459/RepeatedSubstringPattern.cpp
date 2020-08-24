#include <iostream>
#include <string>

class Solution {
public:
  bool repeatedSubstringPattern(std::string s) {
    return (s + s).find(s, 1) != s.size();
  }
};
 
int main () {
  Solution s;
  bool r = s.repeatedSubstringPattern("aabbaabb");
  std::cout << std::boolalpha << r << std::endl;
}
