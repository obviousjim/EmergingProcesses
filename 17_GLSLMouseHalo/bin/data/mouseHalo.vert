
//the vertex shader will pass along the screen position based on the vertex position
//a 'varying' will be different for each pixel, as opposed to 'uniforms' which are set from within openFrameworks and stay the same
varying vec2 screenPosition;

void main(void)
{
	//this is a default vertex shader, don't modify the position
	gl_Position = ftransform();
	//take the xy from the screen position and pass it along to the fragment shader
	screenPosition	= gl_Vertex.xy;
}
