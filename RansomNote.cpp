/*A criminal is constructing a ransom note. In order to disguise his handwriting, he is
cutting out letters from a magazine.

Given a magazine of letters and the note he wants to write, determine whether he can
construct the word.
*/

#include <iostream>
#include <unordered_map>

bool containsTheLetters(char set[], int arrSize,std::string word)
{
    int remaningLetters = word.length();
    std::unordered_map<char,int> counts;

    //^ Recording the occurence of all the characters
    for (int i = 0; i < arrSize; i++) //^ 0(n) where n = size of the array
    {
        if (counts.find(set[i]) == counts.end())
        {
            counts.insert(std::make_pair(set[i],1));
        }
        else
        {
            counts[set[i]]++;
        }
        
    }
    

    for (int i = 0; i < word.length(); i++) //^ 0(n) where n = length of the word
    {
       
        if (counts.find(word[i]) != counts.end())
        {
            // std::cout<<set[i]<<'\n';
            remaningLetters--;
        }
        if (remaningLetters==0)
        {
            break;
        }
        
    }



    if (remaningLetters==0)
    {
        return true;
    }
    
    return false;
    
}

int main()
{
    char letters[]{'a', 'b', 'c', 'd', 'e', 'f'};

    std::cout << containsTheLetters(letters, 6,"feaeaf");
    return 0;
}