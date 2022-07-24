//?Given a non-empty list of words, return the k most frequent words. The output should be sorted from highest to lowest frequency, and if two words have the same frequency, the word with lower alphabetical order comes first. Input will contain only lower-case letters.

//^Example:
//^Input: ["daily", "interview", "pro", "pro",
//^"for", "daily", "pro", "problems"], k = 2
//^Output: ["pro", "daily"]

#include <iostream>
#include <vector>
#include <map>
#include "util.h"

void k_most_frequent_words(std::string input[], int k, int size)
{

    std::vector<std::string> output;
    std::map<std::string,int> frequency;

    for (int i = 0; i < size; i++) //^ Counting thr frequency of each word and storing in the frequecny map
    {
        if (frequency.find(input[i]) == frequency.end())
        {
            frequency.insert(make_pair(input[i], 1));
        }
        else
        {
            frequency[input[i]]++;
        }
    }

    for (size_t i = 0; i < k; i++) // ^ finding the most k frequent words
    {
        std::string frequent;
        int freq = 0;
        for (auto val : frequency) //* Gets the key with highest value
        {
            if (freq < val.second) {freq = val.second; frequent = val.first;}
        }
        
        output.push_back(frequent); //* pushing the most frequent from the map into the output vector and then deleting that key from the map to avoid          recounting the same word again.👨‍🎓
        frequency.erase(frequent);

    }

    for (size_t i = 0; i < output.size(); i++) //^printing the output 
    {
        std::cout<<output[i]<<" ";
    }
    
    
}

int main()
{
    std::string input[] = {"daily", "ask" ,"interview", "pro", "ask", "pro", "for", "daily", "pro", "problems"};
    int k = 2; //^ k most frequently words in the input

    int size = sizeof(input) / sizeof(input[0]);

    k_most_frequent_words(input, k, size);

    return 0;
}