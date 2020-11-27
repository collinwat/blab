.DEFAULT_GOAL := default

VENV = $(shell poetry env info -p)

ifeq ($(SKIP_PACKAGES),)
SKIP_PACKAGES=--skip-packages
else
SKIP_PACKAGES=
endif

ifeq ($(VENV),)
PYTHON=
else
PYTHON=$(VENV)/bin/python
endif

ifeq ($(ENV),)
ENV_FLAG=
else
ENV_FLAG=-e $(ENV)
endif

COMMANDS = buildfs erase size upload uploadfs

.PHONY: $(COMMANDS)
$(COMMANDS):
	poetry run pio run $(ENV_FLAG) -t $@

.PHONY: default
default: check build

.PHONY: build
build:
	poetry run pio run $(ENV_FLAG)
	poetry run pio run -t compiledb

check:
	poetry run pio check $(ENV_FLAG) $(SKIP_PACKAGES)

.PHONY: clean
clean:
	poetry run pio run $(ENV_FLAG) -t clean
	rm -rf .cache .ccls-cache compile_commands.json

.PHONY: compiledb
compiledb:
	poetry run pio run -t compiledb

.PHONY: install
install:
	poetry install

.PHONY: reinstall
reinstall: uninstall install

.PHONY: uninstall
uninstall:
ifeq ($(patsubst %.venv,.venv,$(lastword $(VENV))),.venv)
	rm -rf $(VENV)
else ifneq ($(PYTHON),)
	poetry env remove $(PYTHON)
endif
	rm -rf .pio

.PHONY: update
update:
	poetry update
	poetry run pio update
