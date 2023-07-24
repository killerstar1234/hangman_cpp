#!/bin/bash

# List all your C++ source files here
SOURCE_FILES="main.cpp getRandomWord.cpp giveInstructions.cpp game.cpp checkmatch.cpp gameover.cpp displayGuess.cpp"

# Output executable name
OUTPUT_NAME="hangman"

# Compiler options
# You can customize these options based on your requirements
# For example, you can add optimization flags (-O2) or debugging flags (-g)
COMPILER_OPTIONS="-std=c++11"

# Compile the C++ code
g++ $COMPILER_OPTIONS $SOURCE_FILES -o $OUTPUT_NAME

# Check if compilation was successful
if [ $? -eq 0 ]; then
  echo "Compilation successful. Executable created: $OUTPUT_NAME"
else
  echo "Compilation failed."
fi
