# [Platinum IV] Delete the Points - 18508 

[문제 링크](https://www.acmicpc.net/problem/18508) 

### 성능 요약

메모리: 198796 KB, 시간: 2040 ms

### 분류

해 구성하기, 기하학, 정렬

### 제출 일자

2024년 5월 8일 01:05:23

### 문제 설명

<p>There are n points in the plane. The coordinates of the points are integer. The number n is always even.</p>

<p>You can draw a square whose sides are parallel to the coordinate axes. Its vertices can have real coordinates. If there are exactly two points inside the square or on its borders, they are deleted.</p>

<p>You have to find a way to delete all points or say that it is impossible.</p>

### 입력 

 <p>The first line contains a single integer n (1 ≤ n ≤ 3000), the number of points.</p>

<p>Each of the following n lines contains two integers x<sub>i</sub> and y<sub>i</sub> (0 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>9</sup>), describing the coordinates of the i-th point.</p>

<p>All points are distinct.</p>

### 출력 

 <p>If it is impossible to delete all points, print “No” in the first line.</p>

<p>Otherwise, print “Yes” in the first line. In each of the next n/2 lines, print four real numbers: the coordinates of the opposite corners of the square. Squares should be printed in the order in which they should be drawn. If there are several possible answers, print any one of them.</p>

<p>Real numbers should be output with no more than four digits after the decimal point. Print them in the following form: possibly unary minus, then any number of decimal digits, and then possibly a decimal point, followed by up to four decimal digits.</p>

