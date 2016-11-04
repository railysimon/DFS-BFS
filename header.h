#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include "stack.h"
#include "queue.h"

using namespace std;

class detour
{
private:
        int size;
        bool *visited;
        int *dfsnumber;
        int **graph;
        int num = 0;
public:
        detour(int s);
        ~detour();
        void DFS(int start, int choise);
        void BFS(int start);
        void Show();
};

detour::detour(int s) : size(s)
{
    visited = new bool[size];
    dfsnumber = new int[size];

    for(int i=0; i<size; i++)
        visited[i] = false;

    graph = new int*[size];
    for(int i=0; i<size; i++)
        graph[i] = new int[size];

    ifstream file("data.txt");

    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            file >> graph[i][j];

    cout << "Матриця суміжностей графа: " << endl;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    file.close();
}

detour::~detour()
{
    delete visited;
    delete dfsnumber;

    for(int i=0; i<size; i++)
        delete [] graph[i];
    delete [] graph;
}

void detour::DFS(int start, int choise)
{
    switch (choise)
    {
        case 1: {
                    int dfs = 0;
                    Stack stack;

                    visited[start] = true;
                    dfsnumber[start] = ++dfs;
                    stack.Push(start);

                    while(stack.first)
                    {
                        label:

                        for(int i=0; i<size; i++)
                        {
                            if((graph[stack.first->data][i]) && !(visited[i]))
                            {
                                visited[i] = true;
                                dfsnumber[i] = ++dfs;
                                stack.Push(i);
                                goto label;
                            }
                        }
                            stack.Pop();
                    }

                    break;
                }
        case 2: {
                    int vertex;

                    visited[start] = true;
                    dfsnumber[start] = ++num;

                    for (vertex=0; vertex<=size; vertex++)
                    if ((graph[start][vertex]) && (!visited[vertex]))
                    DFS(vertex, choise);


                    break;
                }

        default : break;
    }

}

void detour::BFS(int start)
{
    int bfs = 0;
    Queue queue;

    visited[start] = true;
    dfsnumber[start] = ++bfs;
    queue.Enqueue(start);


    while(queue.front)
    {
        start = queue.front->data;
        for(int i=0; i<size; i++)
        {
            if((graph[start][i]) && !(visited[i]))
            {
                visited[i] = true;
                dfsnumber[i] = ++bfs;
                queue.Enqueue(i);
            }
        }

        queue.Dequeue();
    }
}

void detour::Show()
{
    num = 0;
    cout << "Name:" << "\tDFS/BFS" << endl;
    for(int i=0; i<size; i++)
        cout << i+1 << "\t" << dfsnumber[i] << endl;

    for(int i=0; i<size; i++)
        visited[i] = false;
}

#endif // HEADER_H
