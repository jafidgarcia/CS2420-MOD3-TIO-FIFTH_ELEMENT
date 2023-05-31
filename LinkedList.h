#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <ostream>

template<class Type>
struct Node
{
   Type data;
   Node<Type> * next;
};

template<class Type>
class LinkedList;

template<class Type>
std::ostream& operator<<(std::ostream& out, const LinkedList<Type>& list);

template<class Type>
class LinkedList{
   public:
    LinkedList();// Default constructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    ~LinkedList(); //Destructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    void insert(Type data); //Adds to the back of the list
    Type peek(int ndx); //Looks at an element at the given ndx value
    void remove(int ndx); //Removes an element at the given ndx position
    friend std::ostream& operator<< <>(std::ostream& out, const LinkedList<Type>& list);// Returns an output stream for displaying the LinkedList

    protected:
        Node<Type>* front;
        Node<Type>* back;
        int count;

};

// CONSTRUCTOR - empty list
template<class Type>
LinkedList<Type>::LinkedList(){
    front = nullptr;
    back = nullptr;
    count = 0;
}
/////////////////// END /////////////////////////// 


// DE-CONSTRUCTOR - delete list
template<class Type>
LinkedList<Type>::~LinkedList(){
    Node<Type>* temp = front;

    // Loop through each node in the list
    while(front != nullptr){
        // Set the temporary pointer to the current front node
        temp = front;
        // Move the front of the list to the next node
        front = front->next;
        // Delete the node that 'temp' is pointing to. This does not affect
        // 'front', because we already moved it to the next node.
        delete temp;
    }
}
/////////////////// END /////////////////////////// 



// Template function for inserting a new node in the linked list. 'Type' is a placeholder
// for any data type. This means that this function can work with linked lists of any data type.
template<class Type>
void LinkedList<Type>::insert(Type data){
     // Create a new Node object using the 'new' keyword, which dynamically allocates memory.
    // The 'new' keyword returns a pointer to the memory location, so 'temp' is a pointer to a Node.
    Node<Type>* temp = new Node<Type>();
    // Assign the data passed into the function to the 'data' member of the new node.
    temp->data = data;
    
    // If 'front' is null, it means that the list is empty.
    if(!front){
        // Since this is the first node in the list, 'front' and 'back' will both point to this node.
        this->front = temp;
        this->back = temp;
    }
    else{
         // If the list is not empty, we add the new node to the end of the list.

        // First, we make sure that the 'next' pointer of the new node is pointing to null,
        // since it will be the last node in the list.
        temp->next = nullptr;
        // Then, we update the 'next' pointer of the current last node to point to the new node.
        back->next = temp;
        // Finally, we update the 'back' pointer to point to the new node, which is now the last node in the list.
        back = temp;
    }
    count++;
}
/////////////////// END /////////////////////////// 


// allows us to look at any particular node in our list
template<class Type>
Type LinkedList<Type>::peek(int ndx){
    int currentNodeNum = 0;
    auto currentNode = front;

    if(ndx >= count){
        throw std::runtime_error("Item does not excist");
    }
    while(currentNodeNum < ndx){
        currentNodeNum ++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
 }
 /////////////////// END /////////////////////////// 



template<class Type>
void LinkedList<Type>::remove(int ndx){
    int currentNodeNum = 0;
    auto currentNode = front;

    if(ndx >= count){
        throw std::runtime_error("Item does not exist");
    }

    if(ndx == 0){
        front = front->next;
        delete currentNode;
        return;
    }

    while(currentNodeNum < ndx -1){
        currentNodeNum ++;
        currentNode = currentNode->next;
    }
    auto toDelete = currentNode->next;
    currentNode->next = toDelete->next;
    delete toDelete;

 }
  /////////////////// END /////////////////////////// 



template<class Type>
std::ostream& operator<<(std::ostream& out, const LinkedList<Type>& list){
    auto currentNode = list.front;
    while(currentNode){
        out << currentNode->data;
        if(currentNode->next){
            out << " ";
        } //end if
        currentNode = currentNode->next;
    } // end while
    return out;
}

#endif