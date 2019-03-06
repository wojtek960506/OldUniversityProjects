#version 330 core

out vec4 fragColor;
 
in vec2 texCoords;  

uniform vec3 ambient;
uniform sampler2D texture1;

void main()
{
		vec3 result = ambient * texture(texture1, texCoords).rgb;
		fragColor = vec4(result, 1.0);
} 