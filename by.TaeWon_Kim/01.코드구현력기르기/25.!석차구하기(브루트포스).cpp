

/**************************************
25. 석차 구하기
N명의 학생의 수학점수가 입력되면 각 학생의 석차를 입력된 순서대로 출력하는 프로그램을 작성하세요.
▣ 입력설명 
첫 줄에 N(1<=N<=100)이 입력되고, 두 번째 줄에 수학점수를 의미하는 N개의 정수가 입력된다. 
같은 점수가 입력될 경우 높은 석차로 동일 처리한다. 
즉 가장 높은 점수가 92점인데 92 점이 3명 존재하면 1등이 3명이고 그 다음 학생은 4등이 된다. 
점수는 100점 만점이다.
▣ 출력설명 
첫 줄에 입력된 순서대로 석차를 출력한다.
▣ 입력예제 1                                  
5 
90 85 92 95 90
▣ 출력예제 1
3 5 2 1 3
***************************************/
#include<stdio.h>
void bubble_sort(int x[], int count);
int main()
{
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	
	for(int i = 0 ; i<n ; i++)
	{
		scanf("%d", &a[i]);
		b[i] = 1;
	}
	for(int i = 0; i< n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(a[j]>a[i])	b[i]++;
		}
	}
	for(int i = 0; i<n; i++)
	{
		printf("%d ", b[i]);
	}

	return 0;
}
void bubble_sort(int x[], int count)
{
	
}
