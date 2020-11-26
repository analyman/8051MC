CC=sdcc
ALL_CFLAGS=$(CFLAGS)
LDFALGS=

src_files=main.c seven_seg_display.c utils.c matrix_keyboard.c beep.c
rel_files=$(patsubst %.c,%.rel,$(src_files))
ihx_files=main.ihx
hex_files=main.hex

num_files=$(words $(src_files))

define rel_template
$(patsubst %.c,%.rel,$(1)): $(1)
endef

all: $(hex_files)

$(foreach CSRC,$(src_files),$(eval $(call rel_template,$(CSRC))))

$(ihx_files): $(rel_files)
	@$(CC) $(LDFALGS) $^ -o $@


$(rel_files):
	@$(CC) -c $(ALL_CFLAGS) $^ -o $@


$(hex_files): $(ihx_files)
	@packihx $< > $@ 2>/dev/null


clean: 
	@[ -d ".git" ] && git clean -Xf || echo "[ERROR]: only work with git repository"
