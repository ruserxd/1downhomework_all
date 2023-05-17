#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#define max 10
//存放0的位置
struct location{
    int x;
    int y;
}typedef loc;
//初始化的答案
int answer[max][max];
int jg_times=0,ans=0;
//判斷是否為答案
bool judge_ans(int array[max][max],int answer[max][max]){
    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            if(array[i][k]!=answer[i][k])return false;
        }
    }
    return true;
}
//觀察陣列的圖形
void print8_puzzle(int array[max][max]){
   for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            printf("%d ",array[i][k]);
        }
        printf("\n");
    } 
}
//判斷有沒有超出邊界
bool jg_exceed_edge(loc meo){
    if(meo.x>2||meo.x<0)return false;
    else if(meo.y>2||meo.y<0)return false;
    return true;
}
loc me(int x, int y ){
    loc m = {x,y};
    return m;
}
//演算法的地方
int run(int array[max][max],loc meo,int ct_run,int origin[max][max]){//跑的陣列,0的位置,次數
    if(judge_ans(array,origin))return -1;
    
    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            origin[i][k]=array[i][k];
        }
    }
    if(judge_ans(array,answer)){
        if(jg_times==0)ans = ct_run;
        if(jg_times>0&&ans>ct_run){
            ans=ct_run;
        }
        jg_times++;
        return ct_run;
    }
    else{
        int x_up[4]={1,0,-1,0};
        int y_up[4]={0,1,0,-1};

        }
    return ct_run;
}
//創立答案的函式
void create_ans_jg(){
    int ct=0;
    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            answer[i][k]=ct;
            ct++;
        }
    }
    answer[2][2]=0;
}

int main(){
    //初始化一個陣列
    int array[max][max];
    //初始化一個答案
    create_ans_jg();
    //紀錄0的位置
    loc memory;
    //輸入答案
    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            scanf("%d",&array[i][k]);
            if(array[i][k]==0){
                memory.x=i;
                memory.y=k;
            }
        }
    }
    /*printf("%d %d\n",memory.x,memory.y);
    print8_puzzle(array);
    print8_puzzle(answer);*/
    printf("\n%d\n",run(array,memory,0,array));
    if(jg_times==0) printf("impossible\n");
}