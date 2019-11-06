.SUFFIXES : .cpp .o

cxx = g++
cppflags = -c

objects = main.o print.o student_id.o

target = test

$(target) : $(objects)
			  $(cxx) -o $(target) $(objects)

clean : 
	rm -rf $(target) $(objects)

main.o = main.cpp
print.o = print.cpp
student_id.o = student_id.cpp
					   
