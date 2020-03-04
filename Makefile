CPP = g++
LINK = $(CPP)
RM = rm -f



DEBUG = -g
CPPFLAGS = 
LDFLAGS =

TARGET = Projet

SRCS = main.cpp Task.cpp

OBJS = $(subst .cpp,.o,$(SRCS))

all: $(TARGET)


main.o : main.cpp Task.h 
Task.o : Task.h Task.cpp  


%.o: %.cpp ; $(CPP) $(CPPFLAGS) $(DEBUG) -c $<

.PHONY : all

$(TARGET): $(OBJS)
	$(LINK) -o $(TARGET) $(OBJS) $(LDFLAGS)

clean:
	$(RM) *.o $(TARGET) *~
