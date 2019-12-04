#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

SEXP test() {
  glewExperimental = true; // Needed for core profile
  if(!glfwInit()) {
    Rprintf("Failed to initialize GLFW");
    return R_NilValue;
  }

  glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

  // Open a window and create its OpenGL context
  GLFWwindow* window; // (In the accompanying source code, this variable is global for simplicity)
  window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
  if (window == NULL) {
    Rprintf("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.");
    glfwTerminate();
    return R_NilValue;
  }
  glfwMakeContextCurrent(window); // Initialize GLEW
  glewExperimental = true; // Needed in core profile
  if (glewInit() != GLEW_OK) {
    Rprintf("Failed to initialize GLEW");
    return R_NilValue;
  }
  return R_NilValue;
}
