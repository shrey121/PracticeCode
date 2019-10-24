
 /* Experiment No. 6: Expression tree from a postfix expression and tree
                     traversals using recursive and non-recursive algorithms
*/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct treenode
{
         char data;
         struct treenode *left,*right;
}treenode;
typedef struct stack
  {
        treenode *data[20];
        int top;
  }stack;
void init(stack *s)
 {
        s->top=-1;
 }
treenode * pop(stack *s)
 {
        treenode *p;
        p=s->data[s->top];
        s->top=s->top-1;
        return(p);
 }
void  push(stack *s, treenode *p)
  {
        s->top=s->top+1;
        s->data[s->top]=p;
  }
int empty(stack *s)
 {
        if(s->top==-1)
                return(1);
        return(0);
 }
int full(stack *s)
  {
        if(s->top==19)
                return(1);
        return(0);
  }

treenode *create();
void inorder(treenode *T);
void preorder(treenode *T);
void postorder(treenode *T);
void non_rec_preorder(treenode *T);
void non_rec_inorder(treenode *T);
void non_rec_postorder(treenode *T);
int main()
{
        treenode *root=NULL,*p;
        int x,op;
        do
          {
                printf("\n\n1)Create\n2)Preorder(recursive)");
                printf("\n3)Inorder(recursive)\n4)Posorder(Recursive)");
                printf("\n5)Preorder(Non-Recursive)\n6)Inorder(Non-Recursive)");
                printf("\n7)Postorder(Non-Recursive\n8)Quit");
                printf("\nEnter Your Choice :");
                scanf("%d",&op);
                switch(op)
                  {
                        case 1: root=create();break;
                        case 2: preorder(root);break;
                        case 3: inorder(root);break;
                        case 4: postorder(root);break;
                        case 5: non_rec_preorder(root);break;
                        case 6: non_rec_inorder(root);break;
                        case 7: non_rec_postorder(root);break;

                  }
         }while(op!=8);
}


void inorder(treenode *T)
{
        if(T!=NULL)
        {
                inorder(T->left);
                printf("%c",T->data);
                inorder(T->right);
        }
}

void preorder(treenode *T)
 {      if(T!=NULL)
          { printf("%c",T->data);
            preorder(T->left);
            preorder(T->right);
          }
 }
void postorder(treenode *T)
 {      if(T!=NULL)
          {
            postorder(T->left);
            postorder(T->right);
            printf("%c",T->data);
          }
 }
void non_rec_preorder(treenode *T)
 {
        stack s;
        init(&s);
        printf("\n");
        if(T==NULL)
                return;
        while(T!=NULL)
          {
                printf("%c",T->data);
                push(&s,T);
                T=T->left;
          }
      while(!empty(&s))
         {
                T=pop(&s);
                T=T->right;
                while(T!=NULL)
                  {
                        printf("%c",T->data);
                        push(&s,T);
                        T=T->left;
                  }
         }

 }

void non_rec_inorder(treenode *T)
 {
        stack s;
        init(&s);
        printf("\n");
        if(T==NULL)
                return;
        while(T!=NULL)
          {
                push(&s,T);
                T=T->left;
          }
        while(!empty(&s))
          {
                T=pop(&s);
                printf("%c",T->data);
                T=T->right;
                while(T!=NULL)
                   {
                        push(&s,T);
                        T=T->left;
                   }
          }
 }

 void non_rec_postorder(treenode *T)
  {
        stack s,s1;
        treenode *flag;
        init(&s);init(&s1);
        printf("\n");
        if(T==NULL)
            return;
        while(T!=NULL)
           {
                push(&s,T);push(&s1,NULL);
                T=T->left;
           }
        while(!empty(&s))
           {
                T=pop(&s);flag=pop(&s1);
                if(flag!=NULL)
                        printf("%c",T->data);
                else
                  {
                        push(&s,T);push(&s1,(treenode*)1);
                        T=T->right;
                        while(T!=NULL)
                           {
                                push(&s,T);push(&s1,NULL);
                                T=T->left;
                           }
                 }
           }
  }

treenode * create()
 {
        char a[50];
        int i;
        treenode *p,*q,*root;
        stack s;
        init(&s);
        fflush(stdin);
        printf("\nEnter a postfix expression : ");
        gets(a);
        for(i=0;a[i]!='\0';i++)
           {
                if(isalnum(a[i]))
                   {
                        p=(treenode*)malloc(sizeof(treenode));
                        p->left=p->right=NULL;
                        p->data=a[i];
                        push(&s,p);
                   }
                else
                   {
                        q=pop(&s);
                        p=pop(&s);
                        root=(treenode*)malloc(sizeof(treenode));
                        root->left=p;
                        root->right=q;
                        root->data=a[i];
                        push(&s,root);
       }
    }
  root=pop(&s);
  return(root);
 }

/*

OUTPUT:

1)Create
2)Preorder(recursive)
3)Inorder(recursive)
4)Posorder(Recursive)
5)Preorder(Non-Recursive)
6)Inorder(Non-Recursive)
7)Postorder(Non-Recursive
8)Quit
Enter Your Choice :1

Enter a postfix expression : abc*+


1)Create
2)Preorder(recursive)
3)Inorder(recursive)
4)Posorder(Recursive)
5)Preorder(Non-Recursive)
6)Inorder(Non-Recursive)
7)Postorder(Non-Recursive
8)Quit
Enter Your Choice :2
+a*bc

1)Create
2)Preorder(recursive)
3)Inorder(recursive)
4)Posorder(Recursive)
5)Preorder(Non-Recursive)
6)Inorder(Non-Recursive)
7)Postorder(Non-Recursive
8)Quit
Enter Your Choice :3
a+b*c

1)Create
2)Preorder(recursive)
3)Inorder(recursive)
4)Posorder(Recursive)
5)Preorder(Non-Recursive)
6)Inorder(Non-Recursive)
7)Postorder(Non-Recursive
8)Quit
Enter Your Choice :4
abc*+

1)Create
2)Preorder(recursive)
3)Inorder(recursive)
4)Posorder(Recursive)
5)Preorder(Non-Recursive)
6)Inorder(Non-Recursive)
7)Postorder(Non-Recursive
8)Quit
Enter Your Choice :5

+a*bc

1)Create
2)Preorder(recursive)
3)Inorder(recursive)
4)Posorder(Recursive)
5)Preorder(Non-Recursive)
6)Inorder(Non-Recursive)
7)Postorder(Non-Recursive
8)Quit
Enter Your Choice :6

a+b*c

1)Create
2)Preorder(recursive)
3)Inorder(recursive)
4)Posorder(Recursive)
5)Preorder(Non-Recursive)
6)Inorder(Non-Recursive)
7)Postorder(Non-Recursive
8)Quit
Enter Your Choice :7

abc*+

1)Create
2)Preorder(recursive)
3)Inorder(recursive)
4)Posorder(Recursive)
5)Preorder(Non-Recursive)
6)Inorder(Non-Recursive)
7)Postorder(Non-Recursive
8)Quit
Enter Your Choice :8

*/
