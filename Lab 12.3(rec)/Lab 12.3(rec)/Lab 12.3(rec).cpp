#include <iostream>
#include <Windows.h>
using namespace std;
typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};
int Input(Elem*& first, Elem*& last, Info value)
{
    enqueue(first, last, value);
    if (value < 21)Input(first, last, value + 1);
    else
        return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->next = NULL; // 3
    if (last != NULL)
        last->next = tmp; // 4
    tmp->prev = last; // 5
    last = tmp; // 6
    if (first == NULL)
        first = tmp; // 7
}
Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next; // 1
    Info value = first->info; // 2
    delete first; // 3
    first = tmp; // 4
    if (first == NULL)
        last = NULL; // 5
    else
        first->prev = NULL; // 6
    return value;
}
void D(Elem* first, Elem* last)
{
    Info x;
    cout << "Введіть  елемент: ";
    cin >> x;
    while (first != NULL)
    {
        if (first->info == x)
        {
            Elem* next = first->next; // 1
            Elem* prev = first->prev; // 2
            delete first; // 3
            next->prev = prev; // 4
            prev->next = next;// 5
            first = next; // 6
        }
        else first = first->next;
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    Elem* first = NULL,
        * last = NULL;
    Input(first, last, 0);
    cout << endl;
   
    D(first, last);

    while (first != NULL)
    {
        cout << dequeue(first, last) << ' ';
    }


    cout << endl;

}

