/*//^Given a string, determine if there is a way to arrange the string such that the string is a palindrome. If such arrangement exists, return a palindrome (There could be many arrangements). Otherwise return None.

Here's some starter code:
def find_palindrome(s):
  # Fill this in.

print(find_palindrome('momom'))
# momom
*/

#include <iostream>
#include <unordered_map>
#include "util.h"

void createPalindrome(std::unordered_map<char, int> &occ, std::string &input, std::string &output, bool noOddCharacter)
{

    int endIndex = input.length() - 1; //^ global indices which can be used in multiple for loops
    int firstIndex = 0;
    // std::cout << "about to put the odd count characters\n";

    if (noOddCharacter == false) //& if no odd character is present then the below code is required to run at all
    {

        for (auto iter : occ) //^ Setting the characters which are repeated once or thrice
        {
            if (iter.second == 1) //^ if only one seprate character exists then we will put it in the center
            {
                char temp = input[input.length() / 2];
                output[input.length() / 2] = iter.first;
                input[input.length() / 2] = iter.first;

                output[input.find(iter.first)] = temp; //^ this will put the current char at the position of the removed charaacter
                input[input.find(iter.first)] = temp;
                occ.erase(iter.first);

                break;
            }
            else if (iter.second % 2 != 0 and iter.second > 1) //^ if the odd character count is more then 1 , exits then we will put them in first, middle and last index of the output string, and put the remaning copies at i and len - i - 1 (except the 0, len/2 and len-1 indices)
            {
                //& his has to be changed to comoputer and inserting all odd numbers greater then 1

                //^ we will put one copy at len/2 position first
                char temp = input[input.length() / 2];
                output[input.length() / 2] = iter.first;
                input[input.length() / 2] = temp;

                output[input.find(iter.first)] = temp; //^ this will put the current char at the position of the removed charaacter
                input[input.find(iter.first)] = temp;

                // std::cout << "have inserted the middle odd character\n";
                // std::cout << output << "\n";

                for (int i = 0; i < input.length() / 2 and iter.second > 0; i++)
                {
                    temp = input[i];
                    output[firstIndex] = iter.first;
                    char lastTemp = input[endIndex];
                    output[endIndex] = iter.first;
                    output[i] = lastTemp;

                    
                    output[input.find(iter.first)] = temp; //^ this will put the current char at the position of the removed charaacter
                    input[input.find(iter.first)] = temp;

                    // std::cout << output << "\n";
                    occ[iter.first]--;
                    endIndex--;
                    firstIndex++;
                }

                occ.erase(iter.first);

                break;
            }
        }
    }



    //^ Below we will insert the remaning characters
   
    for (auto iter : occ)
    {
        while (iter.second > 0 )
        {
            output[firstIndex] = iter.first;
            output[endIndex] = iter.first;

            firstIndex++;
            endIndex--;
            iter.second = iter.second -2; //^ cause we are using 2 copies for front and the back in the string

        }

        
        //^ rest of the character at their place

    }
}

std::string checkAndReturnPalindrome(std::string input)
{
    bool canBeAPalindrome = false;
    bool noOddCharacters = false;

    std::unordered_map<char, int> occurence;
    int oddCharactersReapet = 0, evenCharactersReapet = 0; //^ this will store the number of characters which repeat odd and even number of times
    std::string output = "";
    output = input; //^ equating this to the input so we can change its indices later

    //^checking the base case if the given string is already a palindrome, in that case we will return the same string
    if (util::isPalin(input))
        return input;

    for (int i = 0; i < input.length(); i++) //^ recording the occurence of each unique character
    {
        if (occurence.find(input[i]) == occurence.end())
        {
            occurence.insert(std::make_pair(input[i], 1));
        }
        else
        {
            occurence[input[i]]++;
        }
    }


    for (auto it : occurence) //^ Seprate loop for checking how many even and odd count we have
    {
        if (it.second % 2 == 0)
        {
            evenCharactersReapet++;
        }
        else
        {
            oddCharactersReapet++;
        }
    }

    if (oddCharactersReapet == 0)
        noOddCharacters = true;


    //^ Checking if the string can be made a palindrome
    if (oddCharactersReapet > 1)
    {
        return "NONE"; //^ Base case, it will not be possoble to make a palindrome if there are more than 1 odd characters
    }
    else
    {
        canBeAPalindrome = true;
    }

    if (canBeAPalindrome)
    {
        createPalindrome(occurence, input, output, noOddCharacters); //^ calling other function to make a palindrome
    }

    return output;
}

void print(){
    
    
    
}


int main()
{
     
    std::cout << checkAndReturnPalindrome("momom")<<"\n";
    std::cout << checkAndReturnPalindrome("fassa")<<"\n";
    std::cout << checkAndReturnPalindrome("mmaass")<<"\n";
    std::cout << checkAndReturnPalindrome("moka")<<"\n";
    std::cout << checkAndReturnPalindrome("banana")<<"\n";
    std::cout<<checkAndReturnPalindrome("madamd");
    
    

    return 0;  
}