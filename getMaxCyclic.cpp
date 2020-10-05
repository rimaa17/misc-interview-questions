//return the index of the max num in a shifted scyclic sorted array
int getMaxCyclic(vector<int>& arr){
    if(arr.empty())
        return -1;
    int n=arr.size();
    int begin=0,end=n-1;
    while(begin<end){
        int mid=(end-begin)/2+begin;
        if(arr[mid]>=arr[(mid+1)%n])
            return mid;
        if(arr[mid]<arr[end] && arr[mid]>=arr[begin]){
            begin=(mid+1)%n;
            continue;
        }
        end=(end-1+n)%n;
        
        /*if(arr[mid]>arr[end] && arr[mid]>arr[begin]){
         continue;
         }
         if(arr[mid]<arr[end] && arr[mid]<arr[begin]){
         end=(mid-1+n)%n;
         }*/
    }
    return end;
}
////////////////////////////////////////////////////////////////////////////
//Got accepted on leetcode
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/
int getMinCyclic(vector<int>& arr){
    if(arr.empty())
        return -1;
    int n=arr.size();
    int begin=0,end=n-1;
    while(begin<end){
        int mid=(end-begin)/2+begin;
        if(arr[mid]<=arr[(mid-1+n)%n])
            return mid;
        if(arr[mid]<arr[end] && arr[mid]>=arr[begin]){
            
            end=(mid-1+n)%n;
            continue;
        }
        begin=(begin+1)%n;
    }
    return end;
}
    
