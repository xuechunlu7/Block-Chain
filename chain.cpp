#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <cstdlib>

// PA1 functions
//TODO: insertFront// rotate

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){
/*your code here*/
    clear();
    }




/**
 * Inserts a new node in position one of the Chain,
 * after the sentinel node.
 * This function **SHOULD** create a new Node.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertFront(const Block & ndata){
/* your code here! */

    Node* newNode = new Node(ndata);

        newNode->next = head_->next;
        head_->next->prev = newNode;
        head_->next = newNode;
        newNode->prev = head_;
        length_++;


}


/**
 * Inserts a new node at the back of the Chain,
 * but before the tail sentinel node.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
    
   /* your code here! */

    Node* newNode = new Node(ndata);
    newNode->prev = tail_->prev;
        tail_->prev->next = newNode;
        newNode->next = tail_;
        tail_->prev = newNode;
    length_++;
    /* your code here! */
    


//    Node* newNodePtr= new Node(ndata);
//
//    //    if (length_==0){
//    //        head_=newNodePtr;
//    //        newNodePtr->next=tail_;
//    //        length_++;
//    //    }
//    //    else {
//    newNodePtr->prev=tail_;
//    tail_->next= newNodePtr;
//    //newNodePtr->next=NULL; DEFAULT
//
//    tail_=newNodePtr;
//    length_++;
//    //    }
//
//    newNodePtr=NULL;

}



/**
 * Modifies the Chain by moving a contiguous subset of Nodes to
 * the end of the chain. The subset of len nodes from (and
 * including) startPos are moved so that they
 * occupy the last len positions of the
 * chain (maintaining the sentinel at the end). Their order is
 * not changed in the move.
 */


// EXTRA STUFF, DELETE LATER
/* Returns a pointer to the node in the kth position of the list.
 * beyond curr. It effectively walks forward k steps from curr.
 * You may use this function in your solutions
 * to the PA1 functions. GIVEN in chain_given.cpp.
 typename Chain::Node * Chain::walk(Node * curr, int k){
 
 if (k==0 || curr == NULL)
 return curr;
 else
 return walk(curr->next,k-1);
 }
 */

void Chain::moveToBack(int startPos, int len){
    if (empty())return;

    if (startPos+len>size()||startPos<=0||len<=0)return;
    
    Node* nodeS=walk(head_,startPos);
    Node* nodeBeforeS = walk(head_,startPos-1);

    Node* nodeL=walk(nodeS,len-1);
    Node* nodeAfterL=walk(nodeS,len);
   
    nodeS->prev=tail_->prev;
    tail_->prev->next = nodeS;
    nodeL->next=tail_;
    tail_->prev=nodeL;
    nodeBeforeS->next = nodeAfterL;
    nodeAfterL->prev = nodeBeforeS;}

    


/**
 * Rotates the current Chain by k nodes: removes the first
 * k nodes from the Chain and attaches them, in order, at
 * the end of the chain (maintaining the sentinel at the end).
 */
void Chain::rotate(int k){
     moveToBack(1, k);
   
}

/**
 * Modifies the current chain by swapping the Node at pos1
 * with the Node at pos2. the positions are 1-based.
 */
//void Chain::swap(int pos1, int pos2){
//
//    if (pos1<0||pos2<0||pos1>length_||pos2>length_)return;
//    if (pos1+1==pos2 || pos2+1 == pos1){
//        Node* pre1 = walk(head_,pos1-1);
//        Node* curr1 = walk(head_,pos1);
//        Node* curr2 = walk(head_,pos2);
//        Node* next2 = walk(head_,pos2+1);
//        pre1->next = curr2;
//        curr2->prev = pre1;
//        curr2->next = curr1;
//        curr1 ->prev = curr2;
//        curr1->next = next2;
//        next2->prev = curr1;
//
//
//
//    }
//
//    else{
//        Node* curr1 = walk(head_,pos1);
//    Node* curr2 = walk(head_,pos2);
//
//    Node* pre1 = walk(head_,pos1-1);
//    Node* next1 = walk(head_,pos1+1);
//
//    Node* pre2 = walk(head_,pos2-1);
//    Node* next2 = walk(head_,pos2+1);
//
//
//    pre1->next = curr2;
//    curr2->prev = pre1;
//    curr2->next = next1;
//    next1->prev = curr2;
//
//    pre2->next = curr1;
//    curr1->prev = pre2;
//    curr1->next = next2;
//    next2->prev = curr1;
//
//    }}

void Chain::swap(int pos1, int pos2){
    
    if (pos1<=0||pos2<=0||pos1>size()||pos2>size()||empty())return;
    //ptrs for pos1
    Node* nodePos1= walk(head_,pos1);
    Node* nodePos1Back= walk(nodePos1,1);
    Node* nodePos1Front=nodePos1->prev;
    //ptrs for pos2
    Node* nodePos2= walk(head_,pos2);
    Node* nodePos2Back= walk(nodePos2,1);
    Node* nodePos2Front=nodePos2->prev;
    
    if (nodePos2Back != nodePos1||nodePos2Front!=nodePos1 ){ //not next to each other
        //n2 to pos1 front
        nodePos1Front->next=nodePos2;
        nodePos2->prev=nodePos1Front;
        
        //n2 to pos1 back
        nodePos1Back->prev=nodePos2;
        nodePos2->next=nodePos1Back;
        
        //n1 to pos2 front
        nodePos2Front->next=nodePos1;
        nodePos1->prev=nodePos2Front;
        
        
        //n1 to pos2 back
        nodePos2Back->prev=nodePos1;
        nodePos1->next=nodePos2Back;
    }
    if(nodePos1Back == nodePos2){ //pos 1 at front
        nodePos1Front->next=nodePos2;
        nodePos2->prev=nodePos1Front;
        
        nodePos1->next=nodePos2Back;
        nodePos2Back->prev=nodePos1;
        
        nodePos2->next=nodePos1;
        nodePos1->prev=nodePos2;
    }
    if(nodePos1Front == nodePos2){
        nodePos2Front->next=nodePos1;
        nodePos1->prev=nodePos2Front;
        
        nodePos1->next=nodePos2;
        nodePos2->prev=nodePos1;
        
        nodePos2->next=nodePos1Back;
        nodePos1Back->prev=nodePos2;
    }
}

/*
 *  Modifies both the current and input chains by trading
 * nodes in even positions between the chains. Length
 * of each chain should stay the same. If the block dimensions
 * are NOT the same, the funtion has no effect and a simple
 * error message is output: cout << "Block sizes differ." << endl;
 */

void Chain::twist(Chain & other){
    if (width_!=other.width_ || height_!=other.height_){
        std::cout << "Block sizes differ." << std::endl;
    }
    
    int len = min(other.length_,length_);
    
    for (int i=1;i<=len;i++){
        if (i%2==0){
            Node* curr1 = walk(head_,i);
            Node* pre1 = curr1->prev;
            Node* next1 = curr1->next;
            
            Node* curr2 = walk(other.head_,i);
            Node* pre2 = curr2->prev;
            Node* next2 = curr2->next;
            
            // chain1:
            pre1->next = curr2;
            curr2->prev = pre1;
            curr2->next = next1;
            next1->prev = curr2;
            
            // chain2:
            pre2->next = curr1;
            curr1->prev = pre2;
            curr1->next = next2;
            next2->prev = curr1;
        }
    }
    }




/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */

void Chain::clear() {
    Node* cursor = head_;

    while(cursor){

        Node * nodeToDelete = cursor;
        cursor = cursor->next;
        delete nodeToDelete;
        nodeToDelete=NULL;
    }}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */

void Chain::copy(Chain const& other) {
  
    length_ = 0;
    width_ = other.width_;
    height_ = other.height_;

    head_ = new Node(Block());
    tail_ = new Node(Block());
    head_->next = tail_;
    tail_->prev = head_;
    head_->prev = NULL;
    tail_->next = NULL;


    if (other.length_== 0) return;
    
    for (int i = 1; i <= other.length_; i++){
        this->insertBack(walk(other.head_,i)->data);
    }

    }


