
/*
给一个int array代表一个数字，实现＋１这个功能

source :  http://www.mitbbs.com/article_t/JobHunting/32705311.html
G tel

*/


/*
第一道，给一个int array代表一个数字，实现＋１这个功能。
和对方交流第一个数字会不会是加号或者减号，对方答曰不会，
就是一个正数，就开始写。
如果有问题就是有个Arrays.copy的api没有记清楚，
跟对方说有这么个api大致是这样的，作这样的事情，
对方说好，lets pretend there is an api that would do this.
我心下说本来就有，我不记得了．．．

ＰＳ，第一次写的要历遍所有ｉｎｄｅｘ，后来他说不用，我想了想说对，
应该碰到９以下就ｓｔｏｐ．修改．
对方对我把最后一位单独拎出来也不满意，说放ｌｏｏｐ里面．我自己觉得是小问题．
*/

/* ?
https://oj.leetcode.com/problems/plus-one/
*/

/*
Maybe he wanted this:

void plusOne(vector<int> & A) {
  int i = (int)A.size() - 1;
  while (i >= 0 && A[i] == 9)
      A[i--] = 0;

  if (i >= 0)   
      ++A[i];
  else
      A.insert(A.begin(), 1);
}
*/
