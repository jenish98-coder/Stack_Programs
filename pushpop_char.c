/*Write a program to create and perform push, pop, peek and display
operation on a stack with character data.*/

/*Write a program to create and perform push, pop, peek and display
operation on a stack with integer data.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
int stack[MAX];
void push();
void pop();
void display();
void peak();
int main(){
    int choice;
    while(1){
        printf("choice:\n");
        scanf("%d",&choice);
         getchar();
    
    
    switch(choice){
        case 1:push();
        break;

        case 2:pop();
        break;

        case 3:peak();
        break;

        case 4:display();
        break;

        case 5:
        exit(0);

    
}
}

    return 0;
    

}

void push(){
    char data;
    if(top==MAX-1){
        printf("overflow\n");
    }
    else{
        printf("Enter the data\n");
        scanf("%c",&data);
        top=top+1;
        stack[top]=data;
    }

}
void pop(){
    if(top==-1){
        printf("Underflow\n");
    }
    else{
        stack[top]=0;
        top=top-1;
        
    }

}
void display(){
    if(top==-1){
        printf("Underflow case\n");
    }
    else{
        for( int i=0;i<=top;i++){
            printf("The data are:%c\n",stack[i]);

            }
        }
    }


void peak(){
    if(top==-1){
        printf("no element\n");

    }
    else{
        
       printf("The peak element is:%c\n",stack[top]);
    }

}

