# Makefile Aufgabe6
#
PACKAGES = lib bin
.PHONY: all clean

# Pseudoziel "all": Führt "all" in den Unterverzeichnissen aus
all clean:
	for p in $(PACKAGES); do \
		(cd $$p && $(MAKE) $@); \
	done
