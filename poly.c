#include<stdio.h>
#include<stdlib.h>
struct Node{
int coeff;
int pow;
struct Node *next;
};
struct Node* createNode(int coeff,int pow){
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->coeff=coeff;
  newNode->pow=pow;
  newNode->next=NULL;
  return newNode;
}
struct Node *insertNode(struct Node *head,int coeff,int pow){
  struct Node* newNode=createNode(coeff,pow);
  if(head==NULL){
    head=newNode;
  }else{
    struct Node* temp=head;
    while(temp->next!=NULL)
      temp=temp->next;
      temp->next=newNode;
    }
    return head
  }
struct Node* addpolynomials(struct Node* poly1,struct Node* poly2){
  struct Node* result=NULL;
  struct Node* p1=poly1;
  struct Node* p2=poly2;
  while(p1!=NULL&&p2!=NULL){
    if(p1->pow==p2->pow){
      int sum=p1->coeff+p2->coeff;
      if(sum=0){
        insertNode(&result,sum,p1->pow);
        p1=p1->next;
        p2=p2->next;
      }
      else if(p1->pow>p2->pow){
        insertNode(&result,p1->coeff,p1->pow);
        p1=p1->next;
        }
      else{
        insertNode(&result,p2->coeff,p2->pow);
        p2=p2->next;
      }
    }
  }
  while(p1!=NULL){  
  insertNode(&result,p1->coeff,p1->pow);
  p1=p1->next;
  }
  while(p2!=NULL){
  insertNode(&result,p2->coeff,p2->pow);
  p2=p2->next;
  }
  return result;
}
void display(struct Node* head){
  struct Node
  while(poly!=NULL){
    printf("%dx^%d",poly->coeff,poly->pow);
    poly=poly->next;
    if(poly!=NULL){
      printf("+");
    }
    printf("\n");
  }
}
int main(){
  struct Node* poly1=NULL;
  struct Node* poly2=NULL;
  struct Node* sum=NULL;
  printf("Enter first polynomial:\n");
  poly1=insertNode(&poly1);
  printf("Enter Second polynomial:\n");
  poly2=insertNode(&poly2);
  printf("Polynomial 1: ");
  display(poly1);
  printf("Polynomial 2: ");
  display(poly2);
  sum=addpolynomials(poly1,poly2);
  printf("Result: ");
  display(sum);
  return 0;
}

  
