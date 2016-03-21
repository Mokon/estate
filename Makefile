AM_CXXFLAGS = -g0 -O3
AM_CXXFLAGS += -Wall -Wextra -std=c++1y -pedantic -Werror -Weffc++
AM_CXXFLAGS += -Wpedantic -pedantic-errors -Wundef
AM_CXXFLAGS += -Wshadow -Wstrict-aliasing -Woverloaded-virtual
AM_CXXFLAGS += -Wconversion -Wsign-compare -Wsign-conversion
AM_CXXFLAGS += -Wdeprecated -Wold-style-cast -Wcast-qual -Wcast-align
AM_CXXFLAGS += -Wunused-parameter -Wunused
AM_CXXFLAGS += -Wchar-subscripts -Wcomment -Winit-self
AM_CXXFLAGS += -Wmissing-field-initializers -Wparentheses -Wformat=2

#AM_CXXFLAGS = -DDEBUG -g -O0 -fstack-protector-all -static -pg
#AM_CXXFLAGS += -Wtrampolines -Wlogical-op -Wmissing-declarations
#AM_CXXFLAGS += -fext-numeric-literals -Wzero-as-null-pointer-constant

all:
	clang++ ${AM_CXXFLAGS} *.cpp -o BluePrint
clean:
	/bin/rm -rf BluePrint
