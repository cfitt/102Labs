/* sphere.c */

/* sphere_init()
	sphere_load_attributes()
	sphere_print()
	sphere_hits()
*/


#include "ray.h"
#include <math.h>


//**
// Create a new sphere object and initialize it 
void sphere_init(FILE  *in, model_t  *model, int  attrmax)
{
   sphere_t *sph;
   object_t *obj;
   int count;

	object_init(in, model);
	obj = list_get_entity(model->objs);
	sph = (sphere_t *)malloc(sizeof(sphere_t));
	obj->priv = (void *)sph;
	strcpy(obj->obj_type, "sphere");

   count = sphere_load_attributes(in, sph, attrmax);
   assert(count == 2);
   /* Setup polymorphic function pointers in object_t */
	/* Set obj->hits to sphere_hits() function.        */
	/* Set obj->printer to sphere_print() functions.   */
	obj->hits = sphere_hits;
	obj->printer = sphere_print;
}


//**
// Load attributes as in other load attributes functions 
int sphere_load_attributes(FILE  *in, sphere_t  *sph, int  attrmax)
{
   /* Use same basic approach as camera_load_attributes()  */
	char attrib_name[16];
        int count = 0; // number of items read
        int attrcount = 0; // total number of attributes
	
	count = fscanf(in, "%s", attrib_name);
        assert(count == 1);
 /* '}' means end of the definition */
        while (attrib_name[0] != '}')
        {
                if (strcmp(attrib_name, "center") == 0)
                {
                        count = fscanf(in, "%lf %lf %lf",
                                &sph->center.x, &sph->center.y, &sph->center.z );
                        assert(count == 3);
                        attrcount += 1;
                }
                else if (strcmp(attrib_name, "radius") == 0)
                {
                        count = fscanf(in, "%lf",
                                &sph->radius);
                        assert(count == 1);
                        attrcount += 1;
                }
		else
                {
                        fprintf(stderr, "Bad camera attribute: %s \n", attrib_name);
                        exit(1);
                }
/* Read next attribute name */
        fscanf(in, "%s", attrib_name);
        }
        return(attrcount);
}
// Prints a formatted version of the sphere structure
// The format should be consistent with that produced by
// camera_print() or material_print()
void sphere_print(object_t  *obj,FILE  *out)
{
        sphere_t *sph;
	object_print(obj, out);
	sph = (sphere_t *)obj->priv;	

        fprintf(stderr, "\ncenter  %10.1lf %5.1lf %5.1lf \n",
                        sph->center.x, 
                        sph->center.y, 
                        sph->center.z);
        fprintf(stderr, "radius  %10.1lf \n\n",
                        sph->radius); 
}


/* Determine if a vector projected from location base   */
/* in direction *dir hits the sphere. If so the return  */
/* value is the distance from the base to the point of  */
/* contact.  It must hit the sphere in negative z-space.*/


/************************************************************
 You do not have to implement this function during this lab.
         This will be implemented at a later time.
 ************************************************************/

double sphere_hits(object_t  *obj, vec_t  *base, vec_t  *dir) 
{
	// sphere *sph;
	// assert (obj->cookie == OBJ_COOKIE);

	// extract sph pointer from object structure 
	// see notes for sphere_hits function
	// --- CODE GOES HERE ---
	// return distance
	

}
