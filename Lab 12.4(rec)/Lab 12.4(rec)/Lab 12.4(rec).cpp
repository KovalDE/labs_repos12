#include <iostream>
#include <Windows.h>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link; // 3
		T->link = tmp; // 4
	}
	else
	{
		L = tmp; // 5
	}
	tmp->link = L; // 6
}
Info remove(Elem*& L)
{
	Elem* T = L;
	while (T->link != L)
		T = T->link; // 1
	Info value = L->info; // 2
	if (T != L)
	{
		Elem* tmp = L->link; // 3
		delete L; // 4
		L = tmp; // 5
		T->link = L; // 6
	}
	else
	{
		delete L; // 4
		L = NULL; // 7
	}
	return value; // 8
}
int Count(Elem* L)
{
	if (L == NULL)
		return 0;
	Elem* first = L;
	Info k = L->info;
	int r = 0;
	while (L->link != first)
	{
		L = L->link;
		if (L->info == k)r++;
		k = L->info;
	}
	return r;
}
 Info Print(int N, Elem*& L,int i)
{
	Info a;
		cin >> a;
		insert(L, a);
		if (i < N)Print(N, L, i + 1);
		else return 0;
	
}

int main()
{
	SetConsoleOutputCP(1251);
	Elem* L = NULL;
	int N;
	cout << "Введіть кількість: "; cin >> N;
	Print(N, L,1);
	if (Count(L) > 0)
		cout << " парy сусідніх елементів з однаковими значеннями інформаційного поля знайдено";
	else cout << " пару сусідніх елементів  з однаковими значеннями інформаційного поля не знайдено";
	cout << endl;
	Elem* first = L;
	while (L != NULL)
	{
		cout << remove(L) << ' ';
	}
	return 0;
}

