#version 430 core

uniform mat4 projMat;
uniform mat4 viewMat;
uniform mat4 modelMat;

layout (location = 0) in vec3 in_position;

out vec4 pos;

void main()
{
  gl_Position = projMat * viewMat * modelMat * vec4(in_position, 1.0);
  pos = abs(gl_Position);
  gl_PointSize = 16.0;
}
