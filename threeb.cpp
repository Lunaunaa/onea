#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int temp[100];

    int i = l;
    int j = m + 1;
    int k = 0;

    while(i <= m && j <= r)
    {
        if(a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= m)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while(j <= r)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for(i = l, k = 0; i <= r; i++, k++)
    {
        a[i] = temp[k];
    }
}

void mergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    int a[100];

    cout<<"Enter elements:\n";

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    mergeSort(a, 0, n-1);

    cout<<"Sorted Array:\n";

    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}