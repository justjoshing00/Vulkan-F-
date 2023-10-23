#ifndef SCENE0_H
#define SCENE0_H
#include "Scene.h"
#include "Vector.h"
#include "Renderer.h"
#include "Camera.h"
#include <array>
using namespace MATH;

/// Forward declarations 
union SDL_Event;


class Scene0 : public Scene {
private:
	Renderer *renderer;
	Camera *camera;
	Matrix4 mariosModelMatrix; 
	// normal rotation
	Matrix4 mariosTransform;
	Matrix4 Light1Matrix;
	Matrix4 CameraMatrix;
	
	
	std::array<Vec4, 2> diffuses = { Vec4(0,0,0,0),Vec4(0,0,0,0) };
	std::array<Vec4, 2> positions = { Vec4(0,0,0,0),Vec4(0,0,0,0) };


public:
	explicit Scene0(Renderer* renderer_);
	virtual ~Scene0();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event &sdlEvent) override;
};


#endif // SCENE0_H