/* 
  bluepp
  2014-12-15
  May the force be with me!
  
  http://www.mitbbs.com/article_t/JobHunting/32849297.html
  Divide number and return result in form of a string. e.g 100/3 result should
  be 33.(3) Here 3 is in brackets because it gets repeated continuously and 5
  /10 should be 0.5.
*/


string get_decimal(int num, int den) {
    string ret = to_string(num / den);
    ret.push_back('.');
    num %= den;
    map<int,int> rems;
   
    while(num != 0 && !rems.count(num)) {
        rems[num] = (int)ret.size();
        num *= 10;
        ret.push_back(num / den + '0');
        num %= den;
    }
   
    if (num != 0) {
        ret.insert(ret.begin() + rems[num], '(');
        ret += ")";
    } else {
        ret += "(0)";
    }
    return ret;
}
