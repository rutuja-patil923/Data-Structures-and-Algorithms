#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N1,N2,N3;
	cin>>N1>>N2>>N3;

	int stack1[N1],stack[N2],stack[N3];
	int sum1=0,sum2=0,sum3=0;

	for(int i=0;i<N1;i++)
	{
		cin>>stack1[i];
		sum1 += stack1[i];
	}
	for(int i=0;i<N2;i++)
	{
		cin>>stack2[i];
		sum2 += stack2[i];
	}
	for(int i=0;i<N3;i++)
	{
		cin>>stack3[i];
		sum3 += stack3[i];
	}
	
	int top1=0,top2=0,top3=0;
	while(1)
	{
		if(top1==N1 || top2==N2 || top3==N3)
			return 0;
		if(sum1==sum2 && sum2==sum3)
			return sum1;
		if(sum1>=sum2 && sum1>=sum3)
			sum1 -= stack1[top1++];
		if(sum2>=sum1 && sum2>=sum3)
			sum2 -= stack2[top2++];
		if(sum3>=sum1 && sum3>=sum2)
			sum3 -= stack3[top3++];
	}
}