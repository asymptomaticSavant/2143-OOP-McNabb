#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      Description of your class and what it does
 * 
 * Public Methods:
 *      - CircularArrayQue()
 *      - CircularArrayQue(int size)
 *      - void Push(int item)
 *      - int Pop()
 * 
 * Private Methods:
 *      - void init(int size)
 *      - bool Full()
 * 
 * Usage: 
 * 
 *      - CircularArrayQue()          //create a circular queue of size ten
 *      - CircularArrayQue(int size)  //create a circular queue of inputted size
 *      
 */
class CircularArrayQue {
private:
    int *Container;  //pointer to array
    int Front;       //front of queue tracker
    int Rear;        //rear of queue tracker
    int QueSize;     //items in the queue
    int CurrentSize; //current size of queue 

      /**
     * Private: void init
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - int // array size; defaults to 0
     * 
     * Returns:
     *      - void
     *      - sets size to 0 or inputed value
     *      - sets Front to 0
     *      - sets Reat to 0
     *      - sets CurrentSize to 0
     *      - sets QueSize to size
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

     /**
     * Private : Full
     * 
     * Description:
     *      Checks if the array is full.
     * 
     * Params:
     *      - N/A
     * 
     * Returns:
     *      - boolean
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
     /**
     * Public: CircularArrayQue()
     * 
     * Description:
     *      Constructer #0
     * 
     * Params:
     *      - N/A
     * 
     * Returns:
     *      - sets Container to an empty array with a length of 10
     */
    CircularArrayQue() {
        Container = new int[10];
        init(10); //sets queue size 
    }

     /**
     * Public: CircularArrayQue
     * 
     * Description:
     *      Constructor #1
     * 
     * Params:
     *      - int //size of array
     * 
     * Returns:
     *      - sets Container to inputted size 
     */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size); //sets queue size
    }

    
     /**
     * Public: Push
     * 
     * Description:
     *      Pushes inputted int onto the end of the array;
     *      if the array is full, prints a warning
     * 
     * Params:
     *      - int //to be added to the end of the array
     * 
     * Returns:
     *      - modifies array
     *      - can print
     */
    void Push(int item) {
        if (!Full()) {                   //if queue is not full
            Container[Rear] = item;      //add input to the end
            Rear = (Rear + 1) % QueSize; //move rear tracker
            CurrentSize++;               //keep current size up to date
        } else {                         //if queue is full
            cout << "FULL!!!!" << endl;  //print a warning
        }
    }

     /**
     * Public: Pop
     * 
     * Description:
     *      Pops the first item of the array
     * 
     * Params:
     *      - N/A
     * 
     * Returns:
     *      - int //the first int in the array
     */
    int Pop() {
        int temp = Container[Front];    //add input to front of queue
        Front = (Front + 1) % QueSize;  //move front tracker
        CurrentSize--;                  //keep current size up to date
        return temp;                    //return removed item from queue
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other); //call especial print class
};

/**
 * &operator<<
 * 
 * Description:
 *      Prints CircularArrayQue class
 * 
 * Public Methods:
 *      - N/A
 * 
 * Private Methods:
 *      - N/A
 * 
 * Usage: 
 * 
 *      - &operator<<(ostream &os, const CircularArrayQue &other) //print a CircularArrayClass 
 *      
 */
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " "; //print queue
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * Description:
 *      For this program, the main driver was used to test the CircularArrayQue class
 * 
 * Public Methods:
 *      - N/A
 * 
 * Private Methods:
 *      - N/A
 * 
 * Usage: 
 * 
 *      - main() //various 
 *      
 */
int main() {
    CircularArrayQue C1(5); //queue of size 5

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}