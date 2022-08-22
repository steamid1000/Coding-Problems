//^Given a string s and a character c, find the distance for all characters in the string to the character c in the string s. You can assume that the character c will appear at least once in the string.

// Here's an example and some starter code:
// def shortest_dist(s, c):
//# Fill this in.

// print(shortest_dist('helloworld', 'l'))
//# [2, 1, 0, 0, 1, 2, 2, 1, 0, 1]

#include <iostream>
#include <vector>
#include "util.h"
#include "random";

bool findAllOccurenceOfACharacter(std::vector<int> &storage, char character, std::string word) // ^ 0(n)
{
    int characterCount = 0;
    for (int i = 0; i < word.length(); i++) //^ 0 (n) where n = length of the string
    {
        if (word[i] == character)
        {
            storage.push_back(i);
            characterCount++;
        }
    }

    if (characterCount==0)
    {
        std::cout<<"The entered character is not found in given string\n";
        return false;
    }

    return true;
    
}

void closestDistanceFromCharacter(std::string word, char character) //^ 0 (n x k) n = number of characters in the string and k = character which are the same as target
{                                                                  //^ Could be linear time if we use unordered maps
    std::vector<int> characterPos;
    //^ This will save the position of the character we want for comparasion
    //^Calling the Occurence function here
    if(!findAllOccurenceOfACharacter(characterPos, character, word)) return;

    int distances[word.length()];
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == character)
        {
            distances[i] = 0;
            continue;
        }

        int closest = INT16_MAX;
        for (int j = 0; j < characterPos.size(); j++) //^ Finds minimum distance from all the copies of the target character
        {

            if (i <= characterPos[j])
            {
                if (characterPos[j] - i <= closest)
                {
                    distances[i] = characterPos[j] - i;
                    closest = characterPos[j] - i;
                    // &std::cout << "Character: "<<word[i]<<"\t"<<"Closest: " << closest << "\n";
                }
            }

            else if (i > characterPos[j])
            {
                if (i - characterPos[j] <= closest)
                {
                    distances[i] = i - characterPos[j];
                    closest = i - characterPos[j];
                    //& std::cout << "Character: "<<word[j]<<"\t" <<"Closest: " << closest << "\n";
                }
            }
        }

        distances[i] = closest;
    }

    util::arr_dis(distances, word.length());
}



int main()
{
    closestDistanceFromCharacter("helloworld", 'z');
    return 0;
}