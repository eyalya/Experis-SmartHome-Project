CC = g++
CXX = $(CC)

CPPFLAGS += $(addprefix -I,$(INC_DIRS))
CPPFLAGS += -MMD -MP

CFLAGS = -fPIC -g3 -pedantic -Wall -Werror -Wextra

CXXFLAGS = $(CFLAGS) 
CXXFLAGS += -std=c++17

LDFLAGS += -pthread -export-dynamic
LDLIBS += -ldl

INC_DIRS += ../../include/
INC_DIRS += ../include/
INC_DIRS += ../../include/inl/

SOURCES  = $(TARGET).cpp
SOURCES  += $(wildcard ../../source/*.cpp)

OBJECTS  = $(SOURCES:.cpp=.o)

TARGET = so_loading

.PHONY: clean test all val

all:  $(TARGET)
	LD_LIBRARY_PATH=../../libs/ ./$(TARGET)

test: $(TARGET)
	LD_LIBRARY_PATH=../../libs/ ./$(TARGET)
 
debug: $(TARGET)
	LD_LIBRARY_PATH=../../libs/ gdb ./$(TARGET)  

# $(TARGET): CXXFLAGS += -rdynamic
$(TARGET): $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPENDS)
    
val:
	valgrind --leak-check=full ./$(TARGET)
    
DEPENDS = $(OBJECTS:%.o=%.d)

-include $(DEPENDS)


