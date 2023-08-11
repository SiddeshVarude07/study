#include <iostream>
#include <string>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void test1(int a[], int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        arr[i] = a[i];
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    string name[10];
    string id[10];
    int sal[10];
    int arr[10];
    int a = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << " Enter the name of employee " << endl;
        cin >> name[i];
        cout << " Enter employee id " << endl;
        cin >> id[i];
        cout << " Enter employee salary " << endl;
        cin >> sal[i];
    }

    test1(sal, arr);
    quickSort(arr, 0, 4);

    for (int i = 3; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i] == sal[j])
            {
                cout << " The name of employee " << endl;
                cout << name[j] << endl;
                cout << " Employee id " << endl;
                cout << id[j] << endl;
                cout << " Employee salary " << endl;
                cout << sal[j] << endl;
            }
        }
    }
    cout << endl
         << " Using bubble sort  :" << endl;
    test1(sal, arr);
    bubbleSort(arr, 5);
    for (int i = 3; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i] == sal[j])
            {
                cout << " The name of employee" << endl;
                cout << name[j] << endl;
                cout << " Employee id" << endl;
                cout << id[j] << endl;
                cout << " Employee salary" << endl;
                cout << sal[j] << endl;
            }
        }
    }
    test1(sal, arr);
    cout << endl
         << " Using Insertionsort  :" << endl;
    insertionSort(arr, 5);
    for (int i = 3; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i] == sal[j])
            {
                cout << " The name of employee" << endl;
                cout << name[j] << endl;
                cout << " Employee id" << endl;
                cout << id[j] << endl;
                cout << " Employee salary" << endl;
                cout << sal[j] << endl;
            }
        }
    }
    return 0;
}
