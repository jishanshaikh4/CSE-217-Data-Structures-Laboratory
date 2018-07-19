#include <stdio.h>
#include <stdlib.h>

struct node{
 int num;
 struct node *next;
};

void create(struct node **head){
  int c, ch;
  struct node *temp, *rear;
  do{
   printf("Enter number: ");
   scanf("%d", &c);
   temp = (struct node *)malloc(sizeof(struct node));
   temp->num = c;
   temp->next = NULL;
   if (*head == NULL){
    *head = temp;
   }
   else{
    rear->next = temp;
   }
   rear = temp;
   printf("Do you wish to continue [1/0]: ");
   scanf("%d", &ch);
  }while(ch!=0);
  printf("\n");
}

void generate_evenodd(struct node *list, struct node **head){
 struct node *even = NULL, *odd = NULL, *temp;
 struct node *reven, *rodd;
 while (list != NULL){
  temp = (struct node *)malloc(sizeof(struct node));
  temp->num = list->num;
  temp->next = NULL;
  if (list->num % 2 == 0){
   if (even == NULL){
     even = temp;
   }
   else{
     reven->next = temp;
   }
   reven = temp;
  }
  else{
   if (odd == NULL){
    odd = temp;
   }
   else{
    rodd->next = temp;
   }
   rodd = temp;
  }
  list = list->next;
 }
 reven->next = odd;
 *head = even;
}

void release(struct node **head)
{
 struct node *temp = *head;
 *head = (*head)->next;
 while ((*head) != NULL)
 {
  free(temp);
  temp = *head;
 (*head) = (*head)->next;
 }
}

void display(struct node *p)
{
  while (p != NULL)
  {
   printf("%d\t", p->num);
   p = p->next;
  }
  printf("\n");
}


int main()
{
 struct node *p = NULL, *q = NULL;
 int key, result;
 printf("Enter data into the list\n");
 create(&p);
 printf("Displaying the nodes in the list:\n");
 display(p);
 generate_evenodd(p, &q);
 printf("Displaying the list with even and then odd:\n");
 display(q);
 release(&p);
 return 0;
}



