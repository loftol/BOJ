# [Gold V] Missing Gnomes - 16043 

[문제 링크](https://www.acmicpc.net/problem/16043) 

### 성능 요약

메모리: 2940 KB, 시간: 20 ms

### 분류

그리디 알고리즘

### 제출 일자

2024년 7월 17일 13:12:51

### 문제 설명

<p>A family of n gnomes likes to line up for a group picture. Each gnome can be uniquely identified by a number 1..n written on their hat.</p>

<p>Suppose there are 5 gnomes. The gnomes could line up like so: 1, 3, 4, 2, 5.</p>

<p>Now, an evil magician will remove some of the gnomes from the lineup and wipe your memory of the order of the gnomes. The result is a subsequence, perhaps like so: 1, 4, 2.</p>

<p>He then tells you that if you ordered all permutations of 1..n in lexicographical order, the original sequence of gnomes is the first such permutation which contains the remaining subsequence. Your task is to find the original sequence of gnomes.</p>

### 입력 

 <p>Each input will consist of a single test case. Note that your program may be run multiple times on different inputs. Each test case will begin with a line with two integers n and then m (1 ≤ m ≤ n ≤ 10<sup>5</sup>), where n is the number of gnomes originally, and m is the number of gnomes remaining after the evil magician pulls his trick. Each of the next m lines will contain a single integer g (1 ≤ g ≤ n). These are the remaining gnomes, in order. The values of g are guaranteed to be unique.</p>

### 출력 

 <p>Output n lines, each containing a single integer, representing the first permutation of gnomes that could contain the remaining gnomes in order.</p>

