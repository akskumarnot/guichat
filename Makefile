#############################################################################
# Makefile for building: login
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sun Apr 7 00:43:19 2013
# Project:  login.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile login.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = client.cpp \
		login.cpp \
		main.cpp \
		server.cpp \
		ui.cpp \
		want.cpp \
		join.cpp \
		pm.cpp moc_client.cpp \
		moc_login.cpp \
		moc_server.cpp \
		moc_ui.cpp \
		moc_want.cpp \
		moc_join.cpp \
		moc_pm.cpp \
		qrc_res.cpp
OBJECTS       = client.o \
		login.o \
		main.o \
		server.o \
		ui.o \
		want.o \
		join.o \
		pm.o \
		moc_client.o \
		moc_login.o \
		moc_server.o \
		moc_ui.o \
		moc_want.o \
		moc_join.o \
		moc_pm.o \
		qrc_res.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		login.pro
QMAKE_TARGET  = login
DESTDIR       = 
TARGET        = login

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: login.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtNetwork.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile login.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtNetwork.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile login.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/login1.0.0 || $(MKDIR) .tmp/login1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/login1.0.0/ && $(COPY_FILE) --parents client.h login.h server.h ui.h want.h join.h pm.h .tmp/login1.0.0/ && $(COPY_FILE) --parents res.qrc .tmp/login1.0.0/ && $(COPY_FILE) --parents client.cpp login.cpp main.cpp server.cpp ui.cpp want.cpp join.cpp pm.cpp .tmp/login1.0.0/ && (cd `dirname .tmp/login1.0.0` && $(TAR) login1.0.0.tar login1.0.0 && $(COMPRESS) login1.0.0.tar) && $(MOVE) `dirname .tmp/login1.0.0`/login1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/login1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_client.cpp moc_login.cpp moc_server.cpp moc_ui.cpp moc_want.cpp moc_join.cpp moc_pm.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_client.cpp moc_login.cpp moc_server.cpp moc_ui.cpp moc_want.cpp moc_join.cpp moc_pm.cpp
moc_client.cpp: client.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) client.h -o moc_client.cpp

moc_login.cpp: join.h \
		login.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) login.h -o moc_login.cpp

moc_server.cpp: server.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) server.h -o moc_server.cpp

moc_ui.cpp: client.h \
		ui.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ui.h -o moc_ui.cpp

moc_want.cpp: ui.h \
		client.h \
		want.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) want.h -o moc_want.cpp

moc_join.cpp: join.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) join.h -o moc_join.cpp

moc_pm.cpp: pm.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) pm.h -o moc_pm.cpp

compiler_rcc_make_all: qrc_res.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_res.cpp
qrc_res.cpp: res.qrc \
		smi.png \
		su.jpg \
		next.png \
		close.png \
		ref.png \
		nick.jpg \
		n.jpg \
		signup.jpeg \
		fname.jpg \
		pass.jpg \
		a.jpg
	/usr/bin/rcc -name res res.qrc -o qrc_res.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

client.o: client.cpp client.h \
		pm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o client.o client.cpp

login.o: login.cpp login.h \
		join.h \
		want.h \
		ui.h \
		client.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o login.o login.cpp

main.o: main.cpp login.h \
		join.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

server.o: server.cpp server.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o server.o server.cpp

ui.o: ui.cpp ui.h \
		client.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ui.o ui.cpp

want.o: want.cpp want.h \
		ui.h \
		client.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o want.o want.cpp

join.o: join.cpp join.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o join.o join.cpp

pm.o: pm.cpp pm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pm.o pm.cpp

moc_client.o: moc_client.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_client.o moc_client.cpp

moc_login.o: moc_login.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_login.o moc_login.cpp

moc_server.o: moc_server.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_server.o moc_server.cpp

moc_ui.o: moc_ui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ui.o moc_ui.cpp

moc_want.o: moc_want.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_want.o moc_want.cpp

moc_join.o: moc_join.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_join.o moc_join.cpp

moc_pm.o: moc_pm.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_pm.o moc_pm.cpp

qrc_res.o: qrc_res.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_res.o qrc_res.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

