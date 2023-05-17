//week1_02
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 10050

int main(){
    char array[max];
    fgets(array,max,stdin);
    int len = strlen(array);
    int array_amount[max]={0};
    int ct =0,ten=1,jg=0;
    for(int i=0;i<len;i++){
        if(isdigit(array[i])){
            if(jg)
                array_amount[ct] = -1*(-1*array_amount[ct]*ten +array[i]-'0');
            else 
                array_amount[ct] =array_amount[ct]*ten+array[i]-'0';
            if(ten!=10)ten*=10;
        }
        else if(array[i]=='-'&&isdigit(array[i+1])){
            jg=1;
        }
        else if(ispunct(array[i])){
            jg=0;
            ct-=1;
            ten=1;
            int a =array_amount[ct-1];
            int b =array_amount[ct];
            array_amount[ct]=0;
            array_amount[ct-1]=0;
            switch(array[i]){
                case '+':
                array_amount[ct-1]=a+b;
                break;
                case '-':
                array_amount[ct-1]=a-b;
                break;
                case '/':
                array_amount[ct-1]=a/b;
                break;
                case '*':
                array_amount[ct-1]=a*b;
                break;
            }
            ct-=1;
        }
        else{
            jg=0;
            if(array[i]!=10){
                ct++;
                ten=1;
            }
        }
    }
    printf("%d\n",array_amount[ct]);
}