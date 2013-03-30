CC		= gcc
CFLAGS	= -g -Wall 
RM		= rm
FLAGS  = -fopenmp

CSRCS	= main.c game_of_life.c process.c
TARGET	= game_of_life_openmp
OBJECTS	= $(CSRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
		$(CC) $(OBJECTS) -o $@ $(FLAGS) 

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@ $(FLAGS)

clean:
		$(RM) -f $(OBJECTS) $(TARGET) *~