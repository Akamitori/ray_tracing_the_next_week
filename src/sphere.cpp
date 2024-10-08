﻿//
// Created by PETROS on 15/09/2024.
//

#include "sphere.h"

sphere::sphere(const point3 &center, const double radius, const std::shared_ptr<material> &mat) :
        center(center),
        radius(std::fmax(0, radius)),
        mat(mat) {
}

bool sphere::hit(const ray &r, interval ray_t, hit_record &rec) const {
    const vec3 oc = center - r.origin();

    const auto a = r.direction().length_squared();
    const auto h = dot(r.direction(), oc);
    const auto c = oc.length_squared() - radius * radius;

    const auto discriminant = h * h - a * c;

    if (discriminant < 0) {
        return false;
    }

    auto sqrt_discriminant = sqrt(discriminant);

    auto root = (h - sqrt_discriminant) / a;

    if (!ray_t.surrounds(root)) {
        root = (h + sqrt_discriminant) / a;
        if (!ray_t.surrounds(root)) {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat = mat;

    return true;
}
