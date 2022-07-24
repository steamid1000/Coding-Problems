/*
Hi, here's your problem today. This problem was recently asked by Amazon:

You are given a 2D array of characters, and a target string. Return whether or not the word target word exists in the matrix. Unlike a standard word search, the word must be either going left-to-right, or top-to-bottom in the matrix.

Example:
[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

Given this matrix, and the target word FOAM, you should return true, as it can be found going up-to-down in the first column.

*/

#include <iostream>

void rowFound(char l[][4], int i, int j)
{
    for ( ; i < 4; i++)
    {
        std::cout<<l[i][j]<<" ";
    }
    std::cout<<"\n";
}

void colFound(char l[][4], int i, int j)
{
    for ( ; j < 4; j++)
    {
        std::cout<<l[i][j]<<" ";
    }
    std::cout<<"\n";
}

bool RowSearch(char l[][4], std::string words, int i, int j)
{
    short wordIndex = 0;
    int copy = i;
    for (;i < 4;i++)
    {
        if (l[i][j] != words[wordIndex])
        {
            std::cout << l[i][j] << " NOT Found in Row search\n";
            return false;
        }

        ++wordIndex;
        

        // std::cout << l[i][j] << " ";
    }

    rowFound(l,copy,j);
    // std::cout<<true<<"\n";
    return true;
}

bool ColumnSearch(char l[][4], std::string words, int i, int j)
{
    short wordIndex = 0;
    int copy =  j;
    for (;j < 4;j++)
    {
        if (l[i][j] != words[wordIndex])
        {
            std::cout << l[i][j] << " NOT FOUND IN COLUMN\n";
            return false;
        }

        ++wordIndex;
        
    }

    colFound(l,i,copy);
    // std::cout<<true<<"\n";
    return true;
}

/*bool WordSearch(int n, char l[][4], std::string words)
{
    if (words.length() > n) // base case as it is impossible to find a word whose len is > then arr's colums or rows
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (l[i][j] == words[0])
            {
                // bool foundinrow = RowSearch(n, l, words, i, j); //passung the current indexes to the functions
                // bool foundincolumn = ColumnSearch(n, l, words, i, j);

                if (RowSearch(n, l, words, i, j) == true or ColumnSearch(n, l, words, i, j) == true)
                {
                    std::cout << l[i][j] << " ";
                    return true;
                }
            }

            if (j < words.length())
            {
                break;
            }
        }
        //  std::cout<<"\n";
    }

    return false;
}*/
int main()
{
    int n = 4; // number of rows and colums

    char letters[][4] = {'F', 'A', 'C', 'I', // available letters in matrix form
                         'O', 'B', 'Q', 'P',
                         'A', 'N', 'O', 'B',
                         'M', 'A', 'S', 'S'};

    std::string word = "FOAM"; // word to search

    // std::cout << WordSearch(n, letters, word);

    // experimental of the functions
    bool row = false,col = false;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (letters[i][j] == word[0] and i>=word.length())
            {
                if(RowSearch(letters, word, i, j))
                {
                    row = true;
                    std::cout<<true;
                    return 0;
                }
            
            }

            if (letters[i][j] == word[0] and j>=word.length())
            {
                if(ColumnSearch(letters, word, i, j))
                {
                    col = true;
                    std::cout<<true;
                    return 0;
                }

            }
        }
    }

    if (!row and !col)
    {
        std::cout<<false;
    }
    
    /*bool found = false; // this will be printined at last if the word is found in the array
    int i = 0, j = 0;

    for (; i < 4; i++)
    {
        for (; j < 4; j++)
        {
            if (letters[i][j] == word[0])
            {
                std::cout << i << " " << j << "\n"; // experminatl
                // row search
                int row = i;
                int col = j;
                int index = 0;

                for (; col < 4; col++)
                {
                    if (letters[row][col] != word[index])
                    {
                        break;
                    }
                    index++;
                }

                if (index == word.length())
                {
                    found = true;
                }

                if (found)
                {
                    std::cout << found;
                    return 0;
                }
            }

            // col search
            if (letters[i][j] == word[0])
            {
                std::cout << i << " " << j << "\n"; // experminatl
                int row = i;
                int col = j;
                int index = 0;

                for (; row < 4; row++)
                {
                    if (letters[row][col] != word[index])
                    {
                        break;
                    }
                    index++;
                }

                if (index == word.length())
                {
                    found = true;
                }

                if (found)
                {
                    std::cout << found;
                    return 0;
                }
            }
        }
    }

    std::cout << "did not go in\n";
    std::cout << found << "\n";*/

    return 0;
}