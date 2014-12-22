/*

bluepp
2014-12-22
May the force be with me!


Given a nested list of integers, returns the sum of all integers in the list weighted by their depth
For example, given the list {{1,1},2,{1,1}} the function should return 10 (four 1's at depth 2, one *2 at depth 1)
Given the list {1,{4,{6}}} the function should return 27 (one 1 at depth 1, one 4 at depth 2, and *one 6 at depth 3)

public int depthSum (List<NestedInteger> input)
{
     //Implement this function
}

/**
 * This is the interface that allows for creating nested lists. You should not implement it, or speculate about its implementation
 */
public interface NestedInteger 
{
    // Returns true if this NestedInteger holds a single integer, rather than a nested list
    public boolean isInteger();

    // Returns the single integer that this NestedInteger holds, if it holds a single integer
    // Returns null if this NestedInteger holds a nested list
    public Integer getInteger();

    // Returns the nested list that this NestedInteger holds, if it holds a nested list
    // Returns null if this NestedInteger holds a single integer
    public List<NestedInteger> getList();
}     


*/

struct NestedInteger
{
  bool isInteger();
  int getInteger();
  List<NestedInteger> getList();
}

int depthSum(list<NestedInteger> input)
{
  int sum = 0;
  if(input.isInteger()) return input.getInteger();
  
  getlistsum(input, 1, sum);
  return sum
}

int getlistsum(list<NestedInteger> input, int depth, sum)
{
  if (input.isinteger()) {sum += depth*input.getinteger(); return sum};
  getlistsum(input, depth+1, sum};
  
}


