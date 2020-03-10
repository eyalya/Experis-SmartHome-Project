CC = g++
CXX = $(CC) 

CPPFLAGS += $(addprefix -I,$(INC_DIRS))
CPPFLAGS += -MMD -MP 

CFLAGS = -fpic -g3 -pedantic -Wall -Werror -Wextra 

CXXFLAGS = $(CFLAGS) 
CXXFLAGS += -std=c++17

LDFLAGS += -shared -lpthread  

INC_DIRS += ../include/
INC_DIRS += ../include/inl/

SOURCES  += $(wildcard ../source/*.cpp)

OBJECTS  = $(SOURCES:.cpp=.o)

TARGET = demo_devices.so

.PHONY: clean test all val

all:  $(TARGET)

$(TARGET): $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPENDS)
    
val:
	valgrind --leak-check=full ./$(TARGET)
    
DEPENDS = $(OBJECTS:%.o=%.d)

-include $(DEPENDS)


