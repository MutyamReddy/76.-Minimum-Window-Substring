class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.length(),n2=t.length();
        if(n1<n2||n1==0||n2==0) return "";
        unordered_map<char,int>mp;
        for(auto c:t){
            mp[c]+=1;
        }
        int start=0,minlen=INT_MAX,c=0,minstart=0;
        for(int i=0;i<n1;i++){
            if(mp[s[i]]>0) c++;
            mp[s[i]]-=1;
            while(c==n2){
                if(i-start+1<minlen){
                    minlen=i-start+1;
                    minstart=start;
                }
                if(mp[s[start]]==0) c--;
                mp[s[start]]+=1;
                start++;
            }
        }
        return minlen==INT_MAX?"":s.substr(minstart,minlen);
    }
};
