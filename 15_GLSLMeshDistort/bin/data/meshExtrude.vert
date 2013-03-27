uniform sampler2DRect image;
uniform float extrusionAmount;
void main(void)
{
	//passes the texture coordinates along to the fragment shader
	gl_TexCoord[0] = gl_MultiTexCoord0;

	//samples the texture at the vertex location to get a color
	float brightness = texture2DRect(image, gl_TexCoord[0].st).r;

	vec4 extrudedVertex = vec4(gl_Vertex.x,
							   gl_Vertex.y,
							   gl_Vertex.z + texture2DRect(image, gl_TexCoord[0].st).r * extrusionAmount,
							   gl_Vertex.w);
	
	//magic spell that is the same as ftransform() but takes into account our modified vertex
	gl_Position = gl_ModelViewProjectionMatrix * extrudedVertex;
}
