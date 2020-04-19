include makefile.conf

All: $(TARGET_NAME)

$(TARGET_NAME): $(TARGET_OBJS)
	$(CC) $(OFLAG) $@ $^

$(MAIN_O): $(MAIN_C)
	$(CC) $(CFLAG) $(OFLAG) $@ $(MAIN_C)

$(ER_O): $(ER_C) $(ER_H)
	$(CC) $(CFLAG) $(OFLAG) $@ $(ER_C)

$(MAN_O): $(MAN_C) $(MAN_H)
	$(CC) $(CFLAG) $(OFLAG) $@ $(MAN_C)

$(CAL_O): $(CAL_C) $(CAL_H)
	$(CC) $(CFLAG) $(OFLAG) $@ $(CAL_C)

.PHONY: PRINT

PRINT:
	@echo "TEST PRINT"

clean:
	$(RM) $(TARGET_OBJS)
	$(RM) $(TARGET_NAME)
