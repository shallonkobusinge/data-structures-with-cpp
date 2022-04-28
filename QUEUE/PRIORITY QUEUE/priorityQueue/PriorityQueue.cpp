

#include <iostream>
#include <queue>

using namespace std;

void displayPriortyQueue(priority_queue<int> priorityQueue)
{
    priority_queue<int> queue = priorityQueue;
    while (!queue.empty()) {
        cout << '\t' << queue.top();
        queue.pop();
    }
    cout << '\n';
}

int main()
{
    priority_queue<int> priorityQueue;
    priorityQueue.push(10);
    priorityQueue.push(30);
    priorityQueue.push(20);
    priorityQueue.push(5);
    priorityQueue.push(1);

    cout << "The priority queue : ";
    displayPriortyQueue(priorityQueue);

    cout << "\nSize : " << priorityQueue.size();
    cout << "\nTop : " << priorityQueue.top();

    cout << "\nPop : ";
    priorityQueue.pop();
    displayPriortyQueue(priorityQueue);

    return 0;
}