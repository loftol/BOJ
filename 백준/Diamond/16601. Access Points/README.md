# [Diamond V] Access Points - 16601 

[문제 링크](https://www.acmicpc.net/problem/16601) 

### 성능 요약

메모리: 19080 KB, 시간: 64 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 수학, 스택

### 문제 설명

<p>A well-known programming contest is considering a new way to position its teams. For the contest all n teams have to be assigned some position (x, y) in an infinitely-large gym hall. To keep a good overview of the teams the following strategy is chosen:</p>

<p>All teams have been assigned a unique integer ID in the range [1, n]. Any two teams with IDs i and j, where i < j, must be placed at positions (x<sub>i</sub>, y<sub>i</sub>), (x<sub>j</sub>, y<sub>j</sub>), such that x<sub>i</sub> ≤ x<sub>j</sub> and y<sub>i</sub> ≤ y<sub>j</sub>.</p>

<p>Unfortunately, someone already assigned the (fixed) internet access point for each team. The access points are quite big and only have one port, so access points for different teams are located at different positions. Every team must be connected to its designated access point by a direct UTP cable. The cost of a UTP cable of length ℓ is ℓ<sup>2</sup>.</p>

<p>Find a placement for all teams, such that their respective order along both axes is maintained and the total cost of the required UTP cables is minimised. As the judges are not too worried about privacy, they are fine with two (or more) teams being placed at the exact same location or being arbitrarily close together. See Figure A.1 for an example.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/67ce1f5a-b910-4d46-9b4e-bd615d230e91/-/preview/" style="width: 383px; height: 306px;"></p>

<p style="text-align: center;">Figure A.1: Illustration of an optimal placement for Sample Input 1. Team placement (boxes), access points (circles), and required UTP cables (dashed).</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with one integer n (1 ≤ n ≤ 10<sup>5</sup>), the number of teams.</li>
	<li>n lines, the ith of which contains two integers s<sub>i</sub>, t<sub>i</sub> (1 ≤ s<sub>i</sub>, t<sub>i</sub> ≤ 10<sup>6</sup>), the location of the internet access point of team i.</li>
</ul>

<p>No two access points are at the same position.</p>

### 출력 

 <p>Output the minimum total cost of all UTP cables required to connect the teams to their access points in an optimal legal layout.</p>

<p>Your answer should have an absolute or relative error of at most 10<sup>−6</sup>.</p>

