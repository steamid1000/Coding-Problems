/*//^Given a list of strings, find the longest common prefix between all strings.

Here's some examples and some starter code.
def longest_common_prefix(strs):
  # Fill this in.

print(longest_common_prefix(['helloworld', 'hellokitty', 'hell']))
# hell

print(longest_common_prefix(['daily', 'interview', 'pro']))
# ''
*/

#include <iostream>

std::string longestCommonPrefix(std::string st1, std::string st2, std::string st3)
{
    std::string commonPrefix = ""; //^ if this stays empty even at the end of the operations then we will return " " (none found)

    //* Currently the function is designed to work with 3 string but in future it will work with a array of strings
    for (int i = 0; i < st1.length(); i++)
    {
        if (st1[i] == st2[i] and st1[i] == st3[i])
        {
            commonPrefix += st1[i];
        }

        if (st1[i] != st2[i] or st2[i] != st3[i])
        {
            break;
        }
    }

    if (commonPrefix.length() == 0)
    {
        commonPrefix = "\" \"";
    }

    return commonPrefix;
}

std::string longestCommonPrefixUpdated(std::string words[],int lengthOfTheWordsArray)
{

    std::string commonPrefixCharacters = "";
    for (int i = 0; i <= words[0].length(); i++) //^ O(n * n) or O(n^2);
    {
        bool sameCharacters = true;
        for (int j = 1; j < lengthOfTheWordsArray; j++)
        {
            if (words[j][i]!= words[0][i]) 
            {
              sameCharacters = false;
              break;  
            }
            
        }
        
        if (sameCharacters)
        {
            commonPrefixCharacters+=words[0][i];
        }
        else if (!sameCharacters)
        {
            break;
        }
        
        
    }

    if (commonPrefixCharacters.length()==0)
    {
        return "\" \""; //* returning empty string
    }
    
    return commonPrefixCharacters;
}
int main()
{
    std::cout << longestCommonPrefix("helloworld", "hellokitty", "hell") << "\n";
    std::cout << longestCommonPrefix("daily", "interview", "pro") << "\n";

    std::string words[]{"helloworld", "hellokitty", "hell"};
    std::string words2[]{"daily", "interview", "pro"};

    std::cout << longestCommonPrefixUpdated(words,3) << "\n";
    std::cout << longestCommonPrefixUpdated(words2,3) << "\n";

    return 0;
}