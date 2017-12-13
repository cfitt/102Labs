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

//------------- vec_diff: subtract this vector from v2 with the result in v3 --------------
void vec_t::vec_diff(const vec_t v2, vec_t &v3)
{
	v3.x = v2.x - x;
	v3.y = v2.y - y;
	v3.z = v2.z - z;
}

void vec_t::vec_diff(const vec_t &v2, vec_t *v3)
{
	v3->x = v2.x - x;
	v3->y = v2.y - y;
	v3->z = v2.z - z;
}

void vec_t::vec_diff(const vec_t *v2, vec_t &v3)
{
	v3.x = v2->x - x;
	v3.y = v2->y - y;
	v3.z = v2->z -z;
}

//------------- vec_read: Use cin to read x, y, z componentes from stdin --------------
void vec_t::vec_read(void)
{
	cin >> x >> y >> z;
}

//------------- vec_prn: Print the label,  x, y, z and newline to the standard. 
//			 error IN THE FORMAT SHOWN in the example output ---------------
void vec_t::vec_prn(const char *label)
{
	cerr << label << x << ", "<< y << ", " << z << endl;
}

//------------- vec_dot: Return the dot product of this with the v2 vector --------------
double vec_t::vec_dot(const vec_t &v2)
{
	return ((x * v2.x) + (y * v2.y) + (z * v2.z));
}

double vec_t::vec_dot(const vec_t *v2)
{
	return ((x * v2->x) + (y * v2->y) + (z * v2->z));
}

//------------- vec_scale: multiply x, y, z components by "fact" --------------
void vec_t::vec_scale(double fact)
{
	x = x * fact;
        y = y * fact;
        z = z * fact;
}

//------------- vec_len: Return the length of this vector --------------
double vec_t::vec_len(void)
{
	double len = sqrt((x * x) + (y * y) + (z * z));
	return len;
}

