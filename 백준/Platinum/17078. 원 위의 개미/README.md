# [Platinum IV] 원 위의 개미 - 17078 

[문제 링크](https://www.acmicpc.net/problem/17078) 

### 성능 요약

메모리: 3588 KB, 시간: 60 ms

### 분류

이분 탐색, 누적 합

### 문제 설명

<p>택희는 원 하나를 갖고 있고, 그 원의 둘레를 일정한 속도로 기어다니는 개미 <em>M</em>마리를 키우고 있다. 각 개미들의 크기는 무시할 수 있을 정도로 매우 작다.</p>

<p>어느 날 택희는 원주를 <em>N</em>(≥<em>M</em>)등분하는 점을 찍고, 각 지점에 시계방향으로 1, 2, 3, …, <em>N</em>의 번호를 붙였다. 각 지점의 번호를 시계방향으로 읽으면 1, 2, 3, …, <em>N</em>이 되며, <em>N</em>번 지점 다음에는 1번 지점이 있게 될 것이다. 그 후, 모든 개미가 서로 다른 어떤 지점 위에 있도록 개미들을 놓았다. 개미들은 시계방향 또는 반시계방향의 초기 방향을 바라보고 있으며, 택희가 “시작”을 외치면 모든 개미들은 바라보고 있는 방향으로 이동하게 된다. 시작 시각은 0이며, 그 이후 정확히 1초마다 개미들은 다음 지점에 도착한다.</p>

<p>모든 개미는 동일한 속력으로 이동하다가, 서로를 마주칠 경우 그 즉시 방향을 바꾸어 돌아가게 된다. 개미들은 무한히 움직이며 택희가 찍은 <em>N</em>개의 점을 밟고 지나다니게 될 것이다.</p>

<p>택희는 개미들의 초기 위치와 방향에 따라, 같은 시간동안 상대적으로 조금 더 많이 밟히는 지점들이 있을 것이라 생각했다. 하지만 개미들은 멈추지 않기 때문에, 실제로 그런 지점이 있는지는 확인할 수가 없었다.</p>

<p>개미들은 시각 0에 자신이 서 있는 지점을 밟고 있으므로, 개미가 초기에 서 있는 모든 지점은 시각 0에 밟힌 횟수가 1이며, 아닌 모든 지점은 시각 0에 밟힌 횟수가 0이다. 또한, 개미 두 마리가 동시에 어떤 지점을 밟을 경우, 그 지점은 그 시각에 두 번 밟힌 것으로 센다.</p>

<p>택희는 자신이 세운 가설을 실험할 프로그램이 필요하다고 판단하였다. 정확히는, 어떤 지점 <em>P</em>가 <em>X</em>번 이상 밟히게 되는 최초의 시각이 여러 개 궁금해졌다. 택희를 위해, 이러한 질의를 빠르게 해결해 줄 프로그램을 작성해보도록 하자.</p>

### 입력 

 <p>첫 줄에 원주 위의 점의 개수 <em>N</em> (2 ≤ <em>N</em> ≤ 10<sup>5</sup>)과 개미의 수 <em>M</em> (1 ≤ <em>M</em> ≤ <em>N</em>), 택희가 궁금해하는 정보의 수 <em>Q</em> (1 ≤ <em>Q</em> ≤ 10<sup>5</sup>)가 주어진다.</p>

<p>이어 <em>M</em>개의 줄에 각 개미들의 초기 위치 <em>P<sub>i</sub></em>와 진행방향 <em>d<sub>i</sub></em>가 주어진다. (1 ≤ <em>P<sub>i</sub></em> ≤ <em>N</em>, <em>d<sub>i</sub></em> = 0 or 1)</p>

<p>모든 <em>P<sub>i</sub></em>는 서로 다르다.</p>

<p><em>d<sub>i </sub></em>= 0일 경우 개미는 시계방향으로 이동하고, <em>d<sub>i </sub></em>= 1일 경우 반시계방향으로 이동한다.</p>

<p>이어 <em>Q</em>줄에 걸쳐, 택희가 궁금해하는 정보 <em>P</em> <em>X</em>가 주어진다. (1 ≤ <em>P</em> ≤ <em>N</em>, 1 ≤ <em>X</em> ≤ 10<sup>9</sup>)</p>

<p>이는 지점 <em>P</em>가 <em>X</em>번 이상 밟히는 최초의 시각이 궁금하다는 의미이다.</p>

### 출력 

 <p><em>Q</em>줄에 걸쳐, 각 질의의 답을 출력한다. 시작 시각은 0이다.</p>

