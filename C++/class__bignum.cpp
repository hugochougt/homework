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
    bool negative;          //负数negative =true,else =false;
    void add( const bignum& );
    void sub( const bignum&, int );
    void format();
    bool lessthan( const bignum&, int ) const;
  public:
    bignum( int );
    bignum( char*);
    bignum& operator = ( int b ) { return *this = bignum( b ); }
    bool operator < ( const bignum& ) const;
    bool operator > ( const bignum& b ) const { return b < *this; };
    bool operator <= ( const bignum& b ) const { return !( *this > b ); }
    bool operator >= ( const bignum& b ) const { return !( *this < b ); }
    bool operator != ( const bignum& b ) const { return *this < b || *this > b; }
    bool operator == ( const bignum& b ) const { return !( *this != b ); }
    bool operator < ( const int& b ) const { return *this < bignum( b ); }
    bool operator > ( const int& b ) const { return *this > bignum( b ); }
    bool operator <= ( const int& b ) const { return *this <= bignum( b ); }
    bool operator >= ( const int& b ) const { return *this >= bignum( b ); }
    bool operator != ( const int& b ) const { return *this != bignum( b ); }
    bool operator == ( const int& b ) const { return *this == bignum( b ); }
    void operator += ( const bignum& );
    void operator -= ( const bignum& );
    void operator *= ( const bignum& );
    void operator /= ( const bignum& );
    void operator %= ( const bignum& b ) { *this = *this - *this / b * b; }
    bignum operator + ( const bignum& b ) const { bignum r = *this; r += b; return r; };
    bignum operator - ( const bignum& b ) const { bignum r = *this; r -= b; return r; };
    bignum operator * ( const bignum& b ) const { bignum r = *this; r *= b; return r; };
    bignum operator / ( const bignum& b ) const { bignum r = *this; r /= b; return r; };
    bignum operator % ( const bignum& b ) const { bignum r = *this; r %= b; return r; };
    void operator += ( const int& b ) { *this += bignum( b ); }
    void operator -= ( const int& b ) { *this -= bignum( b ); }
    void operator *= ( const int& );
    void operator /= ( const int& );
    void operator %= ( const int& b ) { *this %= bignum( b ); }
    bignum operator + ( const int& b ) const { bignum r = *this; r += bignum( b ); return r; }
    bignum operator - ( const int& b ) const { bignum r = *this; r -= bignum( b ); return r; }
    bignum operator * ( const int& b ) const { bignum r = *this; r *= bignum( b ); return r; }
    bignum operator / ( const int& b ) const { bignum r = *this; r /= bignum( b ); return r; }
    bignum operator % ( const int& b ) const { bignum r = *this; r %= bignum( b ); return r; }
    bignum operator - () { bignum r = *this; r.negative = !negative; r.format(); return r; }
    friend bignum operator + ( int k, const bignum& b ) { return bignum( k ) + b; }
    friend bignum operator - ( int k, const bignum& b ) { return bignum( k ) - b; }
    friend bignum operator * ( int k, const bignum& b ) { return bignum( k ) * b; }
    friend bignum operator / ( int k, const bignum& b ) { return bignum( k ) / b; }
    friend bignum operator % ( int k, const bignum& b ) { return bignum( k ) % b; }
   
    friend inline bignum mysqrt(const bignum& a);
    int read();
    void print() const;
    void println() const;   
};
bignum::bignum( int e = 0 )
{
    if ( e < 0 )
    {
        negative = true;
        e = -e;
    }
    else   negative = false;
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
    negative = (*str == '-')? true : false;
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
    negative = (*str == '-')? true : false;
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
    if ( len == 1 && nn[ 0 ] == 0 )
        negative = false;
}
bool bignum::lessthan( const bignum& b, int bg = 0 ) const
{
    if ( len - bg != b.len ) return len - bg < b.len;
    bool ret = false;
    for ( int i = len - bg - 1; i > -1; --i )
        if ( nn[ bg + i ] != b.nn[ i ] )
        {
            ret = nn[ bg + i ] < b.nn[ i ];
            break;
        }
    return ret;
}
bool bignum::operator < ( const bignum& b ) const
{
    if ( negative != b.negative )    return negative;
    bool ret = false;
    if ( negative )   ret = b.lessthan( *this );
    else    ret = lessthan( b );
    return ret;
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
void bignum::sub( const bignum& b, int bg = 0 )
{
    int length = len - bg;
    for ( int i = 0; i < length; ++i )
    {
        nn[ i + bg ] -= b.nn[ i ];
        if ( nn[ i + bg ] < 0 )
        {
            nn[ i + bg ] += F;
            --nn[ i + bg + 1 ];
        }
    }
    format();
}
void bignum::operator += ( const bignum& b )
{
    if ( negative == b.negative )     add( b );
    else
    {
        if ( b.lessthan( *this ) )    sub( b );
        else
        {
            bignum r = b;
            r.sub( *this );
            *this = r;
        }
    }
}
void bignum::operator -= ( const bignum& b )
{
    if ( negative == b.negative )
    {
        if ( b.lessthan( *this ) )        sub( b );
        else
        {
            bignum r = b;
            r.sub( *this );
            *this = r;
            negative = !negative;
            format();
        }
    }
    else  add( b );
}
void bignum::operator *= ( const bignum& b )
{
    bignum a = *this;
    memset( nn, 0, sizeof( nn ) );
    len += b.len;
    negative ^= b.negative;
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
void bignum::operator /= ( const bignum& c )
{
    bignum a = *this, b = c;
    memset(nn, 0, sizeof( nn ) );
    len = max( a.len - b.len + 1, 0);
    negative ^= b.negative;
    for ( int i = len-1; i >= 0; i-- )
    {
        int al = a.nn[ max( i + b.len, a.len ) - 1 ], bl = b.nn[ b.len - 1 ], ar = al + 1, br = bl + 1;
        if ( a.len - i != b.len )
        {
            al *= F;
            ar *= F;
        }
        int l = al / br, r = ar / bl + 1;
        while ( r - l != 1 )
        {
            int mid = ( l + r ) / 2;
            if ( a.lessthan( b * mid, i ) )  r = mid;
            else  l = mid;
        }
        a.sub( b * l, i );
        nn[ i ] = l;
    }
    if ( len == 0 )      len++;
    format();
}
void bignum::operator *= ( const int& b )
{
    negative = negative ^ ( b < 0 );
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
void bignum::operator /= ( const int& b )
{
    negative = negative ^ ( b < 0 );
    int r = 0;
    for ( int i = len - 1; i > -1; --i )
    {
        nn[ i ] += r * F;
        r = nn[ i ] % b;
        nn[ i ] /= b;
    }
    format();
}
inline bignum mysqrt(const bignum& a)
{
    bignum x,y=a;
    if(a==0) return x=0;
    do
    {
        x=y;
        y=(x+a/x)/2;
    }while(y<x);
    return x;
}
void bignum::print() const
{
    if ( negative ) putchar( '-' );
    printf( "%d", nn[ len - 1 ] );
    for ( int i = len - 2; i > -1; --i )
        printf( "%0*d", W, nn[ i ] );
    return;
}
void bignum::println() const
{
    if ( negative ) putchar( '-' );
    printf( "%d", nn[ len - 1 ] );
    for ( int i = len - 2; i > -1; --i )
        printf( "%0*d", W, nn[ i ] );
    putchar('\n');
    return;
}
int main ()
{
 int n,i;
 bignum a,b;
 while (a.read())
 {
     b.read();
     (a+b).println();
     (a-b).println();
     (a*b).println();
     (a/b).println();
        (mysqrt(a)).println(); 
    }   
 return 0;
} 
