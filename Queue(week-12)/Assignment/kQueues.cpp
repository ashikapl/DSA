// K - Queues in an array
#include<iostream>
using namespace std;

class KQueues{
    public:
    int n,k,freeSpot;
    int *arr,*next,*front,*rear;

    KQueues(int _n,int _k) : n(_n), k(_k), freeSpot(0) {

        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for(int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1; 
        }
        for(int i = 0; i < n; i++)
        {
            next[i] = i+1;
            next[n-1] = -1;
        }
    }
        
        bool push(int x, int qi)
        {
            // overflow
            if(freeSpot == -1)
            {
                return false;
            }
            
            // find first freee index
            int index = freeSpot;
             
            // update freeSpot 
            freeSpot = next[index];

            // if first element in qi
            if(front[qi] == -1)
            {
                front[qi] = index;
            }
            else
            {
                // link new element to the Q's closest element
                next[rear[qi]] = index;
            }

            // update next
            next[index] = -1;

            // update rear
            rear[qi] = index;
            arr[index] = x;
            return true;
        }

        int pop(int qi)
        {
            // underflow
            if(front[qi] == -1)
            {
                return -1;
            }

            // find index to pop
            int index = front[qi];

            // front update
            front[qi] = next[index];

            // update freeSpot
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }

        ~KQueues()
        {
            delete[] arr;
            delete[] next;
            delete[] front;
            delete[] rear;
        }
};

int main()
{
    KQueues q(8,3);

    cout << q.push(5,0) << endl;
    cout << q.push(2,0) << endl;
    cout << q.push(4,1) << endl;
    cout << q.push(8,0) << endl;
    cout << q.pop(0) << endl;
    cout << q.pop(1) << endl;
   
    return 0;
}