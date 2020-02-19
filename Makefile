CC=sdcc
ALL_CFLAGS=$(CFLAGS)
LDFALGS=

src_files=main.c
ihx_files=main.ihx
hex_files=main.hex


all: $(hex_files)


$(ihx_files): $(src_files)
	@$(CC) $(ALL_CFLAGS) $(LDFLAGS) $< -o $@


$(hex_files): $(ihx_files)
	@packihx $< > $@ 2>/dev/null


clean: 
	@[ -d ".git" ] && git clean -f || echo "[ERROR]: only work with git repository"
