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
        cout << "DFS - 1, BFS - 2" << endl;
        cin >> choise;

        switch (choise)
        {
            case 1: {
                        cout << "1 - нерекурсивний, 2 - рекурсивний пошук" << endl; cin >> choise;
                        ob.DFS(start-1, choise);
                        ob.Show();

                        break;
                    }
            case 2: {
                        ob.BFS(start-1);
                        ob.Show();

                        break;
                    }

            default: { break; }

         }

        cout << "Продовжити? (1/0)" << endl;
        cin >> choise;
    }

    return 0;
}
