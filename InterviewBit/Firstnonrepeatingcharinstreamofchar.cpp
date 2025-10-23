string Solution::solve(string A) {
        queue<char> q;
        vector<int> repeated(26,0);
        string B = "";
        for(int i=0;i<A.size();i++){
            if(repeated[A[i]-'a'] >= 1){
                repeated[A[i]-'a']++;
                while(!q.empty() && repeated[q.front()-'a'] > 1){
                    q.pop();
                }
                if(q.empty())
                    B += "#";
                else
                    B += q.front();
            }
            else{ //The character is not repeated
                repeated[A[i]-'a']++;
                q.push(A[i]);
                while(repeated[q.front()-'a'] > 1)
                    q.pop();
                B += q.front();
            }
        }
        
        return B;
}
