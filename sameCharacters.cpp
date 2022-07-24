/*//^ Given a list of strings, find the list of characters that appear in all strings.

Here's an example and some starter code:
def common_characters(strs):
  # Fill this in.

print(common_characters(['google', 'facebook', 'youtube']))
# ['e', 'o']
*/

#include <iostream>
#include "util.h"
#include <vector>

//& Looking at thier oputput it seems that they have used a ordered map or something like that, we can try that too
void findCommonCharacters(std::string words[], int size) //^ using the new find function or the inbuil string function can be used to reduce the number of loops
{
    std::vector<char> commonChars;

    for (int i = 0; i < words[0].length(); i++)
    {
        bool commonCharacter = false;

        for (int j = 1; j < size; j++)
        {
            for (int k = 0; k < words[j].length(); k++)
            {
                if (words[j][k] == words[0][i])
                {
                    commonCharacter = true;
                    break;
                }
            }
        }

        if (commonCharacter and util::find(commonChars,words[0][i]) == false)
        {
            commonChars.push_back(words[0][i]);
        }
    }

    util::display_vector(commonChars);
}

int main()
{

    std::string words[] = {"google", "facebook", "youtube"};

    findCommonCharacters(words, sizeof(words) / sizeof(words[0]));

    return 0;
}