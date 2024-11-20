CXX ?= g++
CXX_FLAGS := -std=c++14 $\
						 -O2 -march=x86-64 -pipe $\
						 -Wall -Wextra -Wpedantic -Wno-unused-parameter $\
						 -Iinclude -I.

OBJECT_FILES := $(patsubst src/%.cpp,$\
									build/%.o,$\
									$(shell find src -name '*.cpp'))

# uncomment/comment to enable/disable
# PROCESS_HEADER_FILES := yes
PROCESSED_HEADER_FILES := $(if ${PROCESS_HEADER_FILES},$\
														$(subst .hpp,$\
														$(if $(findstring clang++,${CXX}),$\
															.hpp.pch,$\
															.hpp.gch),$\
														$(shell find include -name '*.hpp')))

PSH_REQUIREMENTS := ${PROCESSED_HEADER_FILES} ${OBJECT_FILES}

CLEANUP_FILES := $(shell find -name '*~')

define COMPILE
${CXX} -c $1 ${CXX_FLAGS} -o $2

endef
define REMOVE
$(if $(wildcard $(1)),$\
	rm $(1))

endef
define REMOVE_LIST
$(foreach ITEM,$\
	$(1),$\
	$(call REMOVE,${ITEM}))
endef

all: psh

psh: ${PSH_REQUIREMENTS}
	${CXX} ${OBJECT_FILES} ${CXX_FLAGS} -o psh

build/%.o: src/%.cpp
	$(call COMPILE,$<,$@)

%.gch: %
	$(call COMPILE,$<,$@)
%.pch: %
	$(call COMPILE,$<,$@)

clean:
	$(call REMOVE_LIST,${PSH_REQUIREMENTS})
	$(call REMOVE,psh.exe)

.PHONY: all
