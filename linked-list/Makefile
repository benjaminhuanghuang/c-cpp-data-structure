
CXX       = gcc
CPPEXE    = cppdemo.exe
CEXE    = cdemo.exe
SOURCES   = linked-list.c
CPPFLAGS     = -std=c++11 -Wall
CFLAGS     = -std=c99 -Wall

all: $(CEXE)

$(CPPEXE) : *.cpp
	$(CXX) $(CPPFLAGS) *.cpp -o $(CPPEXE)

$(CEXE) : *.c
	$(CXX) $(CFLAGS) *.c -o $(CEXE)

clean :
	rm -f $(EXEBIN)
