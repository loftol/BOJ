# [Platinum II] Lollipop - 8203 

[문제 링크](https://www.acmicpc.net/problem/8203) 

### 성능 요약

메모리: 8012 KB, 시간: 484 ms

### 분류

애드 혹, 수학

### 문제 설명

<p>Byteasar runs a confectionery in Byteburg. Strawberry-vanilla flavoured lollipops are the favourite of local children. These lollipops are composed of multiple segments of the same length, each segment of either strawberry or vanilla flavour. The price of the lollipop is the sum of the values of its segments, where a vanilla segment costs one bythaler, while a strawberry segments costs two.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/8203/1.jpg" style="height:118px; width:56px"><br>
Fig. 1: An exemplary lollipop of five segments, three strawberry flavoured and two vanilla, alternately. The price of this lollipop is 8 bythalers.</p>

<p>Currently Byteasar is left with only one lollipop, though possibly very long. As a salesman, he knows only too well that probably no one will want to buy the whole lollipop. For this reason he thinks of breaking the lollipop at the joints of the segments in order to get a shorter lollipop. Each fragment for sale, of course, must stay in one piece.</p>

<p>Byteasar vast experience of a salesman, as well as his understanding of children psychology, tell him that his young customers will most likely want to spend all their money on a single lollipop. With this in mind, he wonders for which values of k the lollipop he has can be broken down in such a way that as a result one would get, among other pieces, a lollipop worth exactly k bythalers. Naturally, he is interested in the way of breaking the lollipop as well. As this task overwhelms him, he asks you for help.</p>

### 입력 

 <p>In the first line of the standard input there are two integers n and m (1 ≤ n,m ≤ 1,000,000), separated by a single space. These denote, respectively, the number of segments of the last lollipop left in store, and the number of values of k to consider. The lollipop's segments are numbered from 1 to n. The second line gives an n-letter description of the lollipop, consisting of letters T and W, where T denotes a strawberry flavoured segment, while W - vanilla flavoured; the i-th of these letters specifies the flavour of the i-th segment. In the following m lines successive values of k (1 ≤ k ≤ 2,000,000) to consider are given, one per line.</p>

<p> </p>

### 출력 

 <p>Your program should print out exactly m lines, giving, one per line, the results for successive values of k, to the standard output. If for a given value of k it is impossible to break the lollipop in such a way that there is a contiguous fragment worth exactly k bythalers, then the word NIE (no in Polish) should be printed. Otherwise, two integers l  and r (1 ≤ l ≤ r ≤ n), separated by single spaces, should be printed, such that the fragment of the lollipop composed of the segments numbered from l to r inclusively is worth exactly k bythalers. If there are multiple such pairs, your program is free to choose one arbitrarily.</p>

<p> </p>

