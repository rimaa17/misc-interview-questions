/*Problem src: https://www.interviewcake.com/question/cpp/stock-price */
//not sure how correct it is, need more tests to make sure
int getMaxProfit(vector<int>& stockP){
    if(stockP.size()<2)
        return 0;
    int l=0, r=1, max_p=INT_MIN;
    while(r<stockP.size()){
        if(max_p<stockP[r]-stockP[l]) max_p=stockP[r]-stockP[l];
        if(r<stockP.size()-1 && stockP[r+1]>=stockP[r] && stockP[l]>=stockP[r]){//better sell
            l=r;
        }
        if(r<stockP.size()-1 && stockP[r+1]<stockP[r]){
            l=r;
        }
          r++;
    }
    return max_p;
}
