//week1_01
#include<stdio.h>
#include<string.h>
#define max 10005

int main(){
    char array[max];
    while(scanf("%s",array)!=EOF){
        int ct =0,ct1=0,ct2=0,ct3=0,jg=0,count=0,amount=0;
        int len = strlen(array);
        int ar[4]={0};
        for(int i=0;i<=len;i++){
            switch(array[i]){
                case '(':
                    ct++;
                    amount ++;
                    ar[0]+=amount;
                    count =1;
                    break;
                case ')':
                    ct--;
                    ar[0]-=amount;
                    amount--;
                    if(count!=1&&count!=0){
                        jg=1;
                    }
                    if(ct<0)jg=1;
                    count =0;
                    break;
                case '[':
                    ct1++;
                    amount ++;
                    ar[1]+=amount;
                    count =2;
                    break;
                case ']':
                    ct1--;
                    ar[1]-=amount;
                    amount--;
                    if(count!=2&&count!=0){
                        jg=1;
                    }
                    if(ct1<0)jg=1;
                    count =0;
                    break;
                case '{':
                    ct2++;
                    amount ++;
                    ar[2]+=amount;
                    count =3;
                    break;
                case '}':
                    ct2--;
                    ar[2]-=amount;
                    amount--;
                    if(count!=3&&count!=0){
                        jg=1;
                    }
                    if(ct2<0)jg=1;
                    count =0;
                    break;
                case '<':
                    ct3++;
                    amount ++;
                    ar[3]+=amount;
                    count =4;
                    break;
                case '>':
                    ct3--;
                    ar[3]-=amount;
                    amount--;
                    if(count!=4&&count!=0){
                        jg=1;
                    }
                    if(ct3<0)jg=1;
                    count =0;
                    break;
            }
        }
        if(ct!=0||ct1!=0||ct2!=0||ct3!=0)jg=1;
        if(ar[0]!=0||ar[1]!=0||ar[2]!=0||ar[3]!=0)jg=1;
        if(jg==1)printf("False\n");
        else printf("True\n");
    }
}