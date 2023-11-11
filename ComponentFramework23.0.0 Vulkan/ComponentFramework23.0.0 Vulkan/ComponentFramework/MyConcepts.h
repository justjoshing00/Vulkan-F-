#pragma once
namespace JOConcepts
{
	//These are all concepts I have created. In the same way as there really isnt a camera, these also don't 'really' exist. They are just convenient.
	namespace Lighting
	{
		//a light should 'have' a light ubo in it 
	}
	namespace Cameras
	{
		//a camera should 'have' a camera ubo in it 
	}
	namespace Models
	{
		//a model should have a model ubo in it
	}
	namespace Materials
	{
		//normally, wed put the roughness, reflectivity, and metal-ness in here, but thats too complicated for the shaders I have and so
		// we are just going to store initial diffuse values here.
	}
	
	namespace Tests
	{
		//I just want to test to make sure of some basic things like whether a pointer points to what I think its pointing to.  
	}
	namespace MemoryMarking
	{
		// This is an idea I had for cleaning up memory:
		// I want to be able to mark an object for destruction later by binding it to an owning object using smart pointers. The idea is that when the owning object is destroyed, 
		// the smart pointers are destroyed and so all the things the smart pointers point to are also destroyed.
	}

	namespace GameObjects
	{
		//this is a little loose. Ideally we handle this somewhere else, but this isnt the framework for that. 
		// Probably need to call the contructor for these before the scene begins
		//Need to only have a few of these.
		
		
		struct Mario // is renderable, is movable, has constructor, 
		{
			
		};
		struct Cube // is renderable, is movable, has constructor,
		{

		};
	}
}
