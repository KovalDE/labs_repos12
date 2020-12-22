#include <iostream>
#include <Windows.h>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};
void push(Elem*& top, Info value);
Info pop(Elem*& top);
Info pop1(Elem*& top);
int Input(Elem*& top,int i)
{
		push(top, i);
		if (i < 20) Input(top, i + 1);
		else return 0;
}
void PrintandSearch(Elem*& top,int x,int& k)
{

	while (top != NULL)
	{
		Info r = pop(top);
		if (r == x)
			k++;
		cout << r << ' ';
	}
}
int main()
{
	SetConsoleOutputCP(1251);
	Elem* top = NULL;
	// створення стеку
	int a;
	Input(top,0);
	int x;
	int k = 0;
	cout << "Введіть шуканий елемент: ";
	cin >> x;
	cout << endl;
	PrintandSearch(top,x,k);
	cout << endl;
	if (k >= 1)
	{
		cout << "Елемент знайдено";
		cout << endl << "Кількість співпадінь :" << k;
	}
	else cout << "Немає співпадінь";
	return 0;

}
void push(Elem*& top, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = top; // 3
	top = tmp; // 4
}
Info pop(Elem*& top)
{
	Elem* tmp = top->link; // 1
	Info value = top->info; // 2
	delete top; // 3
	top = tmp; // 4
	return value; // 5
}
Info pop1(Elem*& top)
{
	Elem* tmp = top->link; // 1
	Info value = top->info; // 2
	top = tmp; // 4
	return value; // 5
}