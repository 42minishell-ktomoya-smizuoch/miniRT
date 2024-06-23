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

int main(int argc, char *argv[])
{
    t_data data;

	 if (argc != 2)
	 	exit(1);
    init_data(&data);
	parse_file(argv[1], &data);
	//print_struct(data);

    // 地面
    //add_hittable(data.world, new_lambertian(vec_new(0, -1000, 0), 1000, (t_color){0.5, 0.5, 0.5}));

    // 球
//    add_hittable(data.world, new_dielectric(vec_new(0, 1, 0), 1.0, 1.5)); // 大きなガラス球
//    add_hittable(data.world, new_lambertian(vec_new(-4, 1, 0), 1.0, (t_color){0.4, 0.9, 0.1})); // 拡散球
//    add_hittable(data.world, new_metal(vec_new(4, 1, 0), 1.0, (t_color){0.7, 0.6, 0.5}, 0.0)); // 金属球
//
//    add_hittable(data.world, new_dielectric(vec_new(0, 1, 0), -0.8, 1.5));

    // 長方形
//	t_rectangle r = {
//        vec_new(-2, 0, -2), // p0
//        vec_new(-2, 0, 2),  // p1
//        vec_new(2, 0, 2),   // p2
//        vec_new(2, 0, -2),  // p3
//        vec_new(0, 1, 0),   // normal
//        METAL, // material
//        (t_color){0.9, 0.1, 0.1}// color
//	};
//    add_hittable(data.world, new_rectangle(r));

	// add_hittable(data.world, new_plane(
    //     vec_new(0.0, 0.0, 0.0), // 平面上の点
    //     vec_new(0.0, 0.0, 1.0),   // 法線ベクトル
    //     (t_color){0.0, 0.9, 0}, // 色
    //     METAL // 材質
    // ));

//	t_cylinder c = {
//		vec_new(0, 0, 5), // 中心
//        vec_new(0, 1, 0),  // 軸方向
//        1.0, // 直径
//        3.0, // 高さ
//        (t_color){0.1, 0.4, 0.1}, // 色
//        1
//	};
    // 円柱
//    add_hittable(data.world, new_cylinder(c));
//	add_hittable(data.world, new_lambertian(vec_new(4, 3, 5), 1.0, (t_color){0.4, 0.9, 0.1}));

    // // 複数のライトを追加
    // add_light(&data.lights, new_light(vec_new(5, 5, 5), (t_color){1.0, 1.0, 1.0}, 0.5));
    // add_light(&data.lights, new_light(vec_new(-5, 5, 5), (t_color){1.0, 1.0, 1.0}, 0.3));
    // add_light(&data.lights, new_light(vec_new(0, 5, -5), (t_color){1, 0.1, 1}, 0.5));

    // 環境光を設定
    //data.ambient = new_ambient((t_color){0.2, 0.2, 0.2}, 0.5); // RGBと比率は必要に応じて調整

    render(&data);
    wait_input(&data);

    // メモリの解放
    free(data.lights.lights);
    free_hittable_list(data.world);

    return 0;
}

//int	main(int argc, char *argv[])
//{
//	t_data	data;
//
//	if (argc != 2)
//		exit(1);
//	parse_file(argv[1], &data);
//	print_struct(data);
//}
