 #include <iostream>
 using namespace std;

 // data structure to hold an int data and a pointer to the
 //   next node
 struct IntNode {
     int data;
     IntNode * next = NULL;
 };

 // data structure to hold the head and tail of the list, as well
 //   as the current size
 struct LinkedList {
     IntNode * head = NULL;
     IntNode * tail = NULL;
     int size = 0;
 };

 // Initialize a LinkedList, ll, with a new IntNode with
 //   data = dataVal, set size to 1
 void initLinkedList(LinkedList &ll, int dataVal) {
     ll.head = ll.tail = new IntNode;
     ll.head->data = dataVal;
     ll.size = 1;
 }

 // add a new IntNode with data = dataVal to the end of
 //   the LinkedList, ll
 void add_tail(LinkedList &ll, int dataVal) {
     ll.tail->next = new IntNode;
     ll.tail = ll.tail->next;
     ll.tail->data = dataVal;
     ll.size++;
 }

 // add a new IntNode with data = dataVal at location idx in
 //   the middle of the LinkedList, ll
 void add_index(LinkedList &ll, int dataVal, int idx){
     // if the index is beyond the end of the current list, add to
     //   the end of the list
     if (idx >= ll.size) {
         add_tail(ll, dataVal);
         return;
     }

     IntNode * tmp = new IntNode;
     IntNode * tmp2 = ll.head;
     for (int i = 0; i < idx-1; i++) {
         tmp2 = tmp2->next;
     }
     tmp->data = dataVal;
     tmp->next = tmp2->next;
     tmp2->next = tmp;
     ll.size++;
 }

 // TODO add_head
 void add_head(LinkedList &ll, int dataVal){
     IntNode * tmp = new IntNode;
     tmp -> data = dataVal;
     tmp -> next = ll.head;
     ll.head = tmp;
     ll.size++;
 }
 // remove the last IntNode in LinkedList, ll
 void remove_tail(LinkedList &ll) {
     IntNode * tmp = ll.head;
     for (int i = 0; i < ll.size - 2; i++) {
         tmp = tmp->next;
     }
     delete tmp->next;
     tmp->next = NULL;
     ll.tail = tmp;
     ll.size--;
 }

 // TODO remove_index
void remove_index(LinkedList &ll, int idx){
    IntNode * tmp = ll.head;
    for(int i=0; i < idx-1; i++){
        tmp = tmp -> next;
    }
    IntNode * tmp2 = tmp;
    tmp -> next = tmp -> next -> next;
    delete tmp2 -> next;
    ll.size--;
}
 // TODO remove_head
void remove_head(LinkedList &ll){
    IntNode * tmp = ll.head -> next;
    delete ll.head;
    ll.head = tmp;
    ll.size--;
}
 int main() {
     IntNode * a;
     LinkedList myLL;
     initLinkedList(myLL, 0);

     for(int i = 1; i < 5; i++) {
         add_tail(myLL, i);
     }

     add_index(myLL, 32, 3);
     add_index(myLL, 64, 3);

     // TODO: When you have completed the add_head function,
     //   uncomment the  following two test cases
     add_head(myLL, -1);
     add_head(myLL, -2);

     a = myLL.head;
     while (a != NULL) {
         cout << a->data << endl;
         a = a->next;
     }

     cout << "myLL is now of size: " << myLL.size;
     cout << " and myLL.tail->data is: " << myLL.tail->data << endl;

     // TODO: When you have completed the remove_head function,
    //    uncomment the  following two test cases and their cout lines
     remove_head(myLL);
     cout << "myLL is now of size: " << myLL.size;
     cout << " and myLL.head->data is: " << myLL.head->data << endl;
     remove_head(myLL);
     cout << "myLL is now of size: " << myLL.size;
     cout << " and myLL.head->data is: " << myLL.head->data << endl;

     // TODO: When you have completed the remove_index function,
     //   uncomment the  following two test cases and their cout lines
     remove_index(myLL, 3);
     cout << "myLL is now of size: " << myLL.size;
     cout << " and myLL.tail->data is: " << myLL.tail->data << endl;
     remove_index(myLL, 3);
     cout << "myLL is now of size: " << myLL.size;
     cout << " and myLL.tail->data is: " << myLL.tail->data << endl;

     int sz = myLL.size;
     for(int i = 0; i < sz; i++) {
         remove_tail(myLL);
         cout << "myLL is now of size: " << myLL.size;
         cout << " and myLL.tail->data is: " << myLL.tail->data << endl;
     }

     return 0;
 }