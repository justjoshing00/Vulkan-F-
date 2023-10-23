#pragma once
#include "Vector.h"
#include "VMath.h"

class LightUBO
{

};

class SpotLight :LightUBO
{
	//a cone of light shining on the object
	Vec4 position;
	float Radius;
	Vec4 Direction;
};
class DirectionalLight :LightUBO
{
	Vec4 position;
	Vec4 direction;
};
class GlobalLight :LightUBO
{
public:
	Vec4 position;
	Vec4 diffuse;
};

class VolumetricLight :LightUBO
{
	Vec4 position;
	float length;
	float width;
	float height;
	
};
class AreaLight :LightUBO
{
	Vec4 position;
	float length;
	float width;
};
class PointLight : LightUBO
{
	Vec4 position;
};



struct MarioData
{
	Matrix4 model;
	Matrix4 normal;
};

struct CameraUBO
{
public:
	Matrix4 view;
	Matrix4 proj;
	
};
