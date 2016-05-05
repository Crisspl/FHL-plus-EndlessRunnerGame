#version 330 core

layout (location = 0) in vec2 position;

uniform mat4 translation;
uniform mat4 rotation;
uniform mat4 scale;
uniform mat4 view;
uniform mat4 projection;

out vec3 FragPos;

void main()
{
	mat4 model = translation * rotation * scale;
	gl_Position.xy = position;
	gl_Position.zw = vec2(0.f, 1.f);
	gl_Position = projection * view * model * gl_Position;
	FragPos = vec3(model * vec4(position, 0.f, 1.f));
}