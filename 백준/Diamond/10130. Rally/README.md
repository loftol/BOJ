# [Diamond III] Rally - 10130 

[문제 링크](https://www.acmicpc.net/problem/10130) 

### 성능 요약

메모리: 86644 KB, 시간: 964 ms

### 분류

방향 비순환 그래프, 자료 구조, 그래프 이론, 세그먼트 트리, 스위핑, 위상 정렬

### 제출 일자

2024년 6월 21일 16:34:02

### 문제 설명

<p>An annual bicycle rally will soon begin in Byteburg. The bikers of Byteburg are natural long distance cyclists. Local representatives of motorcyclists, long feuding the cyclists, have decided to sabotage the event.</p>

<p>There are n intersections in Byteburg, connected with one way streets. Strangely enough, there are no cycles in the street network - if one can ride from intersection u to intersection v, then it is definitely impossible to get from v to u.</p>

<p>The rally's route will lead through Byteburg's streets. The motorcyclists plan to ride their blazing machines in the early morning of the rally day to one intersection and completely block it. The cyclists' association will then of course determine an alternative route but it could happen that this new route will be relatively short, and the cyclists will thus be unable to exhibit their remarkable endurance. Clearly, this is the motorcyclists' plan - they intend to block such an intersection that the longest route that does not pass through it is as short as possible.</p>

### 입력 

 <p>In the first line of the standard input, there are two integers, n  and m(2 ≤ n ≤ 500,000, 1 ≤ m ≤ 1,000,000), separated by a single space, that specify the number of intersections and streets in Byteburg. The intersections are numbered from 1 to n. The m lines that follow describe the street network: in the i-th of these lines, there are two integers, a<sub>i</sub>, b<sub>i</sub>(1 ≤ a<sub>i</sub>,b<sub>i</sub> ≤ n, a<sub>i</sub>≠b<sub>i</sub>), separated by a single space, that signify that there is a one way street from the intersection no. a<sub>i</sub> to the one no. b<sub>i</sub>.</p>

### 출력 

 <p>The first and only line of the standard output should contain two integers separated by a single space. The first of these should be the number of the intersection that the motorcyclists should block, and the second - the maximum number of streets that the cyclists can then ride along in their rally. If there are many solutions, your program can choose one of them arbitrarily.</p>

