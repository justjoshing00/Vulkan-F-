#pragma once
#include <string>


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

//Made this to minimize errors from incorrect file path entry
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