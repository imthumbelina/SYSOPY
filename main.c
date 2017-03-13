#include <stdio.h>
#include <stdlib.h>
#include "list.h"



int main() {

  //  list_t*list=createList();

  //  node_t*a=createNode("Agnieszka","pierzchala","a","b","c","d");
  //  addNodeEnd(list,a->firstname,a->lastname,a->email,a->phone,a->address,a->birthdate);
  //  printList(list);
    //node_t*c=createNode("muma","the dog","idonthave","9999","aaa","ddd");
    //addNodeEnd(list,c->firstname,c->lastname,c->email,c->phone,c->address,c->birthdate);
    //node_t*m=createNode("haha","ble","a","b","c","d");
    //addNodeEnd(list,m->firstname,m->lastname,m->email,m->phone,m->address,m->birthdate);

    //printListL(list);
    //list_t*s=selection_sort(list,1);
    //printListL(s);

  //  BSTTree* tree=createTree();
  //  BSTNode*root=tree->root;
    //root=insert3(root,"Agnieszka","Pierzchala");

    //for(int i=0;i<100;i++){
      //root=insert3(root,"Agnieszka","Pierzchala");
  //  }
    //printTree(root);
    //printf("%s","tu usuwam");

    //deleteTree(root);
    //root=NULL;
    //if(root==NULL){
      //printf("%s","to jest puste");
    //}
    //printTree(root);




  list_t*list=createList();
  list_t*sorted=createList();

  for(int i=0;i<5;i++){
    addNodeEnd(list,"a","b","c","d","e","f");
  }
  printList(list);
 sorted=selection_sort(list,1);

 printListL(sorted);
 printf("%d",findContact(sorted,"a","b"));
 deleteContact(sorted,"a","b");
 printList(sorted);





}
