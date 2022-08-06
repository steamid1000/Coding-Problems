//^ Implement auto-completion. Given a large set of words (for instance 1,000,000 words) and then a single word prefix, find all words that it can complete to.

//& Do it in linear time complexcity

#include <iostream>

void autoCompleteSearch(std::string searchThis,std::string input[],int size)
{
    short count = 0;
    for (int i = 0; i < size; i++)
    {
        if (searchThis == input[i].substr(0,searchThis.length()))
        {
            std::cout<<input[i]<<" ";

            count++;
        }
        
    }

    if (count==0) //? this is just additional functionality.
    {
        std::cout<<"None\n";
    }
    
    
    //& Here i have assumed that the substr function works in constant time so the overall 
    //& time complexcity is linear . 😁

    //* And also it is assumed that the auto-complete return strings that start with the given characters right. 💭🤔
}

int main()
{
    std::string input[]{"dog", "dark", "cat", "door", "dodge","ddck"};


    autoCompleteSearch("do",input,6);
    return 0;
}