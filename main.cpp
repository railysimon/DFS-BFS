#include <iostream>
#include "header.h"
#include <fstream>

using namespace std;


int main()
{

    detour ob(5);

    int start, choise = 1;

    while(choise)
    {

        cout << "Початкова вершина: ";
        cin >> start;
        cout << "1 - нерекурсивний, 2 - рекурсивний пошук" << endl; cin >> choise;

        ob.DFS(start-1, choise);
        ob.Show();

        cout << "Продовжити? (1/0)" << endl;
        cin >> choise;
    }

    return 0;
}
