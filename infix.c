#include <stdio.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char c){
    stack[++top]=c;
}
char pop(){
    return stack[top--];
}
char stop(){
    return stack[top];
}
int isOp(char c){
    return(c=='+'||c=='-'||c=='*'||c=='/');
}
int preced(char c){
    if(c=='+'||c=='-')return 1;
    if(c=='*'||c=='/')return 2;
    return 0;
}
void covert(char infix[],char postfix[]){
    int i=0,j=0;
    char c;
    while((c=infix[i++])!='\0'){
        if(c==' '||c=='\t')continue;
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
            postfix[j++]=c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(top!=-1&&stop()!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else if(isOp(c)){
            while(top!=-1&&preced(stop())>=preced(c)){
                postfix[j++]=pop();
            }
            push(c);
        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int main(){
    char infix[MAX],postfix[MAX];
    printf("Enter infix expression:\n");
    fgets(infix,MAX,stdin);
    covert(infix,postfix);
    printf("Postfix: %s\n",postfix);
    return 0;
}


