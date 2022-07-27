#version 460 core

uniform sampler2D text;

in vec2 coord;

out vec4 color;

void main()
{
    color =texture(text, coord);
}