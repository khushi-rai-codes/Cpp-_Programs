#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (heap[parent] <= heap[index])
                break;

            swap(heap[parent], heap[index]);

            index = parent;
        }
    }

    void heapifyDown(int index)
    {
        int size = heap.size();

        while (true)
        {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left] < heap[smallest])
            {
                smallest = left;
            }

            if (right < size &&
                heap[right] < heap[smallest])
            {
                smallest = right;
            }

            if (smallest == index)
                break;

            swap(heap[index], heap[smallest]);

            index = smallest;
        }
    }

public:

    void insert(int value)
    {
        heap.push_back(value);

        heapifyUp(heap.size() - 1);
    }

    int extractMin()
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty.");
        }

        int minimum = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return minimum;
    }

    void display()
    {
        cout << "Heap: ";

        for (int value : heap)
            cout << value << " ";

        cout << endl;
    }
};

int main()
{
    MinHeap minHeap;

    minHeap.insert(40);
    minHeap.insert(20);
    minHeap.insert(30);
    minHeap.insert(10);
    minHeap.insert(50);

    cout << "After insertion:\n";
    minHeap.display();

    cout << "\nMinimum element: "
         << minHeap.extractMin()
         << endl;

    cout << "After extraction:\n";
    minHeap.display();

    return 0;
}
