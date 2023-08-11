#include <iostream>
using namespace std;
template <class T>
class vector
{
    T vec[10];
    int dim;

public:
    void create();
    void display();
    void multiply();
    void modify();
};
template <class T>
void vector<T>::create()
{
    int x;
    T element;
    cout << "Enter dimension of vector:";
    cin >> dim;
    for (int i = 0; i < dim; i++)
    {
        cout << "Enter value at index [" << i << "]:";
        cin >> element;
        vec[i] = element;
    }
}
template <class T>
void vector<T>::display()
{
    cout << "(";
    for (int i = 0; i < dim; i++)
    {
        if (i == dim - 1)
        {
            cout << vec[i] << ")";
        }
        else
        {
            cout << vec[i] << ", ";
        }
    }
}
template <class T>
void vector<T>::multiply()
{
    int x;
    cout << "Enter number to multiply:";
    cin >> x;
    for (int i = 0; i < dim; i++)
    {
        vec[i] = vec[i] * x;
    }
    cout << "Vector after multiplication is:";
    display();
}
template <class T>
void vector<T>::modify()
{
    int flg = 1, i;
    while (flg)
    {
        cout << "Enter index to modify:";
        cin >> i;
        cout << "Enter new value at index [" << i << "]:";
        cin >> vec[i];
        cout << "Enter 1 to continue modifying or 0 to stop:";
        cin >> flg;
    }
    cout << "Vector after modification is:";
    display();
}

int main()
{
    int ch;
    vector<int> obj;
    cout << "\nProgram for template class";
    do
    {
        cout << "\n----------MENU----------";
        cout << "\n1.Create the vector";
        cout << "\n2.Display the vector";
        cout << "\n3.Multiply a scalar to the vector";
        cout << "\n4.Modify the vector";
        cout << "\n0.Exit";
        cout << "\nEnter your choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            obj.create();
            break;

        case 2:
            obj.display();
            break;
        case 3:
            obj.multiply();
            break;

        case 4:
            obj.modify();
            break;

        case 0:
            cout << "\nExit\n";
            break;

        default:
            cout << "\nInvalid choice";
            break;
        }
    } while (ch != 0);
    return 0;
}