#include <stdio.h>
#include <math.h>
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int c = b - a;
		double t = sqrt(c);
		int max = (int)t;
		int max_length = max * max; // 1..max..1 의 합.
		int left = c - max_length; // 남은 거리
		int time = 2 * max - 1; // max_length 까지의 이동횟수
		double j = (double)left / max; // 남은 거리는 최대속도 이하의 속도로 이동하므로 이 값만큼의 추가이동이 필요. 소수점이라면 +1 
		/*printf("최대 속도 %d\n", max);
		printf("최대속도이동거리 %d\n", max_length);
		printf("최대속도이동거리 이동횟수 %d\n", time);
		printf("전체거리 - 최대속도이동거리 = 남은거리 %d\n", left);
		printf("남은거리를 이동하는데 필요한 최소 이동횟수 %lf\n", j);*/
		printf("%d\n", (int)ceil(time + j));
		
	}
}
/*
노가다로 해보면 1 2 3 3 4 4 5 5 5 6 6 6 7 7 7 7 8 8 8 8 ... 의 규칙을 찾게 된다.
위 규칙을 사용해 풀게되면 복잡도가 O(b-a) 가 되는데, 선형복잡도를 가지지만 최대 입력이 워낙 커서 시간초과가 뜬다.
문제를 읽어보면 시작이동거리와 마지막 이동거리는 1로 고정되어있다. 따라서, 어느 최대이동거리를 이동한 시점 이후 이동거리가 점점 감소하게 된다.
한번에 감소할 수 있는 이동거리는 1이므로, 최대 이동거리를 3이라 하면, 1 2 3 2 1 의 이동을 무조건 포함하게 된다. 
각각의 이동과 이동 사이에 3이하의 이동이 포함될 수 있다[ex) 1 2 3 3 2 1 =12]. 따라서, 무조건 포함되는 이동의 이동횟수와, 그것을 제외한 거리를
이동한 이동횟수를 합한게 답이 된다.
여기서, 남은 거리는 최대이동거리 이하의 거리씩만 이동하게 되므로, 남은거리를 최대 이동거리로 나눈 후, 이의 올림값이 남은거리의 이동횟수가 된다.
*/
