SDIR = ./source
ODIR = ./build
OUT = ./bin
INC = ./include
CFILES = $(wildcard $(SDIR)/*.c)
OFILES = $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(CFILES))

all: $(OUT)/player

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(ODIR) $(OUT)
	gcc -c -Wextra -g  $< -o $@ -I$(INC)

$(OUT)/player: $(OFILES)
	gcc $^ -o $@
    
clean:
	rm -rf $(ODIR) $(OUT)
    
.PHONY: all clean
