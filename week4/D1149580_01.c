//week04_01
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1000
#define eg 47
int making(int *array){
    array[0]=0;
    array[1]=1;
    for(int i=2;i<eg;i++){
        array[i]=array[i-1]+array[i-2];
    }
    return 0;
}

int main(){
    int *array=malloc(max*sizeof(int));
    memset(array,0,max*sizeof(int));
    making(array);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int in=0;
        scanf("%d",&in);

        int ct=0;
        for(int k=0;k<eg;k++){
            if(array[k]>in)break;
            ct++;
        }
        int meo=in;
        printf("%d = ",meo);
        for(int k =ct-1;k>=2;k--){
            
            if(meo-array[k]>=0){
                meo-=array[k];
                printf("1");
            }
            else{
                printf("0");
            }
        }
        printf(" (fib)\n");
    }
}