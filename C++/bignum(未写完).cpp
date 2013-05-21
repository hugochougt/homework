//比较高效的大数 
#include<iostream>
using namespace std;

const int base = 10000;     // (base^2) fit into int
const int width = 4;        // width = log base
const int N = 1000;         // n * width: 可表示的最大位数

struct bint
{
    int ln, v[N];
    
    bint(int r = 0)  // r应该是字符串! 
    {
        for(ln = 0;r > 0;r /= base) 
            v[ln++] = r % base;
    }
    bint& operator = (const bint& r)
    {
        memcpy(this, &r, (r.ln + 1)) * sizeof(int);
        return *this;
    }
};

bint operator + (const bint& a, const bint& b)
{
    bint res;
    int i,cy = 0;
    
    for(i = 0;i < a.ln || i < b.ln || cy > 0;i++)
    {
        if(i < a.ln)
            cy += a.v[i];
        if(i < b.ln)
            cy += b.v[i];
        res.v[i] = cy % base;
        cy /= base;
    }
    res.ln = i;
    return res;
}

int digits(bint& a)     //返回位数 
{
    if(a.ln == 0)    return 0;
    int l = (a.ln - 1) * 4;
    for(int t = a.v[a.ln - 1]; t; ++l,t/=10) ; //循环体为空 
    return l;
}

bool read(bint& b, char buf[]) // 读取失败返回0
{
    if(1 != scanf("%s",buf))    return 0;
    int w, u, ln = strlen(buf);
    memset(&b, 0, sizeof(bint));
    if('0' == buf[0] && 0 == buf[1]) return 1;
    for(w = 1, u = 0; ln; )
    {
        u += (buf[--ln] - '0') * w;
        if(w * 10 == base)
        {
            b.v[b.ln++] = u;
            u = 0;
            w = 1;
        }
        else
            w *= 10;
    }
    if(w != 1)
        b.v[b.ln++] = u;
        return 1;
}

void write(const bint& v)
{
    int i;
    printf("%d", v.ln == 0 ? 0 : v.v[v.ln - 1]);
    for(i = v.ln - 2l; i>=0; i--)
        printf("%04d",v.v[i]); // ! 4 == width
    printf("\n");
}
