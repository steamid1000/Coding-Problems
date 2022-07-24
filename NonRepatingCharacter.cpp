/* Hi, here's your problem today. This problem was recently asked by Microsoft:

Given a string, find the length of the longest substring without repeating characters.

Here is an example solution in Python language. (Any language is OK to use in an interview, though we'd recommend Python as a generalist language utilized by companies like Google, Facebook, Netflix, Dropbox, Pinterest, Uber, etc.,)
 */

#include <iostream>
#include <string>
#define len .length()

int find(char charter, std::string searchIn) //will return 1 if it is found or -1 if the char is not found.
{
    for (size_t i = 0; i < searchIn len; i++)
    {
        if (searchIn[i] == charter)
        {
            return 1; // return true if the char is found
        }
    }

    return -1; //for false returing -1
}
int non_linearSolution(std::string inp) //time complexity is linear
{
    int counter = 0;     // final counter to be returned
    std::string longest; // will store the non repeating characters in this string
    for (size_t i = 1; i < inp len; i++)
    {

            if (i == 0)
            {
                longest += inp[i]; //adding the intiaal character in the string
                continue; // this will prevent the program from flaging it as flase
            }

            if (find(inp[i], longest) == -1)
            {
                
                longest += inp[i];
            }
            else
            {
                std::cout << longest<<" "<<longest len;
                std::cout << "\n";
                if (longest len > counter)
                {
                    counter = longest len;
                }

                longest.clear(); // clearing the string for the next iteratiion
                longest+=inp[i]; //adding the current for the next iteration
               
            }

            // std::cout<<i<<std::endl;
        
       
    }
/*
Turn out this works in linear time as well, the extra for loop was not required at all, and also they
had asked me to make it in linear time and this function will run in linear time if we dont consider the find function i wrote that finds if the current char is present in the string uptil now.
**************** OHH Yeah *************
*/
    longest.clear();
    return counter;
}



int non_linearSolution_2(std::string inp) //runs with a time complexity of O (n2 + n)
{
    int counter = 0;     // final counter to be returned
    std::string longest; // will store the non repeating characters in this string
    for (size_t i = 0; i < inp len; i++)
    {
        for (size_t j = i; j < inp len; j++)
        {
            if (j == i)
            {
                longest += inp[i]; //adding the intiaal character in the string
                continue;
            }

            if (find(inp[j], longest) == -1)
            {
                longest += inp[j];
            }
            else
            {
                std::cout << longest<<" "<<longest len;
                std::cout << "\n";
                if (longest len > counter)
                {
                    counter = longest len;
                }

                longest.clear(); // clearing the string for the next iteratiion
                longest+=inp[j];
                // break; // will end this loop and the outer loop will go onto the next iteration, which turns out is not required, i dont know why
            }
        }

       
    }

    return counter;
}
int main()
{
    std::string log = "abrkaabcdefghijjxxx"; //answer should be 10

    // std::cout << non_linearSolution(log);
    std::cout<<"\n\n";
    // std::cout << non_linearSolution_2(log);

    // log = "abalejiba";
    // std::cout<<non_linearSolution(log)<<"\n\n";
    // std::cout<<non_linearSolution_2(log);

    std::string log2 = "abcacedf";
    std::cout<<non_linearSolution(log2);
    // std::cout<<non_linearSolution_2(log2);
    return 0;
}