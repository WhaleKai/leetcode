#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include "string"

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int result = 0;
    int right = -1;
    unordered_set<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp.erase(s[i - 1]);
        while (right != n - 1 && !temp.count(s[right + 1]))
        {
            right++;
            temp.insert(s[right]);
        }
        result = max(result, right - i + 1);
        }
        return result;
    }

int main()
{
    string arr = "abcabcbb";
    cout << lengthOfLongestSubstring(arr);

    return 0;
}