//標頭檔案
#include <iostream>
#include <map>
#include <queue>
#include<vector>
//學習目標： vector ,queue,map

using namespace std;
//判斷上下左右時有沒有超出邊界
//上
bool judge_up(int n){
	if(n<3)return false;
	return true;
}
//下
bool judge_down(int n){
	if(n>5)return false;
	return true;
}
//左
bool judge_left(int n){
	if(n%3==0)return false;
	return true;
}
//右
bool judge_right(int n){
	if(n%3==2)return false;
	return true;
}

int main(){
	map<vector<int>, int> MAP;
	queue<vector<int> > Q;
	//這行程式碼是用來關閉 C++ 的 stdio 和 std::cin 的同步，以提高 I/O 效率。
	ios::sync_with_stdio ( false ); cin.tie(0);
	//輸入要用到的x
	int x;
	//vector 底層實現是一個連續記憶體空間，不夠的空間會再補充
	vector<int> input, ed;
	//輸入測試vector
	for ( int i=0; i<9; ++i ){
		cin >> x;
		input.push_back(x);
	}
	//創立答案的vector
	for ( int i=1; i<9; ++i ){
		ed.push_back(i);
	}
	ed.push_back(0);
	//將MAP加入搜索的Q內
	MAP[input] = 1;
	//將陣列推送進去queue內
	Q.push(input);

	//找出答案
	//上->下->左->右
	while ( !Q.empty()){
		//x為最起點的頭
		vector<int> x = Q.front(); 
		Q.pop();
		//pos代表0的位置 ,curd為步數計算
		int pos = 0, curd = MAP[x];
		//找出0的位置在哪
		while ( x[pos] ) pos++; 

		if ( judge_up(pos)) { // 向上
			swap(x[pos], x[pos-3]);
			//如果這個MAP沒走過步數＋1
			if ( !MAP[x] ) MAP[x] = curd+1, Q.push(x);
			//是終點就停止
			if ( x == ed ) break;
			//還回原位
			swap(x[pos], x[pos-3]);
		}	
		if (judge_down(pos)) { // 向下
			swap(x[pos], x[pos+3]);
			if ( !MAP[x] ) MAP[x] = curd+1, Q.push(x);
			if ( x == ed ) break;
			swap(x[pos], x[pos+3]);
		}
		if (judge_left(pos)) { // 向左
			swap(x[pos], x[pos-1]);
			if ( !MAP[x] ) MAP[x] = curd+1,Q.push(x);
			if ( x == ed ) break;
			swap(x[pos], x[pos-1]);
		}
		if (judge_right(pos) ) { // 向右
			swap(x[pos], x[pos+1]);
			if ( !MAP[x] ) MAP[x] = curd+1,Q.push(x);
			if ( x == ed ) break;
			swap(x[pos], x[pos+1]);
		}
	}
	//輸出答案，若沒找到輸出 impossible 
	if((MAP[ed]-1)==-1)cout<<"impossible";
	else cout<<MAP[ed]-1;
	return 0;
}