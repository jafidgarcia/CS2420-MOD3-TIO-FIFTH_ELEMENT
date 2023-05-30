

#ifndef FIFTHELEMENT_H
#define FIFTHELEMENT_H

#include LINKEDLIST_H

template  <class Type>
class FifthElement : public LinkedList{
    public:
    Type getFifthElement(); //This method returns the data at the fifth node (not index) of the linked list. It will throw a length error (i.e. throw length_error("There is no fifth element");) if there is no fifth element in the list
    void insertNewFifthElement(const Type &value); //This method inserts a node containing a value between the existing 4 and 5 nodes so that the original 5th node becomes the 6th node in the list. If there are only 4 nodes in the list, the new node will become the last node in the list. 
    void deleteFifthElement();//This method deletes the 5th node. If there was a 6th node, the 4th node now points to the 6th node. If there was no 6th node, the 4th node becomes the new back node. 
    void swapFourthAndFifthElement(); //This method rearranges the 4th and 5th nodes. It cannot swap the data in the nodes, it instead must rearrange pointers.

};

#endif

