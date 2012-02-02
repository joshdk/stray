NAME                 = stray

BUILD_DIR            = ./build
BUILD_PROG           = $(BUILD_DIR)/$(NAME)
BUILD_FILES          = $(BUILD_DIR)/main.o

INSTALL_DIR          = /usr/bin
INSTALL_PROG         = $(INSTALL_DIR)/$(NAME)

CC                 = gcc
CFLAGS             = -std=c99 -Wall -Wextra

SUCCESS_MSG        = '  [\e[32m DONE \e[0m]'


all: build

build: $(BUILD_PROG)

$(BUILD_PROG): $(BUILD_FILES)
	@echo 'Building stray:'
	@$(CC) $(CFLAGS) $^ -o $@
	@echo -e $(SUCCESS_MSG)

./build/main.o: ./src/main.c
	@mkdir -p build/
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo 'Cleaning workspace:'
	@rm -rf build/
	@echo -e $(SUCCESS_MSG)

rebuild: clean build

install: build $(CONFIG_FILES)
	@echo 'Installing stray:'
	@install -m 755 $(BUILD_PROG) $(INSTALL_PROG)
	@echo -e $(SUCCESS_MSG)

uninstall:
	@echo 'Uninstalling stray:'
	@rm -f $(INSTALL_PROG)
	@echo -e $(SUCCESS_MSG)
