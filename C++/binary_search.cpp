int firstBadVersion(int n) {
        int high=n;
        int low=0;
        int ans=INT_MAX;
        while(low<=high){
            int rem=(high%2)+(low%2);
            rem/=2;
            int mid=(low/2)+(high/2)+rem;
            if(isBadVersion(mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
	
int firstBadVersion(int n) {
        int l=0, e=n, m;
        
        while(l<=e)
        {
            m = l+(e-l)/2;
            if(l==m){
                break;
            }
            if(l=e-1 && isBadVersion(l))
            {
                return l;
            }
            if(isBadVersion(m))
            {
                e = m;
            }
            else{
                l = m;
            }
        }
        return e;
    }