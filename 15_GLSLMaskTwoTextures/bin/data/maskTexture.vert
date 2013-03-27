
void main(void)
{
	//this is a default vertex shader without modifying the position
	gl_Position = ftransform();
	//.. and it also passes the texture coordinates along to the fragment shader
	gl_TexCoord[0] = gl_MultiTexCoord0;
}
