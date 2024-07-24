# Bonus.mak Aufgabe6
# 
# Dieses Makefile erstellt ein aufgabe6.tar.gz

# Variablen für das Bonus-Makefile
TAR = tar
TARFLAGS = -czvf
RM = rm -f
TARGET = aufgabe6.tar.gz
DIRECTORIES = lib bin

# Pseudoziele
.PHONY: all clean package

# Standardziel "all": Erstellt das Archiv
all: package

# Ziel "clean": Löscht das Archiv
clean:
	$(RM) $(TARGET)

# Ziel "package": Erstellt das Archiv
package: $(TARGET)

# Ziel für das Erstellen des Archivs
$(TARGET):
	$(TAR) $(TARFLAGS) $(TARGET) $(DIRECTORIES) Makefile lib/Makefile bin/Makefile bonus.mak

# Variablen setzen, damit make -R funktioniert
MAKEFLAGS += -r
