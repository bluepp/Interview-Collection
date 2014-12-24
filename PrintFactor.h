/*
  bluepp
  2014-12-25
  May the force be with me!
  
  http://www.mitbbs.com/article_t1/JobHunting/32803907_0_1.html
  
  打印一个数的所有乘数组合，从大到小，不要有重复
  24=2*2*2*3
  =2*3*4
  =2*12
  =3*8
  =4*6
  
  */
  
  vector<vector<int> > printfactor(int n)
  {
        vector<int> vec;
        vector<vector<int> >res;
        _factor(n, n/2, vec, res);
        
        return res;
  }
  
  vector<vector<int> > _factor(int n, int start, vector<int> &vec, vector<vector<int> &res)
  {
        if (n == 1)
        {
            res.push_back(vec);
            return;
        }
        
        for (int i = start; i <= n; i++)
        {
            if (n % i) continue;
            
            vec.push_back(i);
            _factor(n/i, i, vec, res);
            vec.pop_back();
        }
  }
