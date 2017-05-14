dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(Zeta, 1.0.4,[],[],[sourceforge.net/p/eftihia])
AC_PROG_CXX

AC_CANONICAL_SYSTEM

dnl Initialize automake
AM_INIT_AUTOMAKE([subdir-objects])

dnl this allows us specify individual liking flags for each target
AM_PROG_CC_C_O 

dnl Initialize Libtool
LT_INIT

dnl Check if Libtool is present
dnl Libtool is used for building share libraries 
AC_PROG_LIBTOOL
AC_CONFIG_MACRO_DIR([m4])

AC_LANG([C++])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADER([stddef.h])
AC_HEADER_STDC
AC_CHECK_HEADER([string])
AC_CHECK_HEADER([iostream])


# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_SIZE_T
AX_CXX_COMPILE_STDCXX_11([],[mandatory])

# Checks for library functions.
AC_CHECK_FUNCS([sqrt strtol strtoul])

PKG_CHECK_MODULES(lua51, [lua-5.1],[], [PKG_CHECK_MODULES(lua51, [lua5.1])])

AC_SUBST(CPPFLAGS_back,[$CPPFLAGS])
AC_SUBST(CPPFLAGS,["$CPPFLAGS $lua51_CFLAGS"])
AC_CHECK_HEADER([tolua++.h],[],AC_MSG_ERROR([tolua++.h was not found. Consider installing it]))
AC_SUBST(CPPFLAGS,[$CPPFLAGS_back])


PKG_CHECK_MODULES(libxmlpp, [libxml++-2.6])
PKG_CHECK_MODULES(cegui, [CEGUI-0 CEGUI-0-LUA CEGUI-0-OPENGL])
PKG_CHECK_MODULES(zlib, [zlib])
PKG_CHECK_MODULES(allegro5, [allegro_primitives-5.0 allegro_color-5.0 allegro-5.0 allegro_audio-5.0 allegro_acodec-5.0 allegro_image-5.0 ])

AC_CONFIG_FILES(Makefile
                Demo/Makefile
                libzeta/Makefile
                include/Makefile
                libzeta/zeta.pc
                libzeta/zeta-sdk-allegro5.pc)
AC_OUTPUT
