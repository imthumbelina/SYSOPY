#include <stdio.h>
#include <stdlib.h>
#include "list.h"



int main() {



BSTNode**root=malloc(sizeof(BSTNode*));
*root = NULL;
insert(root,"A","B","C","D","E","D");
insert(root,"b","d","C","D","E","D");
printTree(*root);








}
