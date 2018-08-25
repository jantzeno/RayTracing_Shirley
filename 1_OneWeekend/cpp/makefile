TARGET		= raytracer

CC				= g++
CFLAGS		=	-std=c++17 -Wall -pedantic -g -I.
LINKER		=	g++
LFLAGS		= -Wall -I.
BINDIR		=	bin
SRCDIR		= src
OBJDIR		= obj

rm				= rm -f

$(TARGET): main.o
	@$(LINKER) -o $(BINDIR)/$(TARGET) $(LFLAGS) $(OBJDIR)/main.o
	@echo "Linking complete!"

main.o:
	@$(CC) -c $(CFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o
	@echo "Compiling complete!"

.PHONY: clean
clean:
	@$(rm) $(OBJDIR)/*.o
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
