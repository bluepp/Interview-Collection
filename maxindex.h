/*
一个数组，找最大数，可能有重复，要求random输出最大index，
比如[ 1 2 3 4 5 6 6 6], 最大的是6， index可能是5，6， 7。 每次call这个
function的时候，random输出5，6，7. 

source: http://www.mitbbs.com/article_t/JobHunting/32701375.html
Facebook tel
*/


/* 输入数组是无序的，我给的是下面的方法

先scan 一遍，找出最大数max和出现的次数n
然后生成一个随机数m，between 1 to n
然后在scan一遍，找到第m个max，输出idx
*/
