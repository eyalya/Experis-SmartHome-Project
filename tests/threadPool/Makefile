CC = g++ 
CXX = $(CC)

CPPFLAGS += $(addprefix -I,$(INC_DIRS))
CPPFLAGS += -MMD -MP 

CFLAGS = -g3 -pedantic -Wall -Werror -Wextra
CXXFLAGS = $(CFLAGS) 
CXXFLAGS += -std=c++17
CXXFLAGS += -O0
# LDFLAGS += 
LDLIBS += -lpthread

INC_DIRS += ../../../include ../../include ../../inl

SOURCES  = ./$(TARGET).cpp 
SOURCES  += ../../source/thread.cpp ../../source/locks.cpp ../../source/conditional_var.cpp ../../source/taskers.cpp
SOURCES  = $(wildcard ../../source/*.cpp)

OBJECTS  = $(SOURCES:.cpp=.o)

TARGET = thread_pool_test

.PHONY: clean test all val

all:  $(TARGET)

test: $(TARGET)
	./$(TARGET) -v

$(TARGET): $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPENDS)

val:
	valgrind --leak-check=full ./$(TARGET)

hell:
	valgrind --tool=helgrind --log-file=loghelgrind01.txt ./$(TARGET)

valDrd:
	valgrind --tool=drd --log-file=logdrd01.txt ./$(TARGET)


DEPENDS = $(OBJECTS:%.o=%.d)

-include $(DEPENDS)

