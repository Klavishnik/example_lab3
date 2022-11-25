CC =clang

RELEASE_CFLAGS =-g0 -O2 -fvisibility=hidden

DEBUG_CFLAGS = -gdwarf-4 -fno-omit-frame-pointer -Wall -Wextra -Wpedantic -Werror -O0

LDFLAGS =  -fsanitize=address 

REPORT_DIR = reports
ANALYZE_FLAGS = --analyze -Xanalyzer

SRC = main.c lib/*.c

ADDRESS_FLAGS= -fsanitize=address 


all:	release


analyze:
	$(CC) $(ANALYZE_FLAGS) lib/lib.c main.c

debug:
	$(CC) $(DEBUG_CFLAGS) -c $(SRC)
	$(CC) *.o -o bin_debug

address:
	$(CC) $(DEBUG_CFLAGS) $(ADDRESS_FLAGS) -c $(SRC)
	$(CC) $(LDFLAGS) *.o -o bin_asan

release:
	$(CC) $(RELEASE_CFLAGS) -c $(SRC)
	$(CC)  *.o -o bin_release

clean:
	rm -rf $(REPORT_DIR)
	rm -rf bin*
	rm -rf *.o 
	rm -rf in/ out/
fuzz:
	@export AFL_USE_ASAN=1
	afl-clang  $(DEBUG_CFLAGS) -c $(SRC)
	afl-clang -c fuzz.c -o fuzz.o
	afl-clang fuzz.o lib.o -o bin_fuzz
	mkdir in out
	echo 1 >> in/1


help:
	@echo Available goal:
	@echo '  release - make bin without -g and sanitise with optimisation 02'
	@echo '  analyze - run with static analyzer'
	@echo '  debug   - build with debug flags (no sanitsers)'
	@echo '  address - build + sanitisers'
	@echo '  clean   - delete result and backup files'
	@echo '  fuzz    - buid with afl with ASAN'
	@echo '  help    - show this message'
