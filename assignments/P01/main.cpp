/*****************************************************************************
*
*  Author:           Katherine C. McNabb
*  Email:            katherine.claire.mcnabb@gmail.com
*  Label:            PO1
*  Title:            MyVector Class
*  Course:           2143 OOP
*  Semester:         Fall 2021
*
*  Description:
*        Expounded vector class.
*
*  Usage:
*       - $ ./main filename
*
*  Files:           - main.ccp
*                   - banner.cpp
*                   - test.out
*                   - input.dat
*****************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Node
 *
 * Description:
 *      - Node for our linked list
 *
 * Public Methods:
 *      - Node 
 *
 * Private Methods:
 *      - N/A
 *
 * Usage:
 *
 *      - Node(int d, Node* n = nullptr, Node* p)
 *
 */
class Node {
public:
    Node(int d, Node* n = nullptr, Node* p = nullptr) {  //constructor to make adding values easy
        data = d;
        next = n;
        prev = p;
    }
    int data;    //data value
    Node* prev;  //link to previous node in chain
    Node* next;  //link to next node in chain
};


/**
 * MyVector
 *
 * Description:
 *      - Expounded vector class.
 *
 * Public Methods:
 *      - void MyVector(int *A, int size)
 *      - void MyVector(string FileName)
 *      - void MyVector(MyVector V1)
 *      - void pushFront(int val)
 *      - void pushFront(MyVector V2)
 *      - void pushRear(int val)
 *      - void pushRear(MyVector V2)
 *      - void pushAt(int loc,int val)
 *      - void inOrderPush(int val)
 *      - int popFront()
 *      - int popRear()
 *      - int popAt(int loc)
 *      - int find(int val)
 *      - void print()
 *      - bool empty()
 *      - void ~MyVector()
 *
 * Private Methods:
 *      - N/A
 *
 * Usage:
 *
 *      - MyVector(int *A, int size)
 *      - MyVector(string FileName)
 *      - MyVector(MyVector V1)
 *
 */
class MyVector {
private:
    Node* head;  // base pointer of list
    Node* tail;
    //int size;
public:
    int size;    //size of list

   /**
     * Public: MyVector
     *
     * Description: 
     *      - #0 Constructor; creates a new MyVector.
     *
     * Params:
     *      - N/A
     *
     * Returns:
     *      - N/A
     */
    MyVector() {
        head = nullptr;  // NULL = zeros
                         // and zeros imply empty
        tail = nullptr;
    }

    /**
      * Public: MyVector
      *
      * Description:
      *         - #1 Constructor; creates a new MyVector from an array.
      *
      *
      * Params:
      *      - int* A //array used to create new MyVector
      *      - in arrSize //array size
      *
      * Returns:
      *      - N/A
      */
    MyVector(int* A, int arrSize) {
        head = nullptr;                          // NULL = zeros
                                                 // and zeros imply empty
        tail = nullptr;
        for (int i = arrSize - 1; i > -1; i--) { //cycle through given array
            head = new Node(A[i], head);         //update head

            if (head->next == nullptr) {         //if after head, list is empty
                tail = head;                     //relink list
            }
            else {                               //if after head, there's a non-null node
                head->next->prev = head;         //relink list
            }
            size++;                              //update size
        }

    }

    /**
  * Public: MyVector
  *
  * Description: 
  *         -#2 Constructor; Creates a new MyVector from a file.
  *
  *
  * Params: 
  *      - string filename
  *
  * Returns:
  *      - N/A
  */
    MyVector(string filename) {
        ifstream fin; fin.open(filename); //grab file
        head = tail = nullptr;            //set front and end of list to null
        int temp;

        int i = 0;
        while (!fin.eof()) {              //until the end of file
            fin >> temp;
            head = new Node(temp, head);  //updae head
            if (head->next == nullptr) {  //if after head, list is empty
                tail = head;              //relink list
            }
            else {
                head->next->prev = head;  //relink list
            }
            size++;                      //update size
            i++;                         //update i
        }
    }

  /**
  * Public: MyVector
  *
  * Description: 
  *      - #3 Constructor; creates a new MyVector from a MyVector.
  *
  *
  * Params:
  *      - const MyVector& V1 // MyVector used to create new MyVector
  *
  * Returns:
  *      - N/A
  */
    MyVector(const MyVector& V1) {
        head = tail = nullptr;
        for (int i = 0; i < V1.size; i++) {       //cycle through list
            head = new Node(V1.head->data, head); //update head
            if (head->next == nullptr) {          //if after head list is empty
                tail = head;                      //relink list
            }
            else {                                //if after head there is a non-null node
                head->next->prev = head;          //relink list
            }
            size++;                               //update size
        }
    }

    /**
    * Public: print
    *
    * Description: 
    *       - Prints the list to a file.
    *
    *
    * Params:
    *      - N/A
    *
    * Returns:
    *      - N/A
    */
    void print() {
        Node* temp = head;  // temp pointer copies head

        ofstream outfile;
        outfile.open("test.out");

        outfile << "Katherine C. Mcnabb\n9/10/2021\nFall 2143\n[ ";
        while (temp) {  // this loops until temp is NULL
                        // same as `while(temp != NULL)`

            outfile << temp->data;  // print data from node
            if (temp->next) {
                outfile << ", ";
            }
            temp = temp->next;  // move to next node
        }
        outfile << "]" << endl;
    }

    /**
   * Public: pushFront
   *
   * Description:
   *      - Adds single value to front of this.list
   *
   *
   * Params:
   *      - int val //value to added to the list
   *
   * Returns:
   *      - N/A
   */
    void pushFront(int val) {
        head = new Node(val, head);

        if (head->next == nullptr) { //if after head list is empty
            tail = head;             //relink list
        }
        else {                       //if after head theres a non-null node
            head->next->prev = head; //relink list
        }
    }

    /**
    * Public: pushFront
    *
    * Description:
    *      - adds entire other.list to front of this.list
    *
    * Params:
    *      - MyVector V2 //MyVector to be added to the front of the list
    *
    * Returns:
    *      - N/A
    */
    void pushFront(MyVector V2) {
        for (int i = 0; i < V2.size; i++) {       //cycle through given MyVector list
            head = new Node(V2.head->data, head); //input new head; relink list
            if (head->next == nullptr) {          //if after head list is empty
                tail = head;                      //relink list
            }
            else {                                //if theres a non-null node after head
                head->next->prev = head;          //relink list
            }
            size++;                               //update size
        }
    }

    /**
    * Public: pushRear
    *
    * Description:
    *      - adds single value to rear of this.list
    *
    *
    * Params:
    *      - int val //value to be added to the end of the list
    *
    * Returns:
    *      - N/A
    */
    void pushRear(int val) {
        tail = new Node(val, nullptr, tail);

        if (tail->prev == nullptr) { //if list is empty
            head = tail;             //relink list
        }
        else {
            tail->prev->next = tail; //relink list
        }
    }

    /**
    * Public: pushRear
    *
    * Description:
    *      - adds entire other.list to rear of this.list
    *
    *
    * Params:
    *      - MyVector V2 //MyVector to be added to the end of the list
    *
    * Returns:
    *      - N/A
    */
    // void pushRear(MyVector V2) {
    //     for (int i = 0; i < V2.size; i++){
    //         Node* travel = V2.head;      //using a travel node to iterate through the V2 vector   
    //         while(travel){              //while travel != nullptr
    //         tail = new Node(travel->data, nullptr, tail);  //create a new node at the end of the list
    //         if (tail->prev == nullptr){                    //checks to see if this is at the front of the list        
    //             head = tail;
    //         }
    //         else {                      //connects the end of the array to this new node making it the tail
    //             tail->prev->next = tail;
    //         }
    //         travel = travel->next;      //Iterates to the next node in the list
    //         size++;                     //Increases the size of the List thats being added to 
    //     }
    //     }
    //}

    /**
    * Public: pushRear
    *
    * Description:
    *      - adds entire other.list to rear of this.list
    *
    *
    * Params:
    *      - const MyVector& V2 //MyVector to be added to the end of the list
    *
    * Returns:
    *      - N/A
    */
    void pushRear(const MyVector& V2) {
        Node* temp = V2.head;
        while (temp) {            //cycle through given MyVector list
            pushRear(temp->data); //add node
            temp = temp->next;    //relink list
        }
    }

    /**
    * Public: pushAt
    *
    * Description:
    *      - Adds single value at a specified location of this.list
    *
    *
    * Params:
    *      - int val //value to added to the list
    *      - int loc //location for the given value to be inserted
    *
    * Returns:
    *      - N/A
    */
    void pushAt(int loc, int val) {
        Node* travel = head;
        int currentLoc = 0;
        while (currentLoc != loc) {     //cycle through list
            if (currentLoc != loc) {    //if wanted loc is not found
                travel = travel->next;  //move down
                currentLoc++;           //update current location
            }
            else {                     //if wanted location is found
                travel->data = val;    //push node
                return;
            }
        }
    }

    /**
    * Public: intOrderPush
    *
    * Description:
    *      - adds single value to proper location in order to maintain order (ascending or descending)
    *
    *
    * Params:
    *      - int val //value to added to the list
    *
    * Returns:
    *      - N/A
    */
     void inOrderPush(int val) {
         Node* travel = head;
         while(travel->next) {                 //cycle through list
             if(travel->data = val){           //if wanted val is found
                travel->prev->next = travel;   //relink nodes
                travel->next->prev = travel;   //relink nodes
             }
             else if (travel->next = nullptr) { //if hit the end of list
                 return;
             }
             else {                             //if not found, and there's more list
                 travel = travel->next;
             }
         }
     }

     /**
     * Public: popFront
     *
     * Description:
     *      - removes single value from front of list
     *
     *
     * Params:
     *      - N/A
     *
     * Returns:
     *      - N/A
     */
    int popFront() {
        if (!empty()) {
            int popped = head->data; //grab data
            Node* killMe = head;     
            head = head->next;       //relink nodes
            delete killMe;           //pop node
            size--;                  //update size
            return popped;
        }
        return -1;
    }

    /**
    * Public: popRear
    *
    * Description:
    *      - removes single value from rear of list
    *
    *
    * Params:
    *      - N/A
    *
    * Returns:
    *      - int //popped value if list isn't empty, otherwise -1
    */
    int popRear() {
        if (!empty()) {
            int popped = tail->data; //grab data
            Node* killMe = tail;     
            tail = tail->prev;       //relink nodes
            delete killMe;           //pop node
            size--;                  //update size
            return popped;
        }
        return -1;
    }

    /**
    * Public: find
    *
    * Description:
    *      - find location of item (index) if it exists
    *
    *
    * Params:
    *      - int val //value to be sought in the list
    *
    * Returns:
    *      - int //index of searched value if it's in the list; otherwise, 0
    */
     int find(int val) {
         Node* travel = head;
         
         int index = 0;

         for (int i = 0; i < size; i++) {      //cycle through entire list
             if (travel->data = val) {         //if wanted val found
                 return index;
             }
             else if(travel->next = nullptr) { //if wanted val doesn't exist
                 return -1;
             }
             else {
                 index++;                     //update tracker
             }
         }
         return 0;
     }

     /**
     * Public: popAt
     *
     * Description:
     *      - Use a given index to remove item
     *
     *
     * Params:
     *      - int loc //index of the value to be popped from the list
     *
     * Returns:
     *      - int //popped value if exists; 0 otherwise
     */
    int popAt(int loc) {
        Node* travel = head;
        int currentLoc;
        while (currentLoc != loc) {      //cycles through list until given index
            if (currentLoc != loc) {
                travel = travel->next;   //move down
                currentLoc++;
            }
            else {                       //current loc = loc
                int temp = travel->data; //grab data
                travel->prev->next = travel->next;
                delete travel;           //pop node
                return temp;             //return grabbed data
            }
        }
        return 0;
    }

    /**
    * Public: empty
    *
    * Description:
    *      - Checks if the list is empty
    *
    *
    * Params:
    *      - N/A
    *
    * Returns:
    *      - boolean //true if list is empty; otherwise, false
    */
    bool empty() {
        return head == nullptr;
    }

    /**
    * Public: ~MyVector
    *
    * Description:
    *      - Deconstructor
    *
    *
    * Params:
    *      - N/A
    *
    * Returns:
    *      - N/A
    */
    ~MyVector() {
        Node* travel = head;
        while (travel != nullptr) { //cycle through and delete nodes
            Node* tempnode = travel;
            travel = travel->next;
            delete tempnode;
        }
        head = nullptr;
    }
};

/**
* Public: main
*
* Description:
*      - Makes var. calls
*
*
* Params:
*      - N/A
*
* Returns:
*      - N/A
*/
int main() {

    int x = 0;

    MyVector v1;
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    v1.print();
    // [25, 20, 18, 18, 20, 25]

    //int A[] = {11,25,33,47,51};
    MyVector v2;
    v2.pushRear(v1);
    v2.print();
    // [11, 25, 33, 47, 51]

     v2.pushFront(9);
     v2.inOrderPush(27);
     v2.pushRear(63);
     v2.print();
     // [9, 11, 25, 27, 33, 47, 51, 63]
    
     v1.pushRear(v2);
     v1.print();
     // [25, 20, 18, 18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]

     x = v1.popFront();
     x = v1.popFront();
     x = v1.popFront();
     v1.print();
     // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
     cout<<x<<endl;
     // 18

     x = v1.popRear();
     x = v1.popRear();
     x = v1.popRear();
     v1.print();
     // [18, 20, 25, 9, 11, 25, 27, 33]
     cout<<x<<endl;
    // 47

     x = v2.popAt(3);
     v2.print();
     // [9, 11, 25, 33, 47, 51, 63]
     cout<<x<<endl;
     // 27

     x = v2.find(51);
     cout<<x<<endl;
     // 5

     x = v2.find(99);
     cout<<x<<endl;
     // -1

     MyVector v3(v1);
     v3.print();
     // [18, 20, 25, 9, 11, 25, 27, 33]

     v3.pushFront(v2);
     v3.print();
     //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

     MyVector v4("input.dat");
     v4.pushRear(v3);
     v4.print();
     // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

}