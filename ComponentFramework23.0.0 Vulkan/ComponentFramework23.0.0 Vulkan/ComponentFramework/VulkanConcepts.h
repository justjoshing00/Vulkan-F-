#pragma once
#include <string>
namespace VkConcepts
{
	//these are anything vulkan recognizes as a concept. If you crack open a vulkan tutorial and see it on a slide, youll see it here. 
	namespace Descriptors
	{

	}

	namespace UniformBufferObjects
	//This is where we store all the uniform buffer objects. Im still trying to figure out the relation these have to each other and whether those relations should happen at 
	//the UBO level or at the level of the containing object.
	//either way, these are much easier to find in here then they were buried in line 1XX of the VulkanRenderer.h file 
	{
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
	}
	namespace Commands
	{

	}
	namespace Pipelines
	{

	}
	namespace FileNames
	{
		//I had often been entering file paths wrong, so I created this so I didnt have to write them as often.
		//Now, when I need a file name, I define it in here and pass it to where I need it.  
		//const std::string works as a type for this because std::ifstream is okay taking a const string& and readfile returns a vector of char, which is the input type vulkan wants 

		struct TextureFilePaths
		{
			const std::string mariofire = "./textures/mario_fire.png";
			const std::string mariomain = "./textures/mario_main.png";
			const std::string mariomine = "./textures/mario_mime.png";
			const std::string skulltexture = "./textures/mario_texture.png";
		};
		struct MeshFilePaths
		{
			const std::string cube = "./meshes/Cube.obj";
			const std::string mario = "./meshes/Mario.obj";
			const std::string skull = "./meshes/Skull.obj";
			const std::string sphere = "./meshes/Sphere.obj";
			const std::string tetrahedron = "./meshes/Tetrahedron.obj";
		};
		struct ShaderFilePaths
		{
			const std::string vert = "./shaders/vert.spv";
			const std::string frag = "./shaders/frag.spv";
			const std::string phongvert = "./shaders/phong.spv";
			const std::string phongfrag = "./shaders/phongfrag.spv";
			const std::string examplevert = "./shaders/example27.vert.spv";
			const std::string badphongvert = "./shaders/badphongvert.spv";
			const std::string badphongfrag = "./shaders/badphongfrag.spv";
			const std::string multibadphongvert = "./shaders/multibadphongvert.spv";
			const std::string multibadphongfrag = "./shaders/multibadphongfrag.spv";
		};
	}
	namespace PushConstants
	{

	}
}
