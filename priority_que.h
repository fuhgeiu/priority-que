#include <vector>
#include "data.h"

class MaxHeap
{
private:
    std::vector<Job> heap;

    void heapifyUp(int index)
    {
        if (index == 0) return;

        int parentIndex = (index - 1) / 2;

        if (heap[parentIndex].getPriority() < heap[index].getPriority())
        {
            std::swap(heap[parentIndex], heap[index]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index)
    {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int largest = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex].getPriority() > heap[largest].getPriority())
        {
            largest = leftChildIndex;
        }

        if (rightChildIndex < heap.size() && heap[rightChildIndex].getPriority() > heap[largest].getPriority())
        {
            largest = rightChildIndex;
        }

        if (largest != index)
        {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    bool isEmpty() const
    {
        return heap.empty();
    }

    void insert(const Job &job)
    {
        heap.push_back(job);
        heapifyUp(heap.size() - 1);
    }

    Job extractMax()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Heap is empty");
        }

        Job maxJob = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxJob;
    }

    int size() const
    {
        return heap.size();
    }
};


class PriorityQueue
{
private:
    MaxHeap maxHeap;

public:
    void insert(Job job)
    {
        maxHeap.insert(job);
    }

    Job runHighestPriority()
    {
        if (maxHeap.isEmpty())
        {
            throw std::out_of_range("No jobs in the queue.");
        }
        Job job = maxHeap.extractMax();
        job.execute();
        return job;
    }
};


class JobQueue
{
private:
    PriorityQueue queue;

public:
    void insert(Job job)
    {
        queue.insert(job);
    }

    void runHighestPriority()
    {
        queue.runHighestPriority();
    }
};