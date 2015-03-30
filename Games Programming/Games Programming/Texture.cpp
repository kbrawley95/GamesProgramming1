/*
=================
Texture.cpp
- CPP file for class definition - IMPLEMENTATION
- CPP file for the cD3DXTextureMgr class
=================
*/
#include "Texture.h"

/*
=================
- Data constructor initializes the cD3DXTextureMgr object
- Is always called, thus ensures all cD3DXTextureMgr objects are in a consistent state.
=================
*/
Texture::Texture()
{
	Texture::GLTextureID = NULL;
	textCords[0] = vec2(0, 0);
	textCords[1] = vec2(1, 0);
	textCords[2] = vec2(1, 1);
	textCords[3] = vec2(0, 1);
}

Texture::Texture(LPCSTR theFilename)
{
	Texture::createTexture(theFilename);
	textCords[0] = vec2(0, 0);
	textCords[1] = vec2(1, 0);
	textCords[2] = vec2(1, 1);
	textCords[3] = vec2(0, 1);
}

/*
=================
- Destructor.
=================
*/
Texture::~Texture()
{
	ilDeleteImages(1, &ilTextureID);
}

/*
=================
- create the texture for use.
=================
*/
bool Texture::createTexture(LPCSTR theFilename) 	// create the texture for use.
{

	ILboolean success = false;

	if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
	{
		return false;
	}

	ilInit();  /*Initialize the DevIL library*/
	ilGenImages(1, &ilTextureID); //Generate DevIL image objects
	ilBindImage(ilTextureID); /* Binding of image object */
	success = ilLoadImage((const ILstring)theFilename); /* Loading of image*/

	if (!success)
	{
		ilDeleteImages(1, &ilTextureID);
		return false;
	}

	success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE); // Convert every colour component into unsigned byte.
	if (!success)
	{
		return false;
	}

	textureWidth = ilGetInteger(IL_IMAGE_WIDTH);
	textureHeight = ilGetInteger(IL_IMAGE_HEIGHT);

	glGenTextures(1, &GLTextureID); // GLTexture name generation 
	glBindTexture(GL_TEXTURE_2D, GLTextureID); // Binding of GLtexture name 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Use linear interpolation for magnification filter
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Use linear interpolation for minifying filter 
	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
		ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
		ilGetData()); /* Texture specification */
	glBindTexture(GL_TEXTURE_2D, GLTextureID); // Binding of GLtexture name 

	ilDeleteImages(1, &ilTextureID);

	return true;
}
/*
=================
- return the texture.
=================
*/
GLuint Texture::getTexture()        // return the texture.
{
	return Texture::GLTextureID;
}

/*
=================
- Return width of texture.
=================
*/
GLsizei Texture::getTWidth() 						// Return width of texture;
{
	return textureWidth;
}
/*
=================
- Return height of texture.
=================
*/
GLsizei Texture::getTHeight() 						// Return height of texture;
{
	return textureHeight;
}