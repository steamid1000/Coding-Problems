#pragma once // this will be included only once
#include "bits/stdc++.h"

namespace util
{ 
    template <typename T>
    void swap(T arr[], int i, int j) // a simple swapping function
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void bubble_sort(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            short swaped = 0; // will check the number of swaps, if 0 then break
            for (int j = 0; j < size-1; j++)
            {
                if (arr[j]>arr[j+1])
                {
                    swap(arr,i,j);
                    swaped++;
                }
                
            }
            

            if (swaped==0)
            {
               
                return;
            }
            
        }
        
    }

    template <typename T>
    void arr_dis(T arr[],int size=0) //^ displays the array on console
    {
        for (int i = 0; i < size ; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<"\n";
        
    }

    class stack
    { // basic custom stack class
    public:
        int top;
        int size;
        int *elem;

        stack(int n) // constructor for
        {
            size = n;
            top = -1;
            elem = new int[size];
        }

        bool isempty()
        {
            if (top == -1)
            {
                return true;
            }

            return false;
        }

        bool isfull()
        {
            if (top == size - 1)
            {
                return true;
            }

            return false;
        }

        void push(int val)
        {
            if (!isfull())
            {
                top++;
                elem[top] = val;
            }
            else
            {
                std::cout << "The stack is full\n";
            }
        }

        void pop()
        {
            if (!isempty())
            {
                top--;
            }
            else
            {

                std::cout << "The stack is empty\n";
            }
        }

        void peek()
        {

            std::cout << elem[top] << "\n";
        }

        void display()
        {
            for (auto i = 0; i < size; i++)
            {
                std::cout << elem[i] << " ";
            }

            std::cout << "\n";
        }
    };

    // following is the class queue
    template <typename T>
    class queue
    {
    public:
        int rear;  // back pointer of the queue
        int front; // front pointer of the queue
        int size;  // size of the queue which will be given by the user through the constructor
        T *elem;
        queue(int q) // constructor queue
        {
            size = q;
            front = -1;
            rear = -1;
            elem = new T[size]{-2};
        }
        bool isempty()
        {
            if ((front == -1 and rear == -1) or (front >= rear))
            {
                return true;
            }

            return false;
        }

        bool isfull()
        {
            if (rear == size - 1)
            {
                return true;
            }

            return false;
        }
        void nq(int val) // adding element to the queue
        {
            if (front == -1 and rear == -1)
            {
                front++;
                rear++;
                elem[front] = val;
            }

            else if (!isfull())
            {
                rear++;
                elem[rear] = val;
            }
            else
            {
                std::cout << "The Queue is full !\n";
            }
        }

        void dq() // removes element from the queue
        {
            if (!isempty())
            {
                if (front == size)
                {
                    std::cout << "The queue is empty \n";
                    return;
                }

                front++;
            }
            else
            {
                std::cout << "The queue is empty \n";
            }
        }
        void current()
        { // displays the current position of the rear.

            std::cout << "This is Front Position:-" << elem[front] << std::endl;
            std::cout << "This is Rear Position:-" << elem[rear] << std::endl;
        }

        void displayQueue()
        {
            for (int i = 0; i < size; i++)
            {
                std::cout<<elem[i]<<" ";
            }

            std::cout<<"\n";
        }
    };

    // block of the linked list class and fucntion
    class linked_list // Note the data type of the value is changed for a question (int - char)
    {

    public:
        char val;
        linked_list *next;

        linked_list(char dat) // creating the first node
        {
            val = dat;
            next = NULL;
        }

        void insert(linked_list *&head, char val) // simple insert function for the linked list
        {
            linked_list *n = new linked_list(val);
            if (head == NULL)
            {
                head = n;
                return;
            }

            linked_list *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        }

        void display(linked_list *head) // displays the linked list
        {
            while (head != NULL)
            {
                std::cout << head->val << "->";
                head = head->next;
            }

            std::cout << "NULL\n";
        }
    };

    void reversell(linked_list *&head) // fucntion reverses the linked list in place 
    {
        linked_list *prev = NULL;
        linked_list *temp = NULL;
        linked_list *&current = head;

        while (current != NULL)
        {
            temp = current->next; // stores the address of the next node
            current->next = prev; // currents-> will be null
            prev = current;       // prev = current node
            current = temp;       // current will be the next node
        }

        head = prev;
    }


    template <typename T>
    void display_vector(std::vector<T> vec) // takes and display a int vector
    {
        for (auto i:vec)
        {
            std::cout<<i<<" ";
        }
        std::cout<<"\n";
    }


    bool isPalin(std::string input) //^ function to check if a given string is palindrome or not
    {
        int j = input.length()-1;

        for (int i = 0; i < input.length()/2; i++)
        {
            if(input[i]!=input[j]) return false;

            j--;
        }
        
        return true;

    }


    template <typename T>
    bool find(std::vector<T> input,T element)
    {
        for(auto it : input)
        {
            if (it==element)
            {
                return true;
            }
            
        }

        return false;
    }


}