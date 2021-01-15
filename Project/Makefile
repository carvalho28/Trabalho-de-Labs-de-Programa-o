COMPILER = gcc
SOURCEFILES = main.c part1.h part2.h

# Preserves intermediate files created
.PRECIOUS: $(SOURCEFILES)

.PHONY: all clean

all: team13.exe doxy

# Generates an executable project file
team13.exe: main.o
	@$(COMPILER) -o $@ $< -lm
	@echo "team13.exe executable file created successfully."

# Generates Doxygen config file and HTML page
doxy: $(SOURCEFILES)
	@echo "Doxygen configuration file generated."
	@doxygen Doxyfile
	@clear
	@echo "HTML file generated."

# Compiles project files
main.o: $(SOURCEFILES)
	@$(COMPILER) -c  main.c -lm
	@echo "Object file of main.c generated."

# Removes auxiliary files
clean:
	@rm -r latex html Doxyfile *.exe *.o *.bak
	@echo "Auxiliary files removed."
