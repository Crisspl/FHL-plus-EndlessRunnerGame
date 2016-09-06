"#version 330 core\n"
"\n"
"layout (location = 0) in vec2 position;\n"
"\n"
"uniform mat4 translation;\n"
"uniform mat4 rotation;\n"
"uniform mat4 scale;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"\n"
"void main()\n"
"{\n"
"	gl_Position.xy = position;\n"
"	gl_Position.zw = vec2(0.f, 1.f);\n"
"	gl_Position = projection * view * translation * rotation * scale * gl_Position;\n"
"}\n"
