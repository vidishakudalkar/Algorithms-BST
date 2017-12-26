#include <iostream>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

void BST::preorder() const
{
	preorderRecursion(myRoot);
}


void BST::preorderRecursion(BinNode* node ) const{
	if(myRoot!= 0)
	{
		cout<< node->data<< " ";
		if(node->left != 0)
		{
			preorderRecursion(node->left);
		}
		
		if(node->right!= 0){
			preorderRecursion(node->right);
		}
	}
	else 
		cout<< "Tree empty"<<endl;
	
}

void BST::inorder() const
{
	inorderRecursion(myRoot);
}	
	
	

void BST::inorderRecursion(BinNode* node ) const{
	
	if(myRoot!= 0)
	{
	if(node->left != 0)
	{
		inorderRecursion(node->left);
		}
		cout<< node->data<< " ";
	if(node->right!= 0){
		inorderRecursion(node->right);
		}
		
	}
	else 
		cout<< "Tree empty"<<endl;

}


void BST::nodeCount() const
{
	int count = 0;
	count = nodeCountRecursion(myRoot,count);
	cout<<count<<endl;
}	
	
	

int BST::nodeCountRecursion(BinNode* node , int count) const{
	if(node!=0)
	{
		count = 1 + nodeCountRecursion(node->left, count) + nodeCountRecursion(node->right, count);
		return count;
	}
	else{
		return 0;
	}
}


void BST::delete_node(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   char pos;
   if(myRoot == 0)
   {
	   cout << "Tree is Empty. No such item to delete" << endl;
	   return;
	   
	}
   while (!found && locptr != 0)
   {
      if (item < locptr->data)
	  {
		  parent = locptr;
		  locptr = locptr->left;
		  pos = 'l';
	  }
   
         
      else if (locptr->data < item)  // descend right
	  {
		  parent = locptr;
		  locptr = locptr->right;
		  pos = 'r';
	  }
  
      else                           // item found
         found = true;
   }
   
   if (found)
   {            
	   if(locptr->left == 0 && locptr->right == 0){
			if(parent == 0){
				  myRoot = 0;
			}
			else if(parent->left == locptr){
				parent->left=0;
			}
			else{
				parent->right=0;
			}
	   }
	   
	   else if(locptr->left == 0 && locptr->right != 0)
	   {
		   if(parent == 0){
				  myRoot = locptr->right;
			}
			else if(parent->left == locptr){
				parent->left=locptr->right;
			}
			else{
				parent->right=locptr->right;
			}

		}
		
		else if(locptr->left != 0 && locptr->right == 0)
	   {
		   if(parent == 0){
				  myRoot = locptr->left;
			}
			else if(parent->left == locptr){
				parent->left=locptr->left;
			}
			else{
				parent->right=locptr->left;
			}

		}
		
		else if(locptr->left != 0 && locptr->right != 0)
		{
				BinNode* temp = locptr;
				parent = locptr;
				locptr = locptr->left;
				
				while(locptr->right != 0)
					{
						parent = locptr;
						locptr = locptr->right;
					}
					
				temp->data = locptr->data;
				
				if(parent->left!=0 && parent->left->data == locptr->data)
				{
					
					if(locptr->left!=0)
					{
						parent->left = locptr->left;
					}
					
					else
					{
						parent->left = 0;
					}
					
				}
				
				else if(parent->right->data == locptr->data)
				{
					
					if(locptr->left!=0)
					{
						parent->right = locptr->left;
					}
					
					else
					{
						parent->right = 0;
					}
					
				}
				

		}

   }
   else
      cout << "Item doesnt exist in the tree\n";
}
