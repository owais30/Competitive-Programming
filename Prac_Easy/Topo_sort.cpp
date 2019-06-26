string printOrder(string dict[], int n, int k)
{
   vector<int >  adj[k];
   int i,j;
   for(i=0;i<n-1;i++)
   {
       string w1=dict[i],w2=dict[i+1];
       for(int j=0;j<min(w1.length(),w2.length());j++)
       {
           if(w1[j]!=w2[j])
           {
               adj[w1[j]-'a'].push_back(w2[j]-'a');
               break;
           }
       }
   }
   int in_degree[k]={0},counter=0;
   for(i=0;i<k;i++)
   {
       for(auto it=adj[i].begin();it!=adj[i].end();++it)
       {
           in_degree[*it]++;
       }
   }
   queue<int > q;
   for(int i=0;i<k;i++)
   {
       if(in_degree[i]==0)
       q.push(i);
   }
   int topo[k];
   while(!q.empty())
   {
       
       int temp=q.front();q.pop();
       topo[temp]=counter++;
       for(auto it =adj[temp].begin();it!=adj[temp].end();++it)
       {
           in_degree[*it]--;
           if(in_degree[*it]==0)
           q.push(*it);
       }
   }
   char result[k];
   for(i=0;i<k;i++)
   {
        result[topo[i]]=i+'a';   
   }
   string s="";
   for(i=0;i<k;i++)s+=result[i];
  
   return s;
   
}
