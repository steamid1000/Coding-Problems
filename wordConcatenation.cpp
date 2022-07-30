//^ Given a set of words, find all words that are concatenations of other words in the set.

#include <iostream>
#include <vector>
#include "util.h"

void concatenatedWords(std::string input[], int size) //^ Brute-Force
{
    std::vector<std::string> output;
    for (int i = 0; i < size; i++)
    {
        std::string currentWord = input[i];
        int concatenationsFound = 0;
        int indexToSkip = 0;
        for (int j = 0; j < size; j++)
        {
            //^ if the word is same as the currentWord then be
            if (j == i)
            {
                continue;
            }

            //^ Lets find the first word

            std::string temp = input[j];

            if (temp == currentWord.substr(0, temp.length()))
            {
                indexToSkip = temp.length() - 1;
                concatenationsFound++;
                // std::cout << currentWord << "\n";
            }

            if (concatenationsFound > 1 and temp == currentWord.substr(indexToSkip, currentWord.length()) or temp == currentWord.substr(indexToSkip+1, currentWord.length()) )
            {
                concatenationsFound++;
            }

            if (concatenationsFound == 2)
            {
                output.push_back(currentWord);
                break;
            }
        }
    }

    util::display_vector(output);

    //& The only problem i see in this function is that if the first word of the concatenared string comees after 
    //& the last word of the concatenated string, in that case this will not find the other half of the concatenated string 

}

int main()
{
    std::string input[] = {"rat","dog","cat","cats","catsdog", "dogcat", "dogcatrat"};

    concatenatedWords(input, 7);
    return 0;
}