/*
  bluepp
  2014-12-19
  May the force be with me!

http://www.mitbbs.com/article_t1/JobHunting/32611137_0_1.html  
假设你是harry potter，在grid的左上角，你现在要走到右下角，grid中有
正数也有负数，遇到正数表示你的strength增加那么多，遇到负数表示strength减少那
么多，在任何时刻如果你的strength小于等于0，那么你就挂了。在一开始你有一定的
初始的strength，现在问这个初始的strength最少是多少，才能保证你能够找到一条路
走到右下角。每一步只能向右或者向下。

Just dp:

f(m, n) = 0

f(i, j) = min(
  max(f(i+1, j) - w(i+1,j), 0),
  max(f(i, j+1) - w(i, j+1), 0)
)
*/
