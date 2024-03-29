#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>
#include "Ray.h"
#include "Material.h"
#include "BBox3D.h"

class HitRecord;
class BoundingBox;

struct Surface {
    Surface();
    Surface(Surface& surface);
    Surface(Vector3f centre, BoundingBox *bbox);
    Surface& operator=(Surface& surface);
	~Surface();

	Eigen::Vector3f centre;
	Material* mat;
    BBox3Df* worldBounds;
    std::string type;
    bool ignore = false; // TODO: self-shadow prevention
    BoundingBox* bbox;

    virtual void info();
    virtual bool hit(Ray& r, float t0, float t1, HitRecord& hitReturn);
  //virtual bool hit(Ray& r, float t0, float t1) = 0;
    //virtual void makebbox();
    void setbbox(BoundingBox *pBox);
};
