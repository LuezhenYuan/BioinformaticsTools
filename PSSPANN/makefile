SUB_DIR := PSSPcc PSSP-proto PSSP-gui
subsystem:
	@for n in $(SUB_DIR); do make -C $$n ; done
clean:
	@for n in $(SUB_DIR); do make clean -C $$n ; done
install:
	@for n in $(SUB_DIR); do make install -C $$n ; done
uninstall:
	@for n in $(SUB_DIR); do make uninstall -C $$n ; done
