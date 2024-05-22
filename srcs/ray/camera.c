#include "camera.h"
#include <math.h>

t_vec3 random_in_unit_disk();

t_camera camera_new(t_vec3 lookfrom, t_vec3 lookat, t_vec3 vup, double vfov, double aspect_ratio, double aperture, double focus_dist) {
    t_camera cam;
    double theta = vfov * M_PI / 180.0;
    double h = tan(theta / 2);
    double viewport_height = 2.0 * h;
    double viewport_width = aspect_ratio * viewport_height;

    cam.w = vec_normalize(vec_sub(lookfrom, lookat));
    cam.u = vec_normalize(vec_cross(vup, cam.w));
    cam.v = vec_cross(cam.w, cam.u);

    cam.origin = lookfrom;
    cam.horizontal = vec_scalar(cam.u, viewport_width * focus_dist);
    cam.vertical = vec_scalar(cam.v, viewport_height * focus_dist);
    cam.lower_left_corner = vec_sub(vec_sub(vec_sub(cam.origin, vec_scalar(cam.horizontal, 0.5)), vec_scalar(cam.vertical, 0.5)), vec_scalar(cam.w, focus_dist));

    cam.lens_radius = aperture / 2;
    return cam;
}

t_ray get_ray(t_camera *cam, double s, double t) {
    t_vec3 rd = vec_scalar(random_in_unit_disk(), cam->lens_radius);
    t_vec3 offset = vec_add(vec_scalar(cam->u, rd.x), vec_scalar(cam->v, rd.y));

    t_ray ray;
    ray.origin = vec_add(cam->origin, offset);
    ray.direction = vec_sub(vec_add(vec_add(cam->lower_left_corner, vec_scalar(cam->horizontal, s)), vec_scalar(cam->vertical, t)), cam->origin);
    ray.direction = vec_sub(ray.direction, offset);
    return ray;
}

t_vec3 random_in_unit_disk() {
    t_vec3 p;
    do {
        p = vec_new(random_double(), random_double(), 0);
        p = vec_scalar(p, 2.0);
        p = vec_sub(p, vec_new(1, 1, 0));
    } while (vec_dot(p, p) >= 1.0);
    return p;
}
