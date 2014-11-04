2014-11-04

http://www.mitbbs.com/article_t1/JobHunting/32817599_0_1.html

额 那道题目的话，完整是给你int read_buffer(char*buffer, int len)，返回值是-1
或者填好的buffer的大小。如果不是-1需要可能再次调用，再取下一段。

我讨论了这些内容:

1. read_line()的返回值怎么传: 在read_line()里面分配好，还是api调用者分配好把
大小传进来? 如果用c++既有的string类，跨函数体的时候复制是怎么做的，内部内存
表示是怎样的？这些实现在这个scenario里面会有哪些缺陷？在这个scenario里会产生
内存fragmentation吗？有没有办法用一个自己管理的内存池减少fragmentation？当然
，难的设计只是提一下，也没有时间写出来。

2. 然后我用了一个read_line()自己的可以复用的固定大小buffer，一个指针指到上次
自己的内部buffer用了多少了，再遇到read_line就找下一个'n',如果用完了就把
buffer刷新。还有一些边界判定，比如上次取下来的buffer没有取满之类的。

3. 最后简化解是，最后写代码就用了unique_ptr<string>, 里面分配好传出去。说了
一下string内部的implementation会造成的影响，如果resize会怎样，然后口头说如果
自己专门为这个设计一个结构会怎么做。
