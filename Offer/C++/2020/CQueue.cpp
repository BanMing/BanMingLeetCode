//  用两个栈实现队列
#include <stack>
class CQueue
{
private:
    std::stack<int> save;
    std::stack<int> temp;
    int size;

public:
    CQueue()
    {
        size = 0;
    }

    void appendTail(int value)
    {
        while (!save.empty())
        {
            temp.push(save.top());
            save.pop();
        }

        temp.push(value);

        while (!temp.empty())
        {
            save.push(temp.top());
            temp.pop();
        }
        size++;
    }

    int deleteHead()
    {
        // if (save.empty())
        if (size < 1)
        {
            return -1;
        }

        size--;
        int val = save.top();
        save.pop();
        return val;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

void Run()
{
}