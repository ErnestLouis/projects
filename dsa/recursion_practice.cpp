// recursion_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int max(vector<int> vec) {
    int big = vec[0];

    for (int i{}; i < vec.size(); i++)
    {
        if (vec[i] > big)
        {
            big = vec[i];
        }
    }
    return big;
}

int min(vector<int> vec) {
    int small = vec[0];

    for (int i{}; i < vec.size(); i++)
    {
        if (vec[i] < small)
        {
            small = vec[i];
        }
    }
    return small;
}

void recurse(int num)
{
    if (num > 0)
    {
        static int i = 1;
        static  int j = 10;
        cout << i++ << " ";
        recurse(num - 1);
        cout << j-- << " ";
        
    }
}

void tail_recurse(int num)
{
    if (num > 0)
    {
        cout << num << " ";
        tail_recurse(num - 1);
    }
}

void head_recurse(int num)
{
    if (num > 0)
    {
        head_recurse(num - 1);
        cout << num << " ";
    }
}

void tree_recurse(int num)
{
    if (num > 0)
    {
        cout << num << " ";
        tree_recurse(num - 1);
        tree_recurse(num - 1);

    }
}
void indirect_recurse_B(int num);

void indirect_recurse_A(int num)
{
    if (num > 0)
    {
        indirect_recurse_B(num - 1);
        cout << num << " ";
    }
}

void indirect_recurse_B(int num)
{
    if (num > 1)
    {
        indirect_recurse_A(num/2);
        cout << num << " ";
    }
}

int nested_recurse(int num)
{
    if (num > 200)
    {
        return num - 10;
    }
    else
    {
        return nested_recurse(nested_recurse(num + 11));
    }
}

int sum_of_n(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return sum_of_n(num - 1) + num;
    }

}

int factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return factorial(num - 1) * num;
    }

}

int power(int m, int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return power(m,num - 1) * m;
    }
}

int power2(int m, int num)
{
    if (num == 0)
    {
        return 1;
    }
    if (num % 2 == 0) 
    {
        return power2(m * m, num/2);
    }
    else
    {
        return m * power2(m * m, (num - 1)/2);
    }
}


int loop_fib(int num)
{
    int term1 = 0, term2 = 1, sum = 0;
    if (num <= 1)
    {
        return num;
    }
    for (int i = 2; i <= num; i++)
    {
        sum = term1 + term2;
        term1 = term2;
        term2 = sum;
    }
    return sum;
}

int rec_fib(int num)
{
    if (num <= 1)
    {
        return num;
    }
    else
    {
        return rec_fib(num - 2) + rec_fib(num - 1);
    }
}

int memo_fib(int num)
{

    static vector<int> hash_vec(num + 1, -1);

    if (num <= 1)
    {
        hash_vec[num] = num;
        return num;
    }
    else
    {
        if (hash_vec[num - 2] == -1)
        {
            hash_vec[num - 2] = memo_fib(num - 2);
        }
        if (hash_vec[num - 1] == -1)
        {
            hash_vec[num - 1] = memo_fib(num - 1);
        }
        return hash_vec[num - 1] + hash_vec[num - 2];
    }
}

int nCr(int n, int r)
{
    int num = 0, den = 0;
    num = factorial(n);
    den = factorial(r) * factorial(n - r);

    return num / den;
}

int rec_nCr(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    } 
    else
    {
        return rec_nCr(n - 1, r - 1) + rec_nCr(n - 1, r );
    }
}

void TOH(int num, int source, int auxillary, int destination)
{
    if (num > 0)
    {
        TOH(num - 1, source, destination, auxillary);
        cout << source << " to " << destination << endl;
        TOH(num - 1, auxillary, source, destination);
    }
}


int main()
{
    //cout<< rec_nCr(4,2);

    TOH(2,1, 2, 3);
}
