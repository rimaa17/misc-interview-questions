/ *The problem is taken from: https://www.geeksforgeeks.org/google-internship-2020-google-online-challenge1st-coding-round/?ref=lbp */
int specialStringSmaller(string s,int i1,int i2){//i in {0,n/2}
//returns min chars to be changed to get part1<part2.
  char max_in_part1='a',min_in_part2='z';
  for(int i=0;i<s.size()/2;++i){
    if(s[i+i1]>max_in_part1) max_in_part1=s[i+i1];
    if(s[i+i2]<min_in_part2) min_in_part2=s[i+i2];
  }
  int change_in_part1=0,change_in_part2=0;
  for(int i=0;i<s.size()/2;++i){
    if(s[i+i1]>=min_in_part2) change_in_part1++;
    if(s[i+i2]<=max_in_part1) change_in_part2++;
  }
  return min(change_in_part1,change_in_part2);
}
int specialString(string s){
  if(s.empty()|| s.size()==2) return 0;
  //case s[i]=s[j]
  vector<int> hist(26,0);
  int most_pop_char_ap=0, diff_char=0;
  char pop_char;
  for(auto c:s){
    if(hist[c-'a']==0) diff_char++;
    if(++hist[c-'a']>most_pop_char_ap){
      most_pop_char_ap=hist[c-'a'];
      pop_char=c;
     }
  }
  int changes_equal=s.size()-hist[pop_char-'a'];
  //case s[i]<s[j]
  int changes_part1_smaller=specialStringSmaller( s,0,s.size()/2);
  //case s[i]>s[j]
  int changes_part2_smaller=specialStringSmaller( s,s.size()/2,0);
  
  return min(min(changes_part1_smaller,changes_part2_smaller),changes_equal); 
}
