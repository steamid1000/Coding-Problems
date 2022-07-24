#include <iostream>

void block_operation(std::string &log, int block_start[], int block_end[]) // function for operation from 'R' to 'L' and change them to the
{
    int in = 0;
    int ou = 0;
    bool error = false;
    for (size_t i = 0; i < log.length(); i++)
    {
        if (log[i] == 'R' and i < log.length() - 1)
        {
            block_start[in] = i;
            in++;

            int copy = i + 1; // copy of i for security

            int count = 0;
            int r_pos = i;

            for (; log[copy] != 'L'; copy++)
            {
                count++;
                if (log[copy] == 'R')
                {

                    count = 0;
                    break;
                }

                if (copy == log.length() - 1) // security reason
                {
                    block_end[ou] = 0;
                    block_start[--in] = 0; // as this is not a valid block, we will not save the indexs
                    error = true;
                    count = 0;
                    break;
                }
            }
            if (!error)
                block_end[ou] = copy;
            ou++;

            i = copy; // updating the i index to the end of the block

            int l_pos = copy; // last position of the block (i.e L)

            if (count % 2 != 0)
            {
                count--; // reducing the count by 1
            }

            while (count > 0) // actual operations
            {
                ++r_pos;
                log[r_pos] = 'R';
                --count;

                --l_pos;
                log[l_pos] = 'L';
                --count;
            }
        }
    }
}

void l_operations(std::string &p, int block_start[], int block_end[])
{
    bool isblock = false;
    for (int i = 0; i < p.length(); i++)
    {
        // checking if the l is not already proccesed by the block function
        /*for (size_t j = 0; j < 5; j++)
        {
            if (block_end[j]==-1 and block_start[j]==-1)
            {
                isblock = false;
                break;
            }

            if (i > block_start[j] or i < block_end[j])
            {
                isblock = false;
            }

            if (j > 0 and (block_start[j] == 0 or block_end[j]))
            {
                break;
            }
        }*/
        // end

        if (p[i] == 'L' and !isblock)
        {
            // std::cout << "Came here\n";
            int l_pos; // 1 position behind of the
            int count = 0;
            for (l_pos = i - 1; l_pos >= 0 or p[l_pos] == 'L'; l_pos--)
            {
                count++;
                // l_pos--;
                // std::cout << count << "\n";
                // std::cout << l_pos << "\n";
            }

            // std::cout << "been here\n";
            l_pos = i;
            /*while (count > 0)
            {
                --l_pos;
                p[l_pos] = 'L';
                --count;
            }*/
        }
    }
}

void r_operations(std::string &p, int block_start[], int block_end[])
{
    bool less_then_r = false;
    bool greater_then_l = false;
    for (int i = 0; i < p.length(); i++)
    {
        // checking if the l is not already proccesed by the block function
        for (size_t j = 0; j < 5; j++)
        {
            if (block_start[j] == -1 and block_end[j] == -1)
            {
                less_then_r = true;
                greater_then_l = true;
                break;
            }

            if (i < block_start[j])
            {
                less_then_r = true;
            }
            if (i > block_end[j])
            {
                greater_then_l = true;
            }

            if (j > 0 and (block_start[j] == 0 or block_end[j]))
            {
                break;
            }
        }
        // end

        if (p[i] == 'R' and (less_then_r or greater_then_l))
        {
            std::cout << "Came here R_operation\n";
            auto l_pos = i + 1; // 1 position behind of the l
            auto count = 0;
            while (p[l_pos] == '.' and l_pos < p.length())
            {
                p[l_pos] = 'R';
                l_pos++;
            }
        }
    }
}

int main()
{
    std::string initial = "..L...L..L.";
    int s[5]{-1}, e[5]{-1};
    // block_operation(initial, s, e);
    l_operations(initial, s, e);
    // r_operations(initial, s, e);

    std::cout << initial << "\n";
    return 0;
}