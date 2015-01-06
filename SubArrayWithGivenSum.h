/*
  bluepp
  2014-12-24
  2015-01-06
  May the froce be with me!
  
  Find subarray with given sum
Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number.

Examples:

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Ouptut: Sum found between indexes 2 and 4

Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Ouptut: Sum found between indexes 1 and 4

Input: arr[] = {1, 4}, sum = 0
Output: No subarray found
There may be more than one subarrays with sum as the given sum. The following solutions print first such subarray.

two solutions, 1, two pointer, with positive 2. hashmap

*/

/* http://www.geeksforgeeks.org/find-subarray-with-given-sum/ */
/* Returns true if the there is a subarray of arr[] with sum equal to 'sum'
   otherwise returns false.  Also, prints the result */
int subArraySum(int arr[], int n, int sum)
{
    /* Initialize curr_sum as value of first element
       and starting point as 0 */
    int curr_sum = arr[0], start = 0, i;
 
    /* Add elements one by one to curr_sum and if the curr_sum exceeds the
       sum, then remove starting element */
    for (i = 1; i <= n; i++)
    {
        // If curr_sum exceeds the sum, then remove the starting elements
        while (curr_sum > sum && start < i-1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }
 
        // If curr_sum becomes equal to sum, then return true
        if (curr_sum == sum)
        {
            printf ("Sum found between indexes %d and %d", start, i-1);
            return 1;
        }
 
        // Add this element to curr_sum
        if (i < n)
          curr_sum = curr_sum + arr[i];
    }
 
    // If we reach here, then no subarray
    printf("No subarray found");
    return 0;
}

/* 2015-01-06 */
/* mitbbs, hashmap */
/* http://www.mitbbs.com/article_t1/JobHunting/32838067_0_1.html */

int sumarray(int a[], int n, int sum)
{
    int acc[];
    
    acc[0] = 0;
    acc[1] = a[0];
    for (int i = 2; i <= n; i++)
    {
        acc[i] = acc[i-1] + a[i-1];
    }
    
    unordered_map<int, int> map;
    
    for (int i = 0; i <= n; i++)
    {
        if (map.find(acc[i]) == map.end())
        {
            map[acc[i]+sum] = i;
        }
        else
        {
            cout < "from map[acc[i]+sum], ... i";
        }
    }
    
    return 0;
}
