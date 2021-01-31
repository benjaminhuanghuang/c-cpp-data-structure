APP = main.exe
SRC= *.cpp
CXX = g++
RM = rm

$(APP_NAME) : $(SRCS)
	$(CC) $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(APP_PATH)
	
# clean all sources
clean:
	$(RM) -rf $(OBJS)
	$(RM) -rf $(SRC_PATH)/*o
	$(RM) -rf $(APP_PATH)

