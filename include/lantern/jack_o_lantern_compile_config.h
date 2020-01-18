#pragma once


#define   LANTERN_VERSION_MAJOR       0
#define   LANTERN_VERSION_MINOR       1
#define   LANTERN_VERSION_REVISION    0

#define   LANTERN_SDK_VERSION         "0.1.0"


#include <stdio.h>


#ifdef JOL_COMPILE_WITH_CONSOLE_DEVICE
#   undef      NO_JOL_COMPILE_WITH_CONSOLE_DEVICE
#endif  /* def JOL_COMPILE_WITH_CONSOLE_DEVICE */


#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)

#   define     JOL_PLATFORM_IS_WINDOWS
#   define     JOL_USING_WINDOWS_API
#   define     JOL_COMPILE_WITH_WINDOWS_DEVICE

#endif  /* defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64) */

#if defined(_WIN32_CE)

#   define     JOL_PLATFORM_IS_WINDOWS
#   define     JOL_PLATFORM_IS_WINDOWS_CE
#   define     JOL_USING_WINDOWS_API
#   define     JOL_COMPILE_WITH_WINDOWS_DEVICE

#endif  /* defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64) */

#if defined(_MSC_VER) && ( _MSC_VER < 1300 )
#   error "Only Microsoft Visual Studio 7.0 and later are supported."
#endif  /* defined(_MSC_VER) && ( _MSC_VER < 1300 ) */

#if defined(_XBOX)

#   undef      JOL_PLATFORM_IS_WINDOWS
#   define     JOL_PLATFORM_IS_XBOX
#   define     JOL_USING_WINDOWS_API
#   define     JOL_COMPILE_WITH_WINDOWS_DEVICE

#   include <xtl.h>
#endif  /* defined(_XBOX) */

#if defined(__APPLE__) || defined(MACOSX)

#    if !defined(MACOSX)
#       define MAXOSX                               // legacy support
#    endif  /* !defined(MACOSX) */

#    define    JOL_PLATFORM_IS_OSX
#    define    JOL_COMPILE_WITH_OSX_DEVICE

#endif  /* defined(__APPLE__) || defined(MACOSX) */

#if !defined(JOL_USING_WINDOWS_API) && !defined(JOL_PLATFORM_IS_OSX)

#   ifndef JOL_PLATFORM_IS_SOLARIS
// solaris じゃなかったら多分 linux
#       define JOL_PLATFORM_IS_LINUX
#   endif  /* ndef JOL_PLATFORM_IS_SOLARIS */

#   define   JOL_USING_POSIX_API
// 多分 X11 が入ってるデバイスだろうけど、Wayland かもしれないよ？
#   define   JOL_COMPILE_WITH_X11_DEVICE

#endif  /* !defined(JOL_USING_WINDOWS_API) && !defined(JOL_PLATFORM_IS_OSX) */


#define    JOL_COMPILE_WITH_JOYSTICK_EVENTS
#ifdef NO_JOL_COMPILE_WITH_JOYSTICK_EVENTS
#   undef    JOL_COMPILE_WITH_JOYSTICK_EVENTS
#endif  /* def NO_JOL_COMPILE_WITH_JOYSTICK_EVENTS */


/*!
 * \def JOL_MATERIAL_MAX_TEXTURES
 * jack-o-lantern においてはマテリアルテクスチャーの最大値は 4。
 */
#define    JOL_MATERIAL_MAX_TEXTURES    4



#if defined(JOL_USING_WINDOWS_API) && (!defined(__GNUC__) || defined(JOL_COMPILE_DX9_DEV_PACK))

#    define JOL_COMPILE_WITH_DIRECTINPUT_JOYSTICK
#    ifdef NO_JOL_COMPILE_WITH_DIRECTINPUT_JOYSTICK
#       undef JOL_COMPILE_WITH_DIRECTINPUT_JOYSTICK
#    endif  /* def NO_JOL_COMPILE_WITH_DIRECTINPUT_JOYSTICK */

#    if defined(__BORLANDC__)
#       undef JOL_COMPILE_WITH_DIRECTINPUT_JOYSTICK
#    endif  /* defined(__BORLANDC__) */

/* #    define    JOL_COMPILE_WITH_DIRECT3D_9 */
#    define    JOL_COMPILE_WITH_DIRECT3D_10
#    define    JOL_COMPILE_WITH_DIRECT3D_11
#    define    JOL_COMPILE_WITH_DIRECT3D_12


#    ifdef NO_JOL_COMPILE_WITH_DIRECT3D_8
#       undef JOL_COMPILE_WITH_DIRECT3D_8
#    endif  /* def NO_JOL_COMPILE_WITH_DIRECT3D_8 */

#    ifdef NO_JOL_COMPILE_WITH_DIRECT3D_9
#       undef JOL_COMPILE_WITH_DIRECT3D_9
#    endif  /* def NO_JOL_COMPILE_WITH_DIRECT3D_9 */

#    ifdef NO_JOL_COMPILE_WITH_DIRECT3D_10
#       undef JOL_COMPILE_WITH_DIRECT3D_10
#    endif  /* def NO_JOL_COMPILE_WITH_DIRECT3D_10 */

#    ifdef NO_JOL_COMPILE_WITH_DIRECT3D_11
#       undef JOL_COMPILE_WITH_DIRECT3D_11
#    endif  /* def NO_JOL_COMPILE_WITH_DIRECT3D_11 */

#    ifdef NO_JOL_COMPILE_WITH_DIRECT3D_12
#       undef JOL_COMPILE_WITH_DIRECT3D_12
#    endif  /* def NO_JOL_COMPILE_WITH_DIRECT3D_12 */

#endif  /* defined(JOL_USING_WINDOWS_API) && (!defined(__GNUC__) || defined(JOL_COMPILE_DX9_DEV_PACK)) */

/*
  ここで、d3d9 は Windows 10 においては通常は存在しないらしく、その場合は NO_JOL_COMPILE_WITH_DIRECT3D_9 を定義しないといけない。
 */
#if defined(_MSC_VER) && ( _MSC_VER < 1900 )
#   undef JOL_COMPILE_WITH_DIRECT3D_9
#endif  /* defined(_MSC_VER) && ( _MSC_VER < 1300 ) */

/*
  また、msys2 では d3d11 までしかない。
 */
#if defined(MINW32)
#   undef JOL_COMPILE_WITH_DIRECT3D_12
#endif  /* defined(MINW32) */

#define  JOL_COMPILE_WITH_OPENGL
#ifdef NO_JOL_COMPILE_WITH_OPENGL
#   undef   JOL_COMPILE_WITH_OPENGL
#endif  /* def NO_JOL_COMPILE_WITH_OPENGL */


#define  JOL_COMPILE_WITH_SOFTWARE
#ifdef NO_JOL_COMPILE_WITH_SOFTWARE
#   undef   JOL_COMPILE_WITH_SOFTWARE
#endif  /* def NO_JOL_COMPILE_WITH_SOFTWARE */


#define  JOL_COMPILE_WITH_BURNINGSVIDEO
#ifdef NO_JOL_COMPILE_WITH_BURNINGSVIDEO
#   undef   JOL_COMPILE_WITH_BURNINGSVIDEO
#endif  /* def NO_JOL_COMPILE_WITH_BURNINGSVIDEO */


#define  JOL_COMPILE_WITH_X11
#ifdef NO_JOL_COMPILE_WITH_X11
#   undef   JOL_COMPILE_WITH_X11
#endif  /* def NO_JOL_COMPILE_WITH_X11 */


#if !defined(JOL_PLATFORM_IS_OSX) && !defined(JOL_PLATFORM_IS_SOLARIS)
#   define    JOL_OPENGL_USE_EXTPOINTER
#endif  /* !defined(JOL_PLATFORM_IS_OSX) && !defined(JOL_PLATFORM_IS_SOLARIS) */
