TARGET=calculator
INCLUDE=-I/usr/include/qt

LIB=-lQt5Core \
    -lQt5Gui \
    -lQt5Widgets \

OBJS=main.o \
     ui.o \
     math.o \

%.o: %.cpp
	g++ -Wall -Wextra -O2 -c $(INCLUDE) $<

$(TARGET): $(OBJS)
	g++ $(LIB) -o $(TARGET) $(OBJS)

install: $(TARGET)
	cp -f $(TARGET) /usr/local/bin

clean:
	rm -f $(OBJS) $(TARGET)
