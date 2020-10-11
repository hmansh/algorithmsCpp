#include <iostream>
#include <string>

//<---- USE CASE ---->
//Stack<float> stack(LIMIT);

template <typename T>
class Stack
{
private:
    T *array;
    int TOP = -1;
    int LIMIT = 0;

public:
    Stack(int n = 0)
    {
        if (n <= 0)
        {
            throw std::invalid_argument("PLEASE ENTER SIZE\n");
        }
        LIMIT = n;
        array = new T[LIMIT];
    }

    void push(T x)
    {
        if (TOP == LIMIT - 1)
        {
            throw std::invalid_argument("OVERFLOW\n");
            // return;
        }
        this->array[++TOP] = x;
        std::cout << "PUSHED" << std::endl;
        return;
    }

    void pop()
    {
        if (TOP == -1)
        {
            throw std::invalid_argument("UNDERFLOW\n");
            // return;
        }
        this->array[TOP--] = 0;
        std::cout << "POP" << std::endl;
        return;
    }

    void print()
    {
        if (TOP == -1)
        {
            throw std::invalid_argument("STACK EMPTY\n");
            // return;
        }
        for (int i = 0; i <= TOP; i++)
        {
            std::cout << this->array[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
};
