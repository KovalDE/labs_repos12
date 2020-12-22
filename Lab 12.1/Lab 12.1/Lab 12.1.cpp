#include <iostream>
using namespace std;
struct Elem
{
    Elem* link1,
        * link2;
    int info;
};
Elem* p;

int main()
{
p = new Elem;
p->info = 1;
p->link1 = NULL;
p->link2 = new Elem; // 2 block
p->link2->link1 = p;
p->link2->info = 2;
p->link2->link2 = new Elem; //4 block
p->link2->link2->link1 = p;
p->link2->link2->info = 4;
p->link2->link2->link2 = new Elem; // 3 block
p->link2->link2->link2->info = 3;
p->link2->link2->link2->link1 = p;

delete p->link2->link2; // 4 block
delete p->link2->link2->link2; // 3 block
delete p->link2; // 2 block
delete p; // 1 block
return 0;

}


