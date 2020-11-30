/******************************************************************
** DesignLinkedList.cpp
** @Author       : BanMing 
** @Date         : 2020/11/30 下午3:29:13
** @Description  : https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1290/
*******************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class LinkedNode
{
public:
    int val;
    LinkedNode *nextNode;

    LinkedNode()
    {
        val = 0;
        nextNode = NULL;
    }
    LinkedNode(int val, LinkedNode *nextNode)
    {
        this->val = val;
        this->nextNode = nextNode;
    }
    ~LinkedNode()
    {
        val = 0;
        nextNode = NULL;
    }
};

class MyLinkedList
{
private:
    LinkedNode *head;
    int listLen;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        listLen = 0;
        head = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= listLen)
        {
            return -1;
        }
        int curIndex = 0;
        LinkedNode *curNode = head;
        while (index > curIndex)
        {
            curNode = curNode->nextNode;
            curIndex++;
        }
        return curNode->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        LinkedNode *first = new LinkedNode(val, head);
        head = first;
        listLen++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        if (head == NULL)
        {
            addAtHead(val);
        }

        LinkedNode *newNode = new LinkedNode(val, NULL);
        LinkedNode *curNode = head;
        while (curNode != NULL && curNode->nextNode != NULL)
        {
            curNode = curNode->nextNode;
        }

        curNode->nextNode = newNode;
        listLen++;
    }

    /** Add a node of value val before the index-th node in the linked list.
     *  If index equals to the length of linked list, the node will be appended to the end of linked list.
     *  If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > listLen)
        {
            return;
        }

        if (index == 0)
        {
            addAtHead(val);
        }
        else if (index == listLen)
        {
            addAtTail(val);
        }
        else
        {
            listLen++;

            LinkedNode *newNode = new LinkedNode(val, NULL);
            LinkedNode *curNode = head;

            int curIndex = 0;
            while (index - 1 > curIndex)
            {
                curNode = curNode->nextNode;
                curIndex++;
            }
            newNode->nextNode = curNode->nextNode;
            curNode->nextNode = newNode;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= listLen)
        {
            return;
        }

        listLen--;

        if (index == 0)
        {
            head = head->nextNode;
            return;
        }

        LinkedNode *curNode = head;
        int curIndex = 0;
        while (index - 1 > curIndex)
        {
            curNode = curNode->nextNode;
            curIndex++;
        }

        curNode->nextNode = curNode->nextNode->nextNode;
    }
};

void Run()
{
    MyLinkedList myLinkedList;
    // myLinkedList.addAtHead(1);
    // myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(0, 1);       // linked list becomes 1->2->3
    myLinkedList.addAtIndex(0, 2);       // linked list becomes 1->2->3
    myLinkedList.addAtIndex(1, 30);      // linked list becomes 1->2->3
    cout << myLinkedList.get(0) << endl; // return 2
    // myLinkedList.deleteAtIndex(0);       // now the linked list is 1->3
    // cout << myLinkedList.get(1) << endl; // return 3
}
