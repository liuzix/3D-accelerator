//
//  MacLinux.h
//
//  Header file to include the correct header files depending on
//  operating system.
//
//  Created by  on 2/1/17.
//
//

#ifndef ____MacLinux__
#define ____MacLinux__

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#endif /* defined(____MacLinux__) */
