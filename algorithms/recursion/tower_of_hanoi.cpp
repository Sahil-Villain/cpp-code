#include <iostream>
using namespace std;

void tower(int n, char from, char to, char aux)
{
    if (n == 0) return;

    // move n-1 disks from 'from' to 'aux'
    tower(n - 1, from, aux, to);

    // move nth disk from 'from' to 'to'
    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    // move n-1 disks from 'aux' to 'to'
    tower(n - 1, aux, to, from);
}

int main()
{
    int n = 3;
    tower(n, 'A', 'C', 'B'); // source=A, destination=C, helper=B
    return 0;
}
