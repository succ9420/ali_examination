/*************************************************************************
    > File Name: dfs.cpp
    > Author: scc
    > Created Time: 2017年03月10日 星期五 17时12分06秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
	int x, y, value;
	Node(int _x, int _y, int _value){
		x = _x;
		y = _y;
		value = _value;
	}
};

int FindMAX(int i0, int j0, int in, int jn, int step, int* data, int rows, int columns){
	queue<Node*> q;
	int val = data[(i0 - 1) * rows + j0 - 1];
	Node* node = new Node(i0, j0, val);
	q.push(node);
	vector<int> v1;
	vector<int> v2;
	v1.push_back(node->value);

	int stepNow = step; //控制步数
	int nowcnt = 1; //记录当前步数有多少种选择
	int nextcnt = 0;//记录下一步有多少种选择
	int i = 0;//用于索引上一步的累加和
	
	vector<int> ret; //记录最终结果，最多有四个

	while(!q.empty() && stepNow){
	
		Node* p = q.front();
		q.pop();
//		if (nextcnt == 0) cout <<endl;
//		cout <<p->value<<'\t';
		nowcnt--;

		Node* tmp;

		if(p->x - 1 < 0) ;
		else{
			tmp = new Node(p->x - 1, p->y, data[(p->x - 1 - 1) * rows + p->y - 1]);
			q.push(tmp);
			v2.push_back(v1[i] + tmp->value);
			nextcnt ++;
			if(stepNow == 1 && p->x - 1 == in && p->y == jn){
				ret.push_back(v1[i] + tmp->value);
			}
		}
		if(p->x + 1 >= rows) ;
		else{
			tmp = new Node(p->x + 1, p->y, data[(p->x + 1 - 1) * rows + p->y - 1]);
			q.push(tmp);
			v2.push_back(v1[i] + tmp->value);
			nextcnt ++;
			if(stepNow == 1 && p->x + 1 == in && p->y == jn){
				ret.push_back(v1[i] + tmp->value);
			}
		}
		if(p->y - 1 < 0) ;
		else{
			tmp = new Node(p->x, p->y - 1, data[(p->x - 1) * rows + p->y - 1 - 1]);
			q.push(tmp);
			v2.push_back(v1[i] + tmp->value);
			nextcnt ++;
			if(stepNow == 1 && p->x == in && p->y - 1 == jn){
				ret.push_back(v1[i] + tmp->value);
			}
		}
		if(p->y + 1 >= columns) ;
		else{
			tmp = new Node(p->x - 1, p->y + 1, data[(p->x - 1) * rows + p->y + 1 - 1]);
			q.push(tmp);
			v2.push_back(v1[i] + tmp->value);
			nextcnt ++;
			if(stepNow == 1 && p->x == in && p->y + 1 == jn){
				ret.push_back(v1[i] + tmp->value);
			}
		}
		
		i++;
		if(nowcnt == 0){
			stepNow --;
			nowcnt = nextcnt;
			nextcnt = 0;
			i = 0;
			v1.clear();
			v1 = v2;
			v2.clear();
		}
	}
	int size = ret.size();
	if(size == 0) return -1;
	int ans = 0;
	for(int l = 0; l < size; l++){
		if(ret[l] > ans) ans = ret[l];
	}
	return ans;
	
}

int main(){
	int a[] = {
		2,5,8,7,7,4,5,9,5,2,
		5,9,5,0,4,2,1,7,2,0,
		4,4,7,0,0,1,6,1,2,7,
		4,4,3,4,2,0,8,9,1,5,
		3,6,4,1,8,1,3,1,0,7,
		7,5,1,7,7,1,0,5,5,3,
		3,9,7,8,3,1,0,3,2,1,
		8,6,9,5,7,9,8,0,0,8,
		7,9,3,0,6,2,3,7,8,8,
		0,3,7,9,1,2,3,1,7,5
	};
	int i0 = 2, j0 = 10;
	int in = 4, jn = 8;
	int step = 6;
	int result = FindMAX(i0, j0, in, jn, step, a, 10, 10);
//	cout <<endl;
	cout <<result << endl;
	return 0;
}
