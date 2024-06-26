# [Platinum V] 더 어려운 스케줄링 - 26094 

[문제 링크](https://www.acmicpc.net/problem/26094) 

### 성능 요약

메모리: 3296 KB, 시간: 12 ms

### 분류

자료 구조, 덱, 우선순위 큐, 트리를 사용한 집합과 맵

### 제출 일자

2022년 11월 27일 21:29:56

### 문제 설명

<p>지환이는 업무에 치여 산다. 하루에도 몇 건인지도 모를 정도로 많은 업무가 들어온다.</p>

<p>각 업무는 양의 정수로 표현되는 고유번호 $p_i$ ($1 \leq p_i \leq N$)를 가지고 있으며, 고유번호는 모두 다르다.</p>

<p>아, 일이 또 추가되었다. 지환이는 결국 일에 치여 과로사해버렸지만, 스케줄링을 하기 위한 기계 ‘지환봇 스케줄러2’는 여전히 정상적으로 작동한다. '지환봇 스케줄러2'는 기본적으로는 스택(stack) 구조, 즉 제일 나중에 들어간 업무가 제일 먼저 처리되는(LIFO, Last in First out) 특성을 가지고 있다.</p>

<p>기본적인 특성과 더불어, '지환봇 스케줄러2'에게 할 수 있는 명령은 다음과 같다.</p>

<ul>
	<li>$0\,p$: 고유번호가 $p$인 업무를 스케줄러에 추가한다. 특별히 다른 명령이 없는 한, 새로 추가된 일은 스케줄러 상의 맨 앞에 추가된다. 즉, 고유번호 값에 상관없이 스케줄러에서 가장 먼저 처리되어야 하는 업무가 된다.</li>
	<li>$1$: 스케줄러에 들어있는 업무를 고유번호 값 기준으로 오름차순으로 정렬한다. 이 결과, 고유번호 값이 낮은 업무일수록 스케줄러의 앞에 배치된다.</li>
	<li>$2$: 스케줄러에 있는 업무 처리 순서를 뒤집는다. 즉, 스케줄러에 들어가 있는 업무들의 처리 순서가 반대가 된다.</li>
	<li>$3$: 스케줄러에 있는 업무 중 가장 앞에 위치한 업무를 꺼내어 처리하고, 그 고유번호 값을 출력한다. $3$번 명령이 들어왔을 때 스케줄러는 비어있지 않으며, 스케줄러에서 꺼내진 업무는 두 번 다시 들어오지 않는다.</li>
</ul>

<p>'지환봇 스케줄러2'에는 여전히 필요 없어 보이는 기능이 있는 것 같지만, 이전보다 효과적인 업무처리를 하고 있는 것 같다. 주어진 $Q$개의 명령을 순서대로 처리해보자.</p>

### 입력 

 <p>첫째 줄에 업무의 고유번호 값의 범위 제한 $N$과 명령 횟수 $Q$가 주어진다. ($1\leq N,Q \leq 100\,000$)</p>

<p>둘째 줄부터 $Q$개 줄에 걸쳐 명령에 대한 정보가 주어진다.</p>

<p>입력으로 주어지는 모든 수는 정수이다.</p>

### 출력 

 <p>$3$번 명령이 주어질 때마다 각 줄에 답을 출력한다.</p>

