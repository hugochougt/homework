//大数四则运算 
#include<cstdio>
#include<cstring>
#define MAXDIGITS 100   //maximum length bignum

//#define PLUS 1          //positive sign bit
//#define MINUS -1        //negative sign bit
using namespace std;

typedef struct {
    char digits[MAXDIGITS];
    //int signbit;        // PLUS or MINUS
    int lastdigit;      //index of high-order digit
}bignum;

void print_bignum(bignum *n)
{
    int i;
    //if(n->signbit == MINUS)    printf("-");
    for(i=n->lastdigit;i>=0;i--)
        printf("%c",'0'+n->digits[i]);
    printf("\n");
}

void initialize_bignum(bignum *n)
{
    memset(n->digits,0,sizeof(n->digits));
}

void zero_justify(bignum *n)
{
    while((n->lastdigit>0)&&(n->digits[n->lastdigit]==0))
        n->lastdigit--;
}

void add_bignum(bignum *a, bignum *b, bignum *c)
{
    int carry;  //carry digit
    int i;      //counter
    
    initialize_bignum(c);
    a->lastdigit=strlen(a->digits)-1;
    b->lastdigit=strlen(b->digits)-1;
    
    c->lastdigit = (a->lastdigit>=b->lastdigit ? a->lastdigit : b->lastdigit)-1;
    carry = 0;
    
    for(i=0;i<=(c->lastdigit);i++)
    {
        c->digits[i]=(char)(carry+a->digits[i]+b->digits[i])%10;
        carry=(carry+a->digits[i]+b->digits[i])/10;
    }
    zero_justify(c);
}

int main()
{
    bignum a,b,c;
    while(1)
    {
        initialize_bignum(&a);
        initialize_bignum(&b);
        gets(a.digits);
        gets(b.digits);
        add_bignum(&a,&b,&c);
        print_bignum(&c);
    }
    return 0;
}
