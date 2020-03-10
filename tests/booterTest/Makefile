CC = g++
CXX = $(CC)

CPPFLAGS += $(addprefix -I,$(INC_DIRS))
CPPFLAGS += -MMD -MP

CFLAGS = -fPIC -g3 -pedantic -Wall -Werror -Wextra

CXXFLAGS = $(CFLAGS) 
CXXFLAGS += -std=c++17

LDFLAGS += -lpthread -shared -ldl
LDLIBS += 

INC_DIRS += ../../include/
INC_DIRS += ../../include/inl/

SOURCES  = $(TARGET).cpp
SOURCES  += $(wildcard ../../source/*.cpp)

OBJECTS  = $(SOURCES:.cpp=.o)

TARGET = booter_test

.PHONY: clean test all val

all:  $(TARGET)

test: $(TARGET)
	./$(TARGET)
    
$(TARGET): $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPENDS)
    
val:
	valgrind --leak-check=full ./$(TARGET)
    
DEPENDS = $(OBJECTS:%.o=%.d)

-include $(DEPENDS)


