#include <iostream>
#include <map>
#include <vector>
using namespace std;

string shabya_method(string input)
{
    map<char, int> freq;
    char str[input.length() + 2];
    for (int i = 0; i < input.length(); i++)
    {

        freq[input[i]]++;
    }
    char maxv;
    int maxf = 0;
    for (auto i : freq)
    {
        /* code */
        if (i.second > maxf)
        {
            maxf = i.second;
            maxv = i.first;
        }

        // cout<<i.first<<" "<<i.second<<endl;
    }
    cout << "maxf" << maxf << "\t maxv   " << maxv << endl;
    int len = input.length() + 1;

    if (maxf <= len / 2)
    {
        for (int i = 0; i < len - 1; i++)
        {
            if (i % 2 == 0)
            {
                str[i] = maxv;
            }
            else
            {
                str[i] = 'z';
            }
        }
    }
    freq.erase(maxv);

    int index = 1;
    for (auto i : freq)
    {
        short temp = i.second;
        while (temp--)
        {
            str[index] = i.first;
            index += 2;
        }
    }
    string out="";
    for (size_t i = 0; i < input.length(); i++)
    {
        out+=str[i];
    }

    return out;
}

vector<string> my_method(string input)
{   

    vector<string> out;
    for (size_t i = 0; i < input.length(); i++)
    {
        string out_1="";out_1+=input[i];
        for (size_t j = 0; j < input.length(); j++)
        {
            if (out_1[out_1.length()-1]!=input[j] and i!=j)
            {
                out_1+=input[j];
            }
            
        }
        
        out.push_back(out_1);
        
        
    }
    

    return out;
}

int main()
{
    string input = "acccbbb";



    cout<<shabya_method(input)<<endl;
    vector<string> in = my_method(input);

    for (int i = 0; i < in.size(); i++)
    {
        std::cout<<in[i]<<"\n";
    }
    
    return 0;
}