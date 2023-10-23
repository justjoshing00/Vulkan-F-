#version 450
#extension GL_ARB_separate_shader_objects : enable

struct GLUBO
{
	vec4 position;
    vec4 diffuse;
};

layout(binding = 1) uniform LightBlock {
    GLUBO lights[2];
};

layout (location = 0) in vec3 vertNormal;
layout (location = 1) in vec3 lightDir;
layout (location = 2) in vec3 eyeDir; 
layout (location = 3) in vec2 fragTexCoords;
layout (location = 4) in vec3 lightDir2;


layout (location = 0) out vec4 fragColor;

layout(binding = 2) uniform sampler2D texSampler;


void main() { 
	vec4 ks; = vec4(0.6,0.6,0.6,0.0);
	vec4 ks2 = vec4(0.6,0.6,0.6,0.0);
	vec4 kd = lights[0].diffuse;    
	vec4 kd2 = lights[1].diffuse;    
	vec4 kt = texture(texSampler,fragTexCoords);
	vec4 ka = 0.01 * kt;
	
	//diffusion intensity
	float diff = max(dot(vertNormal, lightDir), 0.0);
	float diff2 = max(dot(vertNormal, lightDir2), 0.0);

	/// Reflection is based incedent beam of light which means a vector 
	/// from the light source not the direction to the light source. 
	/// reverse light direction by making it negative
	vec3 reflection = normalize(reflect(-lightDir, vertNormal));
	vec3 reflection2 = normalize(reflect(-lightDir2, vertNormal));

	//reflective intensity
	float spec = max(dot(eyeDir, reflection), 0.0);
	float spec2 = max(dot(eyeDir, reflection2), 0.0);
	spec = pow(spec,14.0);
	spec2 = pow(spec2,14.0);
	
	 
	fragColor = kt + (spec * ks) + (diff * kd) + (spec2 * ks2) + (diff2 * kd2);

	
} 