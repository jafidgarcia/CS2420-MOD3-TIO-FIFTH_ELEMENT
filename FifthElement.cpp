#include "LinkedList.h"
// #include <stdexcept>

template  <class Type>
class FifthElement : public LinkedList<Type>{
    public:
    Type getFifthElement(); //This method returns the data at the fifth node (not index) of the linked list. It will throw a length error (i.e. throw length_error("There is no fifth element");) if there is no fifth element in the list
    void insertNewFifthElement(const Type &value); //This method inserts a node containing a value between the existing 4 and 5 nodes so that the original 5th node becomes the 6th node in the list. If there are only 4 nodes in the list, the new node will become the last node in the list. 
    void deleteFifthElement();//This method deletes the 5th node. If there was a 6th node, the 4th node now points to the 6th node. If there was no 6th node, the 4th node becomes the new back node. 
    void swapFourthAndFifthElement(); //This method rearranges the 4th and 5th nodes. It cannot swap the data in the nodes, it instead must rearrange pointers.
};


//This method returns the data at the fifth node (not index) of the linked list. 
// It will throw a length error (i.e. throw length_error("There is no fifth element");) 
// if there is no fifth element in the list
template  <class Type>
Type FifthElement<Type>::getFifthElement(){
    
    if(this->count < 5){
        throw std::runtime_error("There is no fifth element");
    }
    // using the peek function inherited from LinkedList!
    return this->peek(4);

}


// can use the insert function inherited fromn LinkedList
//This method inserts a node containing a value between the existing 4 and 5 nodes so that the original 5th node becomes the 6th node in the list. 
// If there are only 4 nodes in the list, the new node will become the last node in the list.
template  <class Type>
void FifthElement<Type>::insertNewFifthElement(const Type &value){
    if(this->count <4){
        this->insert(value);
    }

    // creating new node dynamically 
    Node<Type>* insertFifth = new Node<Type>;
    // stores the value passed in into the node 
    insertFifth->data = value;

    // create pointer that points to the first element
    Node<Type>* currElement = this->front;

    // loop currEl to the 5th position
    for(int i = 1; i < 4; i++){
        currElement = currElement->next;
    }

    // point to the right nodes 
    insertFifth->next = currElement->next;
    currElement->next = insertFifth;
    // have to increment count from LinkedList?
    // this->count++;
    
    }


// can use the remove function inherited from LinkedList
//This method deletes the 5th node. If there was a 6th node, 
// the 4th node now points to the 6th node. If there was no 6th node, the 4th node becomes the new back node.
template  <class Type>
void FifthElement<Type>::deleteFifthElement(){
    this->remove(4);
}


// nothing to inherit , will need to create
template  <class Type>
void FifthElement<Type>::swapFourthAndFifthElement(){
    // create pointer that points to the first element
    Node<Type>* currElement = this->front;

    // loop currEl to the 4th position
    for(int i = 1; i < 3; i++){
        currElement = currElement->next;
    }
    // creating pointer for 4th element and set it to currElement (4th right now because of loop)
    Node<Type>* fourthElement = currElement->next;
    Node<Type>* fifthElement = fourthElement->next;

    // now we swap 4 & 5
    currElement->next = fifthElement;
    fourthElement->next = fifthElement->next;
    fifthElement->next = fourthElement;

}