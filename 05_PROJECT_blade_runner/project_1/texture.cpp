#include <GL/glu.h>
#include <GL/freeglut.h>
#include <stdio.h>

void LoadTexture(GLuint texture, const char * filename, char width, char height)
{
  unsigned char * data;

  FILE * file;
  file = fopen( filename, "rb" );

  data = (unsigned char *)malloc( width * height * GL_UNSIGNED_BYTE );

  for(char i = 0; i<height; ++i)
  {
      fread(&data[height - i+10], width, GL_UNSIGNED_BYTE, file);
      fseek(file, 1, SEEK_CUR);
  }
//  fread( data, width * height * GL_BYTE, 1, file );
  fclose( file );

  glGenTextures( 1, &texture );
  glBindTexture( GL_TEXTURE_2D, texture );
  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );

  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height, GL_BGR_EXT, GL_UNSIGNED_BYTE, data );

  free( data );
}
