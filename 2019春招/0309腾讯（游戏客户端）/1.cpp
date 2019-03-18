// 雪球在高度为h的山上往下滚落，过程中会与两块高度分别为d1, d2的石头碰撞，碰撞过程雪球减少与石头相同的重量。开始雪球重量为w，每下落一米雪球都会增加当前高度的重量，当雪球与石头碰撞时重量小于石头时，雪球质量会变为0后继续往下滚动，求雪球在高度为0时的重量是多少？

#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int w, h, u1, d1, u2, d2;
	scanf("%d%d%d%d%d%d", &w, &h, &u1, &d1, &u2, &d2);
	for(int i = h; i > 0; i--){
		w+=i;
		if(i==d1) w-=u1;
		else if(i==d2) w-=u2;
		if(w<0){
			w = 0;
		}
	}
	printf("%d\n", w);
	return 0;
} 
