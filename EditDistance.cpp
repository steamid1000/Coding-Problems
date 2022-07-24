/* Hi, here's your problem today. This problem was recently asked by AirBNB:

Given two strings, determine the edit distance between them. The edit distance is defined as the minimum number of edits (insertion, deletion, or substitution) needed to change one string to the other.

For example, "biting" and "sitting" have an edit distance of 2 (substitute b for s, and insert a t).

*/
#include "bits/stdc++.h"
using namespace std;

#define ln length()
void editdistance(std::string s1, std::string s2)
{
    if (s1.ln == s2.ln)
    { // if the lengths are same
        int count = 0;
        for (int i = 0; i < s1.ln; i++)
        {
            if (s1[i] != s2[i])
            {
                count++;
            }
        }

        std::cout << count << '\n';
    }
    else
    { //if the lengths are different then comes the tricky part
        // std::cout << "Lengths are different and the solution is in the making\n";
        std::unordered_map<char, int> occurence_s1;
        std::unordered_map<char, int> occurence_s2;

        int i; //common index element

        for (i = 0; i < s1.ln; i++) // for the occurence of in the s1 string
        {
            if (occurence_s1.find(s1[i]) == occurence_s1.end())
            {
                occurence_s1.insert(std::make_pair(s1[i], 1));
            }
            else
            {
                occurence_s1[s1[i]]++;
            }
        }

        for (i = 0; i < s2.ln; i++)
        {
            if (occurence_s2.find(s2[i]) == occurence_s2.end())
            {
                occurence_s2.insert(std::make_pair(s2[i], 1));
            }
            else
            {
                occurence_s2[s2[i]]++;
            }
        }

        int same = 0; //will how many are same and how many are different
        int diff = 0;

        for (int i = 0; i < std::min(s1.ln, s2.ln); i++)
        {
            if (occurence_s1[s1[i]] == occurence_s2[s1[i]])
            {
                same++;
            }
            else
            {
                diff++;
            }
        }

        std::cout << "Same: " << same << " diff: " << diff << "\n";

        /*below is the experimental printing of maps
        for (auto &it : occurence_s1)
        {
            std::cout << it.first << ' ' << it.second << '\n';
        }
        std::cout << "\n";
         for (auto &it : occurence_s2)
        {
            std::cout << it.first << ' ' << it.second << '\n';
        }
        */
    }
}

int mindistedit(std::string s1, std::string s2)
{
    int mine = 0;
    for (size_t i = 0; i < s1.ln; i++)
    {
        if (s1[i]!=s2[i])
        {
            mine++;
            s2[i]+=s1[i];
        }
        
    }
    std::cout<<s2<<"\n";
    return mine;
}

//someone else's solution
/*class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        const int m = word1.length();
        const int n = word2.length();
        // dp[i][j] := min # of operations to convert word1[0..i) to word2[0..j)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};*/

int editDistance(string X,string Y){
  int n=X.length();
  int m=Y.length();
  int ed[n+1][m+1];
  // to convert a string into null string we need to perform 
  // deletion operation n number of times where n is length of the string
  for(int i=0;i<=n;i++){
    ed[i][0]=i;
  }
  // to convert a null string into the given string we need to perform 
  // insertion operation n number of times where n is length of the string
  for(int i=0;i<=m;i++){
    ed[0][i]=i;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(X[i-1]==Y[j-1]){
        // no operation required
        ed[i][j] = ed[i-1][j-1];
      }
      else{
        // one of the three operation required
        ed[i][j] = 1+ min( ed[i-1][j],   //deletion
                                   ed[i][j-1],   //insertion
                                   ed[i-1][j-1] //substitution
                       );
      }
    }
  }
  return ed[n][m];
}

int main()
{
    std::string s1 = "biting";
    std::string s2 = "sitting";

    std::string s3 = "witting";
    // std::cout << mindistedit(s2, s3)<<"\n";
    // std::cout << mindistedit(s1, s2);
    std::cout<<editDistance(s1,s2)<<"\n";


    // Solution obj;
    // std::cout << obj.minDistance(s1, s2) << '\n';
    return 0;
}