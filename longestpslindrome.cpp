/*Hi, here's your problem today. This problem was recently asked by Twitter:

A palindrome is a sequence of characters that reads the same backwards and forwards. Given a string, s, find the longest single_palindromedromic substring in s.

Example:
Input: "banana"
Output: "anana"

Input: "million"
Output: "illi"
*/

#include <iostream>
#include <string>

#define ln .length()

void longest_palindrome(std::string input) // wrong func
{

    std::string lp;             // will store the longest palindrome
    int longest_palindrome = 0; // will store the length
    int revs = input.length() - 1;
    for (int i = 0; i < input.length(); i++)
    {
        int largest_palin = 0, rev = revs;
        for (int index_start = i; index_start < input.length() / 2; index_start++)
        {

            std::cout << input[(input.length() - 1) - index_start];
        }

        if (largest_palin > longest_palindrome)
        {
            longest_palindrome = largest_palin;
        }
    }

    std::cout << longest_palindrome++;
}

void single_palindrome(std::string in) // this function will give correct output for string which contain only 1 palindrome substring
{
    int occurence[in ln]{0};
    for (int i = 0; i < in ln; i++) // recording the occurence of all chars
    {
        for (int j = 0; j < in ln; j++)
        {
            if (in[j] == in[i])
            {
                occurence[i]++;
            }
        }
    }

    //  for (size_t i = 0; i < in ln; i++) experimental printing
    //  {
    //      std::cout<<occurence[i]<<" ";
    //  }

    //  std::cout<<"\n";

    int first_index, last_index; // this will store the first and last index of the palindrome substring
    int longest = 0;             // just used as a bool in the for loop below
    for (int i = 0; i < in ln; i++)
    {
        // std::cout<<occurence[i]<<" ";
        if (occurence[i] > 1)
        {
            if (longest == 0)
            {
                first_index = i;
            }

            longest++;
            last_index = i;
        }
    }

    std::cout << first_index << " " << last_index << "\n"; // experimental printing of first and last index

    std::string longest_palin = in.substr(first_index, last_index); // creating a string as a sub-string by using the first and last index of the palindrome

    // std::cout<<"\n"<<lo-ngest;
    // std::cout<<"\n";

    std::cout << longest_palin << "\n"; // printing the final longest palindrome
}

std::string multiple_palindrome(std::string in);

int main()
{
    std::string word;// = "banana";
    std::string res;
    // longest_palindrome(word);
    // single_palindrome(word);
    // multiple_palindrome(word);

    // word = "million";
    // longest_palindrome(word);
    // single_palindrome(word);
    // multiple_palindrome(word);

    // word = "millioniiiiii"; // exception case
    // multiple_palindrome(word);

    word = "madam";
    // res = multiple_palindrome(word);

    single_palindrome(word);
    std::cout<<res<<"\n";

    return 0;
}

std::string multiple_palindrome(std::string in) // this function can handel all types of palindrome
{
    //checking if the string is palindrome as whole, experimental
    int last = in ln-1;
    bool palindrome_as_whole = true;
    for (size_t i = 0; i < in ln/2; i++)
    {
        if (in[i]!=in[last])
        {
            palindrome_as_whole = false; // if this is false then only the below operaion will be carried out, otherwise the original string will be returned
            break;
        }
        last--;

        
    }

    if (palindrome_as_whole)
    {
        return in; // returning the original string as the whole string is palindrome
    }
    
    //else the below operations will be executed

    int occurence[in ln]{0};
    for (int i = 0; i < in ln; i++) // recording the occurence of all chars
    {
        for (int j = 0; j < in ln; j++)
        {
            if (in[j] == in[i])
            {
                occurence[i]++;
            }
        }
    }

     /*for (size_t i = 0; i < in ln; i++) //experimental printing
     {
         std::cout<<occurence[i]<<" ";
     }

     std::cout<<"\n";*/ 

    int first_index, last_index; // this will store the first and last index of the palindrome substring
    int longest = 0;             // just used as a bool in the for loop below
    int length = 0; // this will store the length of the palindrome and if a larger palindrome is found then the first and last index should update
    for (int i = 0; i < in ln; i++)
    {

        if (occurence[i] > 1 )
        {
           int copy = i; // this will be the copy of cuurent index
           int length_copy = 0; // this is a local  length, which is used for checking the length of the current palindrome
           //we will check the length of the substring here
            while (occurence[copy] > 1 and copy<in ln)
            {
                copy++; //incrementing the copy of the index
                length_copy++; // we will increment the length_copy here and use it for further checking

            }

            // std::cout<<"Length_copy: "<<length_copy<<"\n Last Length: "<<length<<"\n";
            // here we will check if the current is longer the last longer
            if (length_copy>length)
            {
                length = length_copy; //updating the final length which will be used to determine the final substring
                first_index = i;
                last_index = copy; // copy will have the last length of the palindrome
            }


            
        }
    }

    // std::cout << first_index << " " << last_index << "\n"; // experimental printing of first and last index

    std::string longest_palin = in.substr(first_index, length); // creating a string as a sub-string by using the first and last index of the palindrome

    // std::cout<<"\n"<<lo-ngest;
    // std::cout<<"\n";

    return longest_palin; // returning the final longest palindrome
}