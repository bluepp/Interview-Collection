/*
还是一个int array,一开始递增然后递减．求最大最小．
最小就是两头数字比较取最小
source : http://www.mitbbs.com/article_t/JobHunting/32705311.html
G tel
*/

/*
最大值，我一开始说如果我工作中碰到了，我第一个想法用Arrays.sort，
对方说好，什么效率？我说NlogN or worst can be N^2．
然后对方说有没有更加快的，我开始想，然后他说ｌｏｇＮ可以做，
我说那就是binary search了，写下了binary serach的基本结构就是low high, 
mid = (low+high)/2,
然后我自言自语说怎么比较呢？怎么比较才知道应该在ｍｉｄ左边还是右边继续搜寻？
愣了一下，然后对方说可以和邻居比较阿，我说对，就开始写．
写出基本架构，然后对对方说还有边界条件要查的，比如ｉｎｄｅｘ不能小于０，
不能大于数组长度，我说我等等来写．对方说不用写了，我说哦．
*/
