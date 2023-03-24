#include <iostream>

using namespace std;

class Calculator
{

private:
    float *numbers;
    int length;

public:
    Calculator();
    Calculator(int size);
    ~Calculator();
    Calculator operator+(const Calculator &obj);
    Calculator operator-(const Calculator &obj);
    Calculator operator*(const Calculator &obj);
    Calculator operator/(const Calculator &obj);
    Calculator &operator=(const Calculator &obj);
    friend ostream &operator<<(ostream &os, const Calculator &obj);
    void generate(int size);
};

Calculator::Calculator()
{
}

Calculator::Calculator(int size)
{
    length = size;
    numbers = new float[size];
}

Calculator::~Calculator()
{
    delete[] numbers;
}

Calculator Calculator::operator+(const Calculator &obj)
{

    Calculator temp(obj.length);

    for (int i{0}; i < length; i++)
    {
        temp.numbers[i] = numbers[i] + obj.numbers[i];
    }
    return temp;
}

Calculator Calculator::operator-(const Calculator &obj)
{
    Calculator temp(obj.length);

    for (int i{0}; i < length; i++)
    {
        temp.numbers[i] = numbers[i] - obj.numbers[i];
    }
    return temp;
}

Calculator Calculator::operator*(const Calculator &obj)
{
    Calculator temp(obj.length);

    for (int i{0}; i < length; i++)
    {
        temp.numbers[i] = numbers[i] * obj.numbers[i];
    }
    return temp;
}

Calculator Calculator::operator/(const Calculator &obj)
{
    Calculator temp(obj.length);

    for (int i{0}; i < length; i++)
    {
        temp.numbers[i] = numbers[i] / obj.numbers[i];
    }
    return temp;
}

Calculator &Calculator::operator=(const Calculator &obj)
{
    if (this != &obj)
    {
        length = obj.length;
        numbers = new float[length];

        for (int i{0}; i < length; i++)
        {
            numbers[i] = obj.numbers[i];
        }
    }

    return *this;
}

ostream &operator<<(ostream &os, const Calculator &obj)
{
    for (int i{0}; i < obj.length; i++)
    {
        os << obj.numbers[i];
        os << " ";
    }
    return os;
}

void Calculator::generate(int size)
{

    for (int i{0}; i < size; i++)
    {
        cin >> numbers[i];
    }
}

int main()
{
    int size1, size2;
    cout << "Length of the first numbers set: ";
    cin >> size1;

    Calculator c1{size1};

    cout << "\nFirst set entered: ";
    c1.generate(size1);

    cout << "\nLength of the second numbers set: ";
    cin >> size2;
    Calculator c2{size2};
    cout << "\nSecond set entered: ";

    c2.generate(size2);

    string operation;

    Calculator temp(size1);
    while (operation != "exit")
    {
        cout << "\nChoose operation: ";
        cin >> operation;

        if (operation == "+")
        {
            temp = c1 + c2;
            cout << temp;
        }
        else if (operation == "-")
        {
            temp = c1 - c2;
            cout << temp;
        }
        else if (operation == "*")
        {
            temp = c1 * c2;
            cout << temp;
        }
        else if (operation == "/")
        {
            temp = c1 / c2;
            cout << temp;
        }
        else
        {
            if (operation != "exit")
                cout << "\nYou entered invalid operation!";
            else
                continue;
        }
    }
    cout << "\nGoodBye!";

    return 0;
}