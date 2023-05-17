//week04_02
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define eg 36
int main(){
    int n,m,i,base,cs,x,total,min;
    int *cost=malloc(sizeof(int)*eg);
    memset(cost,0,sizeof(int)*eg);
    int cheaplist[eg],cheapstcount;
    scanf("%d\n",&n);//測資數量
    for(cs=1;cs<=n;cs++)
    {   
        //花費輸入
        for(int o=0;o<eg;o++){
            scanf("%d",&cost[o]);
        }
        scanf("%d",&m);
        printf("Case %d:\n",cs);
        while(m--){
            scanf("%d",&x);
            min=1000000;
            cheapstcount=0;
            for(base=2;base<eg+1;base++){
                total=0;
                int copy=x;
                while(copy>0){
                    total+=cost[copy%base];
                    copy/=base;
                }
                if(total<min){
                    min=total;
                    cheaplist[0]=base;
                    cheapstcount=1;
                }
                else if(total==min){
                    cheaplist[cheapstcount++]=base;
                }   
            }
            printf("Cheapest base(s) for number %d:",x);
            for(base =0;base<cheapstcount;base++){
                printf(" %d",cheaplist[base]);
            }
            printf("\n");
        }
        if(m!=1)printf("\n");
    }
}