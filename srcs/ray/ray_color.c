#include "hittable.h"
#include "minirt.h"
#include "math_utils.h"
#include "metal.h"
#include "lambertian.h"
#include "dielectric.h"
#include "camera.h"
#include "rectangle.h"
#include "light.h"
#include "cylinder.h"
#include "ambient.h"
#include "plane.h"

t_color ray_color(t_ray *ray, t_hittable_list *world, t_light_list *lights, t_ambient *ambient, int depth) {
    t_hit_record rec;
	t_limits l;
	l.min = 0.001;
	l.max = INFINITY;
    if (depth <= 0)
        return (t_color){0, 0, 0};

    if (hit_list(world, ray, l, &rec)) {
        t_color total_light_color = vec3_to_color(vec_scalar(color_to_vec3(ambient->color), ambient->ratio));
        for (int i = 0; i < lights->count; i++) {
            t_light *light = &lights->lights[i];
            t_vec3 light_dir = vec_normalize(vec_sub(light->position, rec.point));
            double light_intensity = light->intensity * fmax(0.0, vec_dot(rec.normal, light_dir));
            t_vec3 light_color_vec = vec_scalar(color_to_vec3(light->color), light_intensity);
            t_color light_color = vec3_to_color(light_color_vec);
            total_light_color = vec3_to_color(vec_add(color_to_vec3(total_light_color), color_to_vec3(light_color)));
        }

        t_ray scattered;
        t_color attenuation;
        if (rec.material == LAMBERTIAN) {
            t_vec3 target = vec_add(rec.point, vec_add(rec.normal, random_unit_vector()));
            scattered = (t_ray){rec.point, vec_sub(target, rec.point), ray->time};
            attenuation = rec.color;
        } else if (rec.material == METAL) {
            t_vec3 reflected = reflect(vec_normalize(ray->direction), rec.normal);
            scattered = (t_ray){rec.point, vec_add(reflected, vec_scalar(random_in_unit_sphere(), rec.fuzz)), ray->time};
            attenuation = rec.color;
        } else if (rec.material == DIELECTRIC) {
            double etai_over_etat = rec.front_face ? (1.0 / rec.ref_idx) : rec.ref_idx;
            t_vec3 unit_direction = vec_normalize(ray->direction);
            double cos_theta = fmin(vec_dot(vec_scalar(unit_direction, -1), rec.normal), 1.0);
            double sin_theta = sqrt(1.0 - cos_theta * cos_theta);
            if (etai_over_etat * sin_theta > 1.0 || schlick(cos_theta, etai_over_etat) > random_double()) {
                t_vec3 reflected = reflect(unit_direction, rec.normal);
                scattered = (t_ray){rec.point, reflected, ray->time};
            } else {
                t_vec3 refracted = refract(unit_direction, rec.normal, etai_over_etat);
                scattered = (t_ray){rec.point, refracted, ray->time};
            }
            attenuation = rec.color;
        } else {
            return (t_color){0, 0, 0};
        }

        t_color scattered_color = ray_color(&scattered, world, lights, ambient, depth - 1);
        t_vec3 result_color = vec_add(color_to_vec3(total_light_color), vec_mul(color_to_vec3(attenuation), color_to_vec3(scattered_color)));
        return vec3_to_color(result_color);
    }

    return vec3_to_color(vec_scalar(color_to_vec3(ambient->color), ambient->ratio)); // 環境光を背景色として使用
}