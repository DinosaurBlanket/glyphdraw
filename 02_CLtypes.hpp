
typedef uint8_t  uchar;

#define __pair(dt, st)\
st x;\
st y;\
dt () : x(0), y(0) {}\
dt (const st in) : x(in), y(in) {}\
dt (const st xIn, const st yIn) : x(xIn), y(yIn) {}\
dt operator +  (const dt b) {return dt(x + b.x, y + b.y);}\
dt operator -  (const dt b) {return dt(x - b.x, y - b.y);}\
dt operator *  (const dt b) {return dt(x * b.x, y * b.y);}\
dt operator /  (const dt b) {return dt(x / b.x, y / b.y);}\
bool   operator == (const dt b) {return x == b.x  &&  y == b.y;}\
bool   operator != (const dt b) {return x != b.x  ||  y != b.y;}\
void   operator += (const dt b) {x += b.x; y += b.y;}\
void   operator -= (const dt b) {x -= b.x; y -= b.y;}\
void   operator *= (const dt b) {x *= b.x; y *= b.y;}\
void   operator /= (const dt b) {x /= b.x; y /= b.y;}\
dt operator +  (const st  b) {return dt(x + b, y + b);}\
dt operator -  (const st  b) {return dt(x - b, y - b);}\
dt operator *  (const st  b) {return dt(x * b, y * b);}\
dt operator /  (const st  b) {return dt(x / b, y / b);}\
bool   operator == (const st  b) {return x == b  &&  y == b;}\
bool   operator != (const st  b) {return x != b  ||  y != b;}\
void   operator += (const st  b) {x += b; y += b;}\
void   operator -= (const st  b) {x -= b; y -= b;}\
void   operator *= (const st  b) {x *= b; y *= b;}\
void   operator /= (const st  b) {x /= b; y /= b;}\
void   operator  = (const st  b) {x  = b; y  = b;}\
bool   operator !  () {return !x && !y;}\
st pro() {return x*y;}\
bool upLeftOf (dt b) {return x < b.x && y < b.y;}\
bool upRightOf(dt b) {return x > b.x && y < b.y;}\
bool dnLeftOf (dt b) {return x < b.x && y > b.y;}\
bool dnRightOf(dt b) {return x > b.x && y > b.y;}\
st sel(uint8_t axis) {\
  switch(axis) {\
    case  0: return x;\
    case  1: return y;\
    default: return 0;\
  }\
}\
st *pSel(uint8_t axis) {\
  switch(axis) {\
    case  0: return &x;\
    case  1: return &y;\
    default: return 0;\
  }\
}\

struct int2{
  __pair(int2, int);
  //int2(float2 f) : x(f.x), y(f.y) {}
  int2 operator % (const int2 b) {return int2(x % b.x, y % b.y);}
  int2 operator % (const int  b) {return int2(x % b  , y % b  );}
};

struct float2{
  __pair(float2, float);
  float2(int2 i) : x(i.x), y(i.y) {}
};
