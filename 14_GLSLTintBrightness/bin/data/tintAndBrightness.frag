
//here are some example uniforms
uniform sampler2DRect image;
uniform float brightness;
uniform vec4 tint;

void main (void)
{
	vec4 sample = texture2DRect(image, gl_TexCoord[0].st);
	//use the color tint as well as whatever ofSetColor() is set to
	gl_FragData[0] = sample * tint * brightness;
}
