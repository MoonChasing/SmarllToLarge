#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>

#define MAXN 1e9+10
#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

struct node
{
    int val;
    node *lch, *rch;
};

//插入数值
node * insert(node *p, int val)
{
    if(p == NULL)
    {
        node * q = new node;
        q->val = val;
        q->lch = q->rch = NULL;
        return q;
    }
    else
    {
        if(p->val < val)
            p->rch = insert(p->rch, val);
        else
            p->lch = insert(p->lch, val);
        return p;
    }
}

//查找数值
bool find(node *p, int x)
{
    if(p == NULL)
        return false;
    if(x == p->val)
        return true;
    else if(x > p->val)
        return find(p->rch, x);
    else
        return find(p->lch, x);

}

//删除数值
node *remov(node *p, int x)
{
    if(p == NULL)
        return NULL;
    else if(x < p->val)
        p->lch = remov(p->lch, x);
    else if(x > p->val)
        p->rch = remov(p->rch, x);
    else if(p->lch == NULL)
    {
        node *q = p->rch;
        delete p;
        return q;
    }
    else if(p->lch->rch == NULL)
    {
        node *q = p->lch;
        q->rch = p->rch;
        delete p;
        return q;
    }
    else
    {
        node *q;
        for(q=p->lch; q->rch->rch != NULL; q=q->rch);
        node *r = q->rch;
        q->rch = r->lch;
        r->lch = p->lch;
        r->rch = p->rch;
        delete p;
        return r;
    }
    return p;
}

void clearBinaryTree(node *p)
{
    if(p != NULL)
    {
        clearBinaryTree(p->lch);
        clearBinaryTree(p->rch);
        delete p;
        p = NULL;
    }
}
int main(void)
{

    return 0;
}
