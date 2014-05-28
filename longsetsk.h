/× 

array A中含1到N-1的数，要求找到最长的S(k) = A[k], A[A[k]] ...
看起来就像找一个graph的最大loop.

要求O_n


source: http://www.mitbbs.com/article_t/JobHunting/32693351.html
T online test

*/

/*
用图的遍历可做，找largest strongly connected component. 反正各个点都只有一个
degree，BFS/DFS都一样。
用python写个:
*/

visited=[0 for i in range(n)]
max_loop_number = 0
k = 0
for i in range(n):
  loop_number = 0
  while visited[i] == 0:
    loop_number += 1
    visited[i]=1
    i = A[i]
  if loop_number > max_loop_number: 
    max_loop_number = loop_number
    k = i
return k
每个点都只遍历一遍，时间theta(n)
