/* LRU cache is a cache data structure that has limited space, and once there are more items in the cache than available space,
it will preempt the least recently used item. What counts as recently used is any item a key has 'get' or 'put' called on it.

Implement an LRU cache class with the 2 functions 'put' and 'get'. 'put' should place a value mapped to a certain key,
and preempt items if needed. 'get' should return the value for a given key if it exists in the cache, and return None if it doesn't
 exist.
*/

#include <iostream>

class LRUCache
{
    int memory[3][3]{0,0,0}; //^ memory which can store only 3 pairs
    int index = 0;

public:
    void put(int, int);
    void get(int);
    bool isFull();
    void removeLeastUsedPair(int &,int&);
    void display();
};

void LRUCache::put(int key, int value)
{
    if (!isFull())
    {
        memory[index][0] = key;
        memory[index][1] = value;
        index++;
    }
    else
    {
        removeLeastUsedPair(key,value);
    }
    

}

void LRUCache::get(int key)
{
    for (int i = 0; i < 3; i++)
    {
        if (memory[i][0]==key)
        {
            //^ Updating the count of the pair which is asked
            memory[i][2]++;

            std::cout<<memory[i][1]<<"\n";
            return;
        }
        
    }

    std::cout<<"None\n";
    
}

bool LRUCache::isFull()
{
    if (index>2)
    {
        return true;
    }

    return false;
    
}

void LRUCache::removeLeastUsedPair(int &key,int &value)
{
    int minKeyElement = 2;
    int counts = INT16_MAX;

    for (int i = 0; i < 3; i++) //^ Searching the least called pair
    {
        if (memory[i][2]<counts)
        {
            minKeyElement = i;
            counts = memory[i][2];
        }
        
    }

    //^placing the key and value at the least called pair position and reseting the call count
    memory[minKeyElement][0] = key;
    memory[minKeyElement][1] = value;
    memory[minKeyElement][2] = 0;

    
}

void LRUCache::display()
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout<<memory[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    
}

int main()
{
    LRUCache cache;

    cache.put(3,2);
    cache.put(1,5);
    cache.put(4,9);
  

    cache.get(3);
    cache.get(1);

    cache.put(19,59);

    cache.get(19);

    cache.put(0,1); //^ if all the pairs have the same count then one of them will be removed from the memory

    cache.display(); //^ Additional function
   

    return 0;
}