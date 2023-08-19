# Build and run the 'parabolico' executable, and execute the 'animation' script
all: parabolico animation

# Compile and run the 'parabolico' executable
parabolico: parabolico.cpp; g++ -std=c++14 -Wall -Wextra -pedantic parabolico.cpp -o parabolico && ./parabolico

# Run the 'animation' script using Python 3
animation: animation.py; python3 animation.py

# Clean up generated files
clean:;rm -rf parabolico *.png *.gif *.csv
