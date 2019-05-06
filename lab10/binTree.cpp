 #include<iostream>
 using namespace std;

 struct treeNode {
     int val;
     treeNode *left;
     treeNode *right;
 };

 void initialize(treeNode *t, int n) {
     t->val = n;
     t->left = t->right = 0;
 }

 void insert(treeNode *t, int n) {
     cout << "insert t " << t->val << " n " << n << endl;
     treeNode **child;
     if (n <= t->val) child = &(t->left);
     else child = &(t->right);
     if (0 == *child) {  // create new node and store value
         *child = new treeNode;
         initialize(*child, n);
     } else { // recurse on the correct branch
         insert(*child, n);
     }
 }

 void remove(treeNode *t) {
     cout << "remove t " << t->val << endl;
     if (t->left) remove(t->left);  // get rid of left subtree
     if (t->right) remove(t->right); // get rid of right subtree
     delete t;
 }
void preorderPrint( treeNode *t ) {
    // Print all the items in the tree to which t points.
    // The item in the root is printed first, followed by the
    // items in the left subtree and then the items in the
    // right subtree.
    if (t != NULL) { // (Otherwise, there's nothing to print.)
        cout << t->val << " ";   // Print the root item.
        preorderPrint(t->left);  // Print items in left subtree.
        preorderPrint(t->right); // Print items in right subtree.
    }
}
void postorderPrint( treeNode *t ) {
    // Print all the items in the tree to which t points.
    // The items in the left subtree are printed first, followed
    // by the items in the right subtree and then the item in the
    // root node.
    if (t != NULL) {  // (Otherwise, there's nothing to print.)
        postorderPrint(t->left);   // Print items in left subtree.
        postorderPrint(t->right);  // Print items in right subtree.
        cout << t->val << " ";     // Print the root item.
    }
}
void inorderPrint( treeNode *t ) {
    // Print all the items in the tree to which t points.
    // The items in the left subtree are printed first, followed
    // by the item in the root node, followed by the items in
    // the right subtree.
    if (t != NULL ) {  // (Otherwise, there's nothing to print.)
        inorderPrint(t->left);   // Print items in left subtree.
        cout << t->val << " ";    // Print the root item.
        inorderPrint(t->right);  // Print items in right subtree.
    }
}
bool treeContains(treeNode *t, int item){
    bool there = 0;
    if (t != NULL ) {
        treeContains(t->left, item);
        if (t-> val == item){
            there = 1;
        }
        treeContains(t->right,item); 
    }
    return there;
}
 int main() {
     treeNode *root = new treeNode;
     initialize(root, 5);
     insert(root, 3);
     insert(root, 4);
     insert(root, 0);
     insert(root, 8);
     insert(root, 10);
     insert(root, 100);
     insert(root, 9);
     insert(root, 5);
     remove(root);
     preorderPrint(root);
     cout << endl;
     postorderPrint(root);
     cout << endl;
     inorderPrint(root);
     cout << endl;
     if(treeContains(root, 0)){
         cout << "the tree has a zero" << endl;
     }
     if(treeContains(root, 100)){
         cout << "the tree has a 100" << endl;
     }
 }
