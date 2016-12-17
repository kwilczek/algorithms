#
# n.o is made automatically from n.cc, n.cpp, or n.C
# with a recipe of the form ‘$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c’.
#
CXX=g++
CXXFLAGS=-Wall

objects = sorting_alg.o mersenne.o selection.o insertion.o bubble.o quick.o merge.o

sorting_machine: $(objects)
	$(CXX) $(CXXFLAGS) -o sorting_machine $(objects)

sorting_alg.o: colors.h sorter.h
mersenne.o: mersenne.h
merge.o: merge.h
selection.o: selection.h
insertion.o: insertion.h
bubble.o: bubble.h
quick.o: quick.h
