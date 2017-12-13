#include "vec.h"

vec_t::vec_t()
{
	x = y = z = 0.0;
}

vec_t::vec_t(double xi, double yi, double zi)
{
	x = xi;
	y = yi;
	z = zi;
}

//------------- vec_unit: --------------
void vec_t::vec_unit(vec_t &vec)
{
	double scaled = 1/!(this);
	vec.x = scaled * x;
	vec.y = scaled * y;
	vec.z = scaled * z;
}
//-----------------------------------------------------------------------------
//------------- vec_operator+: this + rhs --------------
vec_t vec_t::operator+(vec_t &rhs)
{
	vec_t r;
	r.x = x + rhs.x;
	r.y = y + rhs.y;
	r.z = z + rhs.z;
	return(r);
}

//------------- vec_operator|: projection of rhs on plane with normal this ---------------
vec_t vec_t::operator|(vec_t &rhs)
{
	double dot;
	vec_t t;
	
	dot = sqrt((x*rhs.x)+(y*rhs.y)+(z*rhs.z));
	t.x = rhs.x - (dot*x);
	t.y = rhs.y - (dot*y);
	t.z = rhs.z - (dot*z);
	return(t);
}

//------------- vec_operator&: cross product of this and rhs ---------------
vec_t  vec_t::operator&(vec_t &rhs)
{
	vec_t r;
        r.x = (y * rhs.z) - (z * rhs.y);
        r.y = (z * rhs.x) - (x * rhs.z);
        r.z = (x * rhs.y) - (y * rhs.x);
	return (r);
}

//------------- vec_operator!: length of this vector ---------------
double vec_t::operator!(void)
{
	double len = sqrt((x * x) + (y * y) + (z * z));
	return len;
}

//-----------------------------------------------------------------------------
//-------- vec_t operator*: multiply x, y, z 
//			    components by a double val (Scaled)
vec_t operator*(const double val, const vec_t &rhs)
{
	vec_t temp;
	temp.x = rhs.x * val;
        temp.y = rhs.y * val;
        temp.z = rhs.z * val;
	return (temp);
}

//-------- vec_t operator*: multiply x, y, z 
//			    components by a double val (Scaled)
vec_t operator*(const vec_t &lhs, const double val)
{
	vec_t temp;
	temp.x = lhs.x * val;
        temp.y = lhs.y * val;
        temp.z = lhs.z * val;
	return (temp);
}

//-------- vec_t operator/: divide x, y, z 
//			    components by a double val (Scaled division)
vec_t operator/(const vec_t &lhs, const double val)
{
	vec_t temp;
	temp.x = lhs.x / val;
        temp.y = lhs.y / val;
        temp.z = lhs.z / val;
	return (temp);
}

//-------- vec_t operator/: divide x, y, z 
//			    components by another vec_t (Divide)
vec_t operator/(const vec_t &lhs, const vec_t &rhs)
{
	vec_t temp;
	temp.x = lhs.x / rhs.x;
        temp.y = lhs.y / rhs.y;
        temp.z = lhs.z / rhs.z;
	return (temp);
}

//-------- operator<<: output instance --------------
ostream & operator<<(ostream &out, const vec_t &ovec)
{
	out << ovec.x << ", "<< ovec.y << ", " << ovec.z << endl;
	return(out);
}

//-------- operator>>: input instance --------------
istream & operator>>(istream &in, vec_t &ivec)
{
	in >> ivec.x >> ivec.y >> ivec.z;
	return (in);
}


