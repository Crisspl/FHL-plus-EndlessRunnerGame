"#version 330 core\n"
"\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 2) in vec2 texCoords;\n"
"\n"
"out vec2 TexCoords;\n"
"\n"
"uniform mat4 translation;\n"
"uniform mat4 rotation;\n"
"uniform mat4 scale;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"\n"
"void main()\n"
"{\n"
"	mat4 model = translation * rotation * scale;\n"
"	gl_Position = projection * view * model * vec4(position, 1.0f);\n"
"	TexCoords = texCoords;\n"
"}\n"
