struct trie
{
    trie *next[2];
    int cnt;
    trie()
    {
        memset(next,0,sizeof(next));
        cnt=0;
    }
};
trie *root;
void Insert(char *s,int x)
{
    trie *p=root;
    int i,k;
    for(i=31;i>=0;i--)
    {
        k=s[i]-'0';
        if(p->next[k]==NULL)
            p->next[k]=new trie();
        p=p->next[k];
    }
    p->cnt = x;
}
int query(char *s,int x,int dir)
{
    trie *p = root;
    for(int i=31;i>=0;i--)
    {
        int x = s[i] - '0';
        x = x^dir;
        if(p->next[x] == NULL)
            x^=1;
        p = p->next[x];
    }
    return (p->cnt) ^ x;
}
void del(trie *p)
{
    for(int i=0;i<2;i++)
        if(p->next[i]!=NULL)
            del(p->next[i]);
    free(p);
}
void toString(char *a,int x)
{
    int i;
    for(i=0;i<=31;i++)
        a[i] = '0';
    a[i] ='\0';
    i = 0;
    while(x)
    {
        a[i++] = (x%2)+'0';
        x /= 2;
    }
}

