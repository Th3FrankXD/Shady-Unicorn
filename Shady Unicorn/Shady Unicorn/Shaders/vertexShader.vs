#version 430 core
out vec4 pos;

void main()
{
  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
  pos = abs(gl_Position);
  gl_PointSize = 16.0;
}
