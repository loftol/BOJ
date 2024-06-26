# [Diamond IV] 요리 강좌 - 14869 

[문제 링크](https://www.acmicpc.net/problem/14869) 

### 성능 요약

메모리: 25640 KB, 시간: 192 ms

### 분류

자료 구조, 덱, 덱을 이용한 구간 최댓값 트릭, 다이나믹 프로그래밍, 덱을 이용한 다이나믹 프로그래밍, 슬라이딩 윈도우

### 제출 일자

2024년 5월 11일 03:38:25

### 문제 설명

<p>여러분은 요리에 관심이 많아 요리 자격증을 취득하려고 한다. 요리 자격증을 취득하기 위해서는 총 M개의 강좌를 순서대로 한 번씩만 수강해야 한다. 이 요리 강좌는 N개의 학원에서 수강할 수 있는데, 학원마다 강좌별 수강비용은 다를 수 있다.</p>

<p>아래 표는 M = 5, N = 4인 경우, 학원별, 강좌별 수강비용의 예를 보여준다.</p>

<table class="table table-bordered table-center-30 td-center th-center">
	<thead>
		<tr>
			<th> </th>
			<th>강좌1</th>
			<th>강좌2</th>
			<th>강좌3</th>
			<th>강좌4</th>
			<th>강좌5</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th>학원1</th>
			<td>1</td>
			<td>2</td>
			<td>1</td>
			<td>3</td>
			<td>8</td>
		</tr>
		<tr>
			<th>학원2</th>
			<td>1</td>
			<td>2</td>
			<td>3</td>
			<td>7</td>
			<td>2</td>
		</tr>
		<tr>
			<th>학원3</th>
			<td>1</td>
			<td>8</td>
			<td>8</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<th>학원4</th>
			<td>10</td>
			<td>1</td>
			<td>1</td>
			<td>8</td>
			<td>8</td>
		</tr>
	</tbody>
</table>

<p>여러분은 비용을 줄이기 위해 중간에 학원을 변경할 수 있는데, 학원을 변경할 때마다 T의 추가 비용이 든다. 단, 학원 변경은 다음 규칙을 지켜야 한다.</p>

<ol style="list-style-type:lower-alpha">
	<li>하나의 학원에서 연속으로 수강할 수 있는 강좌의 수는 최소 S개, 최대 E 개다. 단, 마지막 강좌를 수강하는 학원에서는 강좌 S개 이상을 연속해서 들을 필요가 없다.</li>
</ol>

<p>S = 2이고 E = 3이라고 가정하자. 강좌1을 학원1에서 수강했다면, 강좌2는 무조건 학원1에서 수강해야 하고, 강좌 3은 학원1에서 수강할 수도 있고 다른 학원에서 수강할 수도 있다. 만약 강좌1부터 강좌3을 학원1에서 수강했다면, 강좌4는 무조건 다른 학원에서 수강해야 한다.<br>
또한, S = 1이고 E = 2인 경우, 강좌1과 강좌2를 학원3에서 수강하고, 강좌3과 강좌4를 학원1에서 수강하고, 강좌5를 다시 학원3에서 수강하는 것도 가능하다.</p>

<ol start="2" style="list-style-type:lower-alpha">
	<li>학원마다 직전 강좌를 특정한 학원에서 수강한 학생은 받지 않는데, 이를 ‘불허용 학원’이라고 하자. 각 학원마다 불허용 학원은 하나씩 존재한다.</li>
</ol>

<p>예를 들어, 아래 표의 학원1에 대한 정보는 학원2→학원1로 변경하는 것은 불가능하다는 것을 의미한다. 단, 학원2→학원4→학원1처럼 학원4 수강을 거쳐 변경하는 것은 가능하다.</p>

<table class="table table-bordered table-center-30 td-center th-center">
	<thead>
		<tr>
			<th> </th>
			<th>불허용 학원</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th>학원1</th>
			<td>학원2</td>
		</tr>
		<tr>
			<th>학원2</th>
			<td>학원3</td>
		</tr>
		<tr>
			<th>학원3</th>
			<td>학원4</td>
		</tr>
		<tr>
			<th>학원4</th>
			<td>학원3</td>
		</tr>
	</tbody>
</table>

<p>예를 들어, S = 2, E = 3, T = 2이고, 위 수강비용 표와 불허용 학원 표가 주어졌을 때, 강좌 순서대로 수강하는 학원의 번호가</p>

<ul>
	<li>예1) 1 → 1 → 1 → 1 → 3 인 경우, 규칙 (a)에 위배되어 수강이 가능하지 않다.</li>
	<li>예2) 2 → 2 → 1 → 1 → 1 인 경우, 규칙 (b)에 위배되어 수강이 가능하지 않다.</li>
	<li>예3) 3 → 3 → 1 → 1 → 3 인 경우는 가능한 수강 방법이고, 전체 비용은 1+8+T+1+3+T+2 = 19이다.</li>
	<li>예4) 1 → 1 → 1 → 3 → 3 인 경우는 가능한 수강 방법이고, 전체 비용은 1+2+1+T+1+2 = 9이다.</li>
</ul>

<p>강좌 비용, 강좌 선택에 필요한 규칙 정보가 주어졌을 때, 모든 강좌를 순서대로 수강하기 위해 필요한 최소 비용을 구하시오. </p>

### 입력 

 <p>표준 입력으로 다음 정보가 주어진다. 첫 번째 줄에는 학원의 개수 N과 강좌 개수 M(3 ≤ N ≤ 3,000, 1 ≤ M ≤ 3,000, N × M ≤ 3,000,000), 학원 한 곳에서 연속 수강 가능한 최소 강좌 개수 S와 최대 강좌 개수 E(1 ≤ S ≤ E ≤ M), 그리고 학원 변경 비용 T(0 ≤ T ≤ 35,000)가 주어진다. 다음 N개의 줄에는 각 학원의 강좌별 수강비용이 주어진다. (수강비용은 1 이상 35,000 이하이다.) 처음 줄에는 학원1의 M개의 수강비용이 강좌 순서대로 공백을 사이에 두고 주어지고, 그 다음 줄부터 학원2, 학원3, ... , 학원N의 정보가 한 줄에 하나씩 순서대로 주어진다. 그 다음 N개의 줄에는 학원마다 불허용 학원 번호가 순서대로 주어진다.</p>

### 출력 

 <p>표준 출력으로 최소 비용을 출력한다.</p>

