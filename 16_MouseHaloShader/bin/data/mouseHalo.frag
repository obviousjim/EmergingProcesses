//set from openFrameworks before draw
uniform float radius;
uniform vec2 mousePosition;
//will be different for every pixel based on where it is on the screen;
varying vec2 screenPosition;
void main (void)
{
	float color = 1.0 - min( distance(screenPosition, mousePosition) / radius, 1.0);
	gl_FragData[0] = vec4(color,color,color,1.0);
	
}
