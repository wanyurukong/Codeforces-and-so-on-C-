struct PAM{
    int len[N],fa[N],size[N],num[N],tot,last,trans[N][27];
    void init(){
        len[0]=0;fa[0]=1;len[1]=-1;fa[1]=0;
        tot=1;last=0;
        memset(trans[1],0,sizeof(trans[1]));
        memset(trans[0],0,sizeof(trans[0]));
    }
    int new_node(int x){
        int now=++tot;
        memset(trans[tot],0,sizeof(trans[tot]));
        len[now]=x;
        return now;
    }
    void ins(int c,int n){
        int u=last;
        while(s[n-len[u]-1]!=s[n])u=fa[u];
        if(trans[u][c]==0){
            int now=new_node(len[u]+2);
            int v=fa[u];
            while(s[n-len[v]-1]!=s[n])v=fa[v];
            fa[now]=trans[v][c];
            trans[u][c]=now;
            num[now]=num[fa[now]]+1;
        }
        last=trans[u][c];size[last]++;
        L[n]=len[last];
    }
}pam;
