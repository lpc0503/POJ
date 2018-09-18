/***************************************
* POJ 2823 Sliding Window              *
* http://poj.org/problem?id=2823       *
***************************************/

#include<iostream>
#include<cstdio>

using namespace std;

int N, K;
int n = 1;

int array[1000001];
int que[1000001];
int index[1000001];
int ans[1000001];

void getmin(){

	int tail = 0, head = 1;
	
	for(int i = 1 ; i < K ; i++){

		while(tail >= head && que[tail] >= array[i])
			tail--;

		que[++tail] = array[i];
		index[tail] = i;
	}

	for(int i = K ; i <= N ; i++){

		while(tail >= head && que[tail] >= array[i])
			tail--;

		que[++tail] = array[i];
		index[tail] = i;

		while(index[tail] - index[head] >= K)
			head++;

		ans[n++] = que[head];
	}
}

void getmax(){

	int tail = 0, head = 1;
	
	for(int i = 1 ; i < K ; i++){

		while(tail >= head && que[tail] <= array[i])
			tail--;

		que[++tail] = array[i];
		index[tail] = i;
	}

	for(int i = K ; i <= N ; i++){

		while(tail >= head && que[tail] <= array[i])
			tail--;

		que[++tail] = array[i];
		index[tail] = i;

		while(index[tail] - index[head] >= K)
			head++;

		ans[n++] = que[head];
	}
}

void print(){

	for(int i = 1 ; i < n; i++){

		printf("%d ", ans[i]);
	}
	putchar('\n');
}

int main(void){

	#ifndef ONLINE_JUDGE
	freopen("POJ2823.in", "r", stdin);
	freopen("POJ2823.out", "w", stdout);
	#endif

	while(~scanf("%d %d", &N, &K)){
	
		for(int i = 1 ; i <= N ; i++)
			scanf("%d", &array[i]);

		getmin();
		print();

		n = 1;

		getmax();
		print();
	}
	return 0;
}