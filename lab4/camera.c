#include "ray.h"

void camera_init(FILE *in, model_t *model, int attrmax)
{
	
	int attribcount;
 /* Allocate camera structure and store cookie code */
 /* Read attributes into camera data structure */ 
	camera_t *cam;
	cam = malloc(sizeof(camera_t));
        memset(cam, 0, sizeof(camera_t));
        cam->cookie = CAM_COOKIE;
	
	attribcount = camera_load_attributes(in, cam);
	assert(attribcount == 3); 
 /* Allocate an image structure to hold the ppm image data */
	cam->pixmap = malloc(cam->pixel_dim[0] * cam->pixel_dim[1] * sizeof(irgb_t));

 /* Save camera pointer in model structure */
	model->cam = cam;

}
int camera_load_attributes(FILE *in, camera_t *cam)
{
	char attrib_name[16];
	int count = 0; // number of items read
	int attrcount = 0; // total number of attributes
 /* First read camera name string into cam->name */
	count = fscanf(in, "%s", cam->name);
	assert(count == 1);
 /* Now consume "{" */
	count = fscanf(in, "%s", attrib_name);
	assert(count == 1);
	assert(attrib_name[0] == '{');
/* Read first attribute name... */ 
	count = fscanf(in, "%s", attrib_name);
	assert(count == 1); 
/* '}' means end of the camera definition */ 
	while (attrib_name[0] != '}')
	{
		if (strcmp(attrib_name, "pixeldim") == 0)
		{
			count = fscanf(in, "%d %d", &cam->pixel_dim[X], &cam->pixel_dim[Y]);
			assert(count == 2);
			attrcount += 1;
		}
		else if (strcmp(attrib_name, "worlddim") == 0)//rediing worlddim
		{
			count = fscanf(in, "%lf %lf", &cam->world_dim[X], &cam->world_dim[Y]);
			assert(count == 2);
                        attrcount += 1;
		}
		else if (strcmp(attrib_name, "viewpoint") == 0)//reding veiwpoint
		{
			count = fscanf(in, "%lf %lf %lf", &cam->view_point.x, &cam->view_point.y, &cam->view_point.z);
			assert(count == 3);
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

void camera_print(camera_t *cam, FILE *out)
{
	assert(cam->cookie == CAM_COOKIE);
	fprintf(out, "%-12s %s\n", "camera", cam->name);
	
	fprintf(out, "%-12s %5d %5d\n", "pixeldim", 
			cam->pixel_dim[0], cam->pixel_dim[1]);

	fprintf(out, "%-12s %5.1lf %5.1lf\n", "worlddim", 
			cam->world_dim[0], cam->world_dim[1]);

	fprintf(out, "%-12s %5.1lf %5.1lf %5.1lf\n", "veiwpoint", 
			cam->view_point.x, cam->view_point.y, cam->view_point.z);
}

/* x and y are pixel coordinates */
/* vec_t *uvec is the unit vector to be filled in */
void camera_getdir(camera_t *cam, int x, int y, vec_t *uvec) 
{
	assert(cam->cookie == CAM_COOKIE);
	
	double world_x = cam->world_dim[0] * x / (cam->pixel_dim[0] - 1); 
	double world_y = cam->world_dim[1] * y / (cam->pixel_dim[1] - 1);
	
	vec_t pix = {world_x, world_y, 0.0};
	vec_diff(&cam->view_point, &pix, uvec);

	vec_unit(uvec, uvec);
}

void camera_store_pixel(camera_t *cam, int x, int y, drgb_t *pix)
{
	assert(cam->cookie == CAM_COOKIE);
	
	int numcols = cam->pixel_dim[0];
	int row = cam->pixel_dim[1] - y - 1;
	int col = x;
	int set;
	irgb_t *map;
  
	set = row * numcols + col;
	map = cam-> pixmap + set;
   
	if(pix->r > 1.0 )
		pix->r = 1.0;
	if(pix->g > 1.0 )
		pix->g = 1.0;
	if(pix->b > 1.0 )
		pix->b = 1.0;

	pix->r =  ((pix->r * 256.0));
	pix->g =  ((pix->g * 256.0));
	pix->b =  ((pix->b * 256.0));
   
	if(pix->r > 255)
		pix->r = 255;
	if(pix->g > 255)
		pix->g = 255;
	if(pix->b > 255)
		pix->b = 255;
          
	map->r = pix->r;
	map->g = pix->g;
	map->b = pix->b;
}

void camera_write_image(camera_t *cam, FILE *out)
{
	//This function should use fprintf() to write the .ppm header and then use a single call to fwrite to write the entire image
	fprintf(stdout, "P6\n");
        fprintf(stdout, "%d %d %d\n", cam -> pixel_dim[0],
                cam -> pixel_dim[1], 255);
       
        fwrite(cam -> pixmap, sizeof(irgb_t), cam -> pixel_dim[0] *
                cam -> pixel_dim[1], out);
}

