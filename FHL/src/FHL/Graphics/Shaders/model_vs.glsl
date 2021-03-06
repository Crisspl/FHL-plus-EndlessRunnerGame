"#version 330 core\n"

"layout (location = 0) in vec3 position;\n"
"layout (location = 2) in vec2 texCoords;\n"

"out vec2 TexCoords;\n"

"uniform mat4 mvp;\n"

"void main()\n"
"{\n"
	 "gl_Position = mvp * vec4(position, 1.0f);\n"
	 "TexCoords = texCoords;\n"
"}"
