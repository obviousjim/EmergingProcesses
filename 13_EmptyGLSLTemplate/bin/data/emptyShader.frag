
//here are some example uniforms

//uniform sampler2DRect image;
//uniform float singleValue;
//uniform vec2 twoValues;
//uniform vec3 maybeAColor;

void main (void)
{
	//sample the color
	//vec4 colorSample = texture2DRect(image, gl_TexCoord[0].st);
	
	//use the color tint as well as whatever ofSetColor() is set to
	gl_FragData[0] = colorSample * gl_Color;
	
}
