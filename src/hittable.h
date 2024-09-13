﻿//
// Created by PETROS on 15/09/2024.
//

#ifndef HITTABLE_H
#define HITTABLE_H

#include <cassert>
#include <memory>

#include "ray.h"
#include "interval.h"


class material;

class hit_record {
public:
    point3 p;
    vec3 normal;
    std::shared_ptr<material> mat;
    double t{};
    bool front_face{};

    void set_face_normal(const ray &r, const vec3 &outward_normal) {
        assert(std::fabs(outward_normal.length() - 1.0) <= 1e-9);

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};


class hittable {
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray &r, interval ray_t, hit_record &rec) const = 0;
};


#endif //HITTABLE_H
