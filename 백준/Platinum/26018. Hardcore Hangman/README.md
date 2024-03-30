# [Platinum V] Hardcore Hangman - 26018 

[문제 링크](https://www.acmicpc.net/problem/26018) 

### 성능 요약

메모리: 13856 KB, 시간: 12 ms

### 분류

애드 혹, 이분 탐색, 비트마스킹, 해 구성하기, 수학

### 제출 일자

2024년 3월 30일 16:54:56

### 문제 설명

<p>You have probably heard about the game called hangman (and played it as a child). You try to guess a word with as few guesses as possible. In each guess, you suggest a letter, for example an <code>a</code>, and you get all the positions in the word, where an <code>a</code> appears.</p>

<p>That can take quite a few guesses, in particular, if a difficult word was chosen. So, let's change the game a bit. Instead of guessing just a single letter, any set of letters can be guessed in one turn. As a result you get all positions which contain one of the guessed letters.</p>

<p>If the word is 'hangman' and you guess the letters <code>h</code>, <code>z</code> and <code>a</code> in the first turn, you get the positions 1, 2 and 6. Of course, you still don't know whether there is an <code>h</code>, <code>z</code> or <code>a</code> at these positions, but it has to be one of those three letters.</p>

<p>Your task is to find the hidden word (it is not always a proper English word, but can be any string consisting of lowercase English letters) using at most 7 guesses.</p>

### 입력 

 Empty

### 출력 

 Empty

