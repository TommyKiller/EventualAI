const char *vertex_shader =
"#version 460\n"

"layout (location = 0) in vec3 position;"

"void main()"
"{"
"	gl_Position = vec4(position.x, position.y, position.z, 1.0);"
"}";

const char *fragment_shader =
"#version 460 core\n"

"out vec4 color;"

"void main()"
"{"
"	color = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
"}";