#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};
void push(Elem*& top, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->link = top; // 3
    top = tmp; // 4
}
Info read(const char* fname, int x, Elem*& top)
{

    ifstream t(fname);
    if (!t)
    {
        cerr << "file \"f.txt\" not found" << endl;
        return 0;
    }
    while (t >> x)
    {
        push(top, x);
    }
        t.close();
        return 0;
    }
Info pop(Elem*& top)
{
    Elem* tmp = top->link; // 1
    Info value = top->info; // 2
    delete top; // 3
    top = tmp; // 4
    return value; // 5
}
int search(Elem*& top, int s)
{
    int i = 0;
    Elem* tmp = top;
    while (tmp != NULL)
    {
       
        i++;
        if (i == s)return tmp->info;
            tmp = tmp->link;
    }
   
}




int main()
{
	SetConsoleOutputCP(1251);
	Elem* top = NULL;
    int x=0;
    //char fname[101];
    read("1.txt",x,top);
    cout << endl;
    int s;
    cout << "Введіть позицію: ";cin >> s;
    cout << endl;
    cout << "Значення елемента який знаходиться у цій позиції: ";
    cout << search(top, s+1);
    cout << endl;
    while (top != NULL)
    {
        cout << pop(top) << ' ';
    }
}

