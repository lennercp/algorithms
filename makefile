CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -Wconversion -Wlogical-op -Wshift-overflow=2 \
           -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 \
           -fsanitize=address -fsanitize=undefined -fno-sanitize-recover \
           -fstack-protector -std=c++20

# Regra genérica: make nome => compila nome.cpp
%: %.cpp
	@$(CXX) $(CXXFLAGS) -o $@ $<
