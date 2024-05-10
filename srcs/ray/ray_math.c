#include "../../includes/minirt.h"

// ベクトルの加算
t_vec3 vec_add(t_vec3 a, t_vec3 b) {
    return (t_vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

// ベクトルの減算
t_vec3 vec_sub(t_vec3 a, t_vec3 b) {
    return (t_vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

// ベクトルのスカラー倍
t_vec3 vec_scalar(t_vec3 a, double t) {
    return (t_vec3){a.x * t, a.y * t, a.z * t};
}

// ベクトルのドット積
double vec_dot(t_vec3 a, t_vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// ベクトルの長さ
double vec_length(t_vec3 a) {
    return sqrt(vec_dot(a, a));
}

// ベクトルの正規化
t_vec3 vec_normalize(t_vec3 a) {
    return vec_scalar(a, 1.0 / vec_length(a));
}

// レイのt点を計算する
t_vec3 ray_at(t_ray ray, double t) {
    return vec_add(ray.origin, vec_scalar(ray.direction, t));
}