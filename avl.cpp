
#include<iostream>
#include<algorithm>
using namespace std;

struct avl{
	int data;
	struct avl*left;
	struct avl*right;
}*root;

class avl_tree{
public:
	int height(avl*);
	int difference(avl*);

	avl* rr_rotate(avl*);
	avl* ll_rotate(avl*);
	avl* lr_rotate(avl*);
	avl* rl_rotate(avl*);
	avl* balance(avl*);
	avl* insert(avl* , int );
	
	void show(avl* , int);
	void inorder(avl*);
	void preorder(avl*);
	void postorder(avl*);

	avl_tree(){
		root=NULL;
	}

};



int avl_tree :: height(avl *t){
	
	int h=0;
	

	if(t!=NULL){
		int left_height=height(t->left);
		int right_height=height(t->right);
		int max_height=max(left_height,right_height);
		h=max_height+1;

	}
	return h;
}

avl *avl_tree :: ll_rotate(avl* parent){
	
	avl* t=parent->left;
	parent->left=t->right;
	t->right=parent;
	cout<<"LEFT-LEFT ROTATION";
	return t;

} 

avl *avl_tree :: rr_rotate(avl* parent){

	avl* t=parent->right;
	parent->right=t->left;
	t->left=parent;
	cout<<"RIGHT-RIGHT ROTATION";
	return t;
}

avl *avl_tree :: lr_rotate(avl* parent){

	avl* t=parent->left;
	parent->left=rr_rotate(t);
	cout<<"LEFT-RIGHT ROTATE";
	return ll_rotate(parent);
}

avl *avl_tree :: rl_rotate(avl* parent){
	avl* t=parent->right;
	parent->right=ll_rotate(t);
	cout<<"RIGHT-LEFT ROTATE";
	return rr_rotate(parent);
}

int avl_tree :: difference(avl *t){

	int left_height=height(t->left);
	int right_height=height(t->right);
	int balance_factor=left_height - right_height;
	return balance_factor;


}

avl *avl_tree :: balance(avl *t){

	int balance_factor = difference(t);

	if (balance_factor > 1){
		if(difference(t->left)>0){
			t = ll_rotate(t);
		}
		else{
			t= lr_rotate(t);
		}
	}
	else if(balance_factor < -1){
		if(difference(t->right)>0){
			t=rl_rotate(t);

		}
		else{
			t=rr_rotate(t);
		}
	}
	

	return t;
}


avl *avl_tree :: insert(avl *root,int value){

	if(root==NULL){
		root = new avl;
		root->data=value;
		root->left=NULL;
		root->right=NULL;
		return root; 
	}

	else if(value < root->data){
		root->left=insert(root->left,value);
		root=balance(root);
	}

	else if(value >= root->data){
		root->right=insert(root->right,value);
		root=balance(root);
	}

	return root;
}

void avl_tree :: show(avl *parent,int k){
	
	if(parent!=NULL){
		show(parent->right,k+1);
		cout<<" ";
		if(parent == root){
			cout<<"root ->"; 
		}

		for (int i=0;i<k && parent!=root;i++){
			cout<<" ";
			cout<<parent->data;
			show(parent->left,k+1);
		}
	}
}

void avl_tree::inorder(avl *t) {
   if (t == NULL){
   		 return;
     }
      inorder(t->left);
      cout << t->data << " ";
      inorder(t->right);
}
void avl_tree::preorder(avl *t) {
   if (t == NULL){
      return;
    }
      cout << t->data << " ";
      preorder(t->left);
      preorder(t->right);
}
void avl_tree::postorder(avl *t) {
   if (t == NULL){
      return;
  	}
      postorder(t->left);
      postorder(t->right);
      cout << t->data << " ";
}

int main() {
   int c, val;
   avl_tree avl;
   while (1) {
      cout << "1.Insert Element into the tree" << endl;
      cout << "2.show Balanced AVL Tree" << endl;
      cout << "3.InOrder traversal" << endl;
      cout << "4.PreOrder traversal" << endl;
      cout << "5.PostOrder traversal" << endl;
      cout << "6.Exit" << endl;
      cout << "Enter your Choice: ";
      cin >> c;
      switch (c) {
         case 1:
            cout << "Enter value to be inserted: ";
            cin >> val;
            root= avl.insert(root, val);
         break;
         case 2:
            if (root == NULL) {
               cout << "Tree is Empty" << endl;
               continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show(root, 1);
            cout<<endl;
         break;
         case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder(root);
            cout << endl;
         break;
         case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(root);
            cout << endl;
         break;
         case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder(root);
            cout << endl;
         break;
         case 6:
            exit(1);
         break;
         default:
            cout << "Wrong Choice" << endl;
            exit(1);

      }
   }
   return 0;
}
