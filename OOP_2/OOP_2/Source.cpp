#include <iostream>
#include <string>

using namespace std;
class RealNumber
{
private:
    int length;
    double* arr;
public:
    RealNumber()
    {
        length = 1;
        arr = new double[length];
        arr[length - 1] = 0;
    }
    RealNumber(double* arr, int len)
    {
        this->length = len;
        this->arr = new double[len];

        for (int i = 0; i < len; i++)
        {
            this->arr[i] = arr[i];
        }
        cout << "Constructor is successful" << endl;

    }

    RealNumber(const RealNumber& obj)
    {
        this->length = obj.length;
        arr = new double[this->length];
        for (int i = 0; i < this->length; i++)
        {
            this->arr[i] = obj.arr[i];
        }
        cout << "Copy constructor is successful" << endl;
    }

    ~RealNumber()
    {
        delete[]arr;
        cout << "Destructor is successful" << endl;
    };

    void SetNumber(int n)
    {
        delete[]arr;
        arr = new double[n];
        length = n;

        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the number " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    int SetNumberIndex(double value, int i)
    {
        if (i >= length)
        {
            return 1;
        }
        else
        {
            arr[i] = value;
        }
    }

    double GetNumberIndex(int i)
    {
        return arr[i];
    }

    void Print()
    {
        cout << '{';
        for (int i = 0; i < length - 1; i++)
        {
            cout << arr[i];
            cout << ", ";
        }
        cout << arr[length - 1] << '}' << endl;
        cout << endl;
    }

    int IntPart(int i)
    {
        return arr[i];
    }

    double DecPart(int i)
    {
        return arr[i] - IntPart(i);
    }

    double NewNumb(int a, int b)
    {
        double dec_part = b;
        for (int i = 0; i < b; i++)
        {
            dec_part /= 10;
        }
        return a + dec_part;
    }
};


int main()
{
    double arr[] = { 1, 3, 11.1, 9, 96,2 };
    RealNumber obj1(arr, sizeof(arr) / sizeof(double));
    obj1.Print();

    RealNumber obj2(obj1);
    obj1.SetNumberIndex(444, 0);
    obj2.Print();

    RealNumber* obj3 = new RealNumber;
    cout << (*obj3).NewNumb(1, 2);
    (*obj3).Print();
    delete obj3;

    RealNumber obj4;
    obj4.SetNumber(3);
    cout << "values of obj4" << endl;
    obj4.Print();
    cout << "Change the value of number with index 2" << endl;
    obj4.SetNumberIndex(1.1, 2);
    cout << endl;
    obj4.Print();
    cout << "Int part of obj4[0]: " << obj4.IntPart(0) << endl;
    cout << "Dec part of obj4[0]: " << obj4.DecPart(0) << endl;


}
