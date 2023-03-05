// matrix_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::istream;
using std::ostream; 
using std::cin;
using std::cout;
using std::endl;


class Diagonal {

    private:
        int num;
        int* A;

    public:

        Diagonal()
        {
            num = 2;
            A = new int[2];
        }
        
        Diagonal(int num)
        {
            this->num = num;
            A = new int[num];
        }

        void set(int row_num, int col_num, int data);

        int get(int row_num, int col_num);

        void display();

        ~Diagonal()
        {
            delete[] A;
        };
};

class Lower_diagonal_row {

private:
    int num;
    int* A;

public:

    Lower_diagonal_row()
    {
        num = 2;
        A = new int[2*(2+1)/2];
    }

    Lower_diagonal_row(int num)
    {
        this->num = num;
        A = new int[num * (num + 1)/ 2];
    }

    void set(int row_num, int col_num, int data);

    int get(int row_num, int col_num);

    void display();

    ~Lower_diagonal_row()
    {
        delete[] A;
    };
};


class Lower_diagonal_col {

private:
    int num;
    int* A;

public:

    Lower_diagonal_col()
    {
        num = 2;
        A = new int[2 * (2 + 1) / 2];
    }

    Lower_diagonal_col(int num)
    {
        this->num = num;
        A = new int[num * (num + 1) / 2];
    }

    void set(int row_num, int col_num, int data);

    int get(int row_num, int col_num);

    void display();

    ~Lower_diagonal_col()
    {
        delete[] A;
    };
};

//------------------------------------------------------------------------------------------------

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
    int row_num;
    int col_num;
    int num;
    Element* ele;
public:
    Sparse(int row_num, int col_num, int num)
    {
        this->row_num = row_num;
        this->col_num = col_num;
        this->num = num;
        ele = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] ele;
    }

    Sparse operator+(Sparse &s);

    friend istream & operator>>(istream &is, Sparse &s);
    friend ostream& operator<<(ostream& os, Sparse &s);


};

int main()
{

    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);
    cin >> s1;
    cin >> s2;
    Sparse sum = s1 + s2;
    cout << "First Matrix" << endl << s1;
    cout << "Second Matrix" << endl << s2;
    cout << "Sum Matrix" << endl << sum;
   
}



void Diagonal::set(int row_num, int col_num, int num)
{
    if (row_num == col_num)
    {
        A[row_num - 1] = num;
    }
}

int Diagonal::get(int row_num, int col_num)
{
    if (row_num == col_num)
    {
        return A[row_num - 1];
    }
    else
        return 0;
}

void Diagonal::display()
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == j)
            {
                std::cout << A[i] << " ";
            }
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}

//-------------------------------------------------------------------lower row--------------------------------------------------------------------

void Lower_diagonal_row::set(int row_num, int col_num, int num)
{
    if (row_num >= col_num)
    {
        A[row_num * (row_num - 1)/2 + col_num - 1] = num;
    }
}

int Lower_diagonal_row::get(int row_num, int col_num)
{
    if (row_num >= col_num)
    {
        return A[row_num * (row_num - 1) / 2 + col_num - 1];
    }
    else
        return 0;
}

void Lower_diagonal_row::display()
{
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (i >= j)
            {
                std::cout << A[i * (i - 1) / 2 + j - 1] << " ";
            }
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}


//-------------------------------------------------------------------lower col--------------------------------------------------------------------

void Lower_diagonal_col::set(int row_num, int col_num, int num)
{
    if (row_num >= col_num)
    {
        A[this->num * (col_num - 1) - (col_num - 2) * (col_num - 1) / 2 + row_num - col_num] = num;
    }
}

int Lower_diagonal_col::get(int row_num, int col_num)
{
    if (row_num >= col_num)
    {
        return A[this->num * (col_num - 1) - (col_num - 2) * (col_num - 1) / 2 + row_num - col_num];
    }
    else
        return 0;
}

void Lower_diagonal_col::display()
{
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (i >= j)
            {
                std::cout << A[this->num * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] << " ";
            }
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}

Sparse Sparse::operator+(Sparse& s)
{
    int i, j, k;

    if (row_num != s.row_num || col_num != s.col_num)
    {
        return Sparse(0, 0, 0);
    }
    Sparse* sum = new Sparse(row_num, col_num, num + s.num);

    i = j = k = 0;
    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[j].i)
            sum->ele[k++] = ele[i++];
        else if (ele[i].i > s.ele[j].i)
            sum->ele[k++] = ele[j++];
        else
        {
            if (ele[i].j < s.ele[j].j)
                sum->ele[k++] = ele[i++];
            else if (ele[i].j > s.ele[j].j)
                sum->ele[k++] = s.ele[j++];

            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }
    for (; i < num; i++)sum->ele[k++] = ele[i];
    for (; j < s.num; j++)sum->ele[k++] = s.ele[j];
    sum->num = k;

    return *sum;
}

istream & operator>>(istream& is, Sparse& s)
{
    std::cout << "Enter non-zero elements: \n";
    for (int i = 0; i < s.num; i++)
    {
        std::cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }
    return is;
}

ostream& operator<<(ostream& os, Sparse& s)
{
    int k = 0;
    for (int i = 0; i < s.row_num; i++)
    {
        for (int j = 0; j < s.col_num; j++)
        {
            if (s.ele[k].i == i && s.ele[k].j == j)
            {
                std::cout << s.ele[k++].x << " ";
            }
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
    return os;
}


/*




 Diagonal dial(5);

    dial.set(1, 1, 7);
    dial.set(2, 2, 1);
    dial.set(3, 3, 7);
    dial.set(4, 4, 1);
    dial.set(5, 5, 7);

    //7dial.display();



    int d = 0;
    std::cout << "Enter Dimensions \n";
    std::cin >> d;

    Lower_diagonal_col ldr(d);

    int x;

    std::cout << "Enter all elements: " << std::endl;;

    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            std::cin >> x;
            ldr.set(i, j, x);
        }
    }

    ldr.display();





*/