/*
  2015-01-07
  bluepp
  May the force be with me 
  
  http://www.mitbbs.com/article_t1/JobHunting/32849113_0_1.html
  给一个数组有没有三个下标  i < j < k, 满足A[i] < A[j] < A[k]。
  */
  
/* 1.  stack , increas */

/* 2. if a[i] < min, that means there is a smaller one in left */
bool find(int a[], int n)
{
	if (n < 3) return false;
	
	bool hasmin[n];
	memset(hasmin, false, sizeof(hasmin));
	int lmin = a[0];
	
	for (int i = 1; i < n; i++)
	{
		if (a[i] < lmin)
		{
			lmin = a[i];
			hasmin[i] = true;
		}
	}
	
	int rmax = a[n-1];
	for (int i = n-2; i >= 0; i--)
	{
		if (a[i] > rmax)
		{
			rmax = a[i];
			if (hasmin[i]) return true;
		}
	}
	return false;
}

  
