//
// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#include "opengles2_shaderutils.h"






#include "base/types.hpp"
#undef new
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#define new sDEFINE_NEW
#include <assert.h>



extern HWND sHWND;


#include <vector>
#include <iostream>
#include <fstream>

static std::string ReadFileToString(const std::string &source)
{
    std::ifstream stream(source.c_str());
    if (!stream)
    {
        std::cerr << "Failed to load shader file: " << source;
        return "";
    }

    std::string result;

    stream.seekg(0, std::ios::end);
    result.reserve(static_cast<unsigned int>(stream.tellg()));
    stream.seekg(0, std::ios::beg);

    result.assign((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

    return result;
}

GLuint CompileShader(GLenum type, const std::string &source)
{
    GLuint shader = glCreateShader(type);

    const char *sourceArray[1] = { source.c_str() };
    glShaderSource(shader, 1, sourceArray, NULL);
    glCompileShader(shader);

    GLint compileResult;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

    if (compileResult == 0)
    {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

        // Info log length includes the null terminator, so 1 means that the info log is an empty
        // string.
        if (infoLogLength > 1)
        {
            std::vector<GLchar> infoLog(infoLogLength);
            glGetShaderInfoLog(shader, static_cast<GLsizei>(infoLog.size()), NULL, &infoLog[0]);
            std::cerr << "shader compilation failed: " << &infoLog[0];
        }
        else
        {
            std::cerr << "shader compilation failed. <Empty log message>";
        }

        glDeleteShader(shader);
        shader = 0;
    }

    return shader;
}

GLuint CompileShaderFromFile(GLenum type, const std::string &sourcePath)
{
    std::string source = ReadFileToString(sourcePath);
    if (source.empty())
    {
        return 0;
    }

    return CompileShader(type, source);
}

GLuint CompileProgramWithTransformFeedback(
    const std::string &vsSource,
    const std::string &fsSource,
    const std::vector<std::string> &transformFeedbackVaryings,
    GLenum bufferMode)
{
    GLuint program = glCreateProgram();

    GLuint vs = CompileShader(GL_VERTEX_SHADER, vsSource);
    GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fsSource);

    if (vs == 0 || fs == 0)
    {
        glDeleteShader(fs);
        glDeleteShader(vs);
        glDeleteProgram(program);
        return 0;
    }

    glAttachShader(program, vs);
    glDeleteShader(vs);

    glAttachShader(program, fs);
    glDeleteShader(fs);

    if (transformFeedbackVaryings.size() > 0)
    {
        std::vector<const char *> constCharTFVaryings;

        for (const std::string &transformFeedbackVarying : transformFeedbackVaryings)
        {
            constCharTFVaryings.push_back(transformFeedbackVarying.c_str());
        }

        glTransformFeedbackVaryings(program, static_cast<GLsizei>(transformFeedbackVaryings.size()),
                                    &constCharTFVaryings[0], bufferMode);
    }

    glLinkProgram(program);

    GLint linkStatus;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);

    if (linkStatus == 0)
    {
        GLint infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

        // Info log length includes the null terminator, so 1 means that the info log is an empty
        // string.
        if (infoLogLength > 1)
        {
            std::vector<GLchar> infoLog(infoLogLength);
            glGetProgramInfoLog(program, static_cast<GLsizei>(infoLog.size()), nullptr, &infoLog[0]);

            std::cerr << "program link failed: " << &infoLog[0];
        }
        else
        {
            std::cerr << "program link failed. <Empty log message>";
        }

        glDeleteProgram(program);
        return 0;
    }

    return program;
}

GLuint CompileProgram(const std::string &vsSource, const std::string &fsSource)
{
    std::vector<std::string> emptyVector;
    return CompileProgramWithTransformFeedback(vsSource, fsSource, emptyVector, GL_NONE);
}

GLuint CompileProgramFromFiles(const std::string &vsPath, const std::string &fsPath)
{
    std::string vsSource = ReadFileToString(vsPath);
    std::string fsSource = ReadFileToString(fsPath);
    if (vsSource.empty() || fsSource.empty())
    {
        return 0;
    }

    return CompileProgram(vsSource, fsSource);
}
















GLuint mProgram = 0;
//PFNEGLGETPLATFORMDISPLAYEXTPROC eglGetPlatformDisplayEXT;

struct EGLPlatformParameters {
    EGLint renderer;
    EGLint majorVersion;
    EGLint minorVersion;
    EGLint deviceType;
    EGLint presentPath;
};

// privates of EGLWindow
EGLConfig mConfig;
EGLDisplay mDisplay; // just a void pointer
EGLSurface mSurface;
EGLContext mContext;
EGLint mClientMajorVersion = 2;
EGLint mClientMinorVersion = 0;
EGLPlatformParameters mPlatform;
int mRedBits;
int mGreenBits;
int mBlueBits;
int mAlphaBits;
int mDepthBits;
int mStencilBits;
bool mMultisample;
bool mDebug;
bool mNoError;
EGLint mSwapInterval;

void triangle_draw() {
    GLfloat vertices[] =
    {
            0.0f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
    };
    // Set the viewport
    //glViewport(0, 0, getWindow()->getWidth(), getWindow()->getHeight());
	//glClearColor(0.5, 0, 0, 0.5);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glClear(/*GL_COLOR_BUFFER_BIT |*/ GL_DEPTH_BUFFER_BIT);
	//glDisable(GL_DEPTH_TEST);
	//glEnable(GL_SCISSOR_TEST);
	//glEnable(GL_ALPHA);
    // Clear the color buffer
    //glClear(GL_COLOR_BUFFER_BIT);
    // Use the program object
    glUseProgram(mProgram);
    // Load the vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

//egl::Surface *eglSurface;

bool EGLWindow_initializeGL(/*OSWindow *osWindow*/)
{
			//eglGetPlatformDisplayEXT = reinterpret_cast<PFNEGLGETPLATFORMDISPLAYEXTPROC>(eglGetProcAddress("eglGetPlatformDisplayEXT"));
			//assert(eglGetPlatformDisplayEXT != nullptr);
			EGLint dispattrs[] =
			{
				EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D9_ANGLE,
				EGL_NONE
			};
			//mDisplay = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, reinterpret_cast<void *>(EGL_DEFAULT_DISPLAY), dispattrs);
			//assert(mDisplay != EGL_NO_DISPLAY);
			//assert(eglInitialize(mDisplay, nullptr, nullptr) == EGL_TRUE);
			//int nConfigs = 0;
			//assert(eglGetConfigs(mDisplay, nullptr, 0, &nConfigs) == EGL_TRUE);
			//assert(nConfigs != 0);
			//int nReturnedConfigs = 0;
		   // mConfigs.resize(nConfigs);
			//assert(eglGetConfigs(mDisplay, mConfigs.data(), nConfigs, &nReturnedConfigs) == EGL_TRUE);
			//assert(nConfigs == nReturnedConfigs);


    //eglGetPlatformDisplayEXT = reinterpret_cast<PFNEGLGETPLATFORMDISPLAYEXTPROC>(eglGetProcAddress("eglGetPlatformDisplayEXT"));
    //if (!eglGetPlatformDisplayEXT)
    //{
    //    return false;
    //}

    std::vector<EGLint> displayAttributes;

    displayAttributes.push_back(EGL_PLATFORM_ANGLE_TYPE_ANGLE);
    //displayAttributes.push_back(mPlatform.renderer);
	displayAttributes.push_back(EGL_PLATFORM_ANGLE_TYPE_D3D9_ANGLE);

    displayAttributes.push_back(EGL_PLATFORM_ANGLE_MAX_VERSION_MAJOR_ANGLE);
    //displayAttributes.push_back(mPlatform.majorVersion);
	displayAttributes.push_back(2);

    displayAttributes.push_back(EGL_PLATFORM_ANGLE_MAX_VERSION_MINOR_ANGLE);
    //displayAttributes.push_back(mPlatform.minorVersion);
    displayAttributes.push_back(0);

    //if (mPlatform.deviceType != EGL_DONT_CARE)
    //{
    //    displayAttributes.push_back(EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE);
    //    displayAttributes.push_back(mPlatform.deviceType);
    //}

    //if (mPlatform.presentPath != EGL_DONT_CARE)
    //{
    //    const char *extensionString =
    //        static_cast<const char *>(eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS));
    //    if (strstr(extensionString, "EGL_ANGLE_experimental_present_path") == nullptr)
    //    {
    //        //destroyGL();
    //        return false;
    //    }
	//
    //    displayAttributes.push_back(EGL_EXPERIMENTAL_PRESENT_PATH_ANGLE);
    //    displayAttributes.push_back(mPlatform.presentPath);
    //}
    displayAttributes.push_back(EGL_NONE);

    mDisplay = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE,
                                        //reinterpret_cast<void *>(osWindow->getNativeDisplay()),
										reinterpret_cast<void *>(EGL_DEFAULT_DISPLAY),
                                        &displayAttributes[0]);

    if (mDisplay == EGL_NO_DISPLAY)
    {
       // destroyGL();
        return false;
    }

    EGLint majorVersion, minorVersion;
    if (eglInitialize(mDisplay, &majorVersion, &minorVersion) == EGL_FALSE)
    {
        //destroyGL();
        return false;
    }

    const char *displayExtensions = eglQueryString(mDisplay, EGL_EXTENSIONS);
	
    // EGL_KHR_create_context is required to request a non-ES2 context.
    bool hasKHRCreateContext = strstr(displayExtensions, "EGL_KHR_create_context") != nullptr;
    if (majorVersion != 2 && minorVersion != 0 && !hasKHRCreateContext)
    {
        //destroyGL();
        return false;
    }
	
    eglBindAPI(EGL_OPENGL_ES_API);
    if (eglGetError() != EGL_SUCCESS)
    {
        //destroyGL();
        return false;
    }
	
    const EGLint configAttributes[] =
    {
        EGL_RED_SIZE,       (mRedBits >= 0)     ? mRedBits     : EGL_DONT_CARE,
        EGL_GREEN_SIZE,     (mGreenBits >= 0)   ? mGreenBits   : EGL_DONT_CARE,
        EGL_BLUE_SIZE,      (mBlueBits >= 0)    ? mBlueBits    : EGL_DONT_CARE,
        EGL_ALPHA_SIZE,     (mAlphaBits >= 0)   ? mAlphaBits   : EGL_DONT_CARE,
        EGL_DEPTH_SIZE,     (mDepthBits >= 0)   ? mDepthBits   : EGL_DONT_CARE,
        EGL_STENCIL_SIZE,   (mStencilBits >= 0) ? mStencilBits : EGL_DONT_CARE,
        EGL_SAMPLE_BUFFERS, mMultisample ? 1 : 0,
        EGL_NONE
    };

    EGLint configCount;
    if (!eglChooseConfig(mDisplay, configAttributes, &mConfig, 1, &configCount) || (configCount != 1))
    {
        //destroyGL();
        return false;
    }
	
    eglGetConfigAttrib(mDisplay, mConfig, EGL_RED_SIZE, &mRedBits);
    eglGetConfigAttrib(mDisplay, mConfig, EGL_GREEN_SIZE, &mGreenBits);
    eglGetConfigAttrib(mDisplay, mConfig, EGL_BLUE_SIZE, &mBlueBits);
    eglGetConfigAttrib(mDisplay, mConfig, EGL_ALPHA_SIZE, &mAlphaBits);
    eglGetConfigAttrib(mDisplay, mConfig, EGL_DEPTH_SIZE, &mDepthBits);
    eglGetConfigAttrib(mDisplay, mConfig, EGL_STENCIL_SIZE, &mStencilBits);
	
    std::vector<EGLint> surfaceAttributes;
    if (strstr(displayExtensions, "EGL_NV_post_sub_buffer") != nullptr)
    {
        surfaceAttributes.push_back(EGL_POST_SUB_BUFFER_SUPPORTED_NV);
        surfaceAttributes.push_back(EGL_TRUE);
    }
	
    surfaceAttributes.push_back(EGL_NONE);

    //mSurface = eglCreateWindowSurface(mDisplay, mConfig, osWindow->getNativeWindow(), &surfaceAttributes[0]);
	mSurface = eglCreateWindowSurface(mDisplay, mConfig, (EGLNativeWindowType)sHWND, &surfaceAttributes[0]);
    if (eglGetError() != EGL_SUCCESS)
    {
        //destroyGL();
        return false;
    }
    assert(mSurface != EGL_NO_SURFACE);
	
	
	//eglSurface = (egl::Surface *)mSurface;
	
    std::vector<EGLint> contextAttributes;
    if (hasKHRCreateContext)
    {
        contextAttributes.push_back(EGL_CONTEXT_MAJOR_VERSION_KHR);
        contextAttributes.push_back(mClientMajorVersion);
	
        contextAttributes.push_back(EGL_CONTEXT_MINOR_VERSION_KHR);
        contextAttributes.push_back(mClientMinorVersion);
	
        contextAttributes.push_back(EGL_CONTEXT_OPENGL_DEBUG);
        contextAttributes.push_back(mDebug ? EGL_TRUE : EGL_FALSE);
	
        // TODO(jmadill): Check for the extension string.
        // bool hasKHRCreateContextNoError = strstr(displayExtensions,
        // "EGL_KHR_create_context_no_error") != nullptr;
	
        contextAttributes.push_back(EGL_CONTEXT_OPENGL_NO_ERROR_KHR);
        contextAttributes.push_back(mNoError ? EGL_TRUE : EGL_FALSE);
    }
    contextAttributes.push_back(EGL_NONE);

    mContext = eglCreateContext(mDisplay, mConfig, nullptr, &contextAttributes[0]);
    if (eglGetError() != EGL_SUCCESS)
    {
        //destroyGL();
        return false;
    }

    eglMakeCurrent(mDisplay, mSurface, mSurface, mContext);
    if (eglGetError() != EGL_SUCCESS)
    {
        //destroyGL();
        return false;
    }
	
    if (mSwapInterval != -1)
    {
        eglSwapInterval(mDisplay, mSwapInterval);
    }

    return true;
}

void compile_program() {
	const std::string vs = SHADER_SOURCE
	(
		attribute vec4 vPosition;
		void main()
		{
			gl_Position = vPosition;
		}
	);
	const std::string fs = SHADER_SOURCE
	(
		precision mediump float;
		void main()
		{
			gl_FragColor = vec4(1.0, 0.0, 0.0, 0.5);
		}
	);
	mProgram = CompileProgram(vs, fs);
}

extern "C" __declspec(dllimport) void force_this_d3d9_device(/*LPDIRECT3D9 pD3D,*/ IDirect3DDevice9 *mDevice, IDirect3D9 *mD3d9);

D3DPRESENT_PARAMETERS Renderer9_getDefaultPresentParameters()
{
    D3DPRESENT_PARAMETERS presentParameters = {0};

    // The default swap chain is never actually used. Surface will create a new swap chain with the proper parameters.
    presentParameters.AutoDepthStencilFormat = D3DFMT_UNKNOWN;
    presentParameters.BackBufferCount = 1;
    presentParameters.BackBufferFormat = D3DFMT_UNKNOWN;
    presentParameters.BackBufferWidth = 1;
    presentParameters.BackBufferHeight = 1;
    presentParameters.EnableAutoDepthStencil = FALSE;
    presentParameters.Flags = 0;
    //presentParameters.hDeviceWindow = mDeviceWindow;hwnd
	presentParameters.hDeviceWindow = sHWND;
    presentParameters.MultiSampleQuality = 0;
    presentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
    presentParameters.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;
    presentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
    presentParameters.Windowed = TRUE;

    return presentParameters;
}