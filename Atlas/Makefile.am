SUBDIRS = . Message Codecs Filters Net Objects Funky

AM_CPPFLAGS = -I$(top_srcdir)

lib_LTLIBRARIES = libAtlas-0.7.la

libAtlas_0_7_la_LDFLAGS = $(INTERFACE_VERSION)

libAtlas_0_7_la_SOURCES = \
	Bridge.cpp Codec.cpp Negotiate.cpp EncoderBase.cpp Exception.cpp \
	Filter.cpp Formatter.cpp float.cpp PresentationBridge.cpp MultiLineListFormatter.cpp

libAtlasincludedir = $(includedir)/Atlas-C++-0.7/Atlas

libAtlasinclude_HEADERS = \
	Bridge.h Codec.h Filter.h Negotiate.h EncoderBase.h \
	Task.h Codec_impl.h Exception.h Debug.h Version.h Formatter.h float.h PresentationBridge.h \
	MultiLineListFormatter.h
