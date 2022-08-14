#version 460 core

out vec4 color;
in vec2 texcrd;

uniform sampler2D txt;

void main()
{
    color = texture(txt, texcrd);
}