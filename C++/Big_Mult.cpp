//比较高效的大数类
#include <cstdio>
#include <cctype>
#include <cstring>
#define max( a, b ) ( ( a ) > ( b ) ? ( a ) : ( b ) )
using namespace std;
class bignum
{
  private:
    const static int D = 10;             //W*D==位域
    const static int F = 10000, W = 4;
    int nn[ D ], len;                     
    void add( const bignum& );
    void sub( const bignum&, int );
    void format();
    bool lessthan( const bignum&, int ) const;
  public:
    bignum( int );
    bignum( char*);
    bignum& operator = ( int b ) { return *this = bignum( b ); }

    void operator *= ( const bignum& );

    bignum operator * ( const bignum& b ) const { bignum r = *this; r *= b; return r; };

    void operator *= ( const int& );

    bignum operator * ( const int& b ) const { bignum r = *this; r *= bignum( b ); return r; }

    friend bignum operator * ( int k, const bignum& b ) { return bignum( k ) * b; }
   
    int read();
    void print() const;
    void println() const;   
};
bignum::bignum( int e = 0 )
{
    memset( nn, 0, sizeof( nn ) );
    len = 1;
    nn[ 0 ] = e; 
    while ( nn[ len - 1 ] >= F )
    {
        nn[ len ] += nn[ len - 1 ] / F;
        nn[ len - 1 ] %= F;
        ++len;
    }
}
bignum::bignum( char* str) 
{
    memset( nn, 0, sizeof( nn ) );
    if (!isdigit( *str ))   ++str;
    int slen = strlen( str );
    len = ( slen + W - 1 ) / W;
    for ( int i = 0; i < len; ++i )
    {
        int sum = 0;
        for ( int j = max( 0, slen - W ); j < slen; ++j )
            sum = sum * 10 + str[ j ] - '0';
        nn[ i ] = sum;
        slen -= W;
    }
    format();
}
int bignum::read()  //读取错误返回0
{
    char s[D*W+10],*str;
    str=s;
    if(scanf("%s",str)==-1) return 0;
    memset( nn, 0, sizeof( nn ) );
    if (!isdigit( *str ))   ++str;
    int slen =strlen(str);
    len = ( slen + W - 1 ) / W;
    for ( int i = 0; i < len; ++i )
    {
        int sum = 0;
        for ( int j = max( 0, slen - W ); j < slen; ++j )
            sum = sum * 10 + str[ j ] - '0';
        nn[ i ] = sum;
        slen -= W;
    }
    format();
    return 1;
}   
void bignum::format()    //清除高位的零
{
    for ( ; len > 1 && nn[ len - 1 ] == 0; --len );
}

void bignum::add( const bignum& b )
{
    len = max( len, b.len );
    int r = 0;
    for ( int i = 0; i < len; ++i )
    {
        nn[ i ] += b.nn[ i ] + r;
        r = nn[ i ] / F;
        nn[ i ] %= F;
    }
    if ( r )     nn[ len++ ] = r;
    format();
}

void bignum::operator *= ( const bignum& b )
{
    bignum a = *this;
    memset( nn, 0, sizeof( nn ) );
    len += b.len;
    for ( int i = 0; i < a.len; ++i )
        for ( int j = 0; j < b.len; ++j )
        {
            int k = i + j;
            nn[ k ] += a.nn[ i ] * b.nn[ j ];
            if ( nn[ k ] >= F )
            {
                nn[ k + 1 ] += nn[ k ] / F;
                nn[ k ] %= F;
            }
        }
    format();
}

void bignum::operator *= ( const int& b )
{
    int r = 0;
    for ( int i = 0; i < len; ++i )
    {
        nn[ i ] = nn[ i ] * b + r;
        r = nn[ i ] / F;
        nn[ i ] %= F;
    }
    while ( r >= F ) nn[ len++ ] = r % F , r /= F;
    format();
}

void bignum::print() const
{
    printf( "%d", nn[ len - 1 ] );
    for ( int i = len - 2; i > -1; --i )
        printf( "%0*d", W, nn[ i ] );
    return;
}
void bignum::println() const
{
    printf( "%d", nn[ len - 1 ] );
    for ( int i = len - 2; i > -1; --i )
        printf( "%0*d", W, nn[ i ] );
    putchar('\n');
    return;
}
int main ()
{
 int n,i;
 bignum bn[10004];
 bn[0]=1;
 bn[1]=1;
 for(i=2;i<=1000;i++)
    bn[i]=i*bn[i-1];
 while (scanf("%d",&n)!=EOF)
 {
     (bn[i]).println();
    }   
 return 0;
} 
