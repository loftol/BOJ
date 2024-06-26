# [Platinum II] 세상에서 제일 착한 다솜 - 1752 

[문제 링크](https://www.acmicpc.net/problem/1752) 

### 성능 요약

메모리: 5532 KB, 시간: 108 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 1월 23일 20:22:13

### 문제 설명

<p>다솜이는 눈이 오늘 날 아침이면 어김없이 테라스에 나가 발자국을 남기는 것이 취미다. 하지만 늦게 일어나는 조교는 단지 발자국만을 보며 추측할 수 밖에 없다. 그러던 어느 날 아침에 조교는 다솜이의 발자취가 궁금해졌다. 하지만 이미 너무 많은 학생들이 왔다 갔다 했기에 발자취를 찾기란 쉬운 일이 아니었다.</p>

<p>한 가지 확실한 점은 학생들은 언제나 일직선으로 이동하며 눈을 밟으며 걸음폭도 일정하다는 것이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/25fbcb20-9955-4bf8-9263-1a5a8c7096b4/-/preview/" style="width: 424px; height: 29px;"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/f476a40f-d2b7-48e1-a770-d604e2215693/-/preview/" style="width: 203px; height: 29px;"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5214c998-7033-4b11-805e-958a8db938aa/-/preview/" style="width: 222px; height: 122px;"></p>

<p>위의 그림과 같이 다솜이를 포함한 학생들의 발자취는 뛰는 간격이나 방향이 서로 제각각일 수 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/edcb2604-d9c1-4d32-a975-4baaea367a27/-/crop/443x298/535,0/-/preview/" style="width: 221px; height: 149px;"></p>

<p>위의 그림에서와 같이 학생들은 밖에서부터 일직선으로 들어와 정확한 보폭으로 눈을 밟고 지나간다.</p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="https://upload.acmicpc.net/1942a92a-e6b8-449f-93cb-f9380d7e22e5/-/crop/400x298/0,0/-/preview/" style="width: 200px; height: 149px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/1942a92a-e6b8-449f-93cb-f9380d7e22e5/-/crop/349x298/587,0/-/preview/" style="width: 175px; height: 149px;"></td>
		</tr>
		<tr>
			<td>그림 3</td>
			<td>그림 4</td>
		</tr>
	</tbody>
</table>

<p>그림 3과 같이 아침에 여러 학생들은 제각기 다른 방향에서 들어와 서로 다른 방향으로 밟고 지나간다. 물론 여러 명이 한 곳을 밟을 수도 있다. 그리고 늦잠을 잔 조교는 그림 4와 같이 밟고 지나간 최종 상태만 볼 수 있다.</p>

<p>그림 4를 보면, 학생들이 몇 명 들어 와서 어느 방향으로 어느 간격으로 눈 위에 발자국을 내고 갔는지 그 경로를 재현할 수 있다. 단, 세 번 이상 눈 위에 발자국을 낸 학생의 경로만 생각하기로 한다. 그렇다면, 그림 4의 상황이라면 그림 3과 같은 세 개의 학생 경로가 있다고 말할 수 있다. (물론 다른 가짓수도 있을 수 있다.)</p>

<p>한편, 첫째 칸에서 수직으로 내려가는 경로는 보폭이 4인 학생의 경로일 수도 있지만, 이 경로는 총 발자국이 두 개이기 때문에 고려하지 않는다. 그리고 둘째 줄 셋째 칸(2, 3), 셋째 줄 넷째 칸(3, 4), 여섯째 줄 일곱째(6, 7) 칸을 지나는 경로는 일직선이고 세 개의 발자국을 남겼지만, 간격이 일정하지 않기 때문에 한 학생이 밟고 간 경로로 인정하지 않는다.</p>

<p>어떤 학생이 밟고 간 경로에 속하는 선상에 다른 학생이 밟고 간 곳이 있을 수 있다. 예를 들어 위 그림에서 (2, 1), (2, 3), (2, 5), (2, 7)은 한 학생이 밟고 간 경로인데, 이 선 안에는 (2, 6)처럼 다른 학생이 밟고 간 곳이 있을 수 있다. 그리고 사실은, 발자국이 있지만 이번에 학생이 남긴게 아닌 이 전에 눈이 왔을 때 남은 발자국일 수도 있다</p>

<p>세상에서 제일 착한 다솜이는 가장 많은 발자국을 남기고 지나가기에 이를 찾는 것이 문제이다. 그림 4의 경우, 정답은 7이다. 여섯째 줄부터 가로로 일곱 발자국을 모두 밟고 지나간 학생을 다솜이로 추정할 수 있기 때문이다.</p>

### 입력 

 <p>첫째 줄에는 테라스의 세로, 가로 크기를 나타내는 정수 R과 C(1 ≤ R, C ≤ 5000)가 있다. 그리고 둘째 줄에는 학생들의 발자국 수 N(3 ≤ N ≤ 5000)이 있다.  그리고 다음 N 줄에는 발자국이 있는 좌표를 나타내는 정수 두 개가 뒤따른다. 처음 것이 줄(세로) 좌표이고 나중 것이 칸(가로) 좌표이다. (1 ≤ 줄 좌표 ≤ R, 1 ≤ 칸 좌표 ≤ C) 두 정수는 공백 한 칸으로 구분된다. 여러 학생에게 밟혔더라도 좌표는 한 번만 나온다.</p>

### 출력 

 <p>다솜이로 추정되는 가장 많은 발자국을 남기고 간 학생의 발자국 수를 출력한다. 만약 학생의 경로를 하나도 발견하지 못했다면 그냥 0을 출력한다.</p>

