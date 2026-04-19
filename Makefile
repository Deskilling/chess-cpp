PROJECT  := chess

BUILDDIR := bin
OBJDIR   := obj
SRCDIR   := src

CC      := g++
CFLAGS  := -std=c++23 -Wall -Wextra -I. -MMD -MP
LDFLAGS := -lm

SRCS := $(shell find $(SRCDIR) -name "*.cpp")
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS := $(OBJS:.o=.d)

TARGET := $(BUILDDIR)/$(PROJECT)

.PHONY: all clean

all: $(TARGET)

$(BUILDDIR):
	mkdir -p $@

$(TARGET): $(OBJS) | $(BUILDDIR)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(OBJDIR)

-include $(DEPS)
