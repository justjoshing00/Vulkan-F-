#version 450
#extension GL_ARB_separate_shader_objects : enable

layout (location = 0) in  vec4 vVertex;
layout (location = 1) in  vec4 vNormal;
layout (location = 2) in  vec2 texCoords;

struct GLUBO
{
	vec4 position;
    vec4 diffuse;
};


layout(binding = 0) uniform CameraUBO {
    mat4 viewMatrix;
    mat4 projectionMatrix;
	mat4 modelMatrix;
} camera;

layout(binding = 1) uniform LightBlock {
    GLUBO lights[2];
};

layout( push_constant ) uniform MarioData
{
	mat4 modelMatrix;
	mat4 normal;
} PushConstant;



layout (location = 0) out vec3 vertNormal;
layout (location = 1) out vec3 lightDir;
layout (location = 2) out vec3 eyeDir;
layout (location = 3) out vec2 fragmentTexCoords;
layout (location = 4) out vec3 lightDir2;



void main()
{
	fragmentTexCoords = texCoords;
	
	mat3 normalMatrix = mat3(PushConstant.normal);
	

	vertNormal = normalize(normalMatrix * vNormal.xyz); /// Rotate the normal to the correct orientation 
	vec3 vertPos = vec3(camera.viewMatrix * PushConstant.modelMatrix * vVertex); /// This is the position of the vertex from the origin
	vec3 vertDir = normalize(vertPos);
	eyeDir = -vertDir;

	
	lightDir = normalize(vec3(lights[0].position) - vertPos); /// Create the light direction.
	lightDir2 = normalize(vec3(lights[1].position) - vertPos); /// Create the other light direction.
	gl_Position =  camera.projectionMatrix * camera.viewMatrix * PushConstant.modelMatrix * vVertex; 
}