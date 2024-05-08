#include <iostream>
using namespace std;
class Node // creation of class
{
private:
    int data;          // data part of link list
    Node* nextAddress; // address of next node
    Node* head;        // current location of link list
public:
    Node() // default constructor
    {
        head = NULL;
    }
    void insertDataAtEnd(int data)
    {
        // step--01---->   creation of a node
        Node* NewNode = new Node(); // one node is created
        NewNode->data = data;       // data has assigned
        NewNode->nextAddress = NULL;
        Node* visitNode = head;
        if (visitNode != NULL)
        {

            while (visitNode->nextAddress != NULL)
            {
                visitNode = visitNode->nextAddress; //read the next of node
            }
            visitNode->nextAddress = NewNode;
        }
        else
        {
            head = NewNode; // when there is no node in the list
        }
    }
    void printNode()
    {
        Node* printNode = head;
        if (printNode == NULL)
        {
            cout << "List is empty:\n";
        }
        else
        {
            while (printNode != NULL)
            {
                cout << "-->" << printNode->data;   // print this
                printNode = printNode->nextAddress; // i++-->same move to next address
            }
            cout << "-->NULL";
        }
    }
    //--------------------Insert NODE AT START LOCATION ----------------------

    void insertNodeAtStart(int data) // insertion node at start of the list
    {
        Node* headNode = new Node(); // creation of new node
        headNode->data = data;
        headNode->nextAddress = head;
        head = headNode; // now  boss is the new node
        
    }
    void insertnodeatstartofstart(int data){
    	Node* headNode2 = new Node();
        headNode2->data = data;
        headNode2->nextAddress = head;
        head = headNode2;
	}
    //--------------------INSERT NODE AT ANY LOCATION ----------------------

    void insertdataAtdesireLocation(int position, int data)
    {
        Node* newNode = new Node(); // create new node
        newNode->data = data;
        // if list has no node than 👇👇
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        // if list has ,many nodes👇👇
        Node* visitPtr = head; // read all the list of nodes
        int count = 0;
        while (visitPtr != NULL)
        {
            if (count == position - 1) // 3-->0->1-->2->3
            {
                newNode->nextAddress = visitPtr->nextAddress;
                visitPtr->nextAddress = newNode;
            }
            visitPtr = visitPtr->nextAddress; // i++
            count++;
        }
    }
    //--------------------DELETE NODE AT ANY LOCATION ----------------------

    void DeleteNodeLOcation(int position)
    {
        Node* deleteNode = head; // first step
        if (head == NULL)        // if there is no node in the list
            return;
        else
        {
            if (position == 0) // if we want to delete the first node
            {
                head = head->nextAddress; // simple make boss to the next node
                delete deleteNode;
            }
            for (int i = 0; deleteNode != NULL && i < position - 1; i++) // deletednode --->NULL && i<position-1)
            {
                deleteNode = deleteNode->nextAddress; // visiting
            }
            if (deleteNode == NULL || deleteNode->nextAddress == NULL)
                return; // out of range or already deleted node
            Node* nextNode = deleteNode->nextAddress->nextAddress;
            delete deleteNode->nextAddress; // delete the node
            deleteNode->nextAddress = nextNode;
        }
    }
    int max()
    {
        Node* maxNode = head;
        int max = 0;
        while (maxNode != NULL)
        {
            if (maxNode->data > max)
            {
                max = maxNode->data;
            }
            maxNode = maxNode->nextAddress;
        }
        return max;
    }
    int minNode()
    {
        Node* minNode = head;
        int min = 9999;
        while (minNode != NULL)
        {
            if (minNode->data < min)
            {
                min = minNode->data;
            }
            minNode = minNode->nextAddress;
        }
        return min;
    }
    //--------------------SEARCH NODE----------------------

    bool searchNode(int element)
    {
        Node* searchptr = head;
        while (searchptr != NULL)
        {
            if (element == searchptr->data)
                return searchptr;
            searchptr = searchptr->nextAddress;
        }
        return NULL;
    }
    //--------------------REVERSE LIST----------------------
    void reverseList()
    {
        Node* currentPtr = head;
        Node* prevPtr = NULL;
        Node* nextPtr;
        while (currentPtr != NULL)
        {
            nextPtr = currentPtr->nextAddress; // first assign nextptr value
            currentPtr->nextAddress = prevPtr; // current will shift its value yo previous ptr
            prevPtr = currentPtr;              // previous pointer = currenyt ptr
            currentPtr = nextPtr;              // current  = nextstep---->i++
        }
        head = prevPtr; // if there is only one node in the list
    }
};

int main()
{
    Node node;
    node.insertDataAtEnd(20);
    node.insertDataAtEnd(30);
    node.insertDataAtEnd(50);
    node.insertDataAtEnd(60);
    node.insertDataAtEnd(40);
    node.insertDataAtEnd(100);
    node.insertDataAtEnd(999);
    node.insertDataAtEnd(10);
    node.printNode();
    node.insertNodeAtStart(555);
    node.insertnodeatstartofstart(111);

    cout << endl;
    //node.reverseList();
    node.printNode();
    node.insertnodeatstartofstart(111);

    // node.printNode();
     //cout << "\n The node in the list is:\t" << node.searchNode(120);
     //if (node.searchNode(60))
       //  cout << "Node is present in list";
     //else
       //  cout << "Node is not present in list";
     //cout << "\n Tha max node in the list is:\t" << node.max();
     //cout << "\n Tha min node in the list is:\t" << node.minNode();

     //node.DeleteNodeLOcation(3);
     //node.DeleteNodeLOcation(1);
}

