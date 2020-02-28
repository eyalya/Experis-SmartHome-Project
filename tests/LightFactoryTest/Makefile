CC = g++
CXX = $(CC)

CPPFLAGS += $(addprefix -I,$(INC_DIRS))
CPPFLAGS += -MMD -MP

CFLAGS = -g3 -pedantic -Wall -Werror -Wextra

CXXFLAGS = $(CFLAGS) 
CXXFLAGS += -std=c++17

# LDFLAGS += 
# LDLIBS += 

INC_DIRS += ../../include/

SOURCES  = $(TARGET).cpp ../../source/conditional_var.cpp ../../source/locks.cpp ../../source/informative_exception.cpp 
SOURCES  += ../../source/common.cpp 
SOURCES  += ../../source/light_event_factory.cpp
OBJECTS  = $(SOURCES:.cpp=.o)

TARGET = light_factory_test

.PHONY: clean test all val

all:  $(TARGET)

test: $(TARGET)
	./$(TARGET)
    
$(TARGET): $(OBJECTS) -lpthread

clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPENDS)
    
val:
	valgrind --leak-check=full ./$(TARGET)
    
DEPENDS = $(OBJECTS:%.o=%.d)

-include $(DEPENDS)


